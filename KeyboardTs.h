#ifndef KEYBOARDTS_H_
#define KEYBOARDTS_H_

enum eButtonRead{
	BUTTON_0,
	BUTTON_1,
	BUTTON_2,
	BUTTON_3,
	RELEASED
};

class KeyboardTs{
	public:
		KeyboardTs(unsigned char keyboardIndex);
		enum eButtonRead eRead();
	private:
	    unsigned char kIndex;
};


#endif /* KEYBOARDTS_H_ */
