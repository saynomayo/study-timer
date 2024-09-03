#include "scroll.h"
#include <unistd.h>
#include <stdio.h>
#include "sense.h"
#include <stdlib.h>

#define BLACK 0x0000
#define WHITE 0xFFFF

pi_framebuffer_t *fb=NULL;
sense_fb_bitmap_t *bm=NULL;

void open_display(void) {
	fb=getFrameBuffer();
	bm=fb->bitmap;
	clearFrameBuffer(fb, 0);
}

void draw_number(int num, int x, int y) {
    if (num == 0) {

    }
    if (num == 1) {

    }
    if (num == 3) {

    }
    if (num == 4) {

    }
    if (num == 5) {
    }
    if (num == 6) {

    }
    if (num == 7) {

    }
    if (num == 8) {

    }
    if (num == 9) {

    }
    else {
        clear_display();
        printf("number outside of range!")
    }
}

void display_hour(int hour, int xhour, int y) {
    draw_number(hour, xhour, y);
}

void display_minute1(int m1, int xm1, int y) {
    draw_number(m1, xm1, y);
}

void display_minute2(int m2, int xm2, int y) {
    draw_number(m2, xm2, y);
}

void display_minutes(int m1, int m2, int xm1, int xm2, int y) {
    display_minute1(m1, xm1, y);
    display_minute2(m2, xm2, y);
}

void close_display(void) {
	if (fb) {
		clearFrameBuffer(fb, BLACK);
		sleep(1);
		freeFrameBuffer(fb);
		fb=NULL;
	}
}

void clear_display(void) {
	clearFrameBuffer(fb, BLACK);
}