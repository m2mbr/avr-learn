#include <avr/io.h>
#include <util/delay.h>
#include "util.h"

#define XTAL        16000000L
#define TIMER_CLOCK     2

int main(void){
    
    DDRD = _BV(PD5); // set OC1A pin as output, required for output 
    TCCR1A = _BV(COM1A0); // enable toggle OC1A output on compare 
    TCCR1B = _BV(CS10) | _BV(CS11)  | _BV(WGM12); // prescaler=64, clear timer/counter on compareA match                
    OCR1A = ((XTAL/64)/(2*TIMER_CLOCK)) - 1; // preset timer1 high/low byte

    for(;;){

    }

return 0;
}
