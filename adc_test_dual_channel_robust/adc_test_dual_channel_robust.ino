#include <avr/io.h>
#include <util/delay.h>
#include "adcc.h"

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
  select_channel(channels[currently_active_channel_index]);
  start_adc_conversion();
  wait_for_coversion_is_completed();
  // read and store ADC value  
  adc = ADCW;
  temp = temperature(adc);
  
  // printing result
  Serial.print("Temperature at ");
  Serial.print(channels[currently_active_channel_index]);
  Serial.print(" : ");
  if(temp == -999){
    Serial.println("ERROR");
  }
  else{
    Serial.println(temp);
  }
  delay(1000);
  currently_active_channel_index++;
}
