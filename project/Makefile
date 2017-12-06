CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = quadris
OBJECTS = main.o block.o blockdot.o blocki.o blockj.o blockl.o blocks.o blockt.o blockz.o blocko.o cell.o commandinterpreter.o gameboard.o level.o level0.o level1.o level2.o level3.o level4.o pos.o quadris.o scoreboard.o subject.o textdisplay.o window.o graphicsdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11 

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean



