CC = gcc
CFLAGS = -w -g -ljpeg
OBJS = imagecopy.o

 
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o imagecopy

imagecopy.o: imagecopy.c
	$(CC) $(CFLAGS) -c imagecopy.c
	
clean:
	rm imagecopy imagecopy.o  