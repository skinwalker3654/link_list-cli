CC = gcc
DIR = src
TAR = main
BUILD = bin
OBJ = $(DIR)/main.c $(DIR)/node.c

all: $(BUILD)/$(TAR)

$(BUILD)/$(TAR): $(OBJ)
	@echo "Compiling the files..."
	@mkdir -p $(BUILD)
	$(CC) $(OBJ) -o $(BUILD)/$(TAR)

run: $(BUILD)/$(TAR)
	@echo "Running the program..."
	./$(BUILD)/$(TAR)

clean:
	@echo "Deleting the bin folder..."
	rm -rf $(BUILD)

