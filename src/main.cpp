#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <stdlib.h>

#define LED 2
#define pause(x) vTaskDelay(x/portTICK_PERIOD_MS)


void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
  // put your main code here, to run repeatedly:
}
