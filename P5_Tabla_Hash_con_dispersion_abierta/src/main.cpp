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

	int tamaño_tabla = 0;
	int tipo = 0;
	int opcion = 0;

	Clave elemento;

	do {
		std::cout << "Indique el tamaño de la tabla: ";
		std::cin >> tamaño_tabla;
	} while (tamaño_tabla <= 0);

	do {
		std::cout << "Indique el tipo de función de dispersión a utilizar: "
		<< "(1) Función módulo\n(2) Función pseudoaleatoria\nOpción: ";
		std::cin >> tipo;
	} while ((tipo <= 0) && (tipo >2));

	switch (tipo) {
		case 1:
			fd = new fdModulo<Clave>(tamaño_tabla);
			break;
		case 2:
			fd = new fdPseudoaleatoria<Clave>(tamaño_tabla);
	}

	tabla = new TablaHash<Clave>(tamaño_tabla, fd);

	do {
		std::cout << "Elija una opción: " <<
		"(0) Terminar programa\n(1) Insertar nuevo elemento\n" <<
		"(2) Buscar elemento\nOpción: ";
		std::cin >> opcion;

		switch (opcion) {
		case 1:
			std::cout << "Introduzca el elemento a insertar: ";
			std::cin >> elemento;
			if (tabla->Insertar(elemento)) {
				std::cout << "Se ha insertado el elemento\n";
			} else {
				std::cout << "El elemento ya pertenecía a la tabla\n";
			}
			break;
		
		case 2:
			std::cout << "Introduzca el elemento a buscar: ";
			std::cin >> elemento;
			if (tabla->Buscar(elemento)) {
				std::cout << "Se ha encontrado una coincidencia\n";
			} else {
				std::cout << "No se ha encontrado coincidencias\n";
			}
			break;
		
		default:
			break;
		}

	} while (opcion != 0);

}