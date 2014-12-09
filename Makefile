PLATFORM = i686-w64-mingw32
CC       = $(PLATFORM)-g++
SRCDIR   = src
BUILDDIR = build
TARGET   = bin/app

SRCEXT   = cpp
SOURCES  = $(wildcard  $(SRCDIR)/**/*.$(SRCEXT)) # $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS  = $(patsubstr %.$(SRCEXT), $(BUILDDIR)/%.o, $(SOURCES))
CFLAGS   = -g -Wall -std=c++11 -DDX_GCC_COMPILE -DDX_NON_INLINE_ASM
LIB      = -Llib/DxLib	-lDxLib \
						-lDxUseCLib \
						-lDxDrawFunc \
						-ljpeg \
						-lpng \
						-lzlib \
						-ltiff \
						-ltheora_static \
						-lvorbis_static \
						-lvorbisfile_static \
						-logg_static \
						-lbulletdynamics \
						-lbulletcollision \
						-lbulletmath \
						-mwindows

INC      = -Iinclude -Ilib/DxLib

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

