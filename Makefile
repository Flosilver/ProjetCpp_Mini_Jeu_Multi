EXE := game
TEST := test_catch

# code
SRC_DIR := src
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(patsubst %.cpp, %.o, $(SRC))))
#$(SRC: .cpp = .o)))
#OBJ := 

# tests
TEST_DIR := unit_test
TEST_OBJ_DIR := obj_test

SRC_TEST := $(wildcard $(TEST_DIR)/*.cpp)
OBJ_TEST := $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(patsubst %.cpp, %.o, $(SRC_TEST))))


# dependances
CC := g++
CPPFLAGS := -Iinclude
CFLAGS := -g -Wall
LDFLAGS := 
LDLIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

.PHONY: all clean

all: $(EXE) $(TEST)

# Executable
$(EXE): $(OBJ)
	$(CC) $^ -o $@ $(LDLIBS) $(CPPFLAGS)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)
	
$(OBJ_DIR):
	mkdir $@


# Tests
$(TEST): $(OBJ_TEST)
	$(CC) $^ -o $@ $(LDLIBS) $(CPPFLAGS)

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(TEST_OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

$(TEST_OBJ_DIR):
	mkdir $@

#$(TEST): test_paysan

#test_paysan: test_paysan.o point.o Paysan.o
#	$(LD) -o test test_paysan.o Paysan.o

#test_paysan.o: test_paysan.cpp Paysan.hpp catch.hpp
#	$(CPP) -c test_paysan.cpp


clean:
	rm -rf $(OBJ) $(OBJ_TEST)
	
mrproper: clean
	rm -rf $(EXE) $(TEST)

remake: mrproper all
