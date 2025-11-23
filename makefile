CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRC = src/main.c src/tarefas_core.c src/tarefas_io.c src/tarefas_view.c
OBJ = $(SRC:. c=.o)
EXEC = app_tarefas

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $(CFLAGS) -c $< -o $@

clean:

	rm -f scr/*.o $(EXEC)