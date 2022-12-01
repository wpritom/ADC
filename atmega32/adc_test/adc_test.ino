#include <avr/io.h>
#include <util/delay.h>

#define ADC0     0x00
#define ADC1     0x01
#define ADC2     0x02
#define ADC_TEMP 0x08
#define ADC_VBG  0x0E
#define ADC_GND  0x0F


void select_channel(uint8_t ch){
  ADMUX &= 0xF0;
  ADMUX |= ch;
}

void setup() {
  Serial.begin(9600);
  // 1. reference selection
  ADMUX &=~(1 << 7);
  ADMUX |= (1 << 6);

  // 2. channel selection
  // ADC8 (1000)
  //select_channel(ADC_TEMP);
  // GND (1111)
  //select_channel(ADC_GND);

    // VBG (1110)
  select_channel(ADC2); // 1.1V 
  
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

//  dummy = (ADCW/1024.0)*5;
//
//
//  
//  Serial.println(dummy);

  Serial.println(ADCW);
  

  delay(400);

}
