#ifndef LEDLCD_H_
#define LEDLCD_H_

class LedLcd {
	public:
		LedLcd(unsigned char ledColInput);
		void On(unsigned char LedIndex);
	private:
		void DrawRectangleLCD(unsigned char ButtonIndex, unsigned int fillColor);
		unsigned char ledCol;
};

#endif /* LEDLCD_H_ */
