#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H


/*
Aansluitingen Motor 1:
    STEP      →  PA0 (Motor stappen aansturen)
    DIR       →  PA1 (Richting instellen)
*/

/*
Aansluitingen Motor 2:
    STEP      →  PB0 (Motor stappen aansturen)
    DIR       →  PB1 (Richting instellen)
*/

#include <avr/io.h>
#include <util/delay.h>

#define MOTORREGISTER DDRA
#define MOTORREGISTER2 DDRB
#define MOTORPORT1 PORTA
#define MOTORPORT2 PORTB

#define DIR_PIN1 PA1
#define STEP_PIN1 PA0


#define DIR_PIN2 PB1
#define STEP_PIN2 PB0

static int delay = 1;

void initMotor(void);

// Functie om de AGV vooruit te laten rijden
void rijVooruit(void);

// Functie om de AGV achteruit te laten rijden
void rijAchteruit(void);

// Functie om de AGV naar links te laten draaien
void draaiLinks(void);

// Functie om de AGV naar rechts te laten draaien
void draaiRechts(void);

// Functie om de AGV te laten stoppen
void stopAGV(void);


#endif // STEPPERMOTOR_H
