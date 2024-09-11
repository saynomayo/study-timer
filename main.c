#include "timer.h"
#include <time.h>
//EVENT LOOP
int STATE = 0, RUN = 1;
int THEME = 0, STYLE = 0;
//SOLID COLORS
#define BLACK 0x0000
#define WHITE 0xFFFF
#define YELLOW 0xFF0A
#define BLUE 0x00FF
#define RED 0xF000
#define PINK 0xF00F
#define PURPLE 0x88F0
#define ORANGE 0xF300
#define GREEN 0x0F06
#define BROWN 0x4065
#define MAGENTA 0xAA06
#define BEIGE 0x6A06
#define LAVENDER 0x6A0B

#define test 0x4065
//PASTELS/SPECIAL COLORS
#define MINTGREEN 0x0F0A
#define SKYBLUE 0x5F5F
#define PEACH 0xFB66
#define BLUSH 0xF490
//FADED COLORS
#define LOWRED 0x7000

//TIME VALUES
int m1 = 0, m2 = 0, s1 = 0, s2 = 0;

//CLOCK VALUES
int ticks = 0;

void joystick_handler(unsigned int code);
void handle_wrapping(void);
void SET_TIME_STATE(void);
void TIMER_ON_STATE(void);
void TIMER_PAUSE_STATE(void);
void TIMER_COUNTS_DOWN(int theme);
void update_timer(void);

int main(void) {
    open_display();
    open_joystick();
    while (RUN) {
        handle_wrapping();
        if (STATE<2) {
            SET_TIME_STATE();
        }
        if (STATE==2) {
            TIMER_COUNTS_DOWN(THEME);
        }
    }
    close_joystick();
    close_display();
    return 1;
}

void joystick_handler(unsigned int code) {
    printf("%d\n", code);
    if (code==28) {
        if(STATE==1 || STATE==0) {
            STATE++;
        }
    }
    if (code==103) {
        if(STATE==0) {
            STATE++;
        }
        if(STATE==2) {
            THEME++;
        }
    }
    if (code==108) {
        if(STATE==1) {
            STATE--;
        }
        if(STATE==2) {
            THEME--;
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
    display_colons(test);
    draw_number(m2, 0, 0, test);
    draw_number(m1, 4, 0, test);
    draw_number(s2, -1, 4, test);
    draw_number(s1, 3, 4, test);
    usleep(25000);
}

void TIMER_COUNTS_DOWN(int theme) {
    check_joystick(joystick_handler, 1200);
     if (m1==0 && m2==0 && s1==0 && s2==0) {
        sleep(1);
        STATE=0;
     }
     else {
        switch(theme) 
        {
            case(0):
                clear_display();
                //default theme (UDel babyyy)
                display_colons(WHITE);
                draw_number(m2, 0, 0, YELLOW);
                draw_number(m1, 4, 0, YELLOW);
                draw_number(s2, -1, 4, BLUE);
                draw_number(s1, 3, 4, BLUE);
            break;

            case(1):
                clear_display();
                //cherry blossom theme
                display_colons(PINK);
                draw_number(m2, 0, 0, BLUSH);
                draw_number(m1, 4, 0, BLUSH);
                draw_number(s2, -1, 4, WHITE);
                draw_number(s1, 3, 4, WHITE);   
            break;

            case(2):
                clear_display();
                //lava theme
                display_colons(RED);
                draw_number(m2, 0, 0, ORANGE);
                draw_number(m1, 4, 0, ORANGE);
                draw_number(s2, -1, 4, PEACH);
                draw_number(s1, 3, 4, PEACH);   
            break;

            case(3):
                 clear_display();
                //forest theme
                display_colons(SKYBLUE);
                draw_number(m2, 0, 0, GREEN);
                draw_number(m1, 4, 0, GREEN);
                draw_number(s2, -1, 4, BROWN);
                draw_number(s1, 3, 4, BROWN); 
            break;

            case(4):
            break;
            
            case(5):
            break;

            case(6):
            break;

            case(7):
            break;

            case(8):
            break;

            case(9):
            break;
                
            }
     }
    update_timer();
}

void update_timer() {
    if (m1>0 || m2>0 || s1>0 || s2>0) {
        s2--;
    }
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
