#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// El pin del LED integrado del ESP32-C3 Super Mini suele ser el GPIO 8
#define BLINK_GPIO 8

void app_main(void)
{
    // Configura el pin del LED como salida digital
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    printf("¡Entorno listo! Iniciando parpadeo de LED nativo en C...\n");

    while (1) {
        // Enciende el LED (Nota: Muchas placas mini usan lógica inversa, '0' enciende)
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Espera 1 segundo

        // Apaga el LED
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Espera 1 segundo
    }
}
