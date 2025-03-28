#ifndef IRSENSOR_H
#define IRSENSOR_H


#include <avr/io.h>
#include <util/delay.h>

#define IRRegister DDRK
#define IRPins PINK
#define IRSensor1 PK0
#define IRSensor2 PK1

static int aantalPakketten = 0;

void initSensoren(void);
int detecteerPakket(void);
int telPakketten(void);

#endif //IRSENSOR_H
