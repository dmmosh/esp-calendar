#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <stdlib.h>
#include <WiFi.h>
#include <TFT_eSPI.h>
//#include "BluetoothSerial.h"
#define LED 2 // led
#define BACKLIGHT 5 //backlight cpio
#define CLEAR "\x1b[2K\r"

extern TFT_eSPI tft;
extern WiFiServer server;

extern const char* ssid;
extern const char * pass;

extern unsigned int x_set; 
extern unsigned int y_set; 

void led(void* args);
void wifi_boot();
void vTaskMemoryUsage(void *pvParameters);


template<typename ...Args>
void debug(const char* format, Args... args){


  tft.setCursor(x_set, y_set);

  if constexpr (sizeof...(args) == 0){
    tft.print(format);
  } else {
    tft.printf(format, args...);
  }

  y_set+= 10;
  if(y_set>=130){
    y_set = 5;
  }

  //x_set += 10;
}

