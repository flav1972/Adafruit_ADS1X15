#include <Wire.h>
#include <Adafruit_ADS1015.h>

// Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
Adafruit_ADS1015 ads;     /* Use thi for the 12-bit version */

void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Hello!");
  
  Serial.println("Single-ended readings from AIN0 with >3.0V comparator");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 0.1875mV) step by 0.1875mV/ADS1115 3mV/ADS1015)");
  Serial.println("Comparator Threshold: 1000 (3.000V)");
  
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //
  // for ADS1015 the lower 4 bits are always 0 so reading are by mentionned steps
  // for ADS1115 step is 1 bit
  //                                                                            ADS1015 steps
  //                                                                            -------------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 0.1875mV    by 3mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 0.125mV     by 2mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 0.0625mV    by 1mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.03125mV   by 0.5mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.015625mV  by 0.25mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.0078125mV by 0.125mV
  
  ads.begin();
  
  // Setup 3V comparator on channel 0
  ads.startComparator_SingleEnded(0, 1000 * 16);
}

void loop(void) 
{
  int16_t adc0;

  // Comparator will only de-assert after a read
  adc0 = ads.getLastConversionResults();
  Serial.print("AIN0: "); Serial.println(adc0);
  
  delay(100);
}