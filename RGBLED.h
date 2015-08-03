#ifndef RGBLED_H
#define RGBLED_H

class RGBLED {
	public:
		RGBLED(int redPin, int greenPin, int bluePin);
		void setRGB(int r, int g, int b);
		void setRed(int r);
		void setGreen(int g);
		void setBlue(int b);

		int red();
		int green();
		int blue();

	private:
		int redPin;
		int greenPin;
		int bluePin;
		int red;
		int green;
		int blue;
}

#endif
