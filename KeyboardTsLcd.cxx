#include "KeyboardTsLcd.h"
#include <stm32f4xx_hal.h>

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn) {
    pKeyboard = new KeyboardTs(_ucColumn);
    pLed = new LedLcd(_ucColumn);
}


enum eButtonRead KeyboardTsLcd::eRead() {

    eButtonRead eButton = pKeyboard->eRead();

    switch(eButton) {
        case BUTTON_0:
            pLed->On(0);
            break;
        case BUTTON_1:
            pLed->On(1);
            break;
        case BUTTON_2:
            pLed->On(2);
            break;
        case BUTTON_3:
            pLed->On(3);
            break;
        default:
            pLed->On(4);
            break;
    }

    return eButton;
}


