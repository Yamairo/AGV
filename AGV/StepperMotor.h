#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H


/*
Aansluitingen Motor 1:
    VCC       →  5V  (Logic power)
    GND       →  GND (Ground)
    VMOT      →  12V of 24V (Externe voeding voor de motor)
    GND (VMOT) →  GND (Externe voeding ground)
    STEP      →  PA0 (Motor stappen aansturen)
    DIR       →  PA1 (Richting instellen)
    ENABLE    →  PA2 (Optioneel, motor in- of uitschakelen)
    MS1       →  HIGH of LOW (Microstepping mode instellen)
    MS2       →  HIGH of LOW
    MS3       →  HIGH of LOW
    MOTOR A1  →  Steppermotor spoel A (1)
    MOTOR A2  →  Steppermotor spoel A (2)
    MOTOR B1  →  Steppermotor spoel B (1)
    MOTOR B2  →  Steppermotor spoel B (2)
*/

/*
Aansluitingen Motor 2:
    VCC       →  5V  (Logic power)
    GND       →  GND (Ground)
    VMOT      →  12V of 24V (Externe voeding voor de motor)
    GND (VMOT) →  GND (Externe voeding ground)
    STEP      →  PB0 (Motor stappen aansturen)
    DIR       →  PB1 (Richting instellen)
    ENABLE    →  PB2 (Optioneel, motor in- of uitschakelen)
    MS1       →  HIGH of LOW (Microstepping mode instellen)
    MS2       →  HIGH of LOW
    MS3       →  HIGH of LOW
    MOTOR A1  →  Steppermotor spoel A (1)
    MOTOR A2  →  Steppermotor spoel A (2)
    MOTOR B1  →  Steppermotor spoel B (1)
    MOTOR B2  →  Steppermotor spoel B (2)
*/

#include <avr/io.h>
#include <util/delay.h>

#define MOTORREGISTER DDRA
#define MOTORREGISTER2 DDRB

#define VOORUIT_PIN1 PA0
#define ACHTERUIT_PIN1 PA1
#define MICROSTEP_1 PA3


#define VOORUIT_PIN2 PB0
#define ACHTERUIT_PIN2 PB1
#define MICROSTEP_2 PB3

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
