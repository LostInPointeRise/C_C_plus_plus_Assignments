CC = gcc
CFLAGS = -w -g 
OBJS = proportional.o

  
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o proportional  -ljpeg

bilinear.o: proportional.c
	$(CC) $(CFLAGS) -c proportional.c

clean:
	rm proportional.o proportional