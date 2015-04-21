
CXXFLAGS += -I. -g -DDEBUG

all: tunny vcolossus

clean:
	-rm -f tunny vcolossus
	-rm -f *.o

TUNNY_OBJECTS=teleprinter.o tunny.o

TUNNY_CMD_OBJECTS=tunny_cmd.o

COLOSSUS_OBJECTS=q_panel.o selection_panel.o colossus.o

COLOSSUS_CMD_OBJECTS=colossus_cmd.o

tunny: ${TUNNY_CMD_OBJECTS} ${TUNNY_OBJECTS}
	${CXX} ${CXXFLAGS} ${TUNNY_CMD_OBJECTS} ${TUNNY_OBJECTS} -o $@ \
		-lboost_program_options

vcolossus: ${COLOSSUS_CMD_OBJECTS} ${COLOSSUS_OBJECTS} ${TUNNY_OBJECTS}
	${CXX} ${CXXFLAGS} ${COLOSSUS_CMD_OBJECTS} ${COLOSSUS_OBJECTS} \
		${TUNNY_OBJECTS} -o $@ \
		-lboost_program_options

depend:
	makedepend -f Makefile -Y. -I.  *.C

# DO NOT DELETE

colossus.o: ./colossus/colossus.h ./colossus/elemental.h
colossus.o: ./colossus/teleprinter.h ./colossus/tunny.h
colossus.o: ./colossus/paper_tape.h ./colossus/selection_panel.h
colossus.o: ./colossus/q_panel.h ./colossus/counting_unit.h
colossus_cmd.o: ./colossus/teleprinter.h ./colossus/tunny.h
colossus_cmd.o: ./colossus/elemental.h
teleprinter.o: ./colossus/teleprinter.h
tunny.o: ./colossus/tunny.h ./colossus/teleprinter.h ./colossus/elemental.h
tunny_cmd.o: ./colossus/teleprinter.h ./colossus/tunny.h
tunny_cmd.o: ./colossus/elemental.h
