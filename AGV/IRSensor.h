#ifndef IRSENSOR_H
#define IRSENSOR_H


#include <avr/io.h>
#include <util/delay.h>

#define IRRegister DDRF
#define IRPins PINF
#define IRSensor1 PF0
#define IRSensor2 PF1

int aantalPakketten = 0;

void initSensoren(void);
int detecteerPakket(void);
int telPakketten(void);

#endif //IRSENSOR_H
