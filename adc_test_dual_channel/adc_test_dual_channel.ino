#include <avr/io.h>
#include <util/delay.h>
#include "adcc.h"


#define ADC0     0x00
#define ADC1     0x01
#define ADC2     0x02
#define ADC_TEMP 0x08
#define ADC_VBG  0x0E
#define ADC_GND  0x0F


void adc_init(void){
  // reference selection
  ADMUX  &=~(1<<7);
  ADMUX  |= (1<<6);
  // clock selection
  ADCSRA |= ((1<<0)|(1<<1)|(1<<2));
  // enable ADC
  ADCSRA |= (1 << 7);
}

void select_channel(uint8_t ch){
  ADMUX &= 0xF0;
  ADMUX |= ch;
}

void wait_for_coversion_is_completed(void){
  while((ADCSRA & (1<<4))==0){
    
  }
}

long int adc = 0;
int temp = 0;
const int adc_channel_number = 2; // 0 and 1
int channels[adc_channel_number] = {1,2};
int currently_active_channel_index=0;

void setup() {
  Serial.begin(9600);
  adc_init();
  select_channel(1);
}

void loop() {
  if(currently_active_channel_index>adc_channel_number-1){
    currently_active_channel_index = 0;
  }
  // channel select
  select_channel(channels[currently_active_channel_index]);
  // start conversion
  ADCSRA |= (1<<ADSC);
  wait_for_coversion_is_completed();
  // read and store ADC value  
  adc = ADCW;
  Serial.print("Temperature at ");
  Serial.print(channels[currently_active_channel_index]);
  Serial.print(" : ");
  temp = temperature(adc);

  if(temp == -999){
    Serial.println("ERROR");
  }
  else{
    Serial.println(temp);
  }
  
  delay(1000);
  currently_active_channel_index++;
}
