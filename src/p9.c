/**
    PRACTICA #9

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
// se desactive RE3 como Master Clear
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)


// Pins to use
#include <xc.h>
#include <stdbool.h>


#define RESET_BTN PORTEbits.RE3

#define PWM_PR_ON 255
#define PWM_PR_OFF 0

#define PWM_CC_ON 230
#define PWM_CC_OFF 0


void setup(){
    ANSEL = 0x00;  // Configura todos los pines analógicos como pines digitales
    ANSELH = 0x00;
    
    // Boton
    PORTE = 0x00;
    
    TRISEbits.TRISE3 = 1;  // Puerto E como entradas
    
    // Display
    TRISB = 0x00;
    
    // PWM
    TRISCbits.TRISC1 = 0;
    T2CON = 4;
    CCP2CON = 0x3F;
    PR2 = PWM_PR_OFF;
    CCPR2L = PWM_CC_OFF;
    
    
}

void countDown(uint8_t index, uint8_t mask, uint8_t* nums[10] ){
    while(index < 10){
        PORTB = nums[index] | mask;
        __delay_ms(500);
        index++;
    }
}

void beep(){
    PR2 = PWM_PR_ON;
    CCPR2L = PWM_CC_ON;
    __delay_ms(500);
    
    PR2 = PWM_PR_OFF;
    CCPR2L = PWM_CC_OFF;
    __delay_ms(500);
}

void main(void){
    
    setup();
    bool isIdle = false;
    bool isCompleted = false;
    uint8_t nums[10] = { 0x6F, 0x7F, 0x7, 0x7D, 0x6D, 0x66, 0x4F, 0x5B, 0x6, 0x3F};
    
    while(true){
        // Estado en espera
        if(isIdle){
            if(RESET_BTN == 0){
                isIdle = false;
                isCompleted = false;
            }
            continue;
        }
        
        // Estado al finalizar opperacion
        if(isCompleted){
            beep();
            beep();
            beep();
            isIdle = true;
            continue;
        }
        
        countDown(0, 0x80, nums);
        countDown(0, 0x00, nums);
        isCompleted = true;
    }
    
    return;
}
