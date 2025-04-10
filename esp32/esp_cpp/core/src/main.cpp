#include "main.h"

#define LOG_LEVEL_LOCAL ESP_LOG_VERSION
#include "esp_log.h"
#define LOG_TAG "MAIN"

static Main my_main;

extern "C" void app_main(void) {
    ESP_ERROR_CHECK(my_main.setUp());
    while(true) {
        my_main.loop();
    }
}

esp_err_t Main::setUp() {
    esp_err_t status{ESP_OK};
    ESP_LOGI(LOG_TAG, "setUp!");
    return status;
}

void Main::loop() {
    ESP_LOGI(LOG_TAG, "hello esp-idf-c++");
    vTaskDelay(1000);
}