#include "timer.h"

int STATE = 0, PRESSES = 0, RUN = 1, NUM=0;

void handler(unsigned int code);

int main(void) {
    open_display();
    open_input();
    while (RUN) {
        clear_display();
        check_input(handler, 100);
        draw_number(NUM, 0, 0);
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