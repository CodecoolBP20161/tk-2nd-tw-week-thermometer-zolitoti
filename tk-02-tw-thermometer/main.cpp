#include "mbed.h"
#include "codecool/codecool_shield_names.h"

int main() {
	gpio_t led;

	gpio_init_out(&led, LED_GREEN_SHIELD);

	while(1) {
		gpio_write(&led, 1);
		wait(0.5);
		gpio_write(&led, 0);
		wait(0.5);
	}
}
