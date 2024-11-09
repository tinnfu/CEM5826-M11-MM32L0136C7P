#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define _MAIN_C_

#include "platform.h"
#include "uart.h"
#include "slcd.h"

#if !defined(HAVE_SNPRINTF)
#define HAVE_SNPRINTF 1
int snprintf(char *str, size_t size, const char *format, ...);
#endif

void clearScreen();
void process();
void decode(uint8_t c);

typedef enum {
    BUF_RX_AGAIN,       // need more char
    BUF_RX_LAST_2,      // need last 2 char
    BUF_RX_LAST_1,      // need last 1 char
    BUF_RX_COMPLETE,    // message complete
} BufState;
typedef struct {
    char data[32];
    uint8_t len;
    BufState state;
} Buf;
volatile Buf gBuf = {0};

void clearScreen()
{
    SLCD_Clear(1);
    SLCD_Clear(0);
}

typedef enum {
    SMALL_SZ = 5,   // 1~4 num + 1 point
    BIG_SZ = 7      // 5~10 num + 1 point
} SIZE;
void displayNum(float num, SIZE sz)
{
    // EVB-L0136 LCD, max num count is 6
    char buf[8] = {'9', '9', '9', '9', '9', '9', '9', '9'};
    int bufLen = 0;
    int pos = -1;
    int i = 0;

    buf[sz - 1] = '\0';

    if (abs((int)num) > atoi(buf)) {
        sprintf(buf, "nA");
    } else {
        float num1 = num;
        char tmp[sizeof(buf)] = {0};
        if (num1 < 0) {
            num1 = -num1;
        }
        int off = sprintf(tmp, "%d", (int)num1);
        int f = (int)((num1 - (int)num1) * 10);
        if ((off < (sz - 1)) && (f > 0)) {
            pos = off;
            sprintf(tmp + off, "%d", f);
        }

        // add '-'
        if (num != num1) {
            if (strlen(tmp) < (sz-1)) {
                snprintf(buf, sizeof(buf), "-%s", tmp);
				pos += 1;
            } else {
                sprintf(buf, "nA");
				pos = -1;
            }
        } else {
            memcpy(buf, tmp, sizeof(buf));
        }
    }

    bufLen = strlen(buf);

    switch (sz) {
        case SMALL_SZ: {
            for (i = 0; i < bufLen; ++i) {
                SLCD_DisplayNumber1(SMALL_SZ - 1 - bufLen + i, buf[i], i == (pos - 1));
            }
        } break;
        case BIG_SZ: {
            for (i = 0; i < bufLen; ++i) {
                SLCD_DisplayNumber2(BIG_SZ - 1 - bufLen + i, buf[i], i == (pos - 1));
            }
        } break;
        default: break;
    }
}

void process()
{
    clearScreen();

    // v=0.8 km/h, str=989
    printf("%*s", gBuf.len, gBuf.data);

    char *token = NULL;
    float v = 0.0;
    int intensity = 0;

    token = strtok((char *)gBuf.data, " ,=");
    while (token != NULL) {
        if (strcmp(token, "v") == 0 || strcmp(token, "vv") == 0) {
            token = strtok(NULL, " ,=");
            v = atof(token);
        } else if (strcmp(token, "str") == 0) {
            token = strtok(NULL, " ,=");
            intensity = atoi(token);
        }
        token = strtok(NULL, " ,=");
    }

    displayNum(v, SMALL_SZ);
    displayNum(intensity, BIG_SZ);

    memset((void *)&gBuf, 0, sizeof(gBuf));
}

/***********************************************************************************************************************
  * @brief  rx a message
  * @note   none
  * @param  none
  * @retval 0 for rx complete, else need more char
  *********************************************************************************************************************/
void decode(uint8_t c)
{
    gBuf.data[gBuf.len++] = c;

    // v=**, str=**\r\n\r
    switch (gBuf.state) {
        case BUF_RX_AGAIN:
            if (c == '\r') {
                gBuf.state = BUF_RX_LAST_2;
            }
            break;
        case BUF_RX_LAST_2:
            if (c == '\n') {
                gBuf.state = BUF_RX_LAST_1;
            } else {
                gBuf.state = BUF_RX_AGAIN;
            }
            break;
        case BUF_RX_LAST_1:
            if (c == '\r') {
                gBuf.state = BUF_RX_COMPLETE;
            } else {
                gBuf.state = BUF_RX_AGAIN;
            }
            break;
        default:
            break;
    }

    if (gBuf.state == BUF_RX_COMPLETE) {
        PLATFORM_LED_Toggle(LED2);
        PLATFORM_DelayMS(300);

        process();
    } else if (gBuf.len == sizeof(gBuf.data)) {
        memset((void *)&gBuf, 0, sizeof(gBuf));
    }
}

/***********************************************************************************************************************
  * @brief  This function is main entrance
  * @note   main
  * @param  none
  * @retval none
  *********************************************************************************************************************/
int main(void)
{
    PLATFORM_Init();
    SLCD_Configure();
    UART_Configure(115200);

    while (1)
    {
        if (SET == UART_GetFlagStatus(UART1, UART_FLAG_RXAVL))
        {
            decode(UART_ReceiveData(UART1));
        }
    }
}