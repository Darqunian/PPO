#ifndef KEYBOARDTSLCD_H_
#define KEYBOARDTSLCD_H_

#include "KeyboardTs.h"
#include "LedLcd.h"

class KeyboardTsLcd {
	public:
		KeyboardTsLcd(unsigned char _ucColumn);
		enum eButtonRead eRead();

	private:
		KeyboardTs* pKeyboard;
		LedLcd* pLed;
};

#endif /* KEYBOARDTSLCD_H_ */
