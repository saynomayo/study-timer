#include "timer.h"
//EVENT LOOP
int STATE = 0, RUN = 1;

//SOLID COLORS
#define BLACK 0x0000
#define WHITE 0xFFFF
#define YELLOW 0xFF06
#define BLUE 0x00FF
#define RED 0xF000
#define PINK 0xF00F
#define PURPLE 0x60F0
#define ORANGE 0xF300

#define test 0xFB66
//PASTELS/SPECIAL COLORS
#define MINTGREEN 0x0F0A
#define SKYBLUE 0x5F5F
#define PEACH 0xFB66
#define BLUSH 0xF490
//FADED COLORS
#define LOWRED 0x7000

//TIME VALUES
int m1 = 0, m2 = 0, s1 = 0, s2 = 0;

void joystick_handler(unsigned int code);
void handle_wrapping(void);
void SET_TIME_STATE(void);
void TIMER_ON_STATE(void);
void TIMER_PAUSE_STATE(void);

int main(void) {
    open_display();
    open_joystick();
    while (RUN) {
        handle_wrapping();
        if (STATE<2) {
            SET_TIME_STATE();
        }
    }
    close_joystick();
    close_display();
    return 1;
}

void joystick_handler(unsigned int code) {
    printf("%d\n", code);
    if (code==28) {
        if(STATE==1) {
            STATE++;
        }
    }
    if (code==103) {
        if(STATE==0) {
            STATE++;
        }
    }
    if (code==108) {
        if(STATE==1) {
            STATE--;
        }
    }
    if (code==105) {
        if(STATE==0) {
            m2++;
        }
        else if (STATE==1) {
            s2++;
        }
    }
    if (code==106) {
        if(STATE==0) {
            m2--;
        }
        if(STATE==1) {
            s2--;
        }
    }
}
void SET_TIME_STATE(void) {
    check_joystick(joystick_handler, 1);
    clear_display();
    display_colons(LOWRED);
    draw_number(m2, 0, 0, PEACH);
    draw_number(m1, 4, 0, PEACH);
    draw_number(s2, -1, 4, BLUSH);
    draw_number(s1, 3, 4, BLUSH);
    usleep(25000);
}

void handle_wrapping(void) {
    if(s2>9){
        s2=0;
        s1++;
    }
    if(s1>5){
        s1=0;
        s2=0;
        m2++;
    }
    if(m2>9){
        m2=0;
        s2=0;
        s1=0;
        m1++;
    }
    if(m1>9){
        m1=0;
        m2=0;
        s1=0;
        s2=0;
    }
    if(s2<0){
        s2=9;
        s1--;
    }
    if(s1<0){
        s1=5;
        m2--;
    }
    if(m2<0){
        m2=9;
        m1--;
    }
    if(m1<0){
        m1=9;
        m2=9;
        s1=5;
        s2=9;
    }
}
