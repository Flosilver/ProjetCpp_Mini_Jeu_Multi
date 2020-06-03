EXE := game

SRC_DIR := src
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(patsubst %.cpp, %.o, $(SRC))))
#$(SRC: .cpp = .o)))
#OBJ := 

CC := g++
CPPFLAGS := -Iinclude
CFLAGS := -g -Wall
LDFLAGS := 
LDLIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $^ -o $@ $(LDLIBS) $(CPPFLAGS)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)
	
$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ)
	
mrproper: clean
	rm -rf $(EXE)

remake: mrproper all
