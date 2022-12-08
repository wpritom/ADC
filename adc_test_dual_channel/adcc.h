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
