CC = g++
HDIR = ./include 
SDIR = ./src
ODIR = ./obj
IDIR = -I./lib/CGF/include -I./lib/CGF/include/tmxloader -I./lib/CGF/include/pugixml -I./lib/Box2D-2.3.0/include -I./lib/SFML-2.2/include
LIBDIR = -L ./lib -L ./lib/Box2D-2.3.0/lib-Linux64/ -L ./lib/SFML-2.2/lib-Linux64 -L ./lib/glew-1.10

_DEPS = OptionsState.h PauseState.h PlayState.h MenuState.h
DEPS  = $(patsubst %,$(HDIR)/%,$(_DEPS))

_OBJ = main.o OptionsState.o PauseState.o PlayState.o MenuState.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

CFLAGS = -std=c++11 $(LIBDIR) -I$(HDIR) $(IDIR) -Wall -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lz -lBox2D -lCGF-Linux

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bananamen.game: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f bananamen.game
