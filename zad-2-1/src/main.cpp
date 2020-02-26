#include <Arduino.h>

#define LED_RED 10

#define LED_T 20
#define LED_STEP_T 1
#define LED_SPEED_T 100

void setup()
{
  pinMode(LED_RED, OUTPUT);
}

uint16_t ledOn = 0, ledOff = LED_T - 0, i = 0;
uint8_t dir = 0;
float sinVal;

void loop()
{
  digitalWrite(LED_RED, HIGH);
  delay(ledOn);
  digitalWrite(LED_RED, LOW);
  delay(ledOff);

  if ((i % (LED_SPEED_T / LED_T)) == 0)
  {
    if (dir == 0)
    {
      ledOn += LED_STEP_T;
      ledOff -= LED_STEP_T;
      if (ledOn >= LED_T)
      {
        dir = 1;
      }
    }
    else
    {
      ledOn -= LED_STEP_T;
      ledOff += LED_STEP_T;
      if (ledOn == 0)
      {
        dir = 0;
      }
    }

    // sinVal = (sin((i % 180) * (3.1412 / 180)));
    // ledOn = int(sinVal * LED_T);
    // ledOff = LED_T - ledOn;
  }
  i++;
}
