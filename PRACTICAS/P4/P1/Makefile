##  /-------------------------------\
##  |                               |
##  |   CARLOS ANTONIO CORTÉS LORA  |
##  |                               |
##  \-------------------------------/



#Makefile P1

VPATH = ../Tests-auto:. ##ruta para los tests

CXX = clang++	#Compilador de C++

CPPFLAGS = -I../Tests-auto -I. -DP1       
CXXFLAGS = -g -Wall -pedantic -std=c++11 
#Reglas principales
all: test-P1-consola test-P1-auto

test: test-consola test-auto


check:
	make -f Make_check.mk check


#Reglas auxiliares
test-consola: test-P1-consola
	./$<

test-auto: test-P1-auto
	./$<

test-P1-consola: test-P1-consola.o fecha.o cadena.o
	$(CXX) $(CXXFLAGS) $^ -o $@

test-P1-consola.o: test-fechacadena-consola.cpp fecha.hpp cadena.hpp
	$(CXX) -c -DP1 $(CXXFLAGS) $< -o $@

test-P1-auto: test-caso0-fecha-auto.o test-caso0-cadena-auto.o test-auto.o cadena.o fecha.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS)  $^ -o $@

test-caso0-fecha-auto.o test-caso0-cadena-auto.o test-auto.o: \
	test-caso0-fecha-auto.cpp test-caso0-cadena-auto.cpp \
	test-auto.cpp test-auto.hpp fecha.hpp cadena.hpp

fecha.o: fecha.cpp fecha.hpp 
	$(CXX) -c $(CXXFLAGS) $< -o $@

cadena.o: cadena.cpp cadena.hpp
	$(CXX) -c $(CXXFLAGS) $< -o $@



#Regla para limpiar los archivos
clean:
	$(RM)	test-P1-consola.o test-caso0-fecha-auto.o \
	test-caso0-cadena-auto.o test-auto.o fecha.o cadena.o cadena_check.o fecha_check.o \
	test-P1-auto test-P1-consola cadena_check fecha_check



