# Declaration of variables
CC = gcc
CC_FLAGS = -Wall -Wextra -g -std=c99
LD_FLAGS =

# File names
EXEC = main
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=$(BUILDDIR)/%.o)

# Directories
$(BUILDDIR) = build

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(LD_FLAGS)

# To obtain object files
%.o: %.c
	$(CC) -c $(CC_FLAGS) $< -o $(BUILDDIR)/$@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
