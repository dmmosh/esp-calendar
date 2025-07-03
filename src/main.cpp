#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <stdlib.h>
#include <TFT_eSPI.h>  // Include the graphics library (after User_Setup.h is configured)
#define BACKLIGHT 18


TFT_eSPI tft = TFT_eSPI();  // Create screen object

void setup() {
  pinMode(BACKLIGHT,OUTPUT);
  analogWrite(BACKLIGHT,180);
  tft.init();                 // Initialize TFT
  tft.setRotation(1);         // Set screen orientation (0-3)

  tft.setTextColor(TFT_GREEN, TFT_BLACK); // Text color with background
  tft.setTextSize(2);         // Scale text (1-7)
  tft.setCursor(0, 0);      // X, Y position
  tft.println("Hello, World!");
}

void loop() {
  // Nothing here
}