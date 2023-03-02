#pragma config FOSC = HSMP      // Oscillator Selection bits (HS oscillator (medium power 4-16 MHz))
#pragma config PLLCFG = ON      // 4X PLL Enable (Oscillator multiplied by 4)
#pragma config WDTEN = OFF      // Watchdog Timer Enable bits (Watch dog timer is always disabled. SWDTEN has no effect.)

volatile unsigned char TRISD     __at(0xf95);  
volatile unsigned char TRISC     __at(0xf94);

volatile unsigned char LATD      __at(0xf8c);
volatile unsigned char PORTC     __at(0xf82);

typedef struct{

    unsigned char b0 :1;
    unsigned char b1 :1;
    unsigned char b2 :1;
    unsigned char b3 :1;
    unsigned char b4 :1;
    unsigned char b5 :1;
    unsigned char b6 :1;
    unsigned char b7 :1;
    
}reg_t;

volatile reg_t my_latd __at(0xf8c);
volatile reg_t my_portc __at(0xf82);

void init(void){
    TRISD &= ~(1 << 2);     // nastaveni RD2 jako v�stup
    TRISC |= 0b1;           // nastaven� RC0 jako vstup
}

int main(void) {
    
    init();
    
    while(1){
        /*
        if (PORTC & 0b1){               //  kontrola stisknut� BTN1
            LATD ^= (1 << 2);           //  prevr�cen� LED1 pomoc� XOR
        }
        */
        
        /*
        if (PORTC & 0b1){                   //  kontrola stisknut� BTN1
            *((char*)0xf8c) ^= (1 << 2);    //  prevr�cen� LED1 pomoc� XOR
        }
        */
        
        if (my_portc.b0){       //  kontrola stisknut� BTN1
            my_latd.b2 ^= 1;    //  prevr�cen� LED1 pomoc� XOR
        }
        
        
        for(long i=1; i<100000; i++);   //  cekani...  
    }
    return 0;                           // nikdy se neprovede
}
