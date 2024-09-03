#include "timer.h"

int STATE = 0, PRESSES = 0;

void handler(unsigned int code);

int main(void) {
    open_input();
    open_display();
    clear_display();
    while (PRESSES < 2) {
        if (STATE == 0) {
            display_colons();
            display_hour(0, , );
            display_minutes(0, 0, , , );
            sleep(1);
            clear_display();
            sleep(1);
        }
        if (STATE == 1) {
            display_colons();
            display_hour(hr, xhr, y);
            display_minutes(m1, m2, xm1, xm2, y);
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
    if (STATE == 0 || STATE == 1) {
        if (code == 28) {
            STATE++;
        }
    }
}