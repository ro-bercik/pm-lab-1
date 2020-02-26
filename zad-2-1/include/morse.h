#ifndef morse_h
#define morse_h

#include <Arduino.h>

// Sposób kodowania
#define M_KROPKA_T 200
#define M_KRESKA_T 3 * M_KROPKA_T
#define M_PAUZA_T 3 * M_KROPKA_T
#define M_SPACJA_T 7 * M_KROPKA_T

void morseSend(const char *message, uint8_t pin);

#endif