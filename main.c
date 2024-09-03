#include "timer.h"

int state = 0, presses = 0;

void handler(unsigned int code);

int main(void) {
    open_input();
    open_display();
    clear_display();
    while (presses < 3) {

        if (presses > 0) {
            presses = presses - 1;
        }

        if (state == 0) {
            display_colons();
            display_hour(0, , );
            display_minutes(0, 0, , , );
            sleep(1);
            clear_display();
            sleep(1);
        }
    }
    clear_display();
    close_display();
    close_input();
    return 0;
}

void handler(unsigned int code) {
	if (code == 28) {
		state++;
        presses++;
	}
}