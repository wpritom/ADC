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


void start_adc_conversion(void){
  // start conversion
  ADCSRA |= (1<<ADSC);
}


// adc value conversion 
// adc value to temperature
int temperature(long int adc)
{
  int dummy = 0;
  long int T = 0;

  if (adc > 994)
  {
    return -999;
  }

  else if (adc > 968)
  {
    T = (-4096 * adc + 3661824) >> 10;

    dummy = T / 10;

    return dummy;
  }

  else if (adc > 927)
  {
    T = (-2498 * adc + 2112936) >> 10;
    dummy = T / 10;
    return dummy;
  }

  else if (adc > 866)
  {
    T = (-1679 * adc + 1353022) >> 10;
    dummy = T / 10;
    return dummy;
  }

  else if (adc > 783)
  {
    T = (-1234 * adc + 967248) >> 10;

    dummy = T / 10;
    return dummy;
  }
  else if (adc > 680)
  {
    T = (-995 * adc + 779433) >> 10;
    dummy = T / 10;
    return dummy;
  }
  else if (adc > 567)
  {
    T = (-907 * adc + 719518) >> 10;

    dummy = T / 10;
    return dummy;
  }
  else if (adc > 455)
  {

    T = (-915 * adc + 724114) >> 10;

    dummy = T / 10;
    return dummy;
  }

  else if (adc > 354)
  {
    T = (-1014 * adc + 769520) >> 10;
    dummy = T / 10;
    return dummy;
  }

  else if (adc > 269)
  {
    T = (-1205 * adc + 837270) >> 10;

    dummy = T / 10;
    return dummy;
  }
  else if (adc > 202)
  {
    T = (-1529 * adc + 924656) >> 10;

    dummy = T / 10;
    return dummy;
  }

  else
  {
    return -999;
  }
}
