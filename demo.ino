#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

//pins
static const int led_pin = LED_BUILTIN;

//our task:blink LED
void toggleLED(void *parameter){
  while(1){
    digitalWrite(led_pin, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}


void toggleLEDF(void *parameter){
  while(1){
    digitalWrite(led_pin, HIGH);
    vTaskDelay(200 / portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}

void setup() {
  // put your setup code here, to run once:
  //configure pin
  pinMode(led_pin, OUTPUT);

  //Task to run forever
  xTaskCreatePinnedToCore(
    toggleLED,    //Funtction to be called
    "Toggle LED", //Name of task
    1024,         //Stack size in bytes
    NULL,         //Parameter to pass to function
    1,            //Task Priority
    NULL,         //Task Handle
    app_cpu);     //Run on onr core fore demo purposes

  xTaskCreatePinnedToCore(
    toggleLEDF,    //Funtction to be called
    "Toggle LED Fast", //Name of task
    1024,         //Stack size in bytes
    NULL,         //Parameter to pass to function
    1,            //Task Priority
    NULL,         //Task Handle
    app_cpu);     //Run on onr core fore demo purposes


}

void loop() {
  // put your main code here, to run repeatedly:

}
