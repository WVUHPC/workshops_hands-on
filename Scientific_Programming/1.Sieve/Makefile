NMAX=100000000

all: soe_java soe_cxx soe_cpp soe_f90 

soe_java: SieveOfEratosthenes.class

soe_cxx: SieveOfEratosthenes_cxx

soe_f90: SieveOfEratosthenes_f90

soe_cpp: SieveOfEratosthenes_cpp

SieveOfEratosthenes.class: SieveOfEratosthenes.java
	module purge && module load compilers/java/jdk1.8.0 && javac $<

SieveOfEratosthenes_cxx: SieveOfEratosthenes.cxx
	module purge && module load compilers/gcc/6.3.0 && gcc $< -o $@

SieveOfEratosthenes_cpp: SieveOfEratosthenes.cpp
	module purge && module load compilers/gcc/6.3.0 && g++ $< -o $@

SieveOfEratosthenes_f90: SieveOfEratosthenes.f90
	module purge && module load compilers/gcc/6.3.0 && gfortran $< -o $@

clean:
	rm -rf *.class *.out *~ *_f90 *_cxx *_cpp

timing: SieveOfEratosthenes.class SieveOfEratosthenes_cxx SieveOfEratosthenes_cpp SieveOfEratosthenes.py SieveOfEratosthenes_f90
	@echo "R"
	module purge && module load compilers/R/3.4.1 && time ./SieveOfEratosthenes.R ${NMAX}
	@echo "Python"
	module purge && module load compilers/python/3.6.0 && time ./SieveOfEratosthenes.py  ${NMAX}
	@echo "Java"
	module purge && module load compilers/java/jdk1.8.0 && time java SieveOfEratosthenes  ${NMAX}
	@echo "C"
	module purge && module load compilers/gcc/6.3.0 && time ./SieveOfEratosthenes_cxx ${NMAX}
	@echo "C++"
	module purge && module load compilers/gcc/6.3.0 && time ./SieveOfEratosthenes_cpp ${NMAX}
	@echo "Fortran"
	module purge && module load compilers/gcc/6.3.0 && time ./SieveOfEratosthenes_f90 ${NMAX}
	@echo "Julia"
	module purge && module load compilers/julia/0.6.2 && time julia SieveOfEratosthenes.jl ${NMAX}
