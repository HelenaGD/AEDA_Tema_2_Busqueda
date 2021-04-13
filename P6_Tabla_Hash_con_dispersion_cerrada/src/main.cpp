#include <iostream>

#include "tablahash.hpp"
#include "vector.hpp"
//#include "funciondispersion.hpp"
#include "fdmodulo.hpp"
#include "fdpseudoaleatoria.hpp"
//#include "funcionexploracion.hpp"
#include "felineal.hpp"
#include "fecuadratica.hpp"
#include "fedobledispersion.hpp"
#include "feredispersion.hpp"

#define INFINITO 999999

using Clave = int;

int RecogerCantidadPositiva(int cantidad_max = INFINITO) {
	int cantidad = 0;
	do {
		std::cout << "\nInput: ";
		std::cin >> cantidad;
	} while ((cantidad <= 0) && (cantidad > cantidad_max));
	return cantidad;
}

int main() {

	FuncionDispersion<Clave> *fd;
	FuncionExploracion<Clave> *fe;
	TablaHash<Clave> *tabla;

	int size_tabla = 0;
	int tipo_dispersion = 0;
	int tipo_exploracion = 0;
	int opcion = 0;
	int cantidad_sinonimos = 0;
	// int cantidad_iteraciones = 0;

	Clave elemento;

	std::cout << "\nIndique el tamaño de la tabla: ";
	size_tabla = RecogerCantidadPositiva();

	std::cout << "\nIndique la cantidad de sinonimos que se permiten en la tabla: ";
	cantidad_sinonimos = RecogerCantidadPositiva();
	
	// std::cout << "\nIndique la cantidad de iteraciones maximas: ";
	// cantidad_iteraciones = RecogerCantidadPositiva();

	std::cout << "\nIndique el tipo de función de dispersión a utilizar:\n"
						<< "(1) Función módulo\n(2) Función pseudoaleatoria\nOpción: ";
	tipo_dispersion = RecogerCantidadPositiva(2);

	switch (tipo_dispersion) {
		case 1:
			fd = new fdModulo<Clave>(size_tabla);
			break;
		case 2:
			fd = new fdPseudoaleatoria<Clave>(size_tabla);
	}

	std::cout << "\nIndique el tipo de función de exploración a utilizar:\n"
		<< "(1) Exploración Lineal\n(2) Exploración Cuadrática\n"
		<< "(3) Doble dispersión\n(4) Redispersión\nOpción: ";
	tipo_exploracion = RecogerCantidadPositiva(4);

	switch (tipo_exploracion) {
		case 1:
			fe = new feLineal<Clave>;
			break;
		case 2:
			fe = new feCuadratica<Clave>;
			break;
		case 3:
			fe = new feDobleDispersion<Clave>(fd);
			break;
		case 4:
			fe = new feReDispersion<Clave>;
			break;
	}

	tabla = new TablaHash<Clave>(size_tabla, cantidad_sinonimos, fd, fe);

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
				std::cout << "\nEl elemento no se ha podido insertar en la tabla\n";
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

		tabla->printTabla();

	} while (opcion != 0);

	//delete fd;
	delete tabla;
	//system("clear");
}