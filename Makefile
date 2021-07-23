GCC=g++ -std=c++17
SRC_DIR=source
OBJ_DIR=obj
BIN_DIR=bin
EXE := a.out

SRC := $(wildcard $(SRC_DIR)/*cpp) main.cpp
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
all: $(EXE)

$(EXE): $(OBJ)
	$(GCC) $^ -o $@

$(EXE): $(OBJ) | $(BIN_DIR)
	$(GCC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(GCC) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@


$(info $(SRC))
$(info $(OBJ))