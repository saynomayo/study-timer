
#include "sense.h"
#include "timer.h"
#include <linux/input.h>
#include <stdio.h>

pi_joystick_t *joystick = NULL;

void open_joystick(void) {
	joystick = getJoystickDevice();
}

void close_joystick(void) {
	if (joystick != NULL) {
		freeJoystick(joystick);
		joystick = NULL;
	}
	else {
		printf("Joystick hasn't been allocated!");
	}
}

void check_joystick(void (*callback)(unsigned int code), int delay) {
	pollJoystick(joystick,callback,delay);
}
