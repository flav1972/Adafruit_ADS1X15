#include <Wire.h>
#include <Adafruit_ADS1015.h>

// Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
Adafruit_ADS1015 ads;     /* Use thi for the 12-bit version */

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Hello!");
  
  Serial.println("Getting differential reading from AIN0 (P) and AIN1 (N)");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 0.1875mV) step by 0.1875mV/ADS1115 3mV/ADS1015)");
  
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
}

void loop(void)
{
  int16_t results;
  
  /* Be sure to update this value based on the IC and the gain settings! */
  float multiplier = 0.1875F; /* +/- 6.144V gain */

  results = ads.readADC_Differential_0_1();  
    
  Serial.print("Differential: "); Serial.print(results); Serial.print("("); Serial.print(results * multiplier); Serial.println("mV)");

  delay(1000);
}
