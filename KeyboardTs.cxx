#include "KeyboardTs.h"

#include <stm32f429i_discovery_lcd.h>
#include <stm32f429i_discovery_ts.h>
#include <stm32f4xx_hal.h>

TS_StateTypeDef TS_State;


KeyboardTs::KeyboardTs(unsigned char keyboardIndex) {
	kIndex = keyboardIndex;
	BSP_TS_Init(240, 320);
}

enum eButtonRead KeyboardTs::eRead(){
	unsigned char ucLedIndex = 0xF;

	BSP_TS_GetState(&TS_State);

	if(TS_State.TouchDetected == 1 && (TS_State.X / 80) == kIndex){
		ucLedIndex = TS_State.Y / 80;

		switch(ucLedIndex){
		case 0:
			return BUTTON_3;
			break;
		case 1:
			return BUTTON_2;
			break;
		case 2:
			return BUTTON_1;
			break;
		case 3:
			return BUTTON_0;
			break;
		default:
			return RELEASED;
			break;
		}


	}else{
		return RELEASED;
	}

}
