CC = gcc
CFLAGS = -w -g -ljpeg
OBJS = imageresize.o

 
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o imageresize

imageresize.o: imageresize.c
	$(CC) $(CFLAGS) -c imageresize.c

clean:
	rm imageresize.o imageresize  