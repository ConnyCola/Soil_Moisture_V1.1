#include "global.h"
#include "data_proc.h"
//---------------------------------------DATA CONVERSIONS--------------------------

//___TEMPERATURE VALUE CONVERSION___                                /* S_TEMPCON */
unsigned char conv_temp(unsigned int adc_value)
  {
    unsigned char temperature = (unsigned char)(adc_value * 1.70620438 - 1113.062693);
    return temperature;
  }
                                                                    /* E_TEMPCON */
//___SUPPLY VOLTAGE VALUE CONVERSION___
float conv_vcc(unsigned int adc_value)
  {
    float vcc = adc_value * 0.00366211;  //convert to absolute voltage
    return vcc;
  }

//___RETURN MOISTURE VALUE IN % value___
unsigned char conv_mois(unsigned int v)
  {
    unsigned char m = (char)(100 - (0.09765625 * (v)));
    return m;
  }

//___% TO DAC (0-255)___
unsigned char conv_mois_dac(unsigned char moisture_percent)
  {
    unsigned char converted_moisture = (char)(moisture_percent * 2.55);
    return converted_moisture;
  }

//___Volts to DAC 255___
unsigned char conv_dac(float voltage)
  {
    unsigned char spi_dac = (char)(voltage * 62.5);
    return spi_dac;
  }

//___RAW to %___
int calc_mois_perc(unsigned int raw){
	int back = 0;
	back = 10*(10*(*ptr_vref_l - raw)/(*ptr_vref_l - *ptr_vref_h));
	return back;
}
