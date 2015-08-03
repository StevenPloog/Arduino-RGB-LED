#include "Arduino.h"
#include "RGBLED.h"

// Constructor for the led
// Pins passed to this constructor must implement Arduino's analogWrite method
RGBLED::RGBLED(int redPin, int greenPin, int bluePin) {
	this.redPin = redPin;
	this.greenPin = greenPin;
	this.bluePin = bluePin;

	red = 0;
	green = 0;
	blue = 0;
}

// Set the red, green and blue values
void RGBLED::setRGB(int r, int g, int b) {
	red = r;
	green = g;
	blue = b;

	analogWrite(redPin, red);
	analogWrite(greenPin, green);
	analogWrite(bluePin, blue);
}

// Set the red value
void RGBLED::setRed(int r) {
	red = r;
	analogWrite(redPin, red);
}

// Set the green value
void RGBLED::setGreen(int g) {
	green = g;
	analogWrite(greenPin, green);
}

// Set the blue value
void RGBLED::setBlue(int b) {
	blue = b;
	analogWrite(bluePin, blue);
}

// Getter methods for rgb values
int RGBLED::red()	{ return red;	}
int RGBLED::green()	{ return green;	}
int RGBLED::blue()	{ return blue;	}
