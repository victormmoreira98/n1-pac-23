#ifndef _QTR_H
#define _QTR_H

#include <arduino.h>
#include "bluetooth.h"

// Portas sensor QTR
#define QTR_LEFT A5
#define QTR_RIGHT A0
#define QTR_BACK A4

void readFloor(void);

void readFloor(void) {
  // Função para leitura do chão
  clearSerial();
  serial1.print("QTR_LEFT: ");
  serial1.print(analogRead(QTR_LEFT));
  serial1.print("; ");
  serial1.print("QTR_RIGHT: ");
  serial1.print(analogRead(QTR_RIGHT));
  serial1.print("; ");
  serial1.print("QTR_BACK: ");
  serial1.print(analogRead(QTR_BACK));
  serial1.println(";");
}

#endif
