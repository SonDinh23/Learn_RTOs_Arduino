#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

uint8_t state = 0;

TaskHandle_t xTaskhandle;
TaskHandle_t yTaskhandle;
TaskHandle_t zTaskhandle;

void Task1 (void *pvParameters );
void Task2 (void *pvParameters );
void Task3 (void *pvParameters );

void Task1 (void *pvParameters) {
  (void) pvParameters;

  for (;;) {
    Serial.println("Task1");
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void Task2 (void *pvParameters) {
  (void) pvParameters;

  for (;;) {
    Serial.println("Task2");
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void Task3 (void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    if(state == 4) {
      vTaskDelete(zTaskhandle);
      state = 0;
    }
    Serial.println("Task3");
    state++;
  }
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xTaskCreate(Task1, "Print1", 64, NULL, 0, &xTaskhandle);
  xTaskCreate(Task2, "Print2", 64, NULL, 0, &yTaskhandle);
  xTaskCreate(Task3, "Print3", 64, NULL, 3, &zTaskhandle); 
}

void loop() {
  // put your main code here, to run repeatedly:
  
}