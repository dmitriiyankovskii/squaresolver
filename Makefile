DED_FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
PROG_NAME = quad

.PHONY: all clean

all: output quad
	@echo "End compilation"

output:
	@echo "Start compilation"

clean:
	@rm -rf quad *.o

%.o: %.cpp
	@g++ $< -c -o $@ $(DED_FLAGS)

$(PROG_NAME): $(patsubst %.cpp, %.o, $(wildcard *.cpp))
	@g++ $^ -o $@ $(DED_FLAGS)
