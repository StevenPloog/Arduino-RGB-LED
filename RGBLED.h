#ifndef RGBLED_H
#define RGBLED_H

#ifndef RGBLED_FADE_DELAY
#define RGBLED_FADE_DELAY 15
#endif

class RGBLED {
	public:
		RGBLED(int redPin, int greenPin, int bluePin);

		void fadeRGB(int r, int g, int b);
		void fadeRed(int r);
		void fadeGreen(int g);
		void fadeBlue(int b);

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
