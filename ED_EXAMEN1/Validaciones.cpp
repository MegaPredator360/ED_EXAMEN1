#include "Validaciones.h"

string Validaciones::ingresarNumeros()
{
	int asciiChar = 0;
	string num = "";
	do
	{
		asciiChar = _getch();						// Obtendra las teclas de formato ASCII 
		if (asciiChar >= 48 && asciiChar <= 57)		// Validaremos solo los valores que sean equivalentes a numeros
		{
			asciiChar = (asciiChar - 48);			// Los valores de ASCII para numeros 0-9 es igual a 48 hasta 57, por lo que se le resta a 48 por ser equivalente a 0
			cout << asciiChar;						// Se imprime el valor
			num = num + to_string(asciiChar);		// Convertir de Int a String para poder concatenar
		}
		else if (asciiChar == 13 && num != "")		// Hará la funcion del enter
		{
			cout << endl;							// Hará un salto de linea
			break;									// Terminará el while
		}
		else if (asciiChar == 8 && num == "")
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducirá el sonido de alerta en caso de que el espacio esté vacio
		}
		else if (asciiChar == 8)					// Hará la funcion del Backspace
		{
			cout << '\b';							// Moverá el cursor un caracter atrás
			cout << " ";							// Remplazará el valor por un espacio
			cout << '\b';
			num = num.substr(0, num.size() - 1);	// Borrará el ultimo valor del string
		}
	} while (1);

	return (num);
}

string Validaciones::confirmacionDefS()			// Utiliza la misma estructura que el de solo aceptarNumeros()
{
	int asciiChar = 0;
	string letra = "";
	do
	{
		asciiChar = _getch();
		if (asciiChar == 13 && letra == "")
		{
			letra = "S";
			break;
		}
		else if (asciiChar == 13 && letra != "")
		{
			cout << endl;
			break;
		}
		else if (asciiChar == 8 && letra == "")
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
		}
		else if (asciiChar == 8)
		{
			cout << '\b';
			cout << " ";
			cout << '\b';
			letra = letra.substr(0, letra.size() - 1);
		}
		else if (letra.length() >= 1)
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
		}
		else if (asciiChar == 83)
		{
			cout << "S";
			letra = "S";
		}
		else if (asciiChar == 115)
		{
			cout << "s";
			letra = "S";
		}
		else if (asciiChar == 78)
		{
			cout << "N";
			letra = "N";
		}
		else if (asciiChar == 110)
		{
			cout << "n";
			letra = "N";
		}
	} while (1);

	return (letra);
}

string Validaciones::confirmacionDefN()
{
	int asciiChar = 0;
	string letra = "";
	do
	{
		asciiChar = _getch();
		if (asciiChar == 13 && letra == "")
		{
			letra = "N";
			break;
		}
		else if (asciiChar == 13 && letra != "")
		{
			cout << endl;
			break;
		}
		else if (asciiChar == 8 && letra == "")
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
		}
		else if (asciiChar == 8)
		{
			cout << '\b';
			cout << " ";
			cout << '\b';
			letra = letra.substr(0, letra.size() - 1);
		}
		else if (letra.length() >= 1)
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
		}
		else if (asciiChar == 83)
		{
			cout << "S";
			letra = "S";
		}
		else if (asciiChar == 115)
		{
			cout << "s";
			letra = "S";
		}
		else if (asciiChar == 78)
		{
			cout << "N";
			letra = "N";
		}
		else if (asciiChar == 110)
		{
			cout << "n";
			letra = "N";
		}
	} while (1);

	return (letra);
}

int Validaciones::tamanoString(string texto)
{
	int cantidad = 0;						// Cantidad de letras en el string
	for (int i = 0; texto[i] != '\0'; i++)	// Contará la cantidad de letras que hay en el string
	{
		cantidad++;
	}
	return cantidad;
}

void Validaciones::guardarUsuario(iteradorLista<usuario>* IteradorUsuario)
{
	try
	{
		string valor;
		ofstream archivoDatos("datosUsuario.dat");
		usuario* _usuario = IteradorUsuario -> obtenerElemento();

		while (_usuario != NULL) // Se ira por cada nodo buscando los datos para guardalos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
		{
			archivoDatos << _usuario -> archivoUsuario() << "\n";
			_usuario = IteradorUsuario -> proximoElemento();
		}

		archivoDatos.close();
	}
	catch (exception& e)
	{
		throw e;
	}
}

