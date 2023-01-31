TARGET = Calculator
DEBUG = -g
CC = g++

PREF_SRC = ./src/
PREF_OBJ = ./obj/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))



$(TARGET)) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c 
	$(CC) -c $(DEBUG) $< -o $@

clean :
	rm $(PREF_OBJ)*.o