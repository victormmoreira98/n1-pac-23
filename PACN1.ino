#include "bluetooth.h"
#include "control.h"
#include "rgb.h"

void setup() {
  // put your setup code here, to run once:
  serial1.begin(9600);
  rgbControl(255, 0, 0, 1000);
  rgbControl(0, 255, 0, 1000);
  rgbControl(0, 0, 255, 1000);
}

void loop() {
  sumo();
  if (serial1.available()) {
       rgbControl(0, 0, 255, 1);
       char var = serial1.read();
       advancedOption(var);
  } else {
       rgbControl(0, 255, 0, 1);
  } 
}
