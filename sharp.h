#ifndef _SHARP_H
#define _SHARP_H

#include <arduino.h>
#include <SharpIR.h>
#include "bluetooth.h"

// Portas dos sharps

#define SHARP_LEFT A3
#define SHARP_RIGHT A1

SharpIR sharpLeft(GP2Y0A21YK0F, SHARP_LEFT);
SharpIR sharpRight(GP2Y0A21YK0F, SHARP_RIGHT);

void readDistance(void);

void readDistance(void) {
  // Função para leitura da distância
  clearSerial();
  serial1.print("SHARP_LEFT: ");
  serial1.print(sharpLeft.getDistance());
  serial1.print("; ");
  serial1.print("SHARP_RIGHT: ");
  serial1.print(sharpRight.getDistance());
  serial1.println(";");
}

#endif
