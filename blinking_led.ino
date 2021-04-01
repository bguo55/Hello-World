#include <avr/io.h>
#include <util/delay.h>

//Add Names Here:
//Brandon Guo
//Noah Conard
//Noel Moyer

/* KEY: 
 * '_' is the port letter
 * '#' is the number in the port
 *  
 * "DDR_" - Set to '0' for input and '1' for output
 * 
 * "PIN_" - (INPUT) Gives all values of the pins in the port. Can read from this
 * "PORT_" - (OUTPUT) Gives all values of the pins in the port. Can write to this
 * 
 * "P_#" - Gives the offset value of the pin # in the port letter
 */
void setup() {
    //Set PIN "PD6" (pin 12) as input
  DDRD &= ~(1 << PD6);
  
  //Set PIN "PD7" (pin 13) as input
  DDRD &= ~(1 << PD7);

  //Set PIN "PB0" (pin 14) as output
  DDRB = 0x01;
}

void loop() {
  //Instantaneous LED response
  while((PIND & (1<<PD6))){
    PORTB |= (1<<PB0);
  }
  
  //Turn off LED
  PORTB &= ~(1<<PB0);
  
  //Periodically blink LED while input is HIGH
  while((PIND & (1<<PD7))){
    PORTB |= (1<<PB0);
    _delay_ms(500);
    PORTB &= ~(1<<PB0);
    _delay_ms(500);
  }
}
