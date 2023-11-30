.PHONY: all clean

# Variables
EXEC = .app
CXX = g++
DIR = build
MAKE_DIR = mkdir -p
RM_RF = rm -rf

# Entry point
all: $(DIR) $(EXEC) 

# Utils
clean:
	${RM_RF} ${DIR}
	${RM_RF} ${EXEC}

# Rules
$(DIR):
	$(MAKE_DIR) $@

$(EXEC): $(DIR)/test.o
	$(CXX) -o $@ $^

$(DIR)/test.o: test.cpp
	$(CXX) -o $@ -c $<