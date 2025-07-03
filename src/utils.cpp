#include "header.h"


void led(void* args){
    int i = 1000; 
    while(1){
      digitalWrite(LED, HIGH);
      vTaskDelay(i/portTICK_PERIOD_MS);
      digitalWrite(LED, LOW);
      vTaskDelay(i/portTICK_PERIOD_MS);
      i= (int)((float)i /1.2);
      if(i == 0){
        i = 1000;
      }
      //Serial.debug("%i\n", i);
    }
  }
  
  
  
  // if tthe wifi goes out, the esp simply rescans the wifi
  // clears the screen
  void wifi_boot(){
    tft.fillScreen(TFT_BLACK);
    x_set = 5;
    y_set = 5;
    tft.setTextSize(1);
    uint16_t seconds = 0;
    while(!WiFi.isConnected()){
      tft.setTextDatum(TC_DATUM);
      tft.drawString("Connecting...",tft.width() / 2+2,30);
      tft.setTextSize(5);
      tft.drawNumber(seconds,tft.width() / 2+2, tft.height()/2-10);
      tft.setTextSize(2);
      tft.drawChar('s',tft.width() / 2 + 2 + ((int)log10(seconds)+1)*15, tft.height()/2+10);
      tft.setTextSize(1);

      delay(1000);
      seconds++;
      tft.fillScreen(TFT_BLACK);
    }
    tft.setCursor(x_set, y_set);  // Set cursor position
    server.begin();
    debug("wifi connected %is", (unsigned int)seconds);
    debug("ip: %s", WiFi.localIP().toString().c_str());
    
    tft.setCursor(x_set, y_set);  // Set cursor position
  }
  
  void vTaskMemoryUsage(void *pvParameters)
  {
      while(1){
      // Get the task handle
      TaskHandle_t xTaskHandle = xTaskGetCurrentTaskHandle();
      
      // Get the high-water mark of the task's stack (bytes left)
      UBaseType_t uxHighWaterMark = uxTaskGetStackHighWaterMark(xTaskHandle);
      
      // Optionally, print the stack size (this is the total stack size)
      UBaseType_t uxTaskStackSize = configMINIMAL_STACK_SIZE; // Or your stack size
      
      debug("mem: %i | %i", uxHighWaterMark, uxTaskStackSize);
      vTaskDelay(1000/portTICK_PERIOD_MS);
      }
  
  
  }
