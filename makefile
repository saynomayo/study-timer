INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: timer

timer: main.o input.o display.o
	cc -o timer main.o input.o display.o $(LDFLAGS) -g

clean:
	rm -rf *.o timer

main.o: main.c timer.h
	cc -c main.c -I ~/include -g

display.o: display.c timer.h
	cc -c display.c -I ~/include -g

input.o: input.c timer.h
	cc -c input.c -I ~/include -g

run: timer
	. timer

commit:
	git commit -a
	git push
