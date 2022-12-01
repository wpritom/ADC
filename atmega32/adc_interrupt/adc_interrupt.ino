#include <avr/io.h>
#include <avr/interrupt.h>

#define  clear_bit(reg, bit) reg&=~(1<<bit)
#define  set_bit(reg, bit)   reg|=(1<<bit)


volatile uint16_t val[3], channels[3]={2,5,8};
volatile uint8_t channel_index=0;

void adc_channel_select(uint8_t channel){
  ADMUX &= 0xF0;
  ADMUX |= channel;
}


void adc_init(void){
  clear_bit(ADMUX, REFS1);
  set_bit(ADMUX, REFS0);
  clear_bit(ADMUX, ADLAR);
  adc_channel_select(channels[channel_index]);
  set_bit(ADCSRA, ADPS0);
  set_bit(ADCSRA, ADPS1);
  set_bit(ADCSRA, ADPS2);
  set_bit(ADCSRA, ADIE);
  set_bit(ADCSRA, ADEN);
  set_bit(SREG, 7); // or call sei()
  set_bit(ADCSRA, ADSC);
}

void setup() {
  adc_init();
  Serial.begin(9600);
}

void loop() {
  Serial.print("Ch0: ");
  Serial.print(val[0]);
  Serial.print(" Ch1: ");
  Serial.print(val[1]);
  Serial.print(" Ch2: ");
  Serial.println(val[2]);
  delay(500);
}

ISR(ADC_vect){
  val[channel_index]=ADCW;
  channel_index++;
  if(channel_index>3){
    channel_index=0;
  }
  adc_channel_select(channels[channel_index]);
  set_bit(ADCSRA, ADSC);
}
