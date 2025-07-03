#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <stdlib.h>
#include <WiFi.h>
#include <TFT_eSPI.h>
//#include "BluetoothSerial.h"
// DISPLAY DRIVER: HX8357D_DRIVER
#define LED 2 // led
#define BACKLIGHT 5 //backlight cpio



void led(void* args);

