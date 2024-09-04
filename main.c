#include "timer.h"

int STATE = 0, PRESSES = 0, RUN = 1;

void handler(unsigned int code);

int main(void) {
    open_display();
    open_input();
    while (RUN) {
        check_input(handler, 100);
        if (STATE==0) {
            display_colons();
            draw_number(0, 0, 0);
            sleep(1);
            clear_display();
            sleep(1);
    }
    close_input();
    close_display();
    return 1;
}

void handler(unsigned int code) {
    if (code == 28) {
        if (STATE < 3) {
            STATE ++;
        }
        PRESSES++;
    }
}