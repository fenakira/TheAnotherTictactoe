PLATFORM = i686-w64-mingw32
CC       = $(PLATFORM)-g++
SRCDIR   = src
BUILDDIR = build
TARGET   = bin/app

SRCEXT   = cpp
SOURCES  = $(wildcard  $(SRCDIR)/**/*.$(SRCEXT)) # $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS  = $(patsubstr %.$(SRCEXT), $(BUILDDIR)/%.o, $(SOURCES))
CFLAGS   = -g -Wall
LIB      =
INC      = -I include

all: $(TARGET)

$(TARGET): build/main.o # $(OBJECTS)
	@echo Linking...
	@echo "$(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo Cleaning...
	@echo "$(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean