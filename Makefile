
CXXFLAGS += -I. -g -DDEBUG

all: cipherchallenge test_j3kf test_j3ktikk4 tunny_cmd

clean:
	-rm -f cipherchallenge test_j3ktikk4 test_j3kf
	-rm -f *.o

TUNNY_OBJECTS=teleprinter.o tunny.o

TEST_J3KF_OBJECTS=test_j3kf.o ${TUNNY_OBJECTS}

test_j3kf: ${TEST_J3KF_OBJECTS}
	${CXX} ${CXXFLAGS} ${TEST_J3KF_OBJECTS} -o $@

TEST_J3KTIKK4_OBJECTS=test_j3ktikk4.o ${TUNNY_OBJECTS}

test_j3ktikk4: ${TEST_J3KTIKK4_OBJECTS}
	${CXX} ${CXXFLAGS} ${TEST_J3KTIKK4_OBJECTS} -o $@

CIPHERCHALLENGE_OBJECTS=cipherchallenge.o ${TUNNY_OBJECTS}

cipherchallenge: ${CIPHERCHALLENGE_OBJECTS}
	${CXX} ${CXXFLAGS} ${CIPHERCHALLENGE_OBJECTS} -o $@

TUNNY_CMD_OBJECTS=tunny_cmd.o ${TUNNY_OBJECTS}

tunny_cmd: ${TUNNY_CMD_OBJECTS}
	${CXX} ${CXXFLAGS} ${TUNNY_CMD_OBJECTS} -o $@ \
		-lboost_program_options

depend:
	makedepend -f Makefile -Y. -I.  *.C

# DO NOT DELETE

teleprinter.o: ./colossus/teleprinter.h
test_j3kf.o: ./colossus/tunny.h ./colossus/teleprinter.h
test_j3ktikk4.o: ./colossus/tunny.h ./colossus/teleprinter.h
tunny.o: ./colossus/tunny.h ./colossus/teleprinter.h
