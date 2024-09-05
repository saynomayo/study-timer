#include "timer.h"
#include <unistd.h>
#include <stdio.h>
#include "sense.h"
#include <stdlib.h>

#define BLACK 0x0000
#define WHITE 0xFFFF
#define RED 0xF000

pi_framebuffer_t *fb=NULL;
sense_fb_bitmap_t *bm=NULL;


void open_display(void) {
	fb=getFrameBuffer();
	bm=fb->bitmap;
	clearFrameBuffer(fb, 0);
}

void draw_number(int number, int x, int y) {
	switch(number) 
	{
	case 0:
	        bm->pixel[1+x][0+y]=RED;
	        bm->pixel[1+x][1+y]=RED;
	        bm->pixel[1+x][2+y]=RED;
	        bm->pixel[1+x][3+y]=RED;
	        bm->pixel[3+x][0+y]=RED;
	        bm->pixel[3+x][1+y]=RED;
	        bm->pixel[3+x][2+y]=RED;
	        bm->pixel[3+x][3+y]=RED;
	        bm->pixel[2+x][0+y]=RED;
	        bm->pixel[2+x][3+y]=RED;
		break;
	case 1:
	        bm->pixel[2+x][0+y]=RED;
	        bm->pixel[2+x][1+y]=RED;
	        bm->pixel[2+x][2+y]=RED;
	        bm->pixel[2+x][3+y]=RED;
	        bm->pixel[3+x][1+y]=RED;
	    	break;
	case 2:
	        bm->pixel[1+x][0+y]=RED;
	        bm->pixel[1+x][1+y]=RED;
	        bm->pixel[1+x][3+y]=RED;
	        bm->pixel[2+x][0+y]=RED;
	        bm->pixel[2+x][2+y]=RED;
	        bm->pixel[2+x][3+y]=RED;
	        bm->pixel[3+x][0+y]=RED;
	        bm->pixel[3+x][2+y]=RED;
	        bm->pixel[3+x][3+y]=RED;
		break;
	case 3:
	        bm->pixel[1+x][0+y]=RED;
	        bm->pixel[1+x][1+y]=RED;
	        bm->pixel[1+x][2+y]=RED;
	        bm->pixel[1+x][3+y]=RED;
	        bm->pixel[2+x][0+y]=RED;
	        bm->pixel[2+x][1+y]=RED;
	        bm->pixel[2+x][3+y]=RED;
	        bm->pixel[3+x][0+y]=RED;
	        bm->pixel[3+x][3+y]=RED;
		break;
	case 4:
	        bm->pixel[1+x][0+y]=RED;
	        bm->pixel[1+x][1+y]=RED;
	        bm->pixel[1+x][2+y]=RED;
	        bm->pixel[1+x][3+y]=RED;
	        bm->pixel[2+x][2+y]=RED;
	        bm->pixel[3+x][0+y]=RED;
	        bm->pixel[3+x][1+y]=RED;
	        bm->pixel[3+x][2+y]=RED;
		break;
	case 5:
	        bm->pixel[1+x][0+y]=RED;
	        bm->pixel[1+x][2+y]=RED;
	        bm->pixel[1+x][3+y]=RED;
	        bm->pixel[2+x][0+y]=RED;
	        bm->pixel[2+x][1+y]=RED;
	        bm->pixel[2+x][3+y]=RED;
	        bm->pixel[3+x][0+y]=RED;
	        bm->pixel[3+x][1+y]=RED;
	        bm->pixel[3+x][3+y]=RED;
		break;
	case 6:
	        bm->pixel[1+x][0+y]=RED;
	        bm->pixel[1+x][2+y]=RED;
	        bm->pixel[1+x][3+y]=RED;
	        bm->pixel[2+x][0+y]=RED;
	        bm->pixel[2+x][2+y]=RED;
	        bm->pixel[2+x][3+y]=RED;
	        bm->pixel[3+x][0+y]=RED;
	        bm->pixel[3+x][1+y]=RED;
	        bm->pixel[3+x][2+y]=RED;
	        bm->pixel[3+x][3+y]=RED;
		break;
	case 7:
	        bm->pixel[1+x][0+y]=RED;
	        bm->pixel[1+x][1+y]=RED;
	        bm->pixel[1+x][2+y]=RED;
	        bm->pixel[1+x][3+y]=RED;
	        bm->pixel[3+x][0+y]=RED;
	        bm->pixel[2+x][2+y]=RED;
	        bm->pixel[2+x][0+y]=RED;
		break;
	case 8:
	        bm->pixel[1+x][0+y]=RED;
	        bm->pixel[1+x][1+y]=RED;
	        bm->pixel[1+x][2+y]=RED;
	        bm->pixel[1+x][3+y]=RED;
	        bm->pixel[3+x][0+y]=RED;
	        bm->pixel[3+x][1+y]=RED;
	        bm->pixel[3+x][2+y]=RED;
	        bm->pixel[3+x][3+y]=RED;
	        bm->pixel[2+x][0+y]=RED;
	        bm->pixel[2+x][3+y]=RED;
	        bm->pixel[2+x][1+y]=RED;
		break;
	case 9:
	        bm->pixel[1+x][0+y]=RED;
	        bm->pixel[1+x][1+y]=RED;
	        bm->pixel[1+x][2+y]=RED;
	        bm->pixel[1+x][3+y]=RED;
	        bm->pixel[3+x][0+y]=RED;
	        bm->pixel[3+x][1+y]=RED;
	        bm->pixel[2+x][1+y]=RED;
	        bm->pixel[3+x][3+y]=RED;
	        bm->pixel[2+x][0+y]=RED;
	        bm->pixel[2+x][3+y]=RED;   
		break;
	default:
        printf("number outside of range!");
    	}
	printf("chosen number is %d\n", number);
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
void display_colons(void) {
    bm->pixel[0][1]=WHITE;
    bm->pixel[0][3]=WHITE;
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
