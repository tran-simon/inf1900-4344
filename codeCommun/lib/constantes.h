#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <avr/io.h>

#define DDR_PWM DDRD

#define DDR_MOTEUR DDRD

#define TIMER_COUNT 25

#define PORT_MOTEUR PORTD
#define PIN_MOTEUR_GAUCHE 6
#define PIN_MOTEUR_DROITE 7

#define DDR_DEL DDRA
#define PORT_DEL PORTA
#define DDR_BTN_INTERRUPT DDRD

#define PORT_SPEAKER PORTB
#define DDR_SPEAKER DDRB



#define MODE_SORTIE 0xff
#define MODE_ENTREE 0x00




enum Couleur {Rouge, Vert, Ambree, Eteint};

#endif
