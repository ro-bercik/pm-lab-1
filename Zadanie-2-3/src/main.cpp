#include <Arduino.h>

uint8_t ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
uint8_t ledDelay = 65;
uint8_t direction = 1;
uint8_t currentLED = 0;
unsigned long changeTime;

void changeLED();

void setup() {
  // for (int i = 0; i < 10; i++)  {
  //   pinMode(ledPin[i], OUTPUT);
  // }
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // if ((millis() - changeTime) > ledDelay) {
  //   changeLED();
  //   changeTime = millis();
  // }
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
}

void changeLED() {
  for (int x = 0; x < 10; x++) {          // Wyłączenie wszystkich diod
    digitalWrite(ledPin[x], LOW);
  }  
  digitalWrite(ledPin[currentLED], HIGH); // Włączenie kolejnej diody LED
  currentLED += direction;                // Wskazanie na kolejną diode LED
  if (currentLED == 9) {                  // Zmiana kierunku
    direction = -1;
  }
  if (currentLED == 0) {
    direction = 1;
  }
}

