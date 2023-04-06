#ifndef _SUMO_H
#define _SUMO_H

#include <arduino.h>
#include "sharp.h"
#include "motor.h"
#include "rgb.h"

#define DISTANCE 30
#define COLORFLOOR 50
#define CURRECT_TIME 300
#define CURRECT_TIME2 200
#define MAXIMUM_SPEED 255
#define SEARCH_SPEED 55
#define OPTION_TIME 5000
#define TIME_ATTACK 500

void sumo(void);
boolean testDistance(void);
boolean testColorFloor(void);

boolean flag = true;
int option = 0;

long timeAttackStart, timeAttackNow;

void sumo(void) {
  rgbControl(0, 0, 0, 0);
  motorOption('0', 0, 0);

  for (int i = 1; i <= 5; i++) {
    rgbControl(0, 255, 255, 300);
    rgbControl(0, 0, 0, 300);
  }

  //rgbControl(255, 255, 255, 2000);
  
  long timeStart = millis();
  //timeAttackStart = millis();
  while (true) {
    long timeNow = millis();
    
    /*if ((timeNow - timeStart) > OPTION_TIME) {
      option++;
      timeStart = millis();
    }*/

    if (testColorFloor()) {
      if (testDistance()) {
        rgbControl(0, 255, 0, 0);
        motorOption('8', SEARCH_SPEED, SEARCH_SPEED);
        /*switch (option) {
          case 1:
            rgbControl(0, 255, 0, 0);
            motorOption('8', MAXIMUM_SPEED / 2, MAXIMUM_SPEED / 2);
            break;
           case 2:
            rgbControl(0, 255, 0, 0);
            motorOption('8', MAXIMUM_SPEED / 2, MAXIMUM_SPEED);
            break;
          case 3:
            rgbControl(0, 255, 0, 0);
            motorOption('8', MAXIMUM_SPEED, MAXIMUM_SPEED / 2);
            break;
          case 4:
            rgbControl(0, 255, 0, 0);
            motorOption('4', MAXIMUM_SPEED / 2, MAXIMUM_SPEED / 2);
            break;
          case 5:
            rgbControl(0, 255, 0, 0);
            motorOption('6', MAXIMUM_SPEED / 2, MAXIMUM_SPEED / 2);
            break;
          default:
            rgbControl(0, 255, 0, 0);
            motorOption('8', MAXIMUM_SPEED / 2, MAXIMUM_SPEED / 2);
            option = 0;
            break;
        }*/
      }
    }
  }
}
boolean testDistance(void) {
  int sharp_left = sharpLeft.getDistance();
  int sharp_right = sharpRight.getDistance();

  if (sharp_left < DISTANCE || sharp_right < DISTANCE) {
    // frente 100%
    if (sharp_left < DISTANCE && sharp_right < DISTANCE) {
      rgbControl(255, 255, 255, 0);
      motorOption('8', MAXIMUM_SPEED, MAXIMUM_SPEED);
    } else if (sharp_left < DISTANCE) {
      rgbControl(255, 255, 0, 0);
      motorOption('8', MAXIMUM_SPEED, MAXIMUM_SPEED/5);
    } else {
      rgbControl(255, 0, 255, 0);
      motorOption('8', MAXIMUM_SPEED/5, MAXIMUM_SPEED);
    }
    return false;
  }
  timeAttackStart = millis();
  return true;
}

boolean testColorFloor(void) {
  int qtr_left = analogRead(QTR_LEFT);
  int qtr_right = analogRead(QTR_RIGHT);
  int qtr_back = analogRead(QTR_BACK);

  if (qtr_left < COLORFLOOR || qtr_right < COLORFLOOR || qtr_back  < COLORFLOOR) {
    if (qtr_left < COLORFLOOR && qtr_right < COLORFLOOR) {
      rgbControl(255, 0, 0, 0);
      motorOption('2', MAXIMUM_SPEED, MAXIMUM_SPEED);
      delay(CURRECT_TIME);
     if (flag) {
        flag = false;
        motorOption('4', MAXIMUM_SPEED, MAXIMUM_SPEED);
        delay(CURRECT_TIME2);
      } else {
        flag = true;
        motorOption('6', MAXIMUM_SPEED, MAXIMUM_SPEED);
        delay(CURRECT_TIME2);
      } 
    } else if (qtr_left < COLORFLOOR) {
      rgbControl(255, 0, 0, 0);
      motorOption('2', MAXIMUM_SPEED, MAXIMUM_SPEED);
      delay(CURRECT_TIME);
      motorOption('4', MAXIMUM_SPEED, MAXIMUM_SPEED);
      delay(CURRECT_TIME2);
      flag = true;
    } else if (qtr_right < COLORFLOOR) {
      rgbControl(255, 0, 0, 0);
      motorOption('2', MAXIMUM_SPEED, MAXIMUM_SPEED);
      delay(CURRECT_TIME);
      motorOption('6', MAXIMUM_SPEED, MAXIMUM_SPEED);
      delay(CURRECT_TIME2);
      flag = false;
    } /*else {
      rgbControl(255, 0, 0, 0);
      motorOption('8', MAXIMUM_SPEED, MAXIMUM_SPEED);
      delay(CURRECT_TIME2);
    }*/
    return false;
  }
  return true;
}
#endif
