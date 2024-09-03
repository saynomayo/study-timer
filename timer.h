#include <unistd.h>
#include <stdio.h>
#include "sense.h"

void open_display(void);
void close_display(void);
void clear_display(void);

void display_hour(int h1, int h2);
void display_minute(int m1, int m2);

void open_input(void);
void check_input(void (*)(unsigned int code), int delay);
void close_input(void);
