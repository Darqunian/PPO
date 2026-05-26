#include "LedLcd.h"
#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_ts.h"
#include <stdio.h>

LedLcd::LedLcd(unsigned char ledColInput) {
    ledCol = (ledColInput)*80;
    BSP_LCD_SetFont(&Font24);
}

void LedLcd::DrawRectangleLCD(unsigned char ButtonIndex, unsigned int fillColor) {
    char labelBuffer[4];
    uint16_t Yposition = ButtonIndex * 80;
    uint16_t Xposition = ledCol;

    BSP_LCD_SetTextColor(fillColor);
    BSP_LCD_FillRect(Xposition, Yposition + 1, 79, 79);

    BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
    BSP_LCD_DrawRect(Xposition, Yposition, 80, 80);

    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_SetBackColor(LCD_COLOR_RED);

    sprintf(labelBuffer, "%d", ButtonIndex + 1);
    BSP_LCD_DisplayStringAt(Xposition, Yposition, (uint8_t*)labelBuffer, LEFT_MODE);
}

void LedLcd::On(unsigned char LedIndex) {
    for (unsigned char ButtonIndex = 0; ButtonIndex < 4; ButtonIndex++) {
        DrawRectangleLCD(ButtonIndex, (ButtonIndex == LedIndex) ? LCD_COLOR_GREEN : LCD_COLOR_BLUE);
    }
}
