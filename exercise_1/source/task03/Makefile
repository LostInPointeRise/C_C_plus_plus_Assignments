CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = check_parameter_ammount.o check_end_of_user_input.o strlength.o


all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o strlength
 
check_end_of_user_input.o: check_end_of_user_input.c
	$(CC) $(CFLAGS) -c check_end_of_user_input.c

check_parameter_ammount.o: check_parameter_ammount.c
	$(CC) $(CFLAGS) -c check_parameter_ammount.c

strlength.o: strlength.c
	$(CC) $(CFLAGS) -c strlength.c  

clean:
	rm check_parameter_ammount.o check_end_of_user_input.o strlength.o strlength