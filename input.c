
#include "sense.h"
#include "timer.h"
#include <linux/input.h>
#include <stdio.h>

pi_joystick_t *joystick = NULL;

void open_input(void) {
	joystick = getJoystickDevice();
}

void close_input(void) {
	if (joystick != NULL) {
		freeJoystick(joystick);
		joystick = NULL;
	}
	else {
		printf("Joystick hasn't been allocated!");
	}
}

void check_input(void (*callback)(unsigned int code), int delay) {
	pollJoystick(joystick,callback,delay);
}
