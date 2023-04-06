#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H

#include <arduino.h>
#include <SoftwareSerial.h>

// Portas bluetooth
#define BLUETOOTH_RX 12
#define BLUETOOTH_TX 8

SoftwareSerial serial1(BLUETOOTH_RX, BLUETOOTH_TX);

void clearSerial(void);

void clearSerial(void) {
  // Função para limpar a serial do controle
  for (int i = 0; i < 7; i++) {
    serial1.print(";");
  }
  serial1.println();
}

#endif
