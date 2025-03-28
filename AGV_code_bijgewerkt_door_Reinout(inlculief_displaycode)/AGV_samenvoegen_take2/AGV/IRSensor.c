#include "IRSensor.h"

void initSensoren(void) {
    IRRegister |= (1 << IRSensor1) | (1 << IRSensor2);
    IRPins |= (1 << IRSensor1) | (1 << IRSensor2);
}

int detecteerPakket(void) {
    if(!(IRPins & (1 << IRSensor1))) {
        return 1;
    } else {
        return 0;
    }
}

int telPakketten(void) {
   aantalPakketten++;
   while(detecteerPakket()) {
        _delay_ms(1);
   }
   return 1;
}
