#include "timer.h"
//EVENT LOOP
int STATE = 0, RUN = 1;

//TIME VALUES
int h1 = 0, h2 = 0, m1 = 0, m2 = 0;

void joystick_handler(unsigned int code);
void SET_TIME_STATE(void);
void TIMER_ON_STATE(void);
void TIMER_PAUSE_STATE(void);

int main(void) {
    open_display();
    open_joystick();
    while (RUN) {
        if (m2==10) {
            m2=0;
            if (m1<7) {
                m1++;
            }
        }
        if (m1==6) {
            m1=0;
            if (h1<10) {
                h2++;
            }
        }
        if (h2==10) {
            h2==0;
            if (h1<10) {
                h1++;
            }
        }
        if (h1==10) {
            h1=0;
            h2=0;
            m1=0;
            m2=0;
        }
        if (STATE<2) {
            SET_TIME_STATE();
            m2++;
        }
    }
    close_joystick();
    close_display();
    return 1;
}

void joystick_handler(unsigned int code) {
    printf("%d", code);
    if (STATE<2) {
        if(code==28) {
        printf("button pressed\n");
        }   
    }
}
void SET_TIME_STATE(void) {
    check_joystick(joystick_handler, 100);
    clear_display();
    usleep(550000);
    display_colons();
    draw_number(h2, 0, 0);
    draw_number(h1, 4, 0);
    draw_number(m2, -1, 4);
    draw_number(m1, 3, 4);
    usleep(550000);
}
