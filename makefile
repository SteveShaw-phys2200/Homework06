CC=gcc
# flags for compiling .c's
CFLAGS=-c -std=c99 -Wall
# flags for compiling .o's
OFLAGS=
# list of .h's
DEPS=hw06.h
# list of dependent .c's
SOURCES=hw06.c caesar.c
# .o's from .c's
OBJECTS=$(SOURCES:.c=.o)
# final binary produced is Midterm1
EXECUTABLE=hw06
# files to be deleted with clean
CLEANFILES= *.o *~

all: $(SOURCES) $(EXECUTABLE)
	# sucsess!

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OFLAGS) $(OBJECTS) -o $@

.c.o: $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -f $(CLEANFILES)
	# clean!

veryclean: clean
	rm -f $(EXECUTABLE)
	# squeky clean!
