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
  // put your setup code here, to run once:
  // reference selection
  ADMUX &=~(1 << 7);
  ADMUX |= (1<<6);
  // channel selection
  select_channel(ADC1);

  // resolution selection (optional)
  // default
  // clock selection
  ADCSRA |= ((1<<0)|(1<<1)|(1<<2));
  
  // 5. enable ADC
  ADCSRA |= (1 << 7);
}

int dummy = 0;
long int T = 0;
long int adc = 0;
//long int mult = 0;
//long int temp = 0;

void loop() {
  ADCSRA |= (1<<6);

  while (ADCSRA & (1<<4)){
    
  }
  adc = ADCW;
//  Serial.println(ADCW);
//  Serial.print("ADC Val ");
//  Serial.println(adc);
  Serial.print("Temperature ");
  if (adc>1016) {
    Serial.println("ERROR");
  }
  
  else if (adc > 1010){
   T= (-20480*adc + 20398080)>>10; 
   dummy = T/10;
   Serial.println(dummy);
  }
  
   else if (adc > 1000){
    T= (-10240*adc + 10045440)>>10; 

   dummy = T/10;
   Serial.println(dummy);
  }
  
    else if (adc > 983){
   T= (-6024*adc + 5824752)>>10; 
   dummy = T/10;
   Serial.println(dummy);
  }

    else if (adc > 958){
   T= (-4096*adc + 3928064)>>10; 

   dummy = T/10;
   Serial.println(dummy);
  }
    else if (adc > 920){
   T= (-2695*adc + 2584252)>>10; 
   dummy = T/10;
   Serial.println(dummy);
  }
    else if (adc > 869){
   T= (-2008*adc + 1951623)>>10; 

   dummy = T/10;
   Serial.println(dummy);
  }
    else if (adc > 802){
      
   T= ((-1529*adc) + 1534471)>>10;

   dummy = T/10;
   Serial.println(dummy);
  }

   else if (adc > 723){
   T= (-1297*adc + 1348050)>>10; 
   dummy = T/10;
   Serial.println(dummy);
  }

     else if (adc > 633){
   T= (-1138*adc + 1233351)>>10;

   dummy = T/10;
   Serial.println(dummy);
  }
     else if (adc > 540){
   T= (-1102*adc + 1210081)>>10;

   dummy = T/10;
   Serial.println(dummy);
  }

  else{
    Serial.println("ERROR");
   }
  
  delay(400);

}
