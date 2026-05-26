#include <stm32f4xx_hal.h>
#include "LedLcd.h"
#include "KeyboardTsLcd.h"


int main()
{
	KeyboardTsLcd MyKeyboard(0);
	LedLcd MyLed(2);
	while(1) {
		switch(MyKeyboard.eRead()) {
			case BUTTON_0:
				MyLed.On(3);
				break;
			case BUTTON_1:
				MyLed.On(2);
				break;
			case BUTTON_2:
				MyLed.On(1);
				break;
			case BUTTON_3:
				MyLed.On(0);
				break;
			default:
				MyLed.On(4);
				break;
		}

		HAL_Delay(100);
	}
}

