#include <avr/io.h>
#include <util/delay.h>
#include "adcc.h"


void setup() {
  Serial.begin(9600);
  adc_init();
  select_channel(1);
}


//long int adc = 0;
long int temp = 0;
uint8_t adcl_raw;
uint16_t raw_result;

void loop() {
  start_adc_conversion();
  wait_for_coversion_is_completed();
  
  adcl_raw = ADCL;
  raw_result = ADCH <<8 | adcl_raw;
  
  temp = temperature(raw_result);
  
  // printing result
  Serial.print("raw resut ");
  Serial.println(raw_result);
  Serial.print(" Temperature ");
  Serial.println(temp);
  
  delay(1000);

}
