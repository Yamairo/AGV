#include "StepperMotor.h"

void initMotor(void) {
    // Zet de richting pins als output
    MOTORREGISTER |= (1 << DIR_PIN1);
    MOTORREGISTER2 |= (1 << DIR_PIN2);

    // Zet de motor pins als output
    MOTORREGISTER |= (1 << STEP_PIN1);
    MOTORREGISTER2 |= (1 << STEP_PIN2);
}

void rijVooruit(void) {
    MOTORPORT1 |= (1 << DIR_PIN1);
    MOTORPORT2 |= (1 << DIR_PIN2);

    for(int i = 0; i < 400; i++) {
        _delay_ms(delay);
        MOTORPORT1 |= (1 << STEP_PIN1);
        MOTORPORT2 |= (1 << STEP_PIN2);
        _delay_ms(delay);
        MOTORPORT1 &= ~(1 << STEP_PIN1);
        MOTORPORT2 &= ~(1 << STEP_PIN2);
        displayAantalPakketten();
    }
}

void rijAchteruit(void) {
    MOTORPORT1 &= ~(1 << DIR_PIN1);
    MOTORPORT2 &= ~(1 << DIR_PIN2);

    for(int i = 0; i < 400; i++) {
        _delay_ms(delay);
        MOTORPORT1 |= (1 << STEP_PIN1);
        MOTORPORT2 |= (1 << STEP_PIN2);
        _delay_ms(delay);
        MOTORPORT1 &= ~(1 << STEP_PIN1);
        MOTORPORT2 &= ~(1 << STEP_PIN2);
        displayAantalPakketten();
    }
}

void draaiLinks(void) {
    MOTORPORT1 &= ~(1 << DIR_PIN1);
    MOTORPORT2 |= (1 << DIR_PIN2);

    for(int i = 0; i < 200; i++) {
        _delay_ms(1);
        MOTORPORT1 |= (1 << STEP_PIN1);
        MOTORPORT2 |= (1 << STEP_PIN2);
        _delay_ms(1);
        MOTORPORT1 &= ~(1 << STEP_PIN1);
        MOTORPORT2 &= ~(1 << STEP_PIN2);
        displayAantalPakketten();
    }
}

void draaiRechts(void) {
    MOTORPORT1 |= (1 << DIR_PIN1);
    MOTORPORT2 &= ~(1 << DIR_PIN2);

    for(int i = 0; i < 200; i++) {
        _delay_ms(1);
        MOTORPORT1 |= (1 << STEP_PIN1);
        MOTORPORT2 |= (1 << STEP_PIN2);
        _delay_ms(1);
        MOTORPORT1 &= ~(1 << STEP_PIN1);
        MOTORPORT2 &= ~(1 << STEP_PIN2);
        displayAantalPakketten();
    }
}

void stopAGV() {
    MOTORPORT1 &= ~(1 << STEP_PIN1);
    MOTORPORT2 &= ~(1 << STEP_PIN2);
}
