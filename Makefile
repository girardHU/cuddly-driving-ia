# set the compiler
CC := g++

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags` -lSDL2_image
# add header files here
HDRS := Game.hpp

# add source files here
SRCS := Game.cpp \
		TextureManager.cpp \
		GameObject.cpp \
		main.cpp

# generate names of object files
OBJS := $(SRCS:.c=.o)

# name of executable
EXEC := dev_program

# default recipe
all: $(EXEC)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#    $(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

.PHONY: all clean fclean