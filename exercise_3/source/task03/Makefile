CC = gcc
CFLAGS = -w -g -ljpeg
OBJS = bilinear.o

 
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o bilinear

bilinear.o: bilinear.c
	$(CC) $(CFLAGS) -c bilinear.c

clean:
	rm bilinear.o bilinear *.jpg