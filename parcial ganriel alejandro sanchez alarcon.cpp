#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include <locale.h>

using namespace std;

ofstream entrada;
ifstream salida;

int precio2d = 10000, precio3d, precio4d, precio4dh = 100000;
int cont12 = 0;
int k = 1;
int p = 0;
int i, j, siguiente;
string nom, apel, tipdoc, dir;
int fecha, fil, col, sal, pis, ocup, entradas;
long long ced, tel;

struct reservasvariable
{
	int cantentradas;
	int valortotal;

} reservas;

struct datoscliente
{

	string nombre;
	string apellido;
	string tipodocumento;
	long long numdocumento;
	int fechanacimiento;
	string direccion;
	long long telefono;
	int ocupacion;
	int fila;
	int columna;
	int piso;
	int sala;
	int cantentradas;

} datosclientesala1p1_2D[15][15],
	datosclientesala2p1_2D[15][15],
	datosclientesala3p2_2D[15][15],
	datosclientesala4p2_2D[15][15],
	datosclientesala5p2_2D[15][15],
	datosclientesala6p2_2D[15][15],
	datosclientesala7p3_3D[15][15],
	datosclientesala8p3_3D[15][15],
	datosclientesala9p3_3D[15][15],
	datosclientesala10p3_3D[15][15],
	datosclientesala11p4_4D[30][30],
	datosclientesala12p4_4D[30][30],
	datosclientesala12p4_4Dh[30][30],

	datoscliente[3000], aux, x,
	cancelaciones[1000];

void sala1p1_2D();
void sala2p1_2D();
void sala3p2_2D();
void sala4p2_2D();
void sala5p2_2D();
void sala6p2_2D();
void sala7p3_3D();
void sala8p3_3D();
void sala9p3_3D();
void sala10p3_3D();
void sala11p4_4D();
void sala12p4_4D();
void sala12p4_4Dh();
void consreservas();
void listaprecios();
void reservaentrada();
void cartelera();
void cancelacion();
void listareservas();
void listacancelaciones();
void seleccion();
void ordenamientoC();
void imprimirLista();
void pasardatos();
void listaclientes();
void ordenamientoN();
void busquedaporcedula();
void guardarclientes();
void recuperardatos();

int main()
{
	setlocale(LC_ALL, "spanish");

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			datosclientesala1p1_2D[i][j].ocupacion = 0;
			datosclientesala2p1_2D[i][j].ocupacion = 0;
			datosclientesala3p2_2D[i][j].ocupacion = 0;
			datosclientesala4p2_2D[i][j].ocupacion = 0;
			datosclientesala5p2_2D[i][j].ocupacion = 0;
			datosclientesala6p2_2D[i][j].ocupacion = 0;
			datosclientesala7p3_3D[i][j].ocupacion = 0;
			datosclientesala8p3_3D[i][j].ocupacion = 0;
			datosclientesala9p3_3D[i][j].ocupacion = 0;
			datosclientesala10p3_3D[i][j].ocupacion = 0;
		}
	}

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{

			datosclientesala11p4_4D[i][j].ocupacion = 0;
			datosclientesala12p4_4D[i][j].ocupacion = 0;
			datosclientesala12p4_4Dh[i][j].ocupacion = 0;
		}
	}

	recuperardatos();

	int opc, x = 1;

	while (x == 1)
	{

		cout << "====================================================" << endl;
		cout << "=====---Bienvenidos al Menu de Cine Polombia---=====" << endl;
		cout << "====================================================" << endl;

		cout << "\n-----------Escoja la opcion ha consultar--------------" << endl;

		cout << "\n 1. Consultar Precios de Entrada a las Salas" << endl;

		cout << "\n 2. Reservar Entradas al Cine" << endl;

		cout << "\n 3. Buscar informacionn del Cliente" << endl;

		cout << "\n 4. Consultar Peliculas en Cartelera" << endl;

		cout << "\n 5. Cancelacion de Reservas" << endl;

		cout << "\n 6. listado de Reservas" << endl;

		cout << "\n 7. Listado de Cancelaciones" << endl;

		cout << "\n 8. Salir" << endl;

		cout << "\n-------Digite la opcion para Continuar------\n";
		cin >> opc;
		system("cls");
		switch (opc)
		{

		case 1:
			listaprecios();

			break;

		case 2:
			reservaentrada();

			break;

		case 3:
			cout << "Busqueda de cliente por cedula" << endl;
			pasardatos();
			ordenamientoC();
			busquedaporcedula();

			break;

		case 4:
			cartelera();

			break;

		case 5:
			cancelacion();

			break;
		case 6:
			cout << "Lista de empleados se mostrara por alfabetico de los Nombres" << endl;

			pasardatos();
			ordenamientoN();
			listaclientes();

			break;

		case 7:
			listacancelaciones();

			break;

		case 8:
			guardarclientes();

			cout << "Gracias por Visitar el Programa" << endl;

			return EXIT_SUCCESS;

		default:
			cout << "\nLa opcion que marcaste no es valida" << endl;

			break;
		}
		cout << "\nDesea regresar al menu?" << endl;
		cout << "\n1.si" << endl;
		cout << "\n2.no \n\n";
		cin >> opc;
		system("cls");
		if (opc == 2)
		{
			x = 2;
			guardarclientes();
			cout << "\nGRACIAS POR VISITARNOS Y SER PARTE DE LA FAMILIA DE CINE POLOMBIA " << endl;
		}
	}

	getch();
	return 0;
}

void listaprecios()
{

	cout << "\n--------------- Bienvenido a la Opcion de Precios------------------" << endl;

	cout << "\n--------precio para salas 2D------" << endl;

	cout << "\nLunes a Domingos: " << precio2d << " " << endl;

	cout << "\n--------precio para salas 3D------" << endl;
	precio3d = precio2d * 0.40;
	precio3d += precio2d;
	cout << "\nLunes a domingo: " << precio3d << " " << endl;

	cout << "\n--------precio para salas 4D------" << endl;
	precio4d = precio2d * 0.80;
	precio4d += precio2d;
	cout << "\nLunes a domingo: " << precio4d << " " << endl;

	cout << "\n--------Alquiler de sala 4D------" << endl;

	cout << "\nEl alquiler de las salas 4D para eventos privados tendra un precio de (" << precio4dh << ") por hora " << endl;
}

void reservaentrada()
{
	int opc1, opc2, opc3, opc4, opc5, opc6, opc7, opc8;
	int a, b;
	cout << "\n--------------- Bienvenido a la Opcion de Reservas------------------\n";

	do
	{
		system("cls");
		cout << "\nEscoje en que calidad quieres ver la peli: (2D,3D,4D) ";
		cout << "\n1. 2D.";
		cout << "\n2. 3D.";
		cout << "\n3. 4D.";
		cout << "\nEscoje la opcion deseada: ";
		cin >> opc1;
		system("cls");
		switch (opc1)
		{

		case 1:
			fflush(stdin);
			cout << "\nPiso en el que desea reservar en salas 2D:";
			cout << "\n1. piso 1  ";
			cout << "\n2. piso 2 ";
			cout << "\nEscoja: ";
			cin >> opc2;
			system("cls");
			switch (opc2)
			{

			case 1:

				cout << "\nEscoja la sala.";
				cout << "\n1. Sala 1";
				cout << "\n2. Sala 2";
				cout << "\nEscoja: ";
				cin >> opc3;
				system("cls");
				switch (opc3)
				{

				case 1:

					sala1p1_2D();
					break;

				case 2:

					sala2p1_2D();

					break;

				default:
					cout << "\nOpcion no permitida.";
					break;
				}
				break;

			case 2:
				cout << "\nEscoja la sala.";
				cout << "\n3. Sala 3";
				cout << "\n4. Sala 4";
				cout << "\n5. Sala 5";
				cout << "\n6. Sala 6";
				cout << "\nEscoja: ";
				cin >> opc4;
				system("cls");
				switch (opc4)
				{

				case 3:

					sala3p2_2D();

					break;

				case 4:

					sala4p2_2D();

					break;

				case 5:

					sala5p2_2D();

					break;

				case 6:

					sala6p2_2D();

					break;

				default:
					cout << "\nOpcion no permitida.";
				}
			}

			break;

		case 2:
			cout << "\nEscoja la sala.";
			cout << "\n7. Sala 7";
			cout << "\n8. Sala 8";
			cout << "\n9. Sala 9";
			cout << "\n10. Sala 10";
			cout << "\nEscoja: ";
			cin >> opc5;
			system("cls");
			switch (opc5)
			{

			case 7:

				sala7p3_3D();

				break;

			case 8:

				sala8p3_3D();

				break;

			case 9:

				sala9p3_3D();

				break;

			case 10:

				sala10p3_3D();

				break;

			default:
				cout << "\nOpcion no permitida.";

				break;
			}

			break;

		case 3:
			cout << "\nEscoja la sala.";
			cout << "\n11. Sala 11";
			cout << "\n12. Sala 12";
			cout << "\nEscoja: ";
			cin >> opc6;
			system("cls");
			switch (opc6)
			{

			case 11:

				sala11p4_4D();

				break;

			case 12:
				cout << "\nLa sala 12 la quiere alquilar o reservar un asiento";
				cout << "\n1. Reservar";
				cout << "\n2. Alquilar";
				cout << "\nEscoja: ";
				cin >> opc7;
				system("cls");
				switch (opc7)
				{

				case 1:

					sala12p4_4D();

					break;

				case 2:

					sala12p4_4Dh();

					break;

				default:
					cout << "\nOpcion no permitida.";

					break;
				}

				break;

			default:
				cout << "\nOpcion no permitida.";

				break;
			}
			break;

		default:
			cout << "\n************ OPCION INVALIDA **************** ";

			break;
		}

		fflush(stdin);
		cout << "\nDesea volver a intentarlo?\n\n";
		cout << "1. Para si\n";
		cout << "2. Para no";
		cout << "\n\nOpcion: ";
		fflush(stdin);
		cin >> opc8;

	} while ((opc8 == 1));
}

