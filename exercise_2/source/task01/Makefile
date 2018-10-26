CC = gcc
CFLAGS = -w
OBJS = scope2.o scope1.o 

 
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o scope

warning: $(OBJS)
	$(CC)  -Wl,--warn-common -o scope scope1.o scope2.o

no_common: $(OBJS)
	$(CC)  -Wl,-fno-common -o scope scope1.o scope2.o

scope1.o: scope1.c
	$(CC) $(CFLAGS) -c scope1.c

scope2.o: scope2.c
	$(CC) $(CFLAGS) -c scope2.c

clean:
	rm scope1.o scope2.o scope