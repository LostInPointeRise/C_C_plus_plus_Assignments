CC = gcc
CFLAGS = -w -g 
OBJS = bilinear.o

 
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o bilinear  -ljpeg

bilinear.o: bilinear.c
	$(CC) $(CFLAGS) -c bilinear.c
clean:
	rm bilinear.o bilinear