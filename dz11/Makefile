SRCS += dz11_v1.c
LIBNAME += libdz11_v1.so

all:
	gcc $(SRCS) -o $(LIBNAME) -shared -fPIC

install:
	cp $(LIBNAME) /usr/lib
	cp dz11_v1.h /usr/include

uninstall:
	rm -f /usr/lib/$(LIBNAME) /usr/include/dz11_v1.h

clean:
	rm -f $(LIBNAME) *.o
