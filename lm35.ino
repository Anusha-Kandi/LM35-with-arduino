#include <TimedBlink.h>   /* importing TimedBlink library for blinking */

TimedBlink monitor(LED_BUILTIN);    /*in built function for timedblink library*/
const int lm35_pin = A0;    /* initializing A0 pin as lm35_pin output */

void setup() {
  Serial.begin(9600);           /* beginning serial monitor for printing values */
  pinMode(LED_BUILTIN, OUTPUT);  /* making LED_BUILTIN pin as the output */
}

void loop() {
  monitor.blink();     /*call the function*/
  int temp_adc_val;     /*initializztion of required variables */
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);	/* Reading Temperature from lm35 sensor */
  temp_val = (temp_adc_val * 4.88);	/* Convert adc value to equivalent voltage value */
  temp_val = (temp_val/10);	/* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");/*printing the temperatuitre values on the serial monitor*/
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
  if(temp_val<30)
  {
    monitor.blink(250,30); /* led on for 250ms and off for 30ms*/ 
  }
  else
  {
    monitor.blink(500,30); /* led on for 500ms and off for 30ms*/
  }
}