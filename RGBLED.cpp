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

// Fade the red, green and blue values
void RGBLED::fadeRGB(int r, int g, int b) {
    while (red != r || green != g || blue != b) {
        if (red < r)        { setRed(red+1); }
        else if (red > r)   { setRed(red-1); }

        if (green < g)      { setGreen(green+1); }
        else if (green > g) { setGreen(green-1); }

        if (blue < b)       { setBlue(blue+1); }
        else if (blue > b)  { setBlue(blue-1); }

        delay(RGBLED_FADE_DELAY);
    }
}

// Fade the red value
void RGBLED::fadeRed(int r) {
    while (red != r) {
        if (red < r)    { setRed(red+1); }
        else            { setRed(red-1); }

        delay(RGBLED_FADE_DELAY);
    }
}

// Fade the green value
void RGBLED::fadeGreen(int g) {
    while (green != g) {
        if (green < g)  { setGreen(green+1); }
        else            { setGreen(green-1); }

        delay(RGBLED_FADE_DELAY);
    }
}

// Fade the blue value
void RGBLED::fadeBlue(int b) {
    while (blue != b) {
        if (blue < b)   { setblue(blue+1); }
        else            { setblue(blue-1); }

        delay(RGBLED_FADE_DELAY);
    }
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
int RGBLED::red()   { return red;   }
int RGBLED::green() { return green; }
int RGBLED::blue()  { return blue;  }