void Validaciones::guardarPlaylist(iteradorLista<listaReproduccion>* IteradorListaReproduccion)
{
	try
	{
		string valor;
		ofstream archivoDatos("datosPlaylist.dat");
		listaReproduccion* _listaReproduccion = IteradorListaReproduccion -> obtenerElemento();

		while (_listaReproduccion != NULL) // Se ira por cada nodo buscando los datos para guardalos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
		{
			archivoDatos << _listaReproduccion -> archivoPlaylist() << "\n";
			_listaReproduccion = IteradorListaReproduccion -> proximoElemento();
		}

		archivoDatos.close();
	}
	catch (exception& e)
	{
		throw e;
	}
}

void Validaciones::mostrarUsuarios(iteradorLista<usuario>* IteradorUsuario)
{
	try
	{
		usuario* _usuario;

		if (IteradorUsuario -> masElementos() == NULL)
		{
			throw exception("No hay usuarios registrados en el sistema");
		}
		else
		{
			cout << "----------------------------------------" << endl;
			cout << "--------- Usuarios Registrados ---------" << endl;
			cout << "----------------------------------------" << endl;
			_usuario = IteradorUsuario -> obtenerElemento();

			while (_usuario != NULL)
			{
				cout << _usuario -> toString();
				_usuario = IteradorUsuario -> proximoElemento();
			}
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

bool Validaciones::verificarUsername(iteradorLista<usuario>* IteradorUsuario, string Username)
{
	try
	{
		usuario* _usuario;

		_usuario = IteradorUsuario -> obtenerElemento();

		while (_usuario != nullptr && _usuario -> getUsername() != Username)
		{
			_usuario = IteradorUsuario -> proximoElemento();
		}

		if (_usuario == nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

bool Validaciones::verificarLista(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string Username, string NombreLista)
{
	listaReproduccion* _listaReproduccion;
	_listaReproduccion = IteradorListaReproduccion -> obtenerElemento();

	while (_listaReproduccion != NULL)
	{
		if (_listaReproduccion -> getUsuario() -> getUsername() == Username && _listaReproduccion -> getNombre() == NombreLista)
		{
			return true;
		}
		_listaReproduccion = IteradorListaReproduccion -> proximoElemento();
	}

	if (_listaReproduccion == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Validaciones::verificarLista2(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string NombreLista)
{
	listaReproduccion* _listaReproduccion;
	_listaReproduccion = IteradorListaReproduccion -> obtenerElemento();

	while (_listaReproduccion != NULL)
	{
		if (_listaReproduccion -> getNombre() == NombreLista)
		{
			return true;
		}
		_listaReproduccion = IteradorListaReproduccion -> proximoElemento();
	}

	if (_listaReproduccion == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Validaciones::verificarCancion(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string NombreLista, string Cancion)
{
	listaReproduccion* _listaReproduccion;
	_listaReproduccion = IteradorListaReproduccion -> obtenerElemento();

	while (_listaReproduccion != NULL)
	{
		if (_listaReproduccion -> getNombre() == NombreLista && _listaReproduccion -> getMusica() -> getNombre() == Cancion)
		{
			return true;
		}
		_listaReproduccion = IteradorListaReproduccion -> proximoElemento();
	}

	if (_listaReproduccion == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Validaciones::contarCanciones(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string Username, string NombreLista)
{
	listaReproduccion* _listaReproduccion;
	int cantidad = 0;
	_listaReproduccion = IteradorListaReproduccion -> obtenerElemento();

	while (_listaReproduccion != NULL && cantidad != 10)
	{
		if (_listaReproduccion -> getNombre() == NombreLista && _listaReproduccion -> getUsuario() -> getUsername() == Username)
		{
			if (_listaReproduccion -> getUsuario() -> getTipoSubscripcion() == "Gratuita")
			{
				cantidad = cantidad + 1;
			}
		}
		_listaReproduccion = IteradorListaReproduccion -> proximoElemento();
	}

	if (cantidad == 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

usuario* Validaciones::obtenerUsuario(iteradorLista<usuario>* IteradorUsuario, string Username)
{
	try
	{
		usuario* _usuario;

		_usuario = IteradorUsuario -> obtenerElemento();

		while (_usuario != nullptr && _usuario -> getUsername() != Username)
		{
			_usuario = IteradorUsuario -> proximoElemento();
		}

		if (_usuario == nullptr)
		{
			throw exception("Ocurrió un error al obtener el usuario");
		}
		else
		{
			return _usuario;
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

nodo<listaReproduccion>* Validaciones::borrarCancion(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string NombreLista, string NombreCancion)
{
	try
	{
		nodo<listaReproduccion>* _reproduccion = NULL;
		listaReproduccion* _listaReproduccion;
		_listaReproduccion = IteradorListaReproduccion -> obtenerElemento();

		while (_listaReproduccion != nullptr && _listaReproduccion -> getNombre() != NombreLista && _listaReproduccion -> getMusica() -> getNombre() != NombreCancion)
		{
			_listaReproduccion = IteradorListaReproduccion -> proximoElemento();
		}

		if (_listaReproduccion == nullptr)
		{
			throw exception("Ocurrió un error al obtener el nodo");
		}
		else
		{
			_reproduccion = IteradorListaReproduccion -> obtenerNodo();
			return _reproduccion;
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void Validaciones::mostrarListasCreadas(iteradorLista<listaReproduccion>* IteradorListaReproduccion)
{
	try
	{
		listaReproduccion* _listaReproduccion;
		vector<string> NombreLista;					// Intente usar un array de String, pero me pedia convertirlo a char, y lo que recibia era un const char*
													// y no pude encontrar forma de convertirlo a char

		if (IteradorListaReproduccion -> masElementos() == NULL)
		{
			throw exception("No hay listas de reproducción registradas en el sistema");
		}
		else
		{
			cout << "----------------------------------------" << endl;
			cout << "---- Listas de Reproducción Creadas ----" << endl;
			cout << "----------------------------------------" << endl;
			_listaReproduccion = IteradorListaReproduccion -> obtenerElemento();

			while (_listaReproduccion != NULL)
			{
				if (find(NombreLista.begin(), NombreLista.end(), _listaReproduccion -> getNombre()) == NombreLista.end())
				{
					cout << _listaReproduccion -> toString();
					NombreLista.push_back(_listaReproduccion -> getNombre());
				}
				
				_listaReproduccion = IteradorListaReproduccion -> proximoElemento();
			}
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

bool Validaciones::mostrarListasUsuario(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string Username)
{
	try
	{
		listaReproduccion* _listaReproduccion;
		vector<string> NombreLista;					// Intente usar un array de String, pero me pedia convertirlo a char, y lo que recibia era un const char*
													// y no pude encontrar forma de convertirlo a char

		_listaReproduccion = IteradorListaReproduccion -> obtenerElemento();

		while (_listaReproduccion != NULL && _listaReproduccion->getUsuario()->getUsername() != Username)
		{
			_listaReproduccion = IteradorListaReproduccion->proximoElemento();
		}

		if (_listaReproduccion == NULL)
		{
			return false;
		}
		else
		{
			cout << "----------------------------------------" << endl;
			cout << "---- Listas de Reproducción Creadas ----" << endl;
			cout << "----------------------------------------" << endl;

			while (_listaReproduccion != NULL)
			{
				if (find(NombreLista.begin(), NombreLista.end(), _listaReproduccion -> getNombre()) == NombreLista.end())
				{
					if (_listaReproduccion -> getUsuario() -> getUsername() == Username)
					{
						cout << _listaReproduccion -> toString();
						NombreLista.push_back(_listaReproduccion->getNombre());
					}
				}
				_listaReproduccion = IteradorListaReproduccion->proximoElemento();
			}
			return true;
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void Validaciones::obtenerLista(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string NombreLista)
{
	try
	{
		listaReproduccion* _listaReproduccion;

		if (IteradorListaReproduccion -> masElementos() == NULL)
		{
			throw exception("No hay listas de reproducción registradas en el sistema");
		}
		else
		{
			cout << "----------------------------------------" << endl;

			_listaReproduccion = IteradorListaReproduccion -> obtenerElemento();

			while (_listaReproduccion != NULL)
			{
				if (_listaReproduccion -> getNombre() == NombreLista)
				{
					cout << _listaReproduccion -> getMusica() -> toString();
				}
				_listaReproduccion = IteradorListaReproduccion -> proximoElemento();
			}
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void Validaciones::obtenerDuracionLista(iteradorLista<listaReproduccion>* IteradorListaReproduccion, string NombreLista)
{
	try
	{
		int duracionTotal = 0;
		listaReproduccion* _listaReproduccion;

		if (IteradorListaReproduccion -> masElementos() == NULL)
		{
			throw exception("No hay listas de reproducción registradas en el sistema");
		}
		else
		{
			cout << "----------------------------------------" << endl;

			_listaReproduccion = IteradorListaReproduccion -> obtenerElemento();

			while (_listaReproduccion != NULL)
			{
				if (_listaReproduccion -> getNombre() == NombreLista)
				{
					duracionTotal = duracionTotal + _listaReproduccion -> getMusica() -> getDuracion();
				}
				_listaReproduccion = IteradorListaReproduccion -> proximoElemento();
			}

			cout << "-- La duración total del playlist es: " << duracionTotal << " segundos" << endl;
			cout << "----------------------------------------" << endl;
			cout << GREEN << "¡Las canciones de la lista de reproducción han sido cargadas con exito!" << RESET << endl << endl;
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}
