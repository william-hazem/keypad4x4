#include <keypad.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void app_main() {
    /// keypad pinout
    ///                     R1  R2  R3  R4  C1  C2  C3  C4 
    gpio_num_t keypad[8] = {13, 12, 14, 27, 26, 25, 33, 32};

    /// Initialize keyboard
    keypad_initalize(keypad);
    while(true)
    {
        char keypressed = keypad_getkey();  /// gets from key queue
        if(keypressed != '\0')
        {
            ets_printf("Pressed key: %c\n", keypressed);
        }

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    
}