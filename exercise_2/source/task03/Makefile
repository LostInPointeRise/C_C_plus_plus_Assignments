CC = gcc
CFLAGS = -Wmissing-prototypes
OBJS = read_from_command_line.o solve_expression.o check_if_operator_match_expected_ones.o check_parameter_ammount.o calculator.o calc.o


all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o calc

debug: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -g -o calc


read_from_command_line.o: read_from_command_line.c
	$(CC) $(CFLAGS) -c read_from_command_line.c

solve_expression.o: solve_expression.c
	$(CC) $(CFLAGS) -c solve_expression.c

check_if_operator_match_expected_ones.o: check_if_operator_match_expected_ones.c
	$(CC) $(CFLAGS) -c check_if_operator_match_expected_ones.c

check_parameter_ammount.o: check_parameter_ammount.c
	$(CC) $(CFLAGS) -c check_parameter_ammount.c

calculator.o: calculator.c
	$(CC) $(CFLAGS) -c calculator.c

calc.o: calc.c
	$(CC) $(CFLAGS) -c calc.c  

clean:
	rm check_parameter_ammount.o calculator.o calc.o solve_expression.o read_from_command_line.o check_if_operator_match_expected_ones.o calc