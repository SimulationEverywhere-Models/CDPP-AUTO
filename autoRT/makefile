.SUFFIXES : .cpp .o .c .y

include ../../Makefile.common


EXAMPLESOBJS=body.o chassis.o engineAss.o engineBody.o finalAss.o piston.o trans.o

ALLOBJS=${EXAMPLESOBJS} 
ALLSRCS=${ALLOBJS:.o=.cpp}

all: ${EXAMPLESOBJS} libauto.a

clean:
	- rm -f *.o *.a simu core drawlog initest exptest parser makerand toMap

depend:
	makedepend -Y ${ALLSRCS}

backup:
	tar -cvf simu.tar *.cpp *.h *.c *.y makefile* *.ma *.ev *.vpj *.bat *.txt *.val *.inc *.map; gzip simu.tar; mv simu.tar.gz simu.tgz

.cpp.o:
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} ${OPTCPPFLAGS} $<

libauto.a: ${EXAMPLESOBJS}
	ar crs libauto.a ${EXAMPLESOBJS}

.c.o:
	${CC} -c ${INCLUDES_C} ${DEFINES_C}  ${DEBUGFLAGS} ${CFLAGS} ${OPTCPPFLAGS} $<

.y.o:
	bison -d -v -o gram.c gram.y
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} ${OPTCPPFLAGS} ${@:.o=.c} 
	rm $*.c
	
# DO NOT DELETE
