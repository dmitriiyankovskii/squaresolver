DED_FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
PROG_NAME = quad
SOURCES = sources
OBJ = obj
HEADERS = C:\Users\d8388\vscode progs\quadro\headers
CC = g++
.PHONY: all clean

all: output $(PROG_NAME)
	@echo "End compilation"

output:
	@echo "Start compilation"

clean:
	@rm -rf quad *.o

	
$(OBJ)/%.o: $(SOURCES)/%.cpp 
	@$(CC) $< -c -o $@  $(DED_FLAGS)  -I $(HEADERS)

$(PROG_NAME): $(patsubst $(SOURCES)/%.cpp, $(OBJ)/%.o, $(wildcard $(SOURCES)/*.cpp))
	@$(CC) $^ -o $@ $(DED_FLAGS)
