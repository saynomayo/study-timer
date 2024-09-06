#include <unistd.h>
#include <stdio.h>
#include "sense.h"

void open_display(void);
void close_display(void);
void clear_display(void);

void draw_number(int number, int x, int y);

void display_colons(void);


void run_timer(void);
void increase_time(void);
void decrease_time(void);
void timer_blinks(void);

void open_magnet(void);
void check_magnet(void);

void open_joystick(void);
void check_joystick(void (*)(unsigned int code), int delay);
void close_joystick(void);
