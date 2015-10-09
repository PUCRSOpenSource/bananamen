CC = g++
HDIR = ./include
SDIR = ./src
ODIR = ./obj
IDIR = -I./lib/CGF/include
IDIR += -I./lib/CGF/include/tmxloader
IDIR += -I./lib/CGF/include/pugixml
IDIR += -I./lib/Box2D-2.3.0/include
IDIR += -I./lib/SFML-2.2/include
LIBDIR = -L ./lib -L ./lib/Box2D-2.3.0/lib-Linux64/ -L ./lib/SFML-2.2/lib-Linux64 -L ./lib/glew-1.10
CFLAGS = -std=c++11 $(LIBDIR) -I$(HDIR) $(IDIR) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lz -lBox2D -lCGF-Linux


_DEPS = OptionsState.h PauseState.h PlayState.h MenuState.h
DEPS  = $(patsubst %,$(HDIR)/%,$(_DEPS))

_OBJ = Main.o OptionsState.o PauseState.o PlayState.o MenuState.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bananamen.game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY: clean

all : bananamen.game

clean:
	rm -f $(ODIR)/*.o
	rm -f bananamen.game
