SRCS += main.c
SRCS += dzkurs.c
APPNAME += dzkurs

all:
	gcc $(SRCS) -o $(APPNAME)

debug:
	gcc $(SRCS) -o $(APPNAME) -DDEBUG

clean:
	rm -f *.o $(APPNAME)
