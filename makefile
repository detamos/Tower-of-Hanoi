
CC = gcc
CFLAGS = -std=gnu99 -Wall -Wextra -g 

RM = rm
RMFLAGS = -f

SRCS = src/main.c src/iterative.c src/recursive.c

INCLUDES = include/stack.h

LIBS = -lm

OBJS = $(SRCS:.c = .o)

all: TowerOfHanoi

clean:
		$(RM) $(RMFLAGS) TowerOfHanoi

clean-objects: 
		$(RM) $(RMFLAGS) src/*.o

TowerOfHanoi: $(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o TowerOfHanoi $(OBJS) $(LIBS)