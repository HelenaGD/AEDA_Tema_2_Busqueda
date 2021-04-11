#include <iostream>

#include "tablahash.hpp"
#include "lista.hpp"
#include "funciondispersion.hpp"
#include "fdmodulo.hpp"
#include "fdpseudoaleatoria.hpp"
#include "funcionexploracion.hpp"
#include "felineal.hpp"
#include "fecuadratica.hpp"
#include "fedobledispersion.hpp"
#include "feredispersion.hpp"


int main() {

	using Clave = int;
	FuncionDispersion<Clave> *fd;
	FuncionExploracion<Clave> *fe;
	TablaHash<Clave> *tabla;

	int size_tabla = 0;
	int tipo_dispersion = 0;
	int tipo_exploracion = 0;
	int opcion = 0;
	int size_position = 0;

	Clave elemento;

	do {
		std::cout << "\nIndique el tamaño de la tabla: ";
		std::cin >> size_tabla;
	} while (size_tabla <= 0);

	do {
		std::cout << "\nIndique el tamaño del vector: ";
		std::cin >> size_position;
	} while (size_position <= 0);

	do {
		std::cout << "\nIndique el tipo de función de dispersión a utilizar:\n"
		<< "(1) Función módulo\n(2) Función pseudoaleatoria\nOpción: ";
		std::cin >> tipo_dispersion;
	} while ((tipo_dispersion <= 0) && (tipo_dispersion >2));

	switch (tipo_dispersion) {
		case 1:
			fd = new fdModulo<Clave>(size_tabla);
			break;
		case 2:
			fd = new fdPseudoaleatoria<Clave>(size_tabla);
	}

	do {
		std::cout << "\nIndique el tipo de función de exploración a utilizar:\n"
		<< "(1) Exploración Lineal\n(2) Exploración Cuadrática\n"
		<< "(3) Doble dispersión\n(4) Redispersión\nOpción: ";
		std::cin >> tipo_exploracion;
	} while ((tipo_exploracion <= 0) && (tipo_exploracion > 4));

	switch (tipo_exploracion) {
		case 1:
			fe = new feLineal<Clave>(size_tabla);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
	}


	tabla = new TablaHash<Clave>(size_tabla, fd, size_position);

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