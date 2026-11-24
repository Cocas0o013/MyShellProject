CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TARGET = MyShellProject
SRCS = main.c 
OBJS = $(SRCS:.c=.o)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)