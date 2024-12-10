FC=gfortran
FFLAGS=-Wall -Wno-maybe-uninitialized -Wno-unused-function -static-libgfortran -flto
FOPT=-O3 -ftree-vectorize -fopt-info-vec

all:
	$(FC) $(FFLAGS) $(FOPT) -c src/DECOMP.F -J obj/ -o obj/DECOMP.o
	$(FC) $(FFLAGS) $(FOPT) -c src/QUANC8.F -J obj/ -o obj/QUANC8.o
	$(FC) $(FFLAGS) $(FOPT) -c src/SOLVE.F -J obj/ -o obj/SOLVE.o
	$(FC) $(FFLAGS) $(FOPT) -c src/ZEROIN.F -J obj/ -o obj/ZEROIN.o
	$(FC) $(FFLAGS) $(FOPT) -c src/FMIN.F -J obj/ -o obj/FMIN.o
	$(FC) $(FFLAGS) $(FOPT) -c src/SEVAL.F -J obj/ -o obj/SEVAL.o
	$(FC) $(FFLAGS) $(FOPT) -c src/SPLINE.F -J obj/ -o obj/SPLINE.o
	$(FC) $(FFLAGS) -c src/environment.f90 -J obj/ -o obj/environment.o
	$(FC) $(FFLAGS) $(FOPT) -c src/main.f90 -I obj/ -o obj/main.o

	$(FC) $(FFLAGS) $(FOPT) -o bin/app obj/main.o ./obj/environment.o obj/DECOMP.o obj/QUANC8.o obj/SOLVE.o  obj/ZEROIN.o obj/FMIN.o obj/SEVAL.o obj/SPLINE.o 
clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	cd ./bin; ./app;
