#include <xc.h>

// Definiciones del PIC16F887
#define _XTAL_FREQ 4000000  // Frecuencia de cristal del PIC (4MHz)

// Configuración del PIC
#pragma config FOSC = INTRC_NOCLKOUT  // Oscilador HS
#pragma config WDTE = OFF             // Watchdog Timer deshabilitado
#pragma config PWRTE = OFF            // Power-up Timer deshabilitado
#pragma config BOREN = OFF            // Brown-out Reset deshabilitado
#pragma config LVP = OFF              // Low-Voltage Programming deshabilitado
#pragma config CPD = OFF              // Data Code Protection deshabilitado
#pragma config WRT = OFF              // Write Protection deshabilitado
#pragma config CP = OFF               // Code Protection deshabilitado

// Función de inicialización
void init() {
    ANSEL = 0x00;  // Configura todos los pines analógicos como pines digitales
    ANSELH = 0x00;
    TRISA = 0xFF;  // Puerto A como entradas
    TRISB = 0x00;  // Puerto B como salidas
}

unsigned char multiplyTwoNumbers(unsigned char a, unsigned char b) {
    unsigned char step = 1;
    unsigned char result = 0;
    while (b > 0x00) {
        if (b & 0x01) {
            result += a;
        }
        b = (unsigned char)b >> step;  // Esto es como X / 2
        a = (unsigned char)a << step;  // Esto es como X * 2
    }
    return result;
}

// Función principal
void main(void) {
    init();  // Inicializar el PIC

    // Bucle infinito
    while (1) {
        PORTB = multiplyTwoNumbers(PORTA ^ 0xFF, 0x03);
        __delay_ms(10);
    }

    return;
}
