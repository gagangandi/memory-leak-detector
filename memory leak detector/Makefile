
all: func mymalloc.so

func:
	gcc -o func func.c -g -L./ -lmymalloc

mymalloc.so:
	gcc -o libmymalloc.so list.c mymalloc.c -shared -fPIC
