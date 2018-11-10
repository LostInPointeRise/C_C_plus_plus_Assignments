CC = gcc
CFLAGS = -w -g
OBJS = imageresize.o

 
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o imageresize  -ljpeg

imageresize.o: imageresize.c
	$(CC) $(CFLAGS) -c imageresize.c

clean:
	rm imageresize.o imageresize  