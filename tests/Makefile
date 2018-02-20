CC=gcc
CXX=g++
CFLAGS=-O3 #-Wall -Wextra -Werror #-fopenmp -mavx -ffast-math 
LFLAGS=-lpng -ljpeg -ltiff -lm 

all: bin obj bin/test

bin:
	mkdir -p bin

obj:
	mkdir -p obj

obj/iio.o: ../src/iio.c ../src/iio.h
	$(CC) -c $< -o $@ -std=c99 $(CFLAGS) -Wno-unused -pedantic -DNDEBUG -D_GNU_SOURCE 

obj/gradient.o: ../src/gradient.cpp ../src/gradient.h
	$(CXX) -c $< -o $@ -std=c++11 $(CFLAGS) -Wno-unused -pedantic -DNDEBUG -D_GNU_SOURCE 

obj/gaussian.o: ../src/gaussian.cpp ../src/gaussian.h
	$(CXX) -c $< -o $@ -std=c++11 $(CFLAGS) -Wno-unused -pedantic -DNDEBUG -D_GNU_SOURCE 

obj/interpolation.o: ../src/interpolation.cpp ../src/interpolation.h
	$(CXX) -c $< -o $@ -std=c++11 $(CFLAGS) -Wno-unused -pedantic -DNDEBUG -D_GNU_SOURCE 

obj/harris.o: ../src/harris.cpp
	$(CXX) -c $< -o $@ -std=c++11 $(CFLAGS) -Wno-unused -pedantic -DNDEBUG -D_GNU_SOURCE 

obj/bicubic_interpolation.o: bicubic_interpolation.cpp
	$(CXX) -c $< -o $@ -std=c++11 $(CFLAGS) -Wno-unused -pedantic -DNDEBUG -D_GNU_SOURCE 


	
# ------- test -------
bin/test: test.cpp obj/bicubic_interpolation.o obj/harris.o obj/iio.o obj/gradient.o obj/gaussian.o obj/interpolation.o
	$(CXX) -std=c++11 -o $@ $^ $(CFLAGS) $(LFLAGS)

	
clean:
	rm -f obj/*.o bin/test
	rmdir bin obj