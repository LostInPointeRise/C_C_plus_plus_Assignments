CC = gcc
CFLAGS = -w -g
OBJS = imagecopy.o

 
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o imagecopy  -ljpeg

imagecopy.o: imagecopy.c
	$(CC) $(CFLAGS) -c imagecopy.c
	
clean:
	rm imagecopy imagecopy.o  