void consreservas()
{

	int cont = 0;
	int id;
	int opc;
	fflush(stdin);

	do
	{

		system("cls");
		cont = 0;

		cout << "\n--------------- Bienvenido a la Opcion de Consulta de Reservas------------------" << endl;
		cout << "\nIngrese el numero de documento del cliente a consultar: ";
		cin >> id;
		fflush(stdin);

		for (int x = 0; x < 15; x++)
		{
			for (int y = 0; y < 15; y++)
			{
				if (id == datosclientesala1p1_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos: \n\n";
					cout << "\nNombre: " << datosclientesala1p1_2D[x][y].nombre;
					cout << "\nApellido: " << datosclientesala1p1_2D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala1p1_2D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala1p1_2D[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala1p1_2D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala1p1_2D[x][y].direccion;
					cout << "\nTelefono: " << datosclientesala1p1_2D[x][y].telefono;
					cout << "\n\nReservo Pelicula 2D";
					cout << "\nPiso: " << datosclientesala1p1_2D[x][y].piso;
					cout << "\nSala: " << datosclientesala1p1_2D[x][y].sala;
					cout << "\nFila: " << datosclientesala1p1_2D[x][y].fila;
					cout << "\nColumna: " << datosclientesala1p1_2D[x][y].columna;
					cout << "\nPago: $" << precio2d;
					cout << "\n";

					cont++;
				}
				if (id == datosclientesala2p1_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala2p1_2D[x][y].nombre;
					cout << "\nApellido: " << datosclientesala2p1_2D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala2p1_2D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala2p1_2D[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala2p1_2D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala2p1_2D[x][y].direccion;
					cout << "\nTelefono: " << datosclientesala2p1_2D[x][y].telefono;
					cout << "\n\nReservo Pelicula 2D";
					cout << "\nPiso: " << datosclientesala2p1_2D[x][y].piso;
					cout << "\nSala: " << datosclientesala2p1_2D[x][y].sala;
					cout << "\nFila: " << datosclientesala2p1_2D[x][y].fila;
					cout << "\nColumna: " << datosclientesala2p1_2D[x][y].columna;
					cout << "\nPago: $" << precio2d;
					cout << "\n";

					cont++;
				}
				if (id == datosclientesala3p2_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala3p2_2D[x][y].nombre;
					cout << "\nApellido: " << datosclientesala3p2_2D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala3p2_2D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala3p2_2D[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala3p2_2D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala3p2_2D[x][y].direccion;
					cout << "\nTelefono: " << datosclientesala3p2_2D[x][y].telefono;
					cout << "\n\nReservo Pelicula 2D";
					cout << "\nPiso: " << datosclientesala3p2_2D[x][y].piso;
					cout << "\nSala: " << datosclientesala3p2_2D[x][y].sala;
					cout << "\nFila: " << datosclientesala3p2_2D[x][y].fila;
					cout << "\nColumna: " << datosclientesala3p2_2D[x][y].columna;
					cout << "\nPago: $" << precio2d;
					cout << "\n";

					cont++;
				}
				if (id == datosclientesala4p2_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala4p2_2D[x][y].nombre;
					cout << "\nApellido: " << datosclientesala4p2_2D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala4p2_2D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala4p2_2D[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala4p2_2D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala4p2_2D[x][y].direccion;
					cout << "\nTelefono: " << datosclientesala4p2_2D[x][y].telefono;
					cout << "\n\nReservo Pelicula 2D";
					cout << "\nPiso: " << datosclientesala4p2_2D[x][y].piso;
					cout << "\nSala: " << datosclientesala4p2_2D[x][y].sala;
					cout << "\nFila: " << datosclientesala4p2_2D[x][y].fila;
					cout << "\nColumna: " << datosclientesala4p2_2D[x][y].columna;
					cout << "\nPago: $" << precio2d;
					cout << "\n";

					cont++;
				}
				if (id == datosclientesala5p2_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala5p2_2D[x][y].nombre;
					cout << "\nApellido: " << datosclientesala5p2_2D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala5p2_2D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala5p2_2D[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala5p2_2D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala5p2_2D[x][y].direccion;
					cout << "\nTelefono: " << datosclientesala5p2_2D[x][y].telefono;
					cout << "\n\nReservo Pelicula 2D";
					cout << "\nPiso: " << datosclientesala5p2_2D[x][y].piso;
					cout << "\nSala: " << datosclientesala5p2_2D[x][y].sala;
					cout << "\nFila: " << datosclientesala5p2_2D[x][y].fila;
					cout << "\nColumna: " << datosclientesala5p2_2D[x][y].columna;
					cout << "\nPago: $" << precio2d;
					cout << "\n";

					cont++;
				}
				if (id == datosclientesala6p2_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala6p2_2D[x][y].nombre;
					cout << "\nNombre: " << datosclientesala6p2_2D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala6p2_2D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala6p2_2D[x][y].numdocumento;
					cout << "\nNombre completo: " << datosclientesala6p2_2D[x][y].nombre;
					cout << "\nFecha de nacimiento: " << datosclientesala6p2_2D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala6p2_2D[x][y].direccion;
					cout << "\nTelefono: " << datosclientesala6p2_2D[x][y].telefono;
					cout << "\n\nReservo Pelicula 2D";
					cout << "\nPiso: " << datosclientesala6p2_2D[x][y].piso;
					cout << "\nSala: " << datosclientesala6p2_2D[x][y].sala;
					cout << "\nFila: " << datosclientesala6p2_2D[x][y].fila;
					cout << "\nColumna: " << datosclientesala6p2_2D[x][y].columna;
					cout << "\nPago: $" << precio2d;
					cout << "\n";

					cont++;
				}
				if (id == datosclientesala7p3_3D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala7p3_3D[x][y].nombre;
					cout << "\nNombre: " << datosclientesala7p3_3D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala7p3_3D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala7p3_3D[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala7p3_3D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala7p3_3D[x][y].direccion;
					cout << "\nTelefono: " << datosclientesala7p3_3D[x][y].telefono;
					cout << "\n\nReservo Pelicula 3D";
					cout << "\nPiso: " << datosclientesala7p3_3D[x][y].piso;
					cout << "\nSala: " << datosclientesala7p3_3D[x][y].sala;
					cout << "\nFila: " << datosclientesala7p3_3D[x][y].fila;
					cout << "\nColumna: " << datosclientesala7p3_3D[x][y].columna;
					cout << "\nPago: $" << precio3d;
					cout << "\n";

					cont++;
				}

				if (id == datosclientesala8p3_3D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala8p3_3D[x][y].nombre;
					cout << "\nApellido: " << datosclientesala8p3_3D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala8p3_3D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala8p3_3D[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala8p3_3D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala8p3_3D[x][y].direccion;
					cout << "\nTelefono: " << datosclientesala8p3_3D[x][y].telefono;
					cout << "\n\nReservo Pelicula 3D";
					cout << "\nPiso: " << datosclientesala8p3_3D[x][y].piso;
					cout << "\nSala: " << datosclientesala8p3_3D[x][y].sala;
					cout << "\nFila: " << datosclientesala8p3_3D[x][y].fila;
					cout << "\nColumna: " << datosclientesala8p3_3D[x][y].columna;
					cout << "\nPago: $" << precio3d;
					cout << "\n";

					cont++;
				}
				if (id == datosclientesala9p3_3D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala9p3_3D[x][y].nombre;
					cout << "\nNombre: " << datosclientesala9p3_3D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala9p3_3D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala9p3_3D[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala9p3_3D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala9p3_3D[x][y].direccion;
					cout << "\nTelefono: " << datosclientesala9p3_3D[x][y].telefono;
					cout << "\n\nReservo Pelicula 3D";
					cout << "\nPiso: " << datosclientesala9p3_3D[x][y].piso;
					cout << "\nSala: " << datosclientesala9p3_3D[x][y].sala;
					cout << "\nFila: " << datosclientesala9p3_3D[x][y].fila;
					cout << "\nColumna: " << datosclientesala9p3_3D[x][y].columna;
					cout << "\nPago: $" << precio3d;
					cout << "\n";

					cont++;
				}

				if (id == datosclientesala10p3_3D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala10p3_3D[x][y].nombre;
					cout << "\nApellido: " << datosclientesala10p3_3D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala10p3_3D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala10p3_3D[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala10p3_3D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala10p3_3D[x][y].direccion;
					cout << "\nTelefono: " << datosclientesala10p3_3D[x][y].telefono;
					cout << "\n\nReservo Pelicula 3D";
					cout << "\nPiso: " << datosclientesala10p3_3D[x][y].piso;
					cout << "\nSala: " << datosclientesala10p3_3D[x][y].sala;
					cout << "\nFila: " << datosclientesala10p3_3D[x][y].fila;
					cout << "\nColumna: " << datosclientesala10p3_3D[x][y].columna;
					cout << "\nPago: $" << precio3d;
					cout << "\n";

					cont++;
				}
			}
		}

		for (int x = 0; x < 30; x++)
		{
			for (int y = 0; y < 30; y++)
			{

				if (id == datosclientesala11p4_4D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala11p4_4D[x][y].nombre;
					cout << "\nApellido: " << datosclientesala11p4_4D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala11p4_4D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala11p4_4D[x][y].numdocumento;
					cout << "\nNombre completo: " << datosclientesala11p4_4D[x][y].nombre;
					cout << "\nFecha de nacimiento: " << datosclientesala11p4_4D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala11p4_4D[x][y].direccion;
					fflush(stdin);
					cout << "\nTelefono: " << datosclientesala11p4_4D[x][y].telefono;
					fflush(stdin);
					cout << "\n\nReservo Pelicula 4D";
					cout << "\nPiso: " << datosclientesala11p4_4D[x][y].piso;
					cout << "\nSala: " << datosclientesala11p4_4D[x][y].sala;
					cout << "\nFila: " << datosclientesala11p4_4D[x][y].fila;
					cout << "\nColumna: " << datosclientesala11p4_4D[x][y].columna;
					cout << "\nPago: $" << precio4d;
					cout << "\n";

					cont++;
				}

				if (id == datosclientesala12p4_4Dh[x][y].numdocumento)
				{
					fflush(stdin);
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala12p4_4Dh[x][y].nombre;
					cout << "\nNombre: " << datosclientesala12p4_4Dh[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala12p4_4Dh[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala12p4_4Dh[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala12p4_4Dh[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala12p4_4Dh[x][y].direccion;
					fflush(stdin);
					cout << "\nTelefono: " << datosclientesala12p4_4Dh[x][y].telefono;

					cout << "\n\nReservo un evento en sala 4D:";
					cout << "\nPiso: " << datosclientesala12p4_4Dh[x][y].piso;
					cout << "\nSala: " << datosclientesala12p4_4Dh[x][y].sala;
					cout << "\nDuracion: " << reservas.cantentradas << " Horas";
					cout << "\nPago: $" << reservas.valortotal;
					cout << "\n";

					cont++;
				}

				if (id == datosclientesala12p4_4D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nDatos:\n\n";
					cout << "\nNombre: " << datosclientesala12p4_4D[x][y].nombre;
					cout << "\nApellido: " << datosclientesala12p4_4D[x][y].apellido;
					cout << "Tipo de documento: " << datosclientesala12p4_4D[x][y].tipodocumento;
					cout << "\nNumero de documento: " << datosclientesala12p4_4D[x][y].numdocumento;
					cout << "\nFecha de nacimiento: " << datosclientesala12p4_4D[x][y].fechanacimiento;
					cout << "\nDireccion: " << datosclientesala12p4_4D[x][y].direccion;
					fflush(stdin);
					cout << "\nTelefono: " << datosclientesala12p4_4D[x][y].telefono;
					fflush(stdin);
					cout << "\n\nReservo Pelicula 4D";
					cout << "\nPiso: " << datosclientesala12p4_4D[x][y].piso;
					cout << "\nSala: " << datosclientesala12p4_4D[x][y].sala;
					cout << "\nFila: " << datosclientesala12p4_4D[x][y].fila;
					cout << "\nColumna: " << datosclientesala12p4_4D[x][y].columna;
					cout << "\nPago: $" << precio4d;
					cout << "\n";

					cont++;
				}
			}
		}

		if (cont == 0)
		{
			fflush(stdin);
			cout << "\n\n\tUSUARIO NO ENCONTRADO\n\n";
		}
		fflush(stdin);
		cout << "\nDesea volver a intentarlo?\n\n";
		cout << "1. Para si\n";
		cout << "2. Para no";
		cout << "\n\nOpcion: ";
		fflush(stdin);
		cin >> opc;

	} while ((opc == 1));
}

void cartelera()
{
	cout << "\n--------------- Bienvenido a la Opcion de Carteleras------------------" << endl;

	cout << "\n ****** ( El Avispon Verde ) ******* quedan 2 semanas disponible" << endl;
	cout << "\n ****** ( Titanes del Pacifico ) ******* quedan 3 dias disponible" << endl;
	cout << "\n ****** ( A 2 metros de Ti ) ******* quedan 7 dias disponible" << endl;
	cout << "\n ****** ( La Dama y el Vagabundo ) ******* quedan 1 dia disponible" << endl;
}

void sala1p1_2D()
{

	int cont = 0, a, b;
	if (cont <= 156)
	{

		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14  \n";
		for (int i = 0; i <= 14; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 14; j++)
			{
				cout << datosclientesala1p1_2D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre : ";
		getline(cin, datosclientesala1p1_2D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido : ";
		getline(cin, datosclientesala1p1_2D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala1p1_2D[a][b].tipodocumento, '\n');
		cin.ignore();
		cout << "\nNumero del documento: ";
		cin >> datosclientesala1p1_2D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala1p1_2D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala1p1_2D[a][b].direccion, '\n');
		cin.ignore();

		cout << "\nTelefono: ";
		cin >> datosclientesala1p1_2D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala1p1_2D[a][b].ocupacion = 1;
		datosclientesala1p1_2D[a][b].fila = a;
		datosclientesala1p1_2D[a][b].columna = b;
		datosclientesala1p1_2D[a][b].piso = 1;
		datosclientesala1p1_2D[a][b].sala = 1;
		system("cls");

		precio2d;
		cout << "\nValor Total a Pagar: " << precio2d;
	}
	else
	{

		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala2p1_2D()
{
	int cont = 0, a, b;
	if (cont <= 156)
	{
		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";

		cout << "\n  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14  \n";
		for (int i = 0; i <= 14; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 14; j++)
			{
				cout << datosclientesala2p1_2D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala2p1_2D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido ";
		getline(cin, datosclientesala2p1_2D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala2p1_2D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala2p1_2D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala2p1_2D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala2p1_2D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala2p1_2D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala2p1_2D[a][b].ocupacion = 1;
		datosclientesala2p1_2D[a][b].fila = a;
		datosclientesala2p1_2D[a][b].columna = b;
		datosclientesala2p1_2D[a][b].piso = 1;
		datosclientesala2p1_2D[a][b].sala = 2;

		system("cls");
		precio2d;
		cout << "\nValor Total a Pagar: " << precio2d;
	}
	else
	{
		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala3p2_2D()
{

	int cont = 0, a, b;
	if (cont <= 156)
	{
		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n 0  1  2 3 4 5 6 7 8 9 10 11 12 13 14  \n";
		for (int i = 0; i <= 14; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 14; j++)
			{
				cout << datosclientesala3p2_2D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala3p2_2D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala3p2_2D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala3p2_2D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala3p2_2D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala3p2_2D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala3p2_2D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala3p2_2D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala3p2_2D[a][b].ocupacion = 1;
		datosclientesala3p2_2D[a][b].fila = a;
		datosclientesala3p2_2D[a][b].columna = b;
		datosclientesala3p2_2D[a][b].piso = 2;
		datosclientesala3p2_2D[a][b].sala = 3;
		system("cls");
		precio2d;
		cout << "\nValor Total a Pagar: " << precio2d;
	}
	else
	{
		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala4p2_2D()
{

	int cont = 0, a, b;
	if (cont <= 156)
	{
		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n  0  1  2 3 4 5 6 7 8 9 10 11 12 13 14  \n";
		for (int i = 0; i <= 14; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 14; j++)
			{
				cout << datosclientesala4p2_2D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre Completo: ";
		getline(cin, datosclientesala4p2_2D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala4p2_2D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala4p2_2D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala4p2_2D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala4p2_2D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala4p2_2D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala4p2_2D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala4p2_2D[a][b].ocupacion = 1;
		datosclientesala4p2_2D[a][b].fila = a;
		datosclientesala4p2_2D[a][b].columna = b;
		datosclientesala4p2_2D[a][b].piso = 2;
		datosclientesala4p2_2D[a][b].sala = 4;
		system("cls");

		precio2d;
		cout << "\nValor Total a Pagar: " << precio2d;
	}
	else
	{
		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala5p2_2D()
{

	int cont = 0, a, b;
	if (cont <= 156)
	{
		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n  0  1  2 3 4 5 6 7 8 9 10 11 12 13 14  \n";
		for (int i = 0; i <= 14; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 14; j++)
			{
				cout << datosclientesala5p2_2D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala5p2_2D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala5p2_2D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala5p2_2D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala5p2_2D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala5p2_2D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala5p2_2D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala5p2_2D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala5p2_2D[a][b].ocupacion = 1;
		datosclientesala5p2_2D[a][b].fila = a;
		datosclientesala5p2_2D[a][b].columna = b;
		datosclientesala5p2_2D[a][b].piso = 2;
		datosclientesala5p2_2D[a][b].sala = 5;
		system("cls");

		precio2d;
		cout << "\nValor Total a Pagar: " << precio2d;
	}
	else
	{
		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala6p2_2D()
{

	int cont = 0, a, b;
	if (cont <= 156)
	{

		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n  0  1  2 3 4 5 6 7 8 9 10 11 12 13 14  \n";
		for (int i = 0; i <= 14; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 14; j++)
			{
				cout << datosclientesala6p2_2D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala6p2_2D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala6p2_2D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala6p2_2D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala6p2_2D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala6p2_2D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala6p2_2D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala6p2_2D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala6p2_2D[a][b].ocupacion = 1;
		datosclientesala6p2_2D[a][b].fila = a;
		datosclientesala6p2_2D[a][b].columna = b;
		datosclientesala6p2_2D[a][b].piso = 2;
		datosclientesala6p2_2D[a][b].sala = 6;
		system("cls");

		precio2d;
		cout << "\nValor Total a Pagar: " << precio2d;
	}
	else
	{

		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala7p3_3D()
{

	int cont = 0, a, b;
	if (cont <= 156)
	{

		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n  0  1  2 3 4 5 6 7 8 9 10 11 12 13 14  \n";
		for (int i = 0; i <= 14; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 14; j++)
			{
				cout << datosclientesala7p3_3D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala7p3_3D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala7p3_3D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala7p3_3D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala7p3_3D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala7p3_3D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala7p3_3D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala7p3_3D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala7p3_3D[a][b].ocupacion = 1;
		datosclientesala7p3_3D[a][b].fila = a;
		datosclientesala7p3_3D[a][b].columna = b;
		datosclientesala7p3_3D[a][b].piso = 3;
		datosclientesala7p3_3D[a][b].sala = 7;
		system("cls");
		precio3d = precio2d * 0.40;
		precio3d += precio2d;

		cout << "\nValor Total a Pagar: " << precio3d;
	}
	else
	{
		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala8p3_3D()
{

	int cont = 0, a, b;
	if (cont <= 156)
	{

		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n  0  1  2 3 4 5 6 7 8 9 10 11 12 13 14  \n";
		for (int i = 0; i <= 14; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 14; j++)
			{
				cout << datosclientesala8p3_3D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala8p3_3D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala8p3_3D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala8p3_3D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala8p3_3D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala8p3_3D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala8p3_3D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala8p3_3D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala8p3_3D[a][b].ocupacion = 1;
		datosclientesala8p3_3D[a][b].fila = a;
		datosclientesala8p3_3D[a][b].columna = b;
		datosclientesala8p3_3D[a][b].piso = 3;
		datosclientesala8p3_3D[a][b].sala = 8;
		system("cls");
		precio3d = precio2d * 0.40;
		precio3d += precio2d;

		cout << "\nValor Total a Pagar: " << precio3d;
	}
	else
	{

		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala9p3_3D()
{

	int cont = 0, a, b;
	if (cont <= 156)
	{
		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n  0  1  2 3 4 5 6 7 8 9 10 11 12 13 14  \n";
		for (int i = 0; i <= 14; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 14; j++)
			{
				cout << datosclientesala9p3_3D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala9p3_3D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala9p3_3D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala9p3_3D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala9p3_3D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala9p3_3D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala9p3_3D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala9p3_3D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala9p3_3D[a][b].ocupacion = 1;
		datosclientesala9p3_3D[a][b].fila = a;
		datosclientesala9p3_3D[a][b].columna = b;
		datosclientesala9p3_3D[a][b].piso = 3;
		datosclientesala9p3_3D[a][b].sala = 9;
		system("cls");

		precio3d = precio2d * 0.40;
		precio3d += precio2d;

		cout << "\nValor Total a Pagar: " << precio3d;
	}
	else
	{
		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala10p3_3D()
{
	int cont = 0, a, b;
	if (cont <= 156)
	{

		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n  0  1  2 3 4 5 6 7 8 9 10 11 12 13 14  \n";
		for (int i = 0; i <= 14; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 14; j++)
			{
				cout << datosclientesala10p3_3D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala10p3_3D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala10p3_3D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala10p3_3D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala10p3_3D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala10p3_3D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala10p3_3D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala10p3_3D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala10p3_3D[a][b].ocupacion = 1;
		datosclientesala10p3_3D[a][b].fila = a;
		datosclientesala10p3_3D[a][b].columna = b;
		datosclientesala10p3_3D[a][b].piso = 3;
		datosclientesala10p3_3D[a][b].sala = 10;
		system("cls");

		precio3d = precio2d * 0.40;
		precio3d += precio2d;

		cout << "\nValor Total a Pagar: " << precio3d;
	}
	else
	{
		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala11p4_4D()
{

	int cont = 0, a, b;

	if (cont <= 630)
	{

		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n  0  1  2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29  \n";
		for (int i = 0; i <= 29; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 29; j++)
			{
				cout << datosclientesala11p4_4D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala11p4_4D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala11p4_4D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala11p4_4D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala11p4_4D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala11p4_4D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala11p4_4D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala11p4_4D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala11p4_4D[a][b].ocupacion = 1;
		datosclientesala11p4_4D[a][b].fila = a;
		datosclientesala11p4_4D[a][b].columna = b;
		datosclientesala11p4_4D[a][b].piso = 4;
		datosclientesala11p4_4D[a][b].sala = 11;
		system("cls");

		precio4d = precio2d * 0.80;
		precio4d += precio2d;

		cout << "\nValor Total a Pagar: " << precio4d;
	}
	else
	{

		cout << "\n\tSALA OCUPADA" << endl;
	}
}
void sala12p4_4D()
{
	int a, b;
	if (cont12 <= 630)
	{

		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";
		cout << "\n  0  1  2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29  \n";
		for (int i = 0; i <= 29; i++)
		{

			cout << i << "  ";

			for (int j = 0; j <= 29; j++)
			{
				cout << datosclientesala12p4_4D[i][j].ocupacion << " ";
			}
			cout << "\n";
		}

		cout << "Escoja su puesto por favor: \n";
		cout << "fila:";
		cin >> a;
		cout << "columna:";
		cin >> b;

		fflush(stdin);
		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala12p4_4D[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala12p4_4D[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:   ";
		getline(cin, datosclientesala12p4_4D[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala12p4_4D[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala12p4_4D[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala12p4_4D[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala12p4_4D[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala12p4_4D[a][b].ocupacion = 1;
		datosclientesala12p4_4D[a][b].fila = a;
		datosclientesala12p4_4D[a][b].columna = b;
		datosclientesala12p4_4D[a][b].piso = 4;
		datosclientesala12p4_4D[a][b].sala = 12;
		system("cls");

		precio4d = precio2d * 0.80;
		precio4d += precio2d;

		cout << "\nValor Total a Pagar: " << precio4d;
	}
	else
	{
		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void sala12p4_4Dh()
{
	if (cont12 <= 630)
	{
		int a, b;
		fflush(stdin);
		cout << "\n----Llena tu perfil para registrarse---- ";

		cout << "\nIngrese su Nombre: ";
		getline(cin, datosclientesala12p4_4Dh[a][b].nombre, '\n');
		cin.ignore();
		cout << "\nIngrese su Apellido: ";
		getline(cin, datosclientesala12p4_4Dh[a][b].apellido, '\n');
		cin.ignore();
		cout << "\n (Pasaporte, Cedulaidentidad, Tarjetadeidentidad, CedulaExtranjeria, PEP)";
		cout << "\nTipo de Documento:  ";
		getline(cin, datosclientesala12p4_4Dh[a][b].tipodocumento, '\n');

		cout << "\nNumero del documento: ";
		cin >> datosclientesala12p4_4Dh[a][b].numdocumento, '\n';

		cout << "\n******Digite la fecha en numeros sin ningun caracter especial (dia-mes-a�o)******* ";
		cout << "\nFecha de Nacimiento: ";
		cin >> datosclientesala12p4_4Dh[a][b].fechanacimiento, '\n';
		fflush(stdin);
		cout << "\nDireccion: ";
		getline(cin, datosclientesala12p4_4Dh[a][b].direccion, '\n');

		cout << "\nTelefono: ";
		cin >> datosclientesala12p4_4Dh[a][b].telefono, '\n';
		fflush(stdin);
		datosclientesala12p4_4Dh[a][b].ocupacion = 631;
		datosclientesala12p4_4Dh[a][b].piso = 4;
		datosclientesala12p4_4Dh[a][b].sala = 12;
		system("cls");

		cout << "\nCuantas horas desea alquilar la sala: ";
		cin >> datosclientesala12p4_4Dh[a][b].cantentradas;

		reservas.valortotal = precio4dh * datosclientesala12p4_4Dh[a][b].cantentradas;
		cout << "\nLa sala la tengras ocupada por " << datosclientesala12p4_4Dh[a][b].cantentradas << " horas";
		cout << "\nValor Total a Pagar: " << reservas.valortotal;
	}
	else
	{

		cout << "\n\tSALA OCUPADA" << endl;
	}
}

void cancelacion()
{

	int cont = 0;
	int id;
	int opc;
	fflush(stdin);

	do
	{

		system("cls");
		cont = 0;

		cout << "\n--------------- Bienvenido a la Opcion de Cancelacion de Reservas------------------" << endl;
		cout << "\nIngrese el numero de documento del cliente a cancelar: ";
		cin >> id;
		fflush(stdin);

		for (int x = 0; x < 15; x++)
		{

			for (int y = 0; y < 15; y++)
			{
				if (id == datosclientesala1p1_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";

					cancelaciones[p] = datosclientesala1p1_2D[x][y];
					p++;
					datosclientesala1p1_2D[x][y].tipodocumento = ' ';
					datosclientesala1p1_2D[x][y].numdocumento = 0;
					datosclientesala1p1_2D[x][y].nombre = ' ';
					datosclientesala1p1_2D[x][y].apellido = ' ';
					datosclientesala1p1_2D[x][y].fechanacimiento = 0;
					datosclientesala1p1_2D[x][y].direccion = ' ';
					datosclientesala1p1_2D[x][y].telefono = 0;
					datosclientesala1p1_2D[x][y].fila = 0;
					datosclientesala1p1_2D[x][y].columna = 0;
					datosclientesala1p1_2D[x][y].ocupacion = 0;
					datosclientesala1p1_2D[x][y].sala = 0;
					datosclientesala1p1_2D[x][y].piso = 0;
					precio2d = 0;
				}
				if (id == datosclientesala2p1_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					cancelaciones[p] = datosclientesala2p1_2D[x][y];
					p++;
					datosclientesala2p1_2D[x][y].tipodocumento = ' ';
					datosclientesala2p1_2D[x][y].numdocumento = 0;
					datosclientesala2p1_2D[x][y].nombre = ' ';
					datosclientesala2p1_2D[x][y].apellido = ' ';
					datosclientesala2p1_2D[x][y].fechanacimiento = 0;
					datosclientesala2p1_2D[x][y].direccion = ' ';
					datosclientesala2p1_2D[x][y].telefono = 0;
					datosclientesala2p1_2D[x][y].fila = 0;
					datosclientesala2p1_2D[x][y].columna = 0;
					datosclientesala2p1_2D[x][y].piso = 0;
					datosclientesala2p1_2D[x][y].sala = 0;
					precio2d = 0;
				}
				if (id == datosclientesala3p2_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					cancelaciones[p] = datosclientesala3p2_2D[x][y];
					p++;
					datosclientesala3p2_2D[x][y].tipodocumento = ' ';
					datosclientesala3p2_2D[x][y].numdocumento = 0;
					datosclientesala3p2_2D[x][y].nombre = ' ';
					datosclientesala3p2_2D[x][y].apellido = ' ';
					datosclientesala3p2_2D[x][y].fechanacimiento = 0;
					datosclientesala3p2_2D[x][y].direccion = ' ';
					datosclientesala3p2_2D[x][y].telefono = 0;
					datosclientesala3p2_2D[x][y].fila = 0;
					datosclientesala3p2_2D[x][y].columna = 0;
					datosclientesala3p2_2D[x][y].piso = 0;
					datosclientesala3p2_2D[x][y].sala = 0;
					precio2d = 0;
				}
				if (id == datosclientesala4p2_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					cancelaciones[p] = datosclientesala4p2_2D[x][y];
					p++;
					datosclientesala4p2_2D[x][y].tipodocumento = ' ';
					datosclientesala4p2_2D[x][y].numdocumento = 0;
					datosclientesala4p2_2D[x][y].nombre = ' ';
					datosclientesala4p2_2D[x][y].apellido = ' ';
					datosclientesala4p2_2D[x][y].fechanacimiento = 0;
					datosclientesala4p2_2D[x][y].direccion = ' ';
					datosclientesala4p2_2D[x][y].telefono = 0;
					datosclientesala4p2_2D[x][y].fila = 0;
					datosclientesala4p2_2D[x][y].columna = 0;
					datosclientesala4p2_2D[x][y].piso = 0;
					datosclientesala4p2_2D[x][y].sala = 0;
					precio2d = 0;
				}
				if (id == datosclientesala5p2_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					cancelaciones[p] = datosclientesala5p2_2D[x][y];
					p++;
					datosclientesala5p2_2D[x][y].tipodocumento = ' ';
					datosclientesala5p2_2D[x][y].numdocumento = 0;
					datosclientesala5p2_2D[x][y].nombre = ' ';
					datosclientesala5p2_2D[x][y].apellido = ' ';
					datosclientesala5p2_2D[x][y].fechanacimiento = 0;
					datosclientesala5p2_2D[x][y].direccion = ' ';
					datosclientesala5p2_2D[x][y].telefono = 0;
					datosclientesala5p2_2D[x][y].fila = 0;
					datosclientesala5p2_2D[x][y].columna = 0;
					datosclientesala5p2_2D[x][y].piso = 0;
					datosclientesala5p2_2D[x][y].sala = 0;
					precio2d = 0;
				}
				if (id == datosclientesala6p2_2D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					cancelaciones[p] = datosclientesala6p2_2D[x][y];
					p++;
					datosclientesala6p2_2D[x][y].tipodocumento = ' ';
					datosclientesala6p2_2D[x][y].numdocumento = 0;
					datosclientesala6p2_2D[x][y].nombre = ' ';
					datosclientesala6p2_2D[x][y].apellido = ' ';
					datosclientesala6p2_2D[x][y].fechanacimiento = 0;
					datosclientesala6p2_2D[x][y].direccion = ' ';
					datosclientesala6p2_2D[x][y].telefono = 0;
					datosclientesala6p2_2D[x][y].fila = 0;
					datosclientesala6p2_2D[x][y].columna = 0;
					datosclientesala6p2_2D[x][y].piso = 0;
					datosclientesala6p2_2D[x][y].sala = 0;
					precio2d = 0;
				}
				if (id == datosclientesala7p3_3D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					cancelaciones[p] = datosclientesala7p3_3D[x][y];
					p++;
					datosclientesala7p3_3D[x][y].tipodocumento = ' ';
					datosclientesala7p3_3D[x][y].numdocumento = 0;
					datosclientesala7p3_3D[x][y].nombre = ' ';
					datosclientesala7p3_3D[x][y].apellido = ' ';
					datosclientesala7p3_3D[x][y].fechanacimiento = 0;
					datosclientesala7p3_3D[x][y].direccion = ' ';
					datosclientesala7p3_3D[x][y].telefono = 0;
					datosclientesala7p3_3D[x][y].fila = 0;
					datosclientesala7p3_3D[x][y].columna = 0;
					datosclientesala7p3_3D[x][y].piso = 0;
					datosclientesala7p3_3D[x][y].sala = 0;
					precio3d = 0;
				}
				if (id == datosclientesala8p3_3D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					cancelaciones[p] = datosclientesala8p3_3D[x][y];
					p++;
					datosclientesala8p3_3D[x][y].tipodocumento = ' ';
					datosclientesala8p3_3D[x][y].numdocumento = 0;
					datosclientesala8p3_3D[x][y].nombre = ' ';
					datosclientesala8p3_3D[x][y].apellido = ' ';
					datosclientesala8p3_3D[x][y].fechanacimiento = 0;
					datosclientesala8p3_3D[x][y].direccion = ' ';
					datosclientesala8p3_3D[x][y].telefono = 0;
					datosclientesala8p3_3D[x][y].fila = 0;
					datosclientesala8p3_3D[x][y].columna = 0;
					datosclientesala8p3_3D[x][y].piso = 0;
					datosclientesala8p3_3D[x][y].sala = 0;
					precio3d = 0;
				}
				if (id == datosclientesala9p3_3D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					cancelaciones[p] = datosclientesala9p3_3D[x][y];
					p++;
					datosclientesala9p3_3D[x][y].tipodocumento = ' ';
					datosclientesala9p3_3D[x][y].numdocumento = 0;
					datosclientesala9p3_3D[x][y].nombre = ' ';
					datosclientesala9p3_3D[x][y].apellido = ' ';
					datosclientesala9p3_3D[x][y].fechanacimiento = 0;
					datosclientesala9p3_3D[x][y].direccion = ' ';
					datosclientesala9p3_3D[x][y].telefono = 0;
					datosclientesala9p3_3D[x][y].fila = 0;
					datosclientesala9p3_3D[x][y].columna = 0;
					datosclientesala9p3_3D[x][y].piso = 0;
					datosclientesala9p3_3D[x][y].sala = 0;
					precio3d = 0;
				}
				if (id == datosclientesala10p3_3D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					cancelaciones[p] = datosclientesala10p3_3D[x][y];
					p++;
					datosclientesala10p3_3D[x][y].tipodocumento = ' ';
					datosclientesala10p3_3D[x][y].numdocumento = 0;
					datosclientesala10p3_3D[x][y].nombre = ' ';
					datosclientesala10p3_3D[x][y].apellido = ' ';
					datosclientesala10p3_3D[x][y].fechanacimiento = 0;
					datosclientesala10p3_3D[x][y].direccion = ' ';
					datosclientesala10p3_3D[x][y].telefono = 0;
					datosclientesala10p3_3D[x][y].fila = 0;
					datosclientesala10p3_3D[x][y].columna = 0;
					datosclientesala10p3_3D[x][y].piso = 0;
					datosclientesala10p3_3D[x][y].sala = 0;
					precio3d = 0;
				}
			}
		}

		for (int x = 0; x < 30; x++)
		{
			for (int y = 0; y < 30; y++)
			{

				if (id == datosclientesala11p4_4D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					datosclientesala11p4_4D[x][y].tipodocumento = ' ';
					datosclientesala11p4_4D[x][y].numdocumento = 0;
					datosclientesala11p4_4D[x][y].nombre = ' ';
					datosclientesala11p4_4D[x][y].apellido = ' ';
					datosclientesala11p4_4D[x][y].fechanacimiento = 0;
					datosclientesala11p4_4D[x][y].direccion = ' ';
					datosclientesala11p4_4D[x][y].telefono = 0;
					datosclientesala11p4_4D[x][y].fila = 0;
					datosclientesala11p4_4D[x][y].columna = 0;
					datosclientesala11p4_4D[x][y].piso = 0;
					datosclientesala11p4_4D[x][y].sala = 0;
					precio4d = 0;
				}

				if (id == datosclientesala12p4_4Dh[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					datosclientesala12p4_4Dh[x][y].tipodocumento = ' ';
					datosclientesala12p4_4Dh[x][y].numdocumento = 0;
					datosclientesala12p4_4Dh[x][y].nombre = ' ';
					datosclientesala12p4_4Dh[x][y].apellido = ' ';
					datosclientesala12p4_4Dh[x][y].fechanacimiento = 0;
					datosclientesala12p4_4Dh[x][y].direccion = ' ';
					datosclientesala12p4_4Dh[x][y].telefono = 0;
					datosclientesala12p4_4Dh[x][y].piso = 0;
					datosclientesala12p4_4Dh[x][y].sala = 0;
					precio4dh = 0;
				}

				if (id == datosclientesala12p4_4D[x][y].numdocumento)
				{
					cout << "\n\n\tUSUARIO ENCONTRADO!\n";
					cout << "\nCancelacion Exitosa \n\n";
					datosclientesala12p4_4D[x][y].tipodocumento = ' ';
					datosclientesala12p4_4D[x][y].numdocumento = 0;
					datosclientesala12p4_4D[x][y].nombre = ' ';
					datosclientesala12p4_4D[x][y].apellido = ' ';
					datosclientesala12p4_4D[x][y].fechanacimiento = 0;
					datosclientesala12p4_4D[x][y].direccion = ' ';
					datosclientesala12p4_4D[x][y].telefono = 0;
					datosclientesala12p4_4D[x][y].fila = 0;
					datosclientesala12p4_4D[x][y].columna = 0;
					datosclientesala12p4_4D[x][y].piso = 0;
					datosclientesala12p4_4D[x][y].sala = 0;
					precio4d = 0;
				}
			}
		}

		if (cont == 0)
		{
			fflush(stdin);
			cout << "\n\n\tUSUARIO NO ENCONTRADO\n\n";
		}
		fflush(stdin);
		cout << "\nDesea volver a intentarlo?\n\n";
		cout << "1. Para si\n";
		cout << "2. Para no";
		cout << "\n\nOpcion: ";
		fflush(stdin);
		cin >> opc;

	} while ((opc == 1));
}

void listareservas()
{

	int cont = 0;

	cout << "\n--------------- Bienvenido a la Opcion de listado de Reservas------------------" << endl;

	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{

			if (datosclientesala1p1_2D[x][y].numdocumento > 0)
			{

				cout << "\n--------------------------------------------------------------------------" << endl;

				cout << "Tipo de documento: " << datosclientesala1p1_2D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala1p1_2D[x][y].numdocumento;
				cout << "\nNombre : " << datosclientesala1p1_2D[x][y].nombre;
				cout << "\nApellido : " << datosclientesala1p1_2D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala1p1_2D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala1p1_2D[x][y].direccion;
				cout << "\nTelefono: " << datosclientesala1p1_2D[x][y].telefono;
				cout << "\n\nReservo Pelicula 2D";
				cout << "\nPiso: " << datosclientesala1p1_2D[x][y].piso;
				cout << "\nSala: " << datosclientesala1p1_2D[x][y].sala;
				cout << "\nFila: " << datosclientesala1p1_2D[x][y].fila;
				cout << "\nColumna: " << datosclientesala1p1_2D[x][y].columna;
				cout << "\nPago: $" << precio2d;
				cout << "\n";
				cont++;
			}
			if (datosclientesala2p1_2D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala2p1_2D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala2p1_2D[x][y].numdocumento;
				cout << "\nNombre : " << datosclientesala2p1_2D[x][y].nombre;
				cout << "\nApellido : " << datosclientesala2p1_2D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala2p1_2D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala2p1_2D[x][y].direccion;
				cout << "\nTelefono: " << datosclientesala2p1_2D[x][y].telefono;
				cout << "\n\nReservo Pelicula 2D";
				cout << "\nPiso: " << datosclientesala2p1_2D[x][y].piso;
				cout << "\nSala: " << datosclientesala2p1_2D[x][y].sala;
				cout << "\nFila: " << datosclientesala2p1_2D[x][y].fila;
				cout << "\nColumna: " << datosclientesala2p1_2D[x][y].columna;
				cout << "\nPago: $" << precio2d;
				cout << "\n";

				cont++;
			}
			if (datosclientesala3p2_2D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala3p2_2D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala3p2_2D[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala3p2_2D[x][y].nombre;
				cout << "\nApellido: " << datosclientesala3p2_2D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala3p2_2D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala3p2_2D[x][y].direccion;
				cout << "\nTelefono: " << datosclientesala3p2_2D[x][y].telefono;
				cout << "\n\nReservo Pelicula 2D";
				cout << "\nPiso: " << datosclientesala3p2_2D[x][y].piso;
				cout << "\nSala: " << datosclientesala3p2_2D[x][y].sala;
				cout << "\nFila: " << datosclientesala3p2_2D[x][y].fila;
				cout << "\nColumna: " << datosclientesala3p2_2D[x][y].columna;
				cout << "\nPago: $" << precio2d;
				cout << "\n";

				cont++;
			}
			if (datosclientesala4p2_2D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala4p2_2D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala4p2_2D[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala4p2_2D[x][y].nombre;
				cout << "\nApellido: " << datosclientesala4p2_2D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala4p2_2D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala4p2_2D[x][y].direccion;
				cout << "\nTelefono: " << datosclientesala4p2_2D[x][y].telefono;
				cout << "\n\nReservo Pelicula 2D";
				cout << "\nPiso: " << datosclientesala4p2_2D[x][y].piso;
				cout << "\nSala: " << datosclientesala4p2_2D[x][y].sala;
				cout << "\nFila: " << datosclientesala4p2_2D[x][y].fila;
				cout << "\nColumna: " << datosclientesala4p2_2D[x][y].columna;
				cout << "\nPago: $" << precio2d;
				cout << "\n";

				cont++;
			}
			if (datosclientesala5p2_2D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala5p2_2D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala5p2_2D[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala5p2_2D[x][y].nombre;
				cout << "\nApellido: " << datosclientesala5p2_2D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala5p2_2D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala5p2_2D[x][y].direccion;
				cout << "\nTelefono: " << datosclientesala5p2_2D[x][y].telefono;
				cout << "\n\nReservo Pelicula 2D";
				cout << "\nPiso: " << datosclientesala5p2_2D[x][y].piso;
				cout << "\nSala: " << datosclientesala5p2_2D[x][y].sala;
				cout << "\nFila: " << datosclientesala5p2_2D[x][y].fila;
				cout << "\nColumna: " << datosclientesala5p2_2D[x][y].columna;
				cout << "\nPago: $" << precio2d;
				cout << "\n";

				cont++;
			}
			if (datosclientesala6p2_2D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala6p2_2D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala6p2_2D[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala6p2_2D[x][y].nombre;
				cout << "\nApellido: " << datosclientesala6p2_2D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala6p2_2D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala6p2_2D[x][y].direccion;
				cout << "\nTelefono: " << datosclientesala6p2_2D[x][y].telefono;
				cout << "\n\nReservo Pelicula 2D";
				cout << "\nPiso: " << datosclientesala5p2_2D[x][y].piso;
				cout << "\nSala: " << datosclientesala5p2_2D[x][y].sala;
				cout << "\nFila: " << datosclientesala6p2_2D[x][y].fila;
				cout << "\nColumna: " << datosclientesala6p2_2D[x][y].columna;
				cout << "\nPago: $" << precio2d;
				cout << "\n";

				cont++;
			}
			if (datosclientesala7p3_3D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala7p3_3D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala7p3_3D[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala7p3_3D[x][y].nombre;
				cout << "\nApellido: " << datosclientesala7p3_3D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala7p3_3D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala7p3_3D[x][y].direccion;
				cout << "\nTelefono: " << datosclientesala7p3_3D[x][y].telefono;
				cout << "\n\nReservo Pelicula 3D";
				cout << "\nPiso: " << datosclientesala7p3_3D[x][y].piso;
				cout << "\nSala: " << datosclientesala7p3_3D[x][y].sala;
				cout << "\nFila: " << datosclientesala7p3_3D[x][y].fila;
				cout << "\nColumna: " << datosclientesala7p3_3D[x][y].columna;
				precio3d = precio2d * 0.40;
				precio3d += precio2d;
				cout << "\nPago: $" << precio3d;
				cout << "\n";

				cont++;
			}
			if (datosclientesala8p3_3D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala8p3_3D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala8p3_3D[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala8p3_3D[x][y].nombre;
				cout << "\nApellido: " << datosclientesala8p3_3D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala8p3_3D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala8p3_3D[x][y].direccion;
				cout << "\nTelefono: " << datosclientesala8p3_3D[x][y].telefono;
				cout << "\n\nReservo Pelicula 3D";
				cout << "\nPiso: " << datosclientesala8p3_3D[x][y].piso;
				cout << "\nSala: " << datosclientesala8p3_3D[x][y].sala;
				cout << "\nFila: " << datosclientesala8p3_3D[x][y].fila;
				cout << "\nColumna: " << datosclientesala8p3_3D[x][y].columna;
				precio3d = precio2d * 0.40;
				precio3d += precio2d;
				cout << "\nPago: $" << precio3d;
				cout << "\n";

				cont++;
			}
			if (datosclientesala9p3_3D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala9p3_3D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala9p3_3D[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala9p3_3D[x][y].nombre;
				cout << "\nApellido: " << datosclientesala9p3_3D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala9p3_3D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala9p3_3D[x][y].direccion;
				cout << "\nTelefono: " << datosclientesala9p3_3D[x][y].telefono;
				cout << "\n\nReservo Pelicula 3D";
				cout << "\nPiso: " << datosclientesala9p3_3D[x][y].piso;
				cout << "\nSala: " << datosclientesala9p3_3D[x][y].sala;
				cout << "\nFila: " << datosclientesala9p3_3D[x][y].fila;
				cout << "\nColumna: " << datosclientesala9p3_3D[x][y].columna;
				precio3d = precio2d * 0.40;
				precio3d += precio2d;
				cout << "\nPago: $" << precio3d;
				cout << "\n";

				cont++;
			}
			if (datosclientesala10p3_3D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala10p3_3D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala10p3_3D[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala10p3_3D[x][y].nombre;
				cout << "\nApellido: " << datosclientesala10p3_3D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala10p3_3D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala10p3_3D[x][y].direccion;
				cout << "\nTelefono: " << datosclientesala10p3_3D[x][y].telefono;
				cout << "\n\nReservo Pelicula 3D";
				cout << "\nPiso: " << datosclientesala10p3_3D[x][y].piso;
				cout << "\nSala: " << datosclientesala10p3_3D[x][y].sala;
				cout << "\nFila: " << datosclientesala10p3_3D[x][y].fila;
				cout << "\nColumna: " << datosclientesala10p3_3D[x][y].columna;
				precio3d = precio2d * 0.40;
				precio3d += precio2d;
				cout << "\nPago: $" << precio3d;
				cout << "\n";

				cont++;
			}
		}
	}

	for (int x = 0; x < 30; x++)
	{
		for (int y = 0; y < 30; y++)
		{

			if (datosclientesala11p4_4D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala11p4_4D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala11p4_4D[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala11p4_4D[x][y].nombre;
				cout << "\nApellido: " << datosclientesala11p4_4D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala11p4_4D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala11p4_4D[x][y].direccion;
				fflush(stdin);
				cout << "\nTelefono: " << datosclientesala11p4_4D[x][y].telefono;
				fflush(stdin);
				cout << "\n\nReservo Pelicula 4D";
				cout << "\nPiso: " << datosclientesala11p4_4D[x][y].piso;
				cout << "\nSala: " << datosclientesala11p4_4D[x][y].sala;
				cout << "\nFila: " << datosclientesala11p4_4D[x][y].fila;
				cout << "\nColumna: " << datosclientesala11p4_4D[x][y].columna;
				precio4d = precio2d * 0.80;
				precio4d += precio2d;
				cout << "\nPago: $" << precio4d;
				cout << "\n";

				cont++;
			}

			if (datosclientesala12p4_4Dh[x][y].numdocumento > 0)
			{
				fflush(stdin);
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala12p4_4Dh[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala12p4_4Dh[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala12p4_4Dh[x][y].nombre;
				cout << "\nApellido: " << datosclientesala12p4_4Dh[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala12p4_4Dh[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala12p4_4Dh[x][y].direccion;
				fflush(stdin);
				cout << "\nTelefono: " << datosclientesala12p4_4Dh[x][y].telefono;

				cout << "\n\nReservo un evento en sala 4D:";
				cout << "\nPiso: " << datosclientesala12p4_4Dh[x][y].piso;
				cout << "\nSala: " << datosclientesala12p4_4Dh[x][y].sala;
				cout << "\nDuracion: " << reservas.cantentradas << " Horas";
				cout << "\nPago: $" << precio4dh;
				cout << "\n";

				cont++;
			}

			if (datosclientesala12p4_4D[x][y].numdocumento > 0)
			{
				cout << "\n--------------------------------------------------------------------------" << endl;
				cout << "\nDatos:\n\n";
				cout << "Tipo de documento: " << datosclientesala12p4_4D[x][y].tipodocumento;
				cout << "\nNumero de documento: " << datosclientesala12p4_4D[x][y].numdocumento;
				cout << "\nNombre: " << datosclientesala12p4_4D[x][y].nombre;
				cout << "\nApellido: " << datosclientesala12p4_4D[x][y].apellido;
				cout << "\nFecha de nacimiento: " << datosclientesala12p4_4D[x][y].fechanacimiento;
				cout << "\nDireccion: " << datosclientesala12p4_4D[x][y].direccion;
				fflush(stdin);
				cout << "\nTelefono: " << datosclientesala12p4_4D[x][y].telefono;
				fflush(stdin);
				cout << "\n\nReservo Pelicula 4D";
				cout << "\nPiso: " << datosclientesala12p4_4D[x][y].piso;
				cout << "\nSala: " << datosclientesala12p4_4D[x][y].sala;
				cout << "\nFila: " << datosclientesala12p4_4D[x][y].fila;
				cout << "\nColumna: " << datosclientesala12p4_4D[x][y].columna;
				precio4d = precio2d * 0.80;
				precio4d += precio2d;
				cout << "\nPago: $" << precio4d;
				cout << "\n";

				cont++;
			}
		}
	}

	if (cont == 0)
	{

		cout << "\n\nNO HAY RESERVAS" << endl;
	}
	getch();
}

void listacancelaciones()
{
	int cont = 0;
	cout << "\n--------------- Bienvenido a la Opcion de listado de cancelaciones------------------" << endl;

	for (int x = 0; x < 1000; x++)
	{

		if (cancelaciones[x].ocupacion == 1)
		{

			cout << "\n--------------------------------------------------------------------------" << endl;

			cout << "Tipo de documento: " << cancelaciones[x].tipodocumento;
			cout << "\nNumero de documento: " << cancelaciones[x].numdocumento;
			cout << "\nNombre: " << cancelaciones[x].nombre;
			cout << "\nNombre: " << cancelaciones[x].apellido;
			cout << "\nFecha de nacimiento: " << cancelaciones[x].fechanacimiento;
			cout << "\nDireccion: " << cancelaciones[x].direccion;
			cout << "\nTelefono: " << cancelaciones[x].telefono;
			cout << "\nFila: " << cancelaciones[x].fila;
			cout << "\nColumna: " << cancelaciones[x].columna;
			cout << "\nPago: 000$";
			cout << "\n";
			cont++;
		}
	}
	cout << "\n\tNO HAY CANCELACIONES" << endl;
	getch();
}

void seleccion()
{
	int actual, mas_pequeno, j, n, a;

	for (actual = 0; actual < n - 1; actual++)
	{
		mas_pequeno = actual;
		for (j = actual + 1; j < n; j++)
		{
			if (datoscliente[j].numdocumento < datoscliente[mas_pequeno].numdocumento)
			{
				mas_pequeno = j;
			}
		}
		aux.numdocumento = datoscliente[actual].numdocumento;
		datoscliente[actual].numdocumento = datoscliente[mas_pequeno].numdocumento;
		datoscliente[mas_pequeno].numdocumento = aux.numdocumento;

		aux.nombre = datoscliente[actual].nombre;
		datoscliente[actual].nombre = datoscliente[mas_pequeno].nombre;
		datoscliente[mas_pequeno].nombre = aux.nombre;

		aux.fechanacimiento = datoscliente[actual].fechanacimiento;
		datoscliente[actual].fechanacimiento = datoscliente[mas_pequeno].fechanacimiento;
		datoscliente[mas_pequeno].fechanacimiento = aux.fechanacimiento;

		aux.direccion = datoscliente[actual].direccion;
		datoscliente[actual].direccion = datoscliente[mas_pequeno].direccion;
		datoscliente[mas_pequeno].direccion = aux.direccion;

		aux.telefono = datoscliente[actual].telefono;
		datoscliente[actual].telefono = datoscliente[mas_pequeno].telefono;
		datoscliente[mas_pequeno].telefono = aux.telefono;

		aux.columna = datoscliente[actual].columna;
		datoscliente[actual].columna = datoscliente[mas_pequeno].columna;
		datoscliente[mas_pequeno].columna = aux.columna;

		aux.fila = datoscliente[actual].fila;
		datoscliente[actual].fila = datoscliente[mas_pequeno].fila;
		datoscliente[mas_pequeno].fila = aux.fila;

		aux.piso = datoscliente[actual].piso;
		datoscliente[actual].piso = datoscliente[mas_pequeno].piso;
		datoscliente[mas_pequeno].piso = aux.piso;

		aux.sala = datoscliente[actual].sala;
		datoscliente[actual].sala = datoscliente[mas_pequeno].sala;
		datoscliente[mas_pequeno].sala = aux.sala;

		aux.tipodocumento = datoscliente[actual].tipodocumento;
		datoscliente[actual].tipodocumento = datoscliente[mas_pequeno].tipodocumento;
		datoscliente[mas_pequeno].tipodocumento = aux.tipodocumento;
	}
}

void pasardatos()
{
	int siguiente = 0;

	for (i = 0; i < 3000; i++)
	{
		datoscliente[i].ocupacion = 0;
	}

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (datosclientesala1p1_2D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala1p1_2D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala1p1_2D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala1p1_2D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala1p1_2D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala1p1_2D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala1p1_2D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala1p1_2D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala1p1_2D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala1p1_2D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala1p1_2D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala1p1_2D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala1p1_2D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (datosclientesala2p1_2D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala2p1_2D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala2p1_2D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala2p1_2D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala2p1_2D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala2p1_2D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala2p1_2D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala2p1_2D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala2p1_2D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala2p1_2D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala2p1_2D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala2p1_2D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala2p1_2D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (datosclientesala3p2_2D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala3p2_2D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala3p2_2D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala3p2_2D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala3p2_2D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala3p2_2D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala3p2_2D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala3p2_2D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala3p2_2D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala3p2_2D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala3p2_2D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala3p2_2D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala3p2_2D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (datosclientesala4p2_2D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala4p2_2D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala4p2_2D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala4p2_2D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala4p2_2D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala4p2_2D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala4p2_2D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala4p2_2D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala4p2_2D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala4p2_2D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala4p2_2D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala4p2_2D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala4p2_2D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (datosclientesala5p2_2D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala5p2_2D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala5p2_2D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala5p2_2D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala5p2_2D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala5p2_2D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala5p2_2D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala5p2_2D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala5p2_2D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala5p2_2D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala5p2_2D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala5p2_2D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala5p2_2D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (datosclientesala6p2_2D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala6p2_2D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala6p2_2D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala6p2_2D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala6p2_2D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala6p2_2D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala6p2_2D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala6p2_2D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala6p2_2D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala6p2_2D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala6p2_2D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala6p2_2D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala6p2_2D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (datosclientesala7p3_3D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala7p3_3D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala7p3_3D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala7p3_3D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala7p3_3D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala7p3_3D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala7p3_3D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala7p3_3D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala7p3_3D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala7p3_3D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala7p3_3D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala7p3_3D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala7p3_3D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (datosclientesala8p3_3D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala8p3_3D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala8p3_3D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala8p3_3D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala8p3_3D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala8p3_3D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala8p3_3D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala8p3_3D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala8p3_3D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala8p3_3D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala8p3_3D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala8p3_3D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala8p3_3D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (datosclientesala9p3_3D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala9p3_3D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala9p3_3D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala9p3_3D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala9p3_3D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala9p3_3D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala9p3_3D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala9p3_3D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala9p3_3D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala9p3_3D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala9p3_3D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala9p3_3D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala9p3_3D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (datosclientesala10p3_3D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala10p3_3D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala10p3_3D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala10p3_3D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala10p3_3D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala10p3_3D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala10p3_3D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala10p3_3D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala10p3_3D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala10p3_3D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala10p3_3D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala10p3_3D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala10p3_3D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 29; i++)
	{
		for (j = 0; j < 29; j++)
		{
			if (datosclientesala11p4_4D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala11p4_4D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala11p4_4D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala11p4_4D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala11p4_4D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala11p4_4D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala11p4_4D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala11p4_4D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala11p4_4D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala11p4_4D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala11p4_4D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala11p4_4D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala11p4_4D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 29; i++)
	{
		for (j = 0; j < 29; j++)
		{
			if (datosclientesala12p4_4D[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala12p4_4D[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala12p4_4D[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala12p4_4D[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala12p4_4D[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala12p4_4D[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala12p4_4D[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala12p4_4D[i][j].telefono;
				datoscliente[siguiente].fila = datosclientesala12p4_4D[i][j].fila;
				datoscliente[siguiente].columna = datosclientesala12p4_4D[i][j].columna;
				datoscliente[siguiente].piso = datosclientesala12p4_4D[i][j].piso;
				datoscliente[siguiente].sala = datosclientesala12p4_4D[i][j].sala;
				datoscliente[siguiente].ocupacion = datosclientesala12p4_4D[i][j].ocupacion;
				siguiente++;
			}
		}
	}

	for (i = 0; i < 29; i++)
	{
		for (j = 0; j < 29; j++)
		{
			if (datosclientesala12p4_4Dh[i][j].ocupacion == 1)
			{
				datoscliente[siguiente].nombre = datosclientesala12p4_4Dh[i][j].nombre;
				datoscliente[siguiente].apellido = datosclientesala12p4_4Dh[i][j].apellido;
				datoscliente[siguiente].tipodocumento = datosclientesala12p4_4Dh[i][j].tipodocumento;
				datoscliente[siguiente].numdocumento = datosclientesala12p4_4Dh[i][j].numdocumento;
				datoscliente[siguiente].fechanacimiento = datosclientesala12p4_4Dh[i][j].fechanacimiento;
				datoscliente[siguiente].direccion = datosclientesala12p4_4Dh[i][j].direccion;
				datoscliente[siguiente].telefono = datosclientesala12p4_4Dh[i][j].telefono;
				datoscliente[siguiente].piso = datosclientesala12p4_4Dh[i][j].piso;
				datoscliente[siguiente].cantentradas = datosclientesala12p4_4Dh[i][j].sala;
				datoscliente[siguiente].cantentradas = datosclientesala12p4_4Dh[i][j].cantentradas;
				datoscliente[siguiente].ocupacion = datosclientesala12p4_4Dh[i][j].ocupacion;
				siguiente++;
			}
		}
	}
}

void listaclientes()
{
	system("cls");
	cout << "**** LISTADO DE EMPLEADOS EN ORDEN ALFABETICO **** \n";
	cout << "NOMBRE\t\t"
		 << "APELLIDO\t"
		 << "NUMERO_DOCUMENTO\t"
		 << "TIPO_DOCUMENTO\t"
		 << "FECHA_NACIMIENTO\t"
		 << "DiRECCION\t"
		 << "TELEFONO\t" << endl;
	for (int v = 0; v < 3000; v++)
	{
		if (datoscliente[v].ocupacion == 1)
		{
			cout << datoscliente[v].nombre << "\t\t" << datoscliente[v].apellido << "\t\t" << datoscliente[v].numdocumento << "\t\t" << datoscliente[v].tipodocumento << "\t" << datoscliente[v].fechanacimiento << "\t\t" << datoscliente[v].direccion << "\t" << datoscliente[v].telefono << endl;
		}
	}
}

void ordenamientoN()
{
	int n = siguiente;

	for (i = 0; i <= n - 2; i++)
	{
		for (j = i + 1; j <= n - 1; j++)
		{
			if (datoscliente[i].nombre > datoscliente[j].nombre)
			{
				aux.nombre = datoscliente[i].nombre;
				datoscliente[i].nombre = datoscliente[j].nombre;
				datoscliente[j].nombre = aux.nombre;

				aux.apellido = datoscliente[i].apellido;
				datoscliente[i].apellido = datoscliente[j].apellido;
				datoscliente[j].apellido = aux.apellido;

				aux.tipodocumento = datoscliente[i].tipodocumento;
				datoscliente[i].tipodocumento = datoscliente[j].tipodocumento;
				datoscliente[j].tipodocumento = aux.tipodocumento;

				aux.numdocumento = datoscliente[i].numdocumento;
				datoscliente[i].numdocumento = datoscliente[j].numdocumento;
				datoscliente[j].numdocumento = aux.numdocumento;

				aux.fechanacimiento = datoscliente[i].fechanacimiento;
				datoscliente[i].fechanacimiento = datoscliente[j].fechanacimiento;
				datoscliente[j].fechanacimiento = aux.fechanacimiento;

				aux.direccion = datoscliente[i].direccion;
				datoscliente[i].direccion = datoscliente[j].direccion;
				datoscliente[j].direccion = aux.direccion;

				aux.telefono = datoscliente[i].telefono;
				datoscliente[i].telefono = datoscliente[j].telefono;
				datoscliente[j].telefono = aux.telefono;

				aux.fila = datoscliente[i].fila;
				datoscliente[i].fila = datoscliente[j].fila;
				datoscliente[j].fila = aux.fila;

				aux.columna = datoscliente[i].columna;
				datoscliente[i].columna = datoscliente[j].columna;
				datoscliente[j].columna = aux.columna;

				aux.piso = datoscliente[i].piso;
				datoscliente[i].piso = datoscliente[j].piso;
				datoscliente[j].piso = aux.piso;

				aux.sala = datoscliente[i].sala;
				datoscliente[i].sala = datoscliente[j].sala;
				datoscliente[j].sala = aux.sala;
			}
		}
	}
}

void ordenamientoC()
{
	int n = siguiente;

	for (i = 0; i <= n - 2; i++)
	{
		for (j = i + 1; j <= n - 1; j++)
		{
			if (datoscliente[i].numdocumento > datoscliente[j].numdocumento)
			{
				aux.nombre = datoscliente[i].nombre;
				datoscliente[i].nombre = datoscliente[j].nombre;
				datoscliente[j].nombre = aux.nombre;

				aux.apellido = datoscliente[i].apellido;
				datoscliente[i].apellido = datoscliente[j].apellido;
				datoscliente[j].apellido = aux.apellido;

				aux.tipodocumento = datoscliente[i].tipodocumento;
				datoscliente[i].tipodocumento = datoscliente[j].tipodocumento;
				datoscliente[j].tipodocumento = aux.tipodocumento;

				aux.numdocumento = datoscliente[i].numdocumento;
				datoscliente[i].numdocumento = datoscliente[j].numdocumento;
				datoscliente[j].numdocumento = aux.numdocumento;

				aux.fechanacimiento = datoscliente[i].fechanacimiento;
				datoscliente[i].fechanacimiento = datoscliente[j].fechanacimiento;
				datoscliente[j].fechanacimiento = aux.fechanacimiento;

				aux.direccion = datoscliente[i].direccion;
				datoscliente[i].direccion = datoscliente[j].direccion;
				datoscliente[j].direccion = aux.direccion;

				aux.telefono = datoscliente[i].telefono;
				datoscliente[i].telefono = datoscliente[j].telefono;
				datoscliente[j].telefono = aux.telefono;

				aux.fila = datoscliente[i].fila;
				datoscliente[i].fila = datoscliente[j].fila;
				datoscliente[j].fila = aux.fila;

				aux.columna = datoscliente[i].columna;
				datoscliente[i].columna = datoscliente[j].columna;
				datoscliente[j].columna = aux.columna;

				aux.piso = datoscliente[i].piso;
				datoscliente[i].piso = datoscliente[j].piso;
				datoscliente[j].piso = aux.piso;

				aux.sala = datoscliente[i].sala;
				datoscliente[i].sala = datoscliente[j].sala;
				datoscliente[j].sala = aux.sala;
			}
		}
	}
}
void busquedaporcedula()
{
	int primero, ultimo, medio;
	int cedula;
	primero = 0;
	ultimo = siguiente - 1;
	medio = (primero + ultimo) / 2;

	system("cls");
	cout << "**** BUSQUEDA DE EMPLEADO POR CEDULA **** \n";
	cout << "\nIngrese el documento que desea buscar: ";
	cin >> cedula;

	while (primero <= ultimo)
	{
		if (datoscliente[medio].numdocumento < cedula)
		{
			primero = medio + 1;
		}
		else
		{
			if (datoscliente[medio].numdocumento == cedula)
			{
				cout << "\n-------Datos del Empleado encontrado--------- \n\n ";
				cout << "Nombre: " << datoscliente[medio].nombre << "\n";
				cout << "Apellido: " << datoscliente[medio].apellido << "\n";
				cout << "Tipo Documento: " << datoscliente[medio].tipodocumento << "\n";
				cout << "Numero de Documento: " << datoscliente[medio].numdocumento << "\n";
				cout << "Direccion: " << datoscliente[medio].direccion << "\n";
				cout << "Fecha de Nacimiento: " << datoscliente[medio].fechanacimiento << "\n";
				cout << "Telefono: " << datoscliente[medio].telefono << "\n";
				cout << "Piso: " << datoscliente[medio].piso << "\n";
				cout << "Sala: " << datoscliente[medio].sala << "\n";
				cout << "Columna: " << datoscliente[medio].columna << "\n";
				cout << "Fila: " << datoscliente[medio].fila << "\n";

				break;
			}
			else
			{
				ultimo = medio - 1;
			}
		}

		medio = (primero + ultimo) / 2;
	}

	if (primero > ultimo)
	{
		cout << "\nLa cedula numero " << cedula << " no se encontro" << endl;
	}
}

void guardarclientes()
{

	int x, y;

	entrada.open("clientescine.txt", ios::out | ios::trunc);

	if (entrada.fail())
	{
		cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
	}
	else
	{
		for (x = 0; x < 15; x++)
		{
			for (y = 0; y < 15; y++)
			{
				if (datosclientesala1p1_2D[x][y].ocupacion == 1)
				{
					entrada << datosclientesala1p1_2D[x][y].nombre << " " << datosclientesala1p1_2D[x][y].apellido << " " << datosclientesala1p1_2D[x][y].tipodocumento << " " << datosclientesala1p1_2D[x][y].numdocumento << " " << datosclientesala1p1_2D[x][y].fechanacimiento << " " << datosclientesala1p1_2D[x][y].direccion << " " << datosclientesala1p1_2D[x][y].telefono << " " << datosclientesala1p1_2D[x][y].fila << " " << datosclientesala1p1_2D[x][y].columna << endl;
				}
				if (datosclientesala2p1_2D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala2p1_2D[x][y].nombre << " " << datosclientesala2p1_2D[x][y].apellido << " " << datosclientesala2p1_2D[x][y].tipodocumento << " " << datosclientesala2p1_2D[x][y].numdocumento << " " << datosclientesala2p1_2D[x][y].fechanacimiento << " " << datosclientesala2p1_2D[x][y].direccion << " " << datosclientesala2p1_2D[x][y].telefono << " " << datosclientesala2p1_2D[x][y].fila << " " << datosclientesala2p1_2D[x][y].columna << endl;
				}

				if (datosclientesala3p2_2D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala3p2_2D[x][y].nombre << " " << datosclientesala3p2_2D[x][y].apellido << " " << datosclientesala3p2_2D[x][y].tipodocumento << " " << datosclientesala3p2_2D[x][y].numdocumento << " " << datosclientesala3p2_2D[x][y].fechanacimiento << " " << datosclientesala3p2_2D[x][y].direccion << " " << datosclientesala3p2_2D[x][y].telefono << " " << datosclientesala3p2_2D[x][y].fila << " " << datosclientesala3p2_2D[x][y].columna << endl;
				}

				if (datosclientesala4p2_2D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala4p2_2D[x][y].nombre << " " << datosclientesala4p2_2D[x][y].apellido << " " << datosclientesala4p2_2D[x][y].tipodocumento << " " << datosclientesala4p2_2D[x][y].numdocumento << " " << datosclientesala4p2_2D[x][y].fechanacimiento << " " << datosclientesala4p2_2D[x][y].direccion << " " << datosclientesala4p2_2D[x][y].telefono << " " << datosclientesala4p2_2D[x][y].fila << " " << datosclientesala4p2_2D[x][y].columna << endl;
				}

				if (datosclientesala5p2_2D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala5p2_2D[x][y].nombre << " " << datosclientesala5p2_2D[x][y].apellido << " " << datosclientesala5p2_2D[x][y].tipodocumento << " " << datosclientesala5p2_2D[x][y].numdocumento << " " << datosclientesala5p2_2D[x][y].fechanacimiento << " " << datosclientesala5p2_2D[x][y].direccion << " " << datosclientesala5p2_2D[x][y].telefono << " " << datosclientesala5p2_2D[x][y].fila << " " << datosclientesala5p2_2D[x][y].columna << endl;
				}

				if (datosclientesala6p2_2D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala6p2_2D[x][y].nombre << " " << datosclientesala6p2_2D[x][y].apellido << " " << datosclientesala6p2_2D[x][y].tipodocumento << " " << datosclientesala6p2_2D[x][y].numdocumento << " " << datosclientesala6p2_2D[x][y].fechanacimiento << " " << datosclientesala6p2_2D[x][y].direccion << " " << datosclientesala6p2_2D[x][y].telefono << " " << datosclientesala6p2_2D[x][y].fila << " " << datosclientesala6p2_2D[x][y].columna << endl;
				}

				if (datosclientesala7p3_3D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala7p3_3D[x][y].nombre << " " << datosclientesala7p3_3D[x][y].apellido << " " << datosclientesala7p3_3D[x][y].tipodocumento << " " << datosclientesala7p3_3D[x][y].numdocumento << " " << datosclientesala7p3_3D[x][y].fechanacimiento << " " << datosclientesala7p3_3D[x][y].direccion << " " << datosclientesala7p3_3D[x][y].telefono << " " << datosclientesala7p3_3D[x][y].fila << " " << datosclientesala7p3_3D[x][y].columna << endl;
				}

				if (datosclientesala8p3_3D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala8p3_3D[x][y].nombre << " " << datosclientesala8p3_3D[x][y].apellido << " " << datosclientesala8p3_3D[x][y].tipodocumento << " " << datosclientesala8p3_3D[x][y].numdocumento << " " << datosclientesala8p3_3D[x][y].fechanacimiento << " " << datosclientesala8p3_3D[x][y].direccion << " " << datosclientesala8p3_3D[x][y].telefono << " " << datosclientesala8p3_3D[x][y].fila << " " << datosclientesala8p3_3D[x][y].columna << endl;
				}

				if (datosclientesala9p3_3D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala9p3_3D[x][y].nombre << " " << datosclientesala9p3_3D[x][y].apellido << " " << datosclientesala9p3_3D[x][y].tipodocumento << " " << datosclientesala9p3_3D[x][y].numdocumento << " " << datosclientesala9p3_3D[x][y].fechanacimiento << " " << datosclientesala9p3_3D[x][y].direccion << " " << datosclientesala9p3_3D[x][y].telefono << " " << datosclientesala9p3_3D[x][y].fila << " " << datosclientesala9p3_3D[x][y].columna << endl;
				}

				if (datosclientesala10p3_3D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala10p3_3D[x][y].nombre << " " << datosclientesala10p3_3D[x][y].apellido << " " << datosclientesala10p3_3D[x][y].tipodocumento << " " << datosclientesala10p3_3D[x][y].numdocumento << " " << datosclientesala10p3_3D[x][y].fechanacimiento << " " << datosclientesala10p3_3D[x][y].direccion << " " << datosclientesala10p3_3D[x][y].telefono << " " << datosclientesala10p3_3D[x][y].fila << " " << datosclientesala10p3_3D[x][y].columna << endl;
				}
			}
		}

		for (x = 0; x < 30; x++)
		{
			for (y = 0; y < 30; y++)
			{

				if (datosclientesala11p4_4D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala11p4_4D[x][y].nombre << " " << datosclientesala11p4_4D[x][y].apellido << " " << datosclientesala11p4_4D[x][y].tipodocumento << " " << datosclientesala11p4_4D[x][y].numdocumento << " " << datosclientesala11p4_4D[x][y].fechanacimiento << " " << datosclientesala11p4_4D[x][y].direccion << " " << datosclientesala11p4_4D[x][y].telefono << " " << datosclientesala11p4_4D[x][y].fila << " " << datosclientesala11p4_4D[x][y].columna << endl;
				}

				if (datosclientesala12p4_4D[x][y].ocupacion == 1)
				{

					entrada << datosclientesala12p4_4D[x][y].nombre << " " << datosclientesala12p4_4D[x][y].apellido << " " << datosclientesala12p4_4D[x][y].tipodocumento << " " << datosclientesala12p4_4D[x][y].numdocumento << " " << datosclientesala12p4_4D[x][y].fechanacimiento << " " << datosclientesala12p4_4D[x][y].direccion << " " << datosclientesala12p4_4D[x][y].telefono << " " << datosclientesala12p4_4D[x][y].fila << " " << datosclientesala12p4_4D[x][y].columna << endl;
				}

				if (datosclientesala12p4_4Dh[x][y].ocupacion == 1)
				{

					entrada << datosclientesala12p4_4Dh[x][y].nombre << " " << datosclientesala12p4_4Dh[x][y].apellido << " " << datosclientesala12p4_4Dh[x][y].tipodocumento << " " << datosclientesala12p4_4Dh[x][y].numdocumento << " " << datosclientesala12p4_4Dh[x][y].fechanacimiento << " " << datosclientesala12p4_4Dh[x][y].direccion << " " << datosclientesala12p4_4Dh[x][y].telefono << endl;
				}
			}
		}
	}
	entrada.close();
}

void recuperardatos()
{

	salida.open("clientescine.txt", ios::in);
	if (salida.fail())
	{
		cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
	}
	else
	{
		while (salida >> ced >> nom >> apel >> tipdoc >> dir >> fecha >> tel >> fil >> col >> pis >> sal >> ocup >> entradas)
		{
			if (pis == 1)
			{
				datosclientesala1p1_2D[fil][col].numdocumento = ced;
				datosclientesala1p1_2D[fil][col].nombre = nom;
				datosclientesala1p1_2D[fil][col].apellido = apel;
				datosclientesala1p1_2D[fil][col].tipodocumento = tipdoc;
				datosclientesala1p1_2D[fil][col].direccion = dir;
				datosclientesala1p1_2D[fil][col].fechanacimiento = fecha;
				datosclientesala1p1_2D[fil][col].telefono = tel;
				datosclientesala1p1_2D[fil][col].fila = fil;
				datosclientesala1p1_2D[fil][col].columna = col;
				datosclientesala1p1_2D[fil][col].piso = pis;
				datosclientesala1p1_2D[fil][col].sala = sal;
				datosclientesala1p1_2D[fil][col].ocupacion = ocup;
			}

			if (pis == 1)
			{
				datosclientesala2p1_2D[fil][col].numdocumento = ced;
				datosclientesala2p1_2D[fil][col].nombre = nom;
				datosclientesala2p1_2D[fil][col].apellido = apel;
				datosclientesala2p1_2D[fil][col].tipodocumento = tipdoc;
				datosclientesala2p1_2D[fil][col].direccion = dir;
				datosclientesala2p1_2D[fil][col].fechanacimiento = fecha;
				datosclientesala2p1_2D[fil][col].telefono = tel;
				datosclientesala2p1_2D[fil][col].fila = fil;
				datosclientesala2p1_2D[fil][col].columna = col;
				datosclientesala2p1_2D[fil][col].piso = pis;
				datosclientesala2p1_2D[fil][col].sala = sal;
				datosclientesala2p1_2D[fil][col].ocupacion = ocup;
			}
			if (pis == 2)
			{
				datosclientesala3p2_2D[fil][col].numdocumento = ced;
				datosclientesala3p2_2D[fil][col].nombre = nom;
				datosclientesala3p2_2D[fil][col].apellido = apel;
				datosclientesala3p2_2D[fil][col].tipodocumento = tipdoc;
				datosclientesala3p2_2D[fil][col].direccion = dir;
				datosclientesala3p2_2D[fil][col].fechanacimiento = fecha;
				datosclientesala3p2_2D[fil][col].telefono = tel;
				datosclientesala3p2_2D[fil][col].fila = fil;
				datosclientesala3p2_2D[fil][col].columna = col;
				datosclientesala3p2_2D[fil][col].piso = pis;
				datosclientesala3p2_2D[fil][col].sala = sal;
				datosclientesala3p2_2D[fil][col].ocupacion = ocup;
			}

			if (pis == 2)
			{
				datosclientesala4p2_2D[fil][col].numdocumento = ced;
				datosclientesala4p2_2D[fil][col].nombre = nom;
				datosclientesala4p2_2D[fil][col].apellido = apel;
				datosclientesala4p2_2D[fil][col].tipodocumento = tipdoc;
				datosclientesala4p2_2D[fil][col].direccion = dir;
				datosclientesala4p2_2D[fil][col].fechanacimiento = fecha;
				datosclientesala4p2_2D[fil][col].telefono = tel;
				datosclientesala4p2_2D[fil][col].fila = fil;
				datosclientesala4p2_2D[fil][col].columna = col;
				datosclientesala4p2_2D[fil][col].piso = pis;
				datosclientesala4p2_2D[fil][col].sala = sal;
				datosclientesala4p2_2D[fil][col].ocupacion = ocup;
			}

			if (pis == 2)
			{
				datosclientesala5p2_2D[fil][col].numdocumento = ced;
				datosclientesala5p2_2D[fil][col].nombre = nom;
				datosclientesala5p2_2D[fil][col].apellido = apel;
				datosclientesala5p2_2D[fil][col].tipodocumento = tipdoc;
				datosclientesala5p2_2D[fil][col].direccion = dir;
				datosclientesala5p2_2D[fil][col].fechanacimiento = fecha;
				datosclientesala5p2_2D[fil][col].telefono = tel;
				datosclientesala5p2_2D[fil][col].fila = fil;
				datosclientesala5p2_2D[fil][col].columna = col;
				datosclientesala5p2_2D[fil][col].piso = pis;
				datosclientesala5p2_2D[fil][col].sala = sal;
				datosclientesala5p2_2D[fil][col].ocupacion = ocup;
			}

			if (pis == 2)
			{
				datosclientesala6p2_2D[fil][col].numdocumento = ced;
				datosclientesala6p2_2D[fil][col].nombre = nom;
				datosclientesala6p2_2D[fil][col].apellido = apel;
				datosclientesala6p2_2D[fil][col].tipodocumento = tipdoc;
				datosclientesala6p2_2D[fil][col].direccion = dir;
				datosclientesala6p2_2D[fil][col].fechanacimiento = fecha;
				datosclientesala6p2_2D[fil][col].telefono = tel;
				datosclientesala6p2_2D[fil][col].fila = fil;
				datosclientesala6p2_2D[fil][col].columna = col;
				datosclientesala6p2_2D[fil][col].piso = pis;
				datosclientesala6p2_2D[fil][col].sala = sal;
				datosclientesala6p2_2D[fil][col].ocupacion = ocup;
			}

			if (pis == 3)
			{
				datosclientesala7p3_3D[fil][col].numdocumento = ced;
				datosclientesala7p3_3D[fil][col].nombre = nom;
				datosclientesala7p3_3D[fil][col].apellido = apel;
				datosclientesala7p3_3D[fil][col].tipodocumento = tipdoc;
				datosclientesala7p3_3D[fil][col].direccion = dir;
				datosclientesala7p3_3D[fil][col].fechanacimiento = fecha;
				datosclientesala7p3_3D[fil][col].telefono = tel;
				datosclientesala7p3_3D[fil][col].fila = fil;
				datosclientesala7p3_3D[fil][col].columna = col;
				datosclientesala7p3_3D[fil][col].piso = pis;
				datosclientesala7p3_3D[fil][col].sala = sal;
				datosclientesala7p3_3D[fil][col].ocupacion = ocup;
			}

			if (pis == 3)
			{
				datosclientesala8p3_3D[fil][col].numdocumento = ced;
				datosclientesala8p3_3D[fil][col].nombre = nom;
				datosclientesala8p3_3D[fil][col].apellido = apel;
				datosclientesala8p3_3D[fil][col].tipodocumento = tipdoc;
				datosclientesala8p3_3D[fil][col].direccion = dir;
				datosclientesala8p3_3D[fil][col].fechanacimiento = fecha;
				datosclientesala8p3_3D[fil][col].telefono = tel;
				datosclientesala8p3_3D[fil][col].fila = fil;
				datosclientesala8p3_3D[fil][col].columna = col;
				datosclientesala8p3_3D[fil][col].piso = pis;
				datosclientesala8p3_3D[fil][col].sala = sal;
				datosclientesala8p3_3D[fil][col].ocupacion = ocup;
			}

			if (pis == 3)
			{
				datosclientesala9p3_3D[fil][col].numdocumento = ced;
				datosclientesala9p3_3D[fil][col].nombre = nom;
				datosclientesala9p3_3D[fil][col].apellido = apel;
				datosclientesala9p3_3D[fil][col].tipodocumento = tipdoc;
				datosclientesala9p3_3D[fil][col].direccion = dir;
				datosclientesala9p3_3D[fil][col].fechanacimiento = fecha;
				datosclientesala9p3_3D[fil][col].telefono = tel;
				datosclientesala9p3_3D[fil][col].fila = fil;
				datosclientesala9p3_3D[fil][col].columna = col;
				datosclientesala9p3_3D[fil][col].piso = pis;
				datosclientesala9p3_3D[fil][col].sala = sal;
				datosclientesala9p3_3D[fil][col].ocupacion = ocup;
			}

			if (pis == 3)
			{
				datosclientesala10p3_3D[fil][col].numdocumento = ced;
				datosclientesala10p3_3D[fil][col].nombre = nom;
				datosclientesala10p3_3D[fil][col].apellido = apel;
				datosclientesala10p3_3D[fil][col].tipodocumento = tipdoc;
				datosclientesala10p3_3D[fil][col].direccion = dir;
				datosclientesala10p3_3D[fil][col].fechanacimiento = fecha;
				datosclientesala10p3_3D[fil][col].telefono = tel;
				datosclientesala10p3_3D[fil][col].fila = fil;
				datosclientesala10p3_3D[fil][col].columna = col;
				datosclientesala10p3_3D[fil][col].piso = pis;
				datosclientesala10p3_3D[fil][col].sala = sal;
				datosclientesala10p3_3D[fil][col].ocupacion = ocup;
			}

			if (pis == 4)
			{
				datosclientesala11p4_4D[fil][col].numdocumento = ced;
				datosclientesala11p4_4D[fil][col].nombre = nom;
				datosclientesala11p4_4D[fil][col].apellido = apel;
				datosclientesala11p4_4D[fil][col].tipodocumento = tipdoc;
				datosclientesala11p4_4D[fil][col].direccion = dir;
				datosclientesala11p4_4D[fil][col].fechanacimiento = fecha;
				datosclientesala11p4_4D[fil][col].telefono = tel;
				datosclientesala11p4_4D[fil][col].fila = fil;
				datosclientesala11p4_4D[fil][col].columna = col;
				datosclientesala11p4_4D[fil][col].piso = pis;
				datosclientesala11p4_4D[fil][col].sala = sal;
				datosclientesala11p4_4D[fil][col].ocupacion = ocup;
			}

			if (pis == 4)
			{
				datosclientesala12p4_4D[fil][col].numdocumento = ced;
				datosclientesala12p4_4D[fil][col].nombre = nom;
				datosclientesala12p4_4D[fil][col].apellido = apel;
				datosclientesala12p4_4D[fil][col].tipodocumento = tipdoc;
				datosclientesala12p4_4D[fil][col].direccion = dir;
				datosclientesala12p4_4D[fil][col].fechanacimiento = fecha;
				datosclientesala12p4_4D[fil][col].telefono = tel;
				datosclientesala12p4_4D[fil][col].fila = fil;
				datosclientesala12p4_4D[fil][col].columna = col;
				datosclientesala12p4_4D[fil][col].piso = pis;
				datosclientesala12p4_4D[fil][col].sala = sal;
				datosclientesala12p4_4D[fil][col].ocupacion = ocup;
			}

			if (pis == 4)
			{
				datosclientesala12p4_4Dh[fil][col].numdocumento = ced;
				datosclientesala12p4_4Dh[fil][col].nombre = nom;
				datosclientesala12p4_4Dh[fil][col].apellido = apel;
				datosclientesala12p4_4Dh[fil][col].tipodocumento = tipdoc;
				datosclientesala12p4_4Dh[fil][col].direccion = dir;
				datosclientesala12p4_4Dh[fil][col].fechanacimiento = fecha;
				datosclientesala12p4_4Dh[fil][col].telefono = tel;
				datosclientesala12p4_4Dh[fil][col].fila = fil;
				datosclientesala12p4_4Dh[fil][col].columna = col;
				datosclientesala12p4_4Dh[fil][col].piso = pis;
				datosclientesala12p4_4Dh[fil][col].sala = sal;
				datosclientesala12p4_4Dh[fil][col].ocupacion = ocup;
				datosclientesala12p4_4Dh[fil][col].cantentradas = entradas;
			}
		}
	}
	salida.close();
}
