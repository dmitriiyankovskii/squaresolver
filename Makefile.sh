DED_FLAGS="-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE"
PROG_NAME="quad"
FILES="In.o main.o Out.o run_tests.o shared.o solve.o unit_line_test.o unit_solve_test.o vari.o"

echo "Start compilation"

.PHONY: all clean

all: quad

clean:
	rm -rf quad *.o

In.o: In.cpp
    g++ In.cpp -c -o In.o $DED_FLAGS

main.o: main.cpp
    g++ main.cpp -c -o main.o $DED_FLAGS

Out.o: Out.cpp
    g++ Out.cpp -c -o Out.o $DED_FLAGS

run_tests.o: run_tests.cpp
    g++ run_tests.cpp -c -o run_tests.o $DED_FLAGS

shared.o: shared.cpp
    g++ shared.cpp -c -o shared.o $DED_FLAGS

solve.o: solve.cpp
    g++ solve.cpp -c -o solve.o $DED_FLAGS

unit_line_test.o: unit_line_test.cpp
    g++ unit_line_test.cpp -c -o unit_line_test.o $DED_FLAGS

unit_solve_test.o: unit_solve_test.cpp
    g++ unit_solve_test.cpp -c -o unit_solve_test.o $DED_FLAGS

vari.o: vari.cpp
    g++ vari.cpp -c -o vari.o $DED_FLAGS

$PROG_NAME: $FILES
    g++ -lm $FILES -o $PROG_NAME $DED_FLAGS

echo "End compilation"