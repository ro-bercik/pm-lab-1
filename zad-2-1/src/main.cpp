#include <Arduino.h>
#include <morse.h>

#define LED_RED 10

void setup()
{
  pinMode(LED_RED, OUTPUT);
}



void loop()
{
  uint8_t i;
  for (i = 0; i < 3; i++) // Wysłanie znaku 'S'
  {
    digitalWrite(LED_RED, HIGH);
    delay(M_KROPKA_T);
    digitalWrite(LED_RED, LOW);
    delay(M_PAUZA_T);
  }
  // Wysłanie znaku '0'
  i = 0;
  do
  {
    digitalWrite(LED_RED, HIGH);
    delay(M_KRESKA_T);
    digitalWrite(LED_RED, LOW);
    delay(M_PAUZA_T);
    i++;
  } while (i < 3);
  // Wysłanie znaku 'S'
  i = 0;
  while (i < 3)
  {
    digitalWrite(LED_RED, HIGH);
    delay(M_KROPKA_T);
    digitalWrite(LED_RED, LOW);
    delay(M_PAUZA_T);
    i++;
  }
  delay(M_SPACJA_T);
}
