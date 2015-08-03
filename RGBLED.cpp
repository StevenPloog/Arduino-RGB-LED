#include "Arduino.h"
#include "RGBLED.h"

// Constructor for the led
// Pins passed to this constructor must implement Arduino's analogWrite method
RGBLED::RGBLED(int redPin, int greenPin, int bluePin) {
    _redPin = redPin;
    _greenPin = greenPin;
    _bluePin = bluePin;

    _red = 0;
    _green = 0;
    _blue = 0;
}

// Fade the red, green and blue values
void RGBLED::fadeRGB(int r, int g, int b) {
    while (_red != r || _green != g || _blue != b) {
        if (_red < r)        { setRed(_red+1); }
        else if (_red > r)   { setRed(_red-1); }

        if (_green < g)      { setGreen(_green+1); }
        else if (_green > g) { setGreen(_green-1); }

        if (_blue < b)       { setBlue(_blue+1); }
        else if (_blue > b)  { setBlue(_blue-1); }

        delay(RGBLED_FADE_DELAY);
    }
}

// Fade the red value
void RGBLED::fadeRed(int r) {
    while (_red != r) {
        if (_red < r)   { setRed(_red+1); }
        else            { setRed(_red-1); }

        delay(RGBLED_FADE_DELAY);
    }
}

// Fade the green value
void RGBLED::fadeGreen(int g) {
    while (_green != g) {
        if (_green < g) { setGreen(_green+1); }
        else            { setGreen(_green-1); }

        delay(RGBLED_FADE_DELAY);
    }
}

// Fade the blue value
void RGBLED::fadeBlue(int b) {
    while (_blue != b) {
        if (_blue < b)  { setBlue(_blue+1); }
        else            { setBlue(_blue-1); }

        delay(RGBLED_FADE_DELAY);
    }
}

// Set the red, green and blue values
void RGBLED::setRGB(int r, int g, int b) {
    _red = r;
    _green = g;
    _blue = b;

    analogWrite(_redPin, _red);
    analogWrite(_greenPin, _green);
    analogWrite(_bluePin, _blue);
}

// Set the red value
void RGBLED::setRed(int r) {
    _red = r;
    analogWrite(_redPin, _red);
}

// Set the green value
void RGBLED::setGreen(int g) {
    _green = g;
    analogWrite(_greenPin, _green);
}

// Set the blue value
void RGBLED::setBlue(int b) {
    _blue = b;
    analogWrite(_bluePin, _blue);
}

// Getter methods for rgb values
int RGBLED::red()   { return _red;   }
int RGBLED::green() { return _green; }
int RGBLED::blue()  { return _blue;  }

