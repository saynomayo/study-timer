#include "timer.h"
//EVENT LOOP
int STATE = 0, RUN = 1;

//COLORS
#define BLACK 0x0000
#define WHITE 0xFFFF
#define YELLOW 0xFF00
#define BLUE 0x00F0

//TIME VALUES
int m1 = 0, m2 = 0, s1 = 0, s2 = 0;

void joystick_handler(unsigned int code);
void SET_TIME_STATE(void);
void TIMER_ON_STATE(void);
void TIMER_PAUSE_STATE(void);

int main(void) {
    open_display();
    open_joystick();
    while (RUN) {
        if (s2>9) {
            s2=0;
            if (s1<7) {
                s1++;
            }
        }
        if (s1>5) {
            s1=0;
            if (m1<10) {
                m2++;
            }
        }
        if (m2>9) {
            m2=0;
            if (m1<10) {
                m1++;
            }
        }
        if (m1>9) {
            m1=0;
            m1=0;
            s1=0;
            s2=0;
        }
        if (STATE<2) {
            SET_TIME_STATE();
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
        STATE++;
        printf("state is now %d", STATE);
        printf("button pressed\n");
        }   
    }
    if (STATE==0) {
        if(code==105) {
            m2++;
        }
    }
    if (STATE==1) {
        if (code==105) {
            s2++;
        }
    }
}
void SET_TIME_STATE(void) {
    //CURRENTLY TAKES DOUBLE INPUT INSTEAD OF INTENDED SINGLE INPUT
    //ALSO, WHEN m2 = 10, it does NOT set back to zero, so m1 increments repeatedly
    check_joystick(joystick_handler, 1);
    clear_display();
    display_colons(WHITE);
    draw_number(m2, 0, 0, YELLOW);
    draw_number(m1, 4, 0, YELLOW);
    draw_number(s2, -1, 4, BLUE);
    draw_number(s1, 3, 4, BLUE);
    usleep(25000);
}
