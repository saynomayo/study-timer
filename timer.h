#include <unistd.h>
#include <stdio.h>
#include "sense.h"

void open_display(void);
void close_display(void);
void clear_display(void);

void draw_number(int num, int x, int y);

void display_hour(int hour, int xhour, int y);
void display_minute1(int m1, int xm1, int y);
void display_minute2(int m2, int xm2, int y);
void display_minutes(int m1, int m2, int xm1, int xm2, int y);
void display_colons(void);


void run_timer(void);
void increase_time(void);
void decrease_time(void);
void timer_blinks(void);


void open_input(void);
void check_input(void (*)(unsigned int code), int delay);
void close_input(void);
