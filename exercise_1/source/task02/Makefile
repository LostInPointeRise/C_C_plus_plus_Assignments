CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = cube_xray.o sum2nd_cube_elements.o cubes.o


all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o cubes
 
cube_xray.o: cube_xray.c
	$(CC) $(CFLAGS) -c cube_xray.c
 
sum2nd_cube_elements.o: sum2nd_cube_elements.c
	$(CC) $(CFLAGS) -c sum2nd_cube_elements.c

cubes.o: cubes.c
	$(CC) $(CFLAGS) -c cubes.c

clean:
	rm cubes.o cube_xray.o sum2nd_cube_elements.o cubes