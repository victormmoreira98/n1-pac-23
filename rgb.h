#ifndef _RGB_H
#define _RGB_H

#include <arduino.h>

// Portas led rgb
#define LED_RED 9
#define LED_GREEN 10
#define LED_BLUE 11

void rgbControl(int red, int green, int blue, long rumtime);

void rgbControl(int red, int green, int blue, long rumtime) {
  // Função para controle do led rgb
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);

  analogWrite(LED_RED, red);
  analogWrite(LED_GREEN, green);
  analogWrite(LED_BLUE, blue);
  delay(rumtime);
}

#endif
