
#include <avr/io.h>
#include <util/delay.h>

void setup() {
  Serial.begin(9600);
  // 1. reference selection
  ADMUX &=~(1 << 7);
  ADMUX |= (1 << 6);

  // 2. channel selection
  // ADC8 (1000)
//  ADMUX |= (1 << 3);
//  ADMUX &=~ (1 << 2);
//  ADMUX &=~ (1 << 1);
//  ADMUX &=~ (1 << 0);
  // GND (1111)
//  ADMUX |= (1 << 3);
//  ADMUX |= (1 << 2);
//  ADMUX |= (1 << 1);
//  ADMUX |= (1 << 0);

    // VBG (1110)
  ADMUX |= (1 << 3);
  ADMUX |= (1 << 2);
  ADMUX |= (1 << 1);
  ADMUX &=~ (1 << 0);
  
  // 3. resolution selection (optional)
  // default
  // 4. clock selection
  ADCSRA |= ((1<<0)|(1<<1)|(1<<2));

  // clearing interrupt bits
  ADCSRA &= ~ ((1 << 5)|(1 << 4)|(1 << 3));
  
  // 5. enable ADC
  ADCSRA |= (1 << 7);

  

}

float dummy = 0.0;

void loop() {
  // 6. conversion start
  ADCSRA |= (1<< 6);

  while (ADCSRA & (1<<4)){
    // pass while conversion is in progress
  }
  ADCSRA|=(1<<4);

  dummy = (ADCW/1024.0)*5;

  Serial.println(dummy);

  delay(400);

}