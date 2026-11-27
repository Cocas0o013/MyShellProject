CC = gcc
CFLAGS = -Wall -Wextra -g -std=gnu11
TARGET = MyShellProject
SRCS = main.c parser.c executor.c builtins.c
OBJS = $(SRCS:.c=.o)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)