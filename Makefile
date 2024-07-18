OBJDIR = obj
ifeq (,$(wildcard $(OBJDIR)/.))
$(shell mkdir -p $(OBJDIR))
endif

SRCDIR = src
CC = gcc
SOURCES := $(wildcard $(SRCDIR)/*.c) main.c
# $(info source: '$(SOURCES)')
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(filter-out main.c, $(SOURCES))) $(OBJDIR)/main.o
# $(info obj: '$(OBJECTS)')
EXECUTABLE = main

CFLAGS = -c -Iinclude -g

all: $(EXECUTABLE)
	

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJDIR)/main.o: main.c
	$(CC) $(CFLAGS) $< -o $@

run: clean all
	./main | python3 python_files/display.py

clean:
	rm -f $(OBJECTS)
	@if [ -f a.out ]; then rm a.out; echo "a.out Removed"; fi
	@if [ -f main ]; then rm main; echo "main Removed"; fi
