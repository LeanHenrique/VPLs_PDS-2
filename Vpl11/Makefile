main: build/main.o build/Professor.o build/Funcionario.o build/Pessoa.o
	c++ -I include -std=c++17 build/main.o build/Professor.o build/Funcionario.o build/Pessoa.o -o vpl_execution

build/main.o: src/main.cpp
	c++ -I include -std=c++17 -c src/main.cpp -o build/main.o

build/Professor.o: src/entidades/Professor.cpp include/Professor.hpp
	c++ -I include -std=c++17 -c src/entidades/Professor.cpp -o build/Professor.o

build/Funcionario.o: src/entidades/Funcionario.cpp include/Funcionario.hpp
	c++ -I include -std=c++17 -c src/entidades/Funcionario.cpp -o build/Funcionario.o

build/Pessoa.o: src/entidades/Pessoa.cpp include/Pessoa.hpp
	c++ -I include -std=c++17 -c src/entidades/Pessoa.cpp -o build/Pessoa.o