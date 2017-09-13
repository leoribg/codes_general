CC=gcc
OBJ=sha256

SRC=$(wildcard *.c)

$(OBJ): $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)
	
all: $(OBJ)

clean:
	rm $(OBJ)
	