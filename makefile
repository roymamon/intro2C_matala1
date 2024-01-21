CC = gcc
AR = ar

CFLAGS = -Wall -g
LFLAGS = -shared
SFLAGS = rcs
FP = -fPIC

MAIN = main.c
HEADER = NumClass.h
LIBB = basicClassification.c
LIBLOOP = advancedClassificationLoop.c
LIBREC = advancedClassificationRecursion.c
LIBLS = libclassloops.a
LIBRS = libclassrec.a
LIBLD = libclassloops.so
LIBRD = libclassrec.so

.PHONY: all clean loops recursives recursived loopd

all: mains maindrec maindloop loops recursives recursived loopd

loops: $(LIBLS)

recursives: $(LIBRS)

recursived: $(LIBRD)

loopd: $(LIBLD)



	
mains: $(MAIN:.c=.o) $(LIBRS)
	$(CC) $(CFLAGS) $< ./$(LIBRS) -o $@

maindrec: $(MAIN:.c=.o) $(LIBRD)
	$(CC) $(CFLAGS) $< ./$(LIBRD) -o $@
	
maindloop: $(MAIN:.c=.o) $(LIBLD)
	$(CC) $(CFLAGS) $< ./$(LIBLD) -o $@



$(MAIN:.c=.o): $(MAIN) $(HEADER)
	$(CC) $(CFLAGS) -c $^

$(LIBRD): $(LIBREC:.c=.o) $(LIBB:.c=.o)
	$(CC) $(LFLAGS) $(CFLAGS) $^ -o $@

$(LIBLD): $(LIBLOOP:.c=.o) $(LIBB:.c=.o)
	$(CC) $(LFLAGS) $(CFLAGS) $^ -o $@

$(LIBLS): $(LIBLOOP:.c=.o) $(LIBB:.c=.o)
	$(AR) $(SFLAGS) $@ $^

$(LIBRS): $(LIBREC:.c=.o) $(LIBB:.c=.o)
	$(AR) $(SFLAGS) $@ $^

$(LIBLOOP:.c=.o): $(LIBLOOP) $(HEADER)
	$(CC) $(CFLAGS) -c $^ $(FP)

$(LIBREC:.c=.o): $(LIBREC) $(HEADER)
	$(CC) $(CFLAGS) -c $^ $(FP)

$(LIBB:.c=.o): $(LIBB) $(HEADER)
	$(CC) $(CFLAGS) -c $^ $(FP)

clean:
	rm -f mains maindloop maindrec *.o *.a *.so *.gch