CC = gcc
COPTS = -c
OBJS = test_main.o vector.o gobjfun.o

NAME = main
all:$(NAME)
$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o main

test_main.o : test_main.c
	$(CC) $(COPTS) test_main.c
vector.o : vector.c vector.h
	$(CC) $(COPTS) vector.c
gobjfun.o : ../gobjfun.c ../gobjfun.h
	$(CC) $(COPTS) ../gobjfun.c

clean:
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re: fclean all