# Cellular Automata Makefile - Cross-platform
# Variables

# Detect operating system
ifeq ($(OS),Windows_NT)
	DETECTED_OS = WINDOWS
	RM = cmd /c del /Q
	EXE_EXT = .exe
else
	DETECTED_OS = UNIX
	RM = rm -f
	EXE_EXT =
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		DETECTED_OS = LINUX
	endif
	ifeq ($(UNAME_S),Darwin)
		DETECTED_OS = MACOS
	endif
endif

# Compiler and flags
CC = gcc
CFLAGS = -I C:/raylib/raylib/src
LDFLAGS = -L C:/raylib/raylib/src

# Platform-specific libraries
ifeq ($(DETECTED_OS),WINDOWS)
	LIBS = -lraylib -lgdi32 -lwinmm
else ifeq ($(DETECTED_OS),MACOS)
	LIBS = -lraylib -lm
else
	LIBS = -lraylib -lm -lpthread
endif

# Output executable
OUTPUT = mi_app$(EXE_EXT)

# Source files
SRCS = main.c nextgen.c patterns.c

# Default target
all: $(OUTPUT)

# Build target
$(OUTPUT): $(SRCS)
	$(CC) $(SRCS) -o $(OUTPUT) $(LDFLAGS) $(LIBS) $(CFLAGS)

# Run the application
run: $(OUTPUT)
	./$(OUTPUT)

# Clean build artifacts
clean:
	$(RM) $(OUTPUT)

# Clear all previous compilations
clear:
	$(RM) $(OUTPUT)

.PHONY: all run clean clear
