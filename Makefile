CFLAGS=-std=c11 -Werror -g
#CFLAGS=-std=c11 -Wall -Werror -g
LDFLAGS=
LDLIBS=`pkg-config --libs --cflags sdl2 SDL2_ttf SDL2_image`
CC=gcc

drawing_priority: drawing_priority.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	
fonts: fonts.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	
menu_prototype: menu_prototype.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	
uthash_test: uthash_test.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)