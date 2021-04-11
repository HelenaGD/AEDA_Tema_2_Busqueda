#include <iostream>

#include "tablahash.hpp"
#include "lista.hpp"
#include "funciondispersion.hpp"
#include "fdmodulo.hpp"
#include "fdpseudoaleatoria.hpp"

int main() {

	using Clave = int;
	FuncionDispersion<Clave> *fd;
	TablaHash<Clave> *tabla;

	int size_tabla = 0;
	int tipo = 0;
	int opcion = 0;

	Clave elemento;

	do {
		std::cout << "\nIndique el tamaño de la tabla: ";
		std::cin >> size_tabla;
	} while (size_tabla <= 0);

	do {
		std::cout << "\nIndique el tipo de función de dispersión a utilizar:\n"
		<< "(1) Función módulo\n(2) Función pseudoaleatoria\nOpción: ";
		std::cin >> tipo;
	} while ((tipo <= 0) && (tipo >2));

	switch (tipo) {
		case 1:
			fd = new fdModulo<Clave>(size_tabla);
			break;
		case 2:
			fd = new fdPseudoaleatoria<Clave>(size_tabla);
	}

	tabla = new TablaHash<Clave>(size_tabla, fd);

	do {
		std::cout << "\nElija una opción: \n" <<
		"(0) Terminar programa\n(1) Insertar nuevo elemento\n" <<
		"(2) Buscar elemento\nOpción: ";
		std::cin >> opcion;

		switch (opcion) {
		case 1:
			std::cout << "\nIntroduzca el elemento a insertar: ";
			std::cin >> elemento;
			if (tabla->Insertar(elemento)) {
				std::cout << "\nSe ha insertado el elemento\n";
			} else {
				std::cout << "\nEl elemento ya pertenecía a la tabla\n";
			}
			break;
		
		case 2:
			std::cout << "\nIntroduzca el elemento a buscar: ";
			std::cin >> elemento;
			if (tabla->Buscar(elemento)) {
				std::cout << "\nSe ha encontrado una coincidencia\n";
			} else {
				std::cout << "\nNo se ha encontrado coincidencias\n";
			}
			break;
		
		default:
			break;
		}

	} while (opcion != 0);

	//delete fd;
	delete tabla;
	//system("clear");
}