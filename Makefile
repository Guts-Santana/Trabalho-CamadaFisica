all: Simulador.cpp   CamadaFisica.cpp CamadaFisica.hpp CamadaFisica.o
	g++ -std=c++11 -Wall CamadaFisica.o Simulador.cpp -o Simulador
	./Simulador

compile: Simulador.cpp   CamadaFisica.cpp CamadaFisica.hpp CamadaFisica.o
	g++ -std=c++11 -Wall CamadaFisica.o Simulador.cpp -o Simulador
	
test: Simulador.cpp
	./Simulador
	
cpplint: Simulador.cpp   CamadaFisica.cpp
	cpplint   --exclude=catch.hpp  *.*
	
debug: Simulador.cpp   CamadaFisica.cpp CamadaFisica.hpp 
	g++ -std=c++11 -Wall -Wall -g -c CamadaFisica.cpp
	g++ -std=c++11 -Wall  -g CamadaFisica.o Simulador.cpp -o Simulador
	gdb Simulador
	
	
cppcheck: Simulador.cpp   CamadaFisica.cpp CamadaFisica.hpp
	cppcheck  --enable=warning . 

CamadaFisica.o : CamadaFisica.cpp CamadaFisica.hpp
	g++ -std=c++11 -Wall -Wall -c CamadaFisica.cpp
	
Simulador: 	Simulador.cpp   CamadaFisica.cpp CamadaFisica.hpp Simulador.o
	g++ -std=c++11 -Wall CamadaFisica.o Simulador.cpp -o Simulador

clean:
	rm -rf *.o *.exe *.gc*
	
	