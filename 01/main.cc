#include <avr/io.h>
#include <util/delay.h>
#include "util.h"


int main(void){
    unsigned char i,j;
    unsigned int k;

    DDRB = 0xFF;
    PORTB = 0x00;

    for(;;){

        for(j=0; j<100; j++){
            for(k=0; k<255; k++){
                for(i=0; i<100; i++)
                {
                    if(i < j){
                        PORTB |= 1 << PCINT5;
                    }else{
                        PORTB &= ~(1 << PCINT5);
                    }
                }
            }            
        }

        for(j=0;j<100;j++){
            for(k=0;k<255;k++){
                for(i=100;i>0;i--){
                    if(i>j){
                        PORTB |= 1 << PCINT5;
                    }
                    else{
                        PORTB &= ~(1 << PCINT5);
                    }
                }
            }
        }

    //tbi(PORTB, PCINT5);
    //_delay_ms(500);
    //tbi(PORTB, PCINT5);
    //_delay_ms(20);
    }

return 0;
}
