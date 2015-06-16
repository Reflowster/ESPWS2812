#ifndef ESPWS2812_h
#define ESPWS2812_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "SoftwareSPI.h"

class ESPWS2812 {
public:
    ESPWS2812(uint8_t pin, uint16_t stripLength, bool invert);
    void begin();
    void SEND_WS_0();
    void SEND_WS_1();
    void sendLeds(uint8_t * buf);

private:
    uint16_t stripLength;
    uint8_t ledPin;
    bool invertData;
};

#endif


