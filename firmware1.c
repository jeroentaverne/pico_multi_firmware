// By Jeroen Taverne

#include "pico/stdlib.h"
#include "hardware/watchdog.h"
#include "hardware/structs/watchdog.h"

#define CURRENT_FIRMWARE 1

int main(void)
{
	// Blink LED to show which firmware is running
	gpio_init(PICO_DEFAULT_LED_PIN);
	gpio_set_dir(PICO_DEFAULT_LED_PIN, true);

	for (uint8_t i = 0; i <= CURRENT_FIRMWARE; i++) {
		gpio_put(PICO_DEFAULT_LED_PIN, true);
		sleep_ms(500);
		gpio_put(PICO_DEFAULT_LED_PIN, false);
		sleep_ms(500);
	}
	sleep_ms(2000);

	// Reboot to next firmware
	watchdog_hw->scratch[3] = CURRENT_FIRMWARE + 1;
	watchdog_reboot(0, 0, 0);

	return 0;
}
