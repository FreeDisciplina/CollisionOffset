objects = randmaps.o
nmin?=12
nmax?=32
DEFINES = -DnMin=$(nmin) -DnMax=$(nmax)
CC = icpc
CFLAGS = -xHost -O3 -lippcp -lippcore -std=gnu++11 $(DEFINES)

collisions_n$(nmin)_n$(nmax) : collisions.cpp randmaps.cpp
	$(CC) $(CFLAGS) -c randmaps.cpp -o randmaps.o
	$(CC) $(CFLAGS) collisions.cpp randmaps.o -o collisions_n$(nmin)_n$(nmax)
	make clean


.PHONY:clean

clean:
	rm $(objects)