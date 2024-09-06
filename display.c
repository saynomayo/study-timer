#include "timer.h"
#include <unistd.h>
#include <stdio.h>
#include "sense.h"
#include <stdlib.h>

pi_framebuffer_t *fb=NULL;
sense_fb_bitmap_t *bm=NULL;


void open_display(void) {
	fb=getFrameBuffer();
	bm=fb->bitmap;
	clearFrameBuffer(fb, 0);
}

void draw_number(int number, int x, int y, int color) {
	switch(number) 
	{
	case 0:
	        bm->pixel[1+x][0+y]=color;
	        bm->pixel[1+x][1+y]=color;
	        bm->pixel[1+x][2+y]=color;
	        bm->pixel[1+x][3+y]=color;
	        bm->pixel[3+x][0+y]=color;
	        bm->pixel[3+x][1+y]=color;
	        bm->pixel[3+x][2+y]=color;
	        bm->pixel[3+x][3+y]=color;
	        bm->pixel[2+x][0+y]=color;
	        bm->pixel[2+x][3+y]=color;
		break;
	case 1:
	        bm->pixel[2+x][0+y]=color;
	        bm->pixel[2+x][1+y]=color;
	        bm->pixel[2+x][2+y]=color;
	        bm->pixel[2+x][3+y]=color;
	        bm->pixel[3+x][1+y]=color;
	    	break;
	case 2:
	        bm->pixel[1+x][0+y]=color;
	        bm->pixel[1+x][1+y]=color;
	        bm->pixel[1+x][3+y]=color;
	        bm->pixel[2+x][0+y]=color;
	        bm->pixel[2+x][2+y]=color;
	        bm->pixel[2+x][3+y]=color;
	        bm->pixel[3+x][0+y]=color;
	        bm->pixel[3+x][2+y]=color;
	        bm->pixel[3+x][3+y]=color;
		break;
	case 3:
	        bm->pixel[1+x][0+y]=color;
	        bm->pixel[1+x][1+y]=color;
	        bm->pixel[1+x][2+y]=color;
	        bm->pixel[1+x][3+y]=color;
	        bm->pixel[2+x][0+y]=color;
	        bm->pixel[2+x][1+y]=color;
	        bm->pixel[2+x][3+y]=color;
	        bm->pixel[3+x][0+y]=color;
	        bm->pixel[3+x][3+y]=color;
		break;
	case 4:
	        bm->pixel[1+x][0+y]=color;
	        bm->pixel[1+x][1+y]=color;
	        bm->pixel[1+x][2+y]=color;
	        bm->pixel[1+x][3+y]=color;
	        bm->pixel[2+x][2+y]=color;
	        bm->pixel[3+x][0+y]=color;
	        bm->pixel[3+x][1+y]=color;
	        bm->pixel[3+x][2+y]=color;
		break;
	case 5:
	        bm->pixel[1+x][0+y]=color;
	        bm->pixel[1+x][2+y]=color;
	        bm->pixel[1+x][3+y]=color;
	        bm->pixel[2+x][0+y]=color;
	        bm->pixel[2+x][1+y]=color;
	        bm->pixel[2+x][3+y]=color;
	        bm->pixel[3+x][0+y]=color;
	        bm->pixel[3+x][1+y]=color;
	        bm->pixel[3+x][3+y]=color;
		break;
	case 6:
	        bm->pixel[1+x][0+y]=color;
	        bm->pixel[1+x][2+y]=color;
	        bm->pixel[1+x][3+y]=color;
	        bm->pixel[2+x][0+y]=color;
	        bm->pixel[2+x][2+y]=color;
	        bm->pixel[2+x][3+y]=color;
	        bm->pixel[3+x][0+y]=color;
	        bm->pixel[3+x][1+y]=color;
	        bm->pixel[3+x][2+y]=color;
	        bm->pixel[3+x][3+y]=color;
		break;
	case 7:
	        bm->pixel[1+x][0+y]=color;
	        bm->pixel[1+x][1+y]=color;
	        bm->pixel[1+x][2+y]=color;
	        bm->pixel[1+x][3+y]=color;
	        bm->pixel[3+x][0+y]=color;
	        bm->pixel[2+x][2+y]=color;
	        bm->pixel[2+x][0+y]=color;
		break;
	case 8:
	        bm->pixel[1+x][0+y]=color;
	        bm->pixel[1+x][1+y]=color;
	        bm->pixel[1+x][2+y]=color;
	        bm->pixel[1+x][3+y]=color;
	        bm->pixel[3+x][0+y]=color;
	        bm->pixel[3+x][1+y]=color;
	        bm->pixel[3+x][2+y]=color;
	        bm->pixel[3+x][3+y]=color;
	        bm->pixel[2+x][0+y]=color;
	        bm->pixel[2+x][3+y]=color;
	        bm->pixel[2+x][1+y]=color;
		break;
	case 9:
	        bm->pixel[1+x][0+y]=color;
	        bm->pixel[1+x][1+y]=color;
	        bm->pixel[1+x][2+y]=color;
	        bm->pixel[1+x][3+y]=color;
	        bm->pixel[3+x][0+y]=color;
	        bm->pixel[3+x][1+y]=color;
	        bm->pixel[2+x][1+y]=color;
	        bm->pixel[3+x][3+y]=color;
	        bm->pixel[2+x][0+y]=color;
	        bm->pixel[2+x][3+y]=color;   
		break;
	default:
        printf("number outside of range!");
    	}
	printf("chosen number is %d\n", number);
}

void display_colons(int color) {
    bm->pixel[0][1]=color;
    bm->pixel[0][3]=color;
}

void close_display(void) {
	if (fb) {
		clearFrameBuffer(fb, 0x0000);
		sleep(1);
		freeFrameBuffer(fb);
		fb=NULL;
	}
}

void clear_display(void) {
	clearFrameBuffer(fb, 0x0000);
}
