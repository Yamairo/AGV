# AGV Control Systeem - HHS-Solutions

Dit project betreft de basisbesturing van een **Automated Guided Vehicle (AGV)**. De AGV is ontworpen om autonoom door een parcours te navigeren en specifieke taken uit te voeren met behulp van een stepper motor, sensoren en een interface voor de bediening van de modules.

## Doel van de Code
De code die hier beschreven wordt, stelt de AGV in staat om te navigeren door het sturen van commando's naar een **stepper motor**. De motor wordt aangestuurd via de **DIR**, **STEP** en **ENABLE** pinnen. De code zorgt ervoor dat de motor kan draaien, keren en pauzeren wanneer een noodstop wordt geactiveerd.

## Functionaliteiten
- **Motor Aansturing**: De code stuurt een stepper motor aan via de **STEP** en **DIR** pinnen.
- **Noodstop**: De code controleert de status van de **ENABLE**-pin, gekoppeld aan de noodstop, om te bepalen of de motoren ingeschakeld mogen worden.
- **Autonome Besturing**: De AGV kan autonoom een pad volgen, draaien en stoppen afhankelijk van de input van de sensoren en de noodstop.
- **Volgmodus**: Er is een optie om de AGV een andere AGV of een werknemer te laten volgen, waarbij de afstand tussen de AGV en het doel wordt bewaakt.

## Systeemvereisten
- **Microcontroller**: De code is geoptimaliseerd voor een **AVR microcontroller** (zoals ATmega2560).
- **Motor Driver**: De motoren worden aangestuurd via een stepper motor driver met de gebruikelijke **STEP**, **DIR** en **ENABLE** pinnen.
- **Sensoren**: De AGV maakt gebruik van verschillende sensoren om objecten te detecteren en het parcours te volgen.

## Besturingsinterface
De code maakt gebruik van de volgende pinnen voor motorbesturing:
- **DIR_PIN1 / DIR_PIN2**: Richting van de motoren.
- **STEP_PIN1 / STEP_PIN2**: Pulsaansturing voor motorstappen.
- **ENABLE_PIN**: Schakelt de motoren aan/uit afhankelijk van de noodstop.

