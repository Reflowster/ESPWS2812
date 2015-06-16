#include "ESPWS2812.h"

ESPWS2812::ESPWS2812(uint8_t pin, uint16_t len, bool invert) {
    invertData = invert;
    ledPin = pin;
    stripLength = len;
}

void ESPWS2812::begin() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, invertData ? LOW : HIGH);
}

void ESPWS2812::SEND_WS_0() {
        digitalWrite(ledPin,0);
        digitalWrite(ledPin,1);
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
}

void ESPWS2812::SEND_WS_1() {
        digitalWrite(ledPin,0);
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        __asm__("nop\n\t");
        digitalWrite(ledPin,1);
}


void ESPWS2812::sendLeds(uint8_t * buf) {
  //TODO see if we can remove this.. it seems like it should be unnecessary.. but I was getting flickering LEDs without it
  delayMicroseconds(50);
  noInterrupts();
  uint16_t i;
  uint8_t b;
  uint16_t len = stripLength*3;
  if (invertData) {
      digitalWrite(ledPin,1);
      for( i = 0; i < len; i++ ) {
          b = buf[i];
          if( b & 0x80 ) ESPWS2812::SEND_WS_1(); else ESPWS2812::SEND_WS_0();
          if( b & 0x40 ) ESPWS2812::SEND_WS_1(); else ESPWS2812::SEND_WS_0();
          if( b & 0x20 ) ESPWS2812::SEND_WS_1(); else ESPWS2812::SEND_WS_0();
          if( b & 0x10 ) ESPWS2812::SEND_WS_1(); else ESPWS2812::SEND_WS_0();
          if( b & 0x08 ) ESPWS2812::SEND_WS_1(); else ESPWS2812::SEND_WS_0();
          if( b & 0x04 ) ESPWS2812::SEND_WS_1(); else ESPWS2812::SEND_WS_0();
          if( b & 0x02 ) ESPWS2812::SEND_WS_1(); else ESPWS2812::SEND_WS_0();
          if( b & 0x01 ) ESPWS2812::SEND_WS_1(); else ESPWS2812::SEND_WS_0();
      }
  } else {
      digitalWrite(ledPin,0);
      for( i = 0; i < len; i++ ) {
          b = buf[i];
          if( b & 0x80 ) ESPWS2812::SEND_WS_0(); else ESPWS2812::SEND_WS_1();
          if( b & 0x40 ) ESPWS2812::SEND_WS_0(); else ESPWS2812::SEND_WS_1();
          if( b & 0x20 ) ESPWS2812::SEND_WS_0(); else ESPWS2812::SEND_WS_1();
          if( b & 0x10 ) ESPWS2812::SEND_WS_0(); else ESPWS2812::SEND_WS_1();
          if( b & 0x08 ) ESPWS2812::SEND_WS_0(); else ESPWS2812::SEND_WS_1();
          if( b & 0x04 ) ESPWS2812::SEND_WS_0(); else ESPWS2812::SEND_WS_1();
          if( b & 0x02 ) ESPWS2812::SEND_WS_0(); else ESPWS2812::SEND_WS_1();
          if( b & 0x01 ) ESPWS2812::SEND_WS_0(); else ESPWS2812::SEND_WS_1();
      }
  }
  interrupts();
}
