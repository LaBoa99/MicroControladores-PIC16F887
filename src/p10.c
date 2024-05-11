/**
    PRACTICA #10

    EQUIPO:
    CLAUDIO GAEL RODRIGUEZ VEGA #221943339
    ANGEL DE JESUS DOMINGO CABRERA #218483572
    JOSE EMANUEL GARIBALDO PADILLA #218579952
*/

// Definiciones del PIC16F887
#define _XTAL_FREQ 4000000  // Frecuencia de cristal del PIC (4MHz)

// Configuración del PIC
#pragma config FOSC = HS  // Oscilador HS
#pragma config WDTE = OFF             // Watchdog Timer deshabilitado
#pragma config PWRTE = OFF            // Power-up Timer deshabilitado
#pragma config BOREN = OFF            // Brown-out Reset deshabilitado
#pragma config LVP = OFF              // Low-Voltage Programming deshabilitado
#pragma config CPD = OFF              // Data Code Protection deshabilitado
#pragma config WRT = OFF              // Write Protection deshabilitado
#pragma config CP = OFF               // Code Protection deshabilitado


// Pins to use
#include <xc.h>


#define IN1 PORTDbits.RD0
#define IN2 PORTDbits.RD1
#define IN3 PORTDbits.RD2
#define IN4 PORTDbits.RD3

#define ROUND_STEPS 4095

void setup(){
    ANSEL = 0x00;  // Configura todos los pines analógicos como pines digitales
    ANSELH = 0x00;
    
    TRISA = 0x0F;
    TRISD = 0x00;
    
    PORTD = 0x00;
    PORTA = 0x00;
}

void main(void){
    
    setup();
    uint8_t stepPath[8] = {
        0x08,
        0x0C, 
        0x04,
        0x06,
        0x02,
        0x03,
        0x01,
        0x09,
    };
    
    uint8_t pathIndex = 0;
    uint8_t lastRounds = 0;
    uint16_t steps = 0;
    
    while(true){
        PORTD = 0x00;
        uint8_t rounds = (PORTA ^ 0x0F) & 0x03;
        if(rounds == lastRounds) continue;
        
        steps = ROUND_STEPS * rounds;
        while(steps > 0){
            PORTD = stepPath[pathIndex % 8];
            pathIndex++;
            steps--;
            __delay_ms(1);
        }
        steps = 0;
        pathIndex = 0;
        lastRounds = rounds;
    }
    
    return;
}
