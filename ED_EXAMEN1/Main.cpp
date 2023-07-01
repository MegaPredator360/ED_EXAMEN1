#include "Validaciones.h"
 //♫

void color(int color)		// Darle color a la opcion en la consola
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)	// Direccionar el cursor
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}



int main()
{
	// Listas
	lista<usuario> _listaUsuario;
	lista<listaReproduccion> _listaReproduccion;

	// Iteradores
	iteradorLista<usuario>* IteradorUsuario;
	iteradorLista<listaReproduccion>* IteradorListaReproduccion;

	// Llamados a clases
	Validaciones _validaciones;

	// Llamados a punteros
	musica* _musica;
	usuario* _usuario;
	listaReproduccion* _reproduccion;

	// Nodo para borrar;
	nodo<listaReproduccion>* _nodoReproduccion;

	// Variables para el menú
	setlocale(LC_ALL, "");						// Para mostrar caracteres especiales
	char key;

	// Variables para datos
	string nombre;
	string nombreLista;
	string username;
	string tipoSubscripcion;
	string artista;
	int duracion;
	string confirmacion;

	// Pantalla Inicial

	cout << endl << endl;
	cout << "	     ;                                                                  ;;;;;;;;;;;;;;;;;;;" << endl;
	cout << "	     ;;                           ______  ___                           ;;;;;;;;;;;;;;;;;;;" << endl;
	cout << "	     ;';.                        (  /    ( / \\                          ;                 ;" << endl;
	cout << "	     ;  ;;                         /--    /  /                          ;                 ;" << endl;
	cout << "	     ;   ;;                      (/____/(/\__/                           ;                 ;" << endl;
	cout << "	     ;    ;;                                                            ;                 ;" << endl;
	cout << "	     ;    ;;        ______                               _              ;                 ;" << endl;
	cout << "	     ;   ;'        (  /                                  /              ;                 ;" << endl;
	cout << "	     ;  '            /--   _.,  __,  _ _ _   _  _ _     /               ;                 ;" << endl;
	cout << "	,;;;,;             (/____// /\\_(_/(_/ / / /_(/_/ / /_  /           ,;;;;;            ,;;;;;" << endl;
	cout << "	;;;;;;                                                             ;;;;;;            ;;;;;;" << endl;
	cout << "	`;;;;'                                                             `;;;;'            `;;;;" << endl;
	cout << endl << endl;
	cout << "				Examen realizado por:" << endl;
	cout << "			      Aaron Steve Alfaro Zamora" << endl;
	cout << "			     Luis Fabián Arrieta González" << endl;
	cout << endl << endl;

	system("pause");


	while (1)
	{
		system("cls");
		int counter = 1;
		int Set[] = { 7, 7, 7, 7, 7, 7, 7 };		// Colores por defecto
		Set[0] = 12;

		cout << "		[]------------------------------------------[]" << endl;
		cout << "		|                Menú Principal              |" << endl;
		cout << "		[]------------------------------------------[]" << endl;
		cout << "		|                                            |" << endl;
		cout << "		|           Selecciona una opción:           |" << endl;
		cout << "		|";

		for (int i = 0;;)
		{

			gotoxy(30, 5);
			color(Set[0]);
			cout << "1. Agregar Usuario";

			cout << RESET << "	     |" << endl;
			cout << "		|";

			gotoxy(24, 6);
			color(Set[1]);
			cout << "2. Agregar canción a Playlist";

			cout << RESET << "	     |" << endl;
			cout << "		|";

			gotoxy(23, 7);
			color(Set[2]);
			cout << "3. Eliminar canción de Playlist";

			cout << RESET << "       |" << endl;
			cout << "		|";

			gotoxy(19, 8);
			color(Set[3]);
			cout << "4. Mostrar duración total de la playlist";

			cout << RESET << "  |" << endl;
			cout << "		|";

			gotoxy(23, 9);
			color(Set[4]);
			cout << "5. Mostrar canciones del playlist";

			cout << RESET << "     |" << endl;
			cout << "		|";

			gotoxy(18, 10);
			color(Set[5]);
			cout << "6. Cambiar tipo de subscipcion del usuario";

			cout << RESET << " |" << endl;
			cout << "		|";

			gotoxy(35, 11);
			color(Set[6]);
			cout << "7. Salir";

			cout << RESET << "                  |" << endl;
			cout << "		|                                            |" << endl;
			cout << "		[]------------------------------------------[]" << endl;

			key = _getch();

			if (key == 72 && (counter >= 1 && counter <= 7))		// Validar si la flecha arriba es pulsada	|| 72 es el valor de la flecha arriba en ASCII
			{
				counter--;

				if (counter == 0)
				{
					counter = 7;
				}
			}
			else if (key == 80 && (counter >= 1 && counter <= 7))	// Validar si la flecha abajo es pulsada	|| 80 es el valor de la flecha abajo en ASCII
			{
				counter++;

				if (counter == 8)
				{
					counter = 1;
				}
			}
			else if (key == '\r')	// Identifica si la tecla ENTER fue pulsada
			{
				switch (counter)
				{
				case 1:
					try
					{
						confirmacion = "N";

						while (confirmacion == "N")
						{
							int numTipoSubscripcion = 0;

							system("cls");
							cout << endl;
							cout << "		[]------------------------------------------[]" << endl;
							cout << "		|               Agregar Usuario              |" << endl;
							cout << "		[]------------------------------------------[]" << endl;
							cout << endl;

							cout << "Ingresa el nombre del usuario:" << endl;
							getline(cin, nombre);

							while (nombre == "")
							{
								cout << endl << RED << "El nombre no puede estar vacio, ingresa el nombre de usuario:" << RESET << endl;
								getline(cin, nombre);
							}

							cout << endl << "Ingresa un username para el usuario:" << endl;
							getline(cin, username);

							IteradorUsuario = _listaUsuario.obtenerIterador();
							while (_validaciones.verificarUsername(IteradorUsuario, username) || username == "")
							{
								cout << endl << RED << "El usuario ingresado ya esta registrado o el espacio esta vacio, ingresa nuevamente el username: " << RESET << endl;
								getline(cin, username);
								IteradorUsuario = _listaUsuario.obtenerIterador();
							}

							cout << endl << "¿Que tipo de subscripcion quiere usar?" << endl;
							cout << YELLOW << "1) Gratuita:" << RESET << " Solo podrás ingresar 10 canciones por playlist." << endl;
							cout << YELLOW << "2) Premium:" << RESET << " No tendrás limite al ingresar canciones en cualquier playlist." << endl;
							cout << YELLOW << "3) Familiar:" << RESET << " Podrás compartir esta subscripción Premium con 5 miembros de tu familia." << endl;
							numTipoSubscripcion = stoi(_validaciones.ingresarNumeros());

							while (numTipoSubscripcion <= 0 || numTipoSubscripcion >= 4)
							{
								cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
								numTipoSubscripcion = stoi(_validaciones.ingresarNumeros());
							}

							switch (numTipoSubscripcion)
							{
							case 1:
								tipoSubscripcion = "Gratuita";
								break;

							case 2:
								tipoSubscripcion = "Premium";
								break;

							case 3:
								tipoSubscripcion = "Familiar";
								break;
							}

							cout << "------------------------------------------" << endl;
							cout << "¿La información ingresada es correcta? [S/n]" << endl;
							confirmacion = _validaciones.confirmacionDefS();

							if (confirmacion == "S")
							{
								_usuario = new usuario(username, nombre, tipoSubscripcion);
								_listaUsuario.agregar(_usuario);

								cout << GREEN << "¡Los datos fueron ingresados con exito!" << RESET << endl;
								system("pause");
							}
						}
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << RESET << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al menu principal." << endl << endl;
						system("pause");
					}
					break;

				case 2:
					try
					{
						confirmacion = "N";
						system("cls");
						cout << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << "		|        Agregar canciones a playlist        |" << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << endl;

						_validaciones.mostrarUsuarios(_listaUsuario.obtenerIterador());

						cout << endl << "Ingresa el username del usuario:" << endl;
						getline(cin, username);

						IteradorUsuario = _listaUsuario.obtenerIterador();
						while (_validaciones.verificarUsername(IteradorUsuario, username) == false)
						{
							cout << endl << RED << "El username ingresado no existe, vuelve a ingresar el username:" << RESET << endl;
							getline(cin, username);
							IteradorUsuario = _listaUsuario.obtenerIterador();     // Para reiniciar la lista del iterador al inicio
						}

						cout << endl << "¿Desea agregar una cancion a una playlist existente? [S/n]" << endl;
						confirmacion = _validaciones.confirmacionDefS();

						if (confirmacion == "S")
						{
							if (_validaciones.mostrarListasUsuario(_listaReproduccion.obtenerIterador(), username))
							{
								cout << endl << "Ingresa el nombre de la lista de reproducción:" << endl;
								getline(cin, nombreLista);
								
								while (nombreLista == "" || !_validaciones.verificarLista(_listaReproduccion.obtenerIterador(), username, nombreLista))
								{
									cout << endl << RED << "Lo ingresado no existe o el espacio quedó vacio, favor ingresar el nombre del playlist" << RESET << endl;
									getline(cin, nombreLista);
								}

								if (_validaciones.contarCanciones(_listaReproduccion.obtenerIterador(), username, nombreLista))
								{
									cout << endl << RED << "La lista de reproduccion tiene más de 10 canciones registradas." << RESET << endl;
									cout << RED << "Debes de crear una nueva lista de reproduccion o cambiar tu tipo de subscripcion." << RESET << endl;
									cout << "Ingresa el nombre de la nueva lista de reproducción" << endl;
									getline(cin, nombreLista);

									while (nombreLista == "" || _validaciones.verificarLista(_listaReproduccion.obtenerIterador(), username, nombreLista))
									{
										cout << endl << RED << "Lo ingresado ya existe o el espacio quedó vacio, favor ingresar el nombre del playlist" << RESET << endl;
										getline(cin, nombreLista);
									}
								}
							}
							else
							{
								cout << endl << RED << "No hay playlists creadas por este usuario, deberas de crear una playlist." << RESET << endl;
								cout << endl << "Ingresa el nombre de la lista de reproducción:" << endl;
								getline(cin, nombreLista);

								while (nombreLista == "")
								{
									cout << endl << RED << "El espacio quedó vacio, favor ingresar el nombre del playlist" << RESET << endl;
									getline(cin, nombreLista);
								}
							}
						}
						else
						{
							cout << endl << "Ingresa el nombre de la lista de reproducción:" << endl;
							getline(cin, nombreLista);

							while (nombreLista == "" || _validaciones.verificarLista(_listaReproduccion.obtenerIterador(), username, nombreLista))
							{
								cout << endl << RED << "El espacio quedó vacio o un playlist con el mismo nombre ya fue creado, favor ingresar el nombre del playlist" << RESET << endl;
								getline(cin, nombreLista);
							}
						}

						cout << endl << "Ingrese el nombre de la canción:" << endl;
						getline(cin, nombre);

						while (nombre == "")
						{
							cout << endl << RED << "El nombre no puede estar vacio, ingresa el nombre de la canción:" << RESET << endl;
							getline(cin, nombre);
						}

						cout << endl << "Ingrese el nombre del artista:" << endl;
						getline(cin, artista);

						while (artista == "")
						{
							cout << endl << RED << "El nombre no puede estar vacio, ingresa el nombre del artista:" << RESET << endl;
							getline(cin, artista);
						}

						cout << endl << "Ingrese la duracion de la cancion. " << YELLOW << "(En segundos)" << RESET << endl;
						duracion = stoi(_validaciones.ingresarNumeros());
						
						IteradorUsuario = _listaUsuario.obtenerIterador();
						_usuario = _validaciones.obtenerUsuario(IteradorUsuario, username);

						_musica = new musica(nombre, artista, duracion);
						_reproduccion = new listaReproduccion(nombreLista, _usuario, _musica);

						_listaReproduccion.agregar(_reproduccion);

						cout << "------------------------------------------" << endl;
						cout << GREEN << "¡Los datos fueron ingresados con exito!" << RESET << endl;
						system("pause");
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << RESET << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al menu principal." << endl << endl;
						system("pause");
					}

					break;

				case 3:
					try {
						system("cls");
						cout << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << "		|      Eliminar una canción del playlist     |" << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << endl;

						_validaciones.mostrarListasCreadas(_listaReproduccion.obtenerIterador());

						cout << endl << "Ingresa el nombre del playlist:" << endl;
						getline(cin, nombreLista);

						while (!_validaciones.verificarLista2(_listaReproduccion.obtenerIterador(), nombreLista))
						{
							cout << RED << "El nombre de la lista ingresado no existe, favor volver a ingresar el nombre del playlist:" << RESET << endl;
							getline(cin, nombreLista);
						}

						_validaciones.obtenerLista(_listaReproduccion.obtenerIterador(), nombreLista);

						cout << endl << "Ingresa el nombre de la canción a eliminar:" << endl;
						getline(cin, nombre);

						while (!_validaciones.verificarCancion(_listaReproduccion.obtenerIterador(), nombreLista, nombre))
						{
							cout << RED << "La cancion ingresada no existe en el playlist, favor volver a ingresar una cancion valida:" << RESET << endl;
							getline(cin, nombre);
						}

						_nodoReproduccion = _validaciones.borrarCancion(_listaReproduccion.obtenerIterador(), nombreLista, nombre);

						_listaReproduccion.eliminarNodo(_nodoReproduccion);
						cout << "-------------------------------------" << endl;
						cout << GREEN << "¡La canción ha sido eliminada con exito!" << RESET << endl;
						system("pause");
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << RESET << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al menu principal." << endl << endl;
						system("pause");
					}

					break;

				case 4:
					try {
						system("cls");
						cout << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << "		|         Duración total del playlist        |" << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << endl;

						IteradorListaReproduccion = _listaReproduccion.obtenerIterador();
						_validaciones.mostrarListasCreadas(IteradorListaReproduccion);

						cout << endl << "Ingresa el nombre de la lista de reproducción:" << endl;
						getline(cin, nombreLista);
						cout << endl;

						while (!_validaciones.verificarLista2(_listaReproduccion.obtenerIterador(), nombreLista))
						{
							cout << RED << "El nombre de la lista ingresado no existe, favor volver a ingresar el nombre del playlist:" << RESET << endl;
							getline(cin, nombreLista);
						}

						IteradorListaReproduccion = _listaReproduccion.obtenerIterador();
						_validaciones.obtenerDuracionLista(IteradorListaReproduccion, nombreLista);
						system("pause");
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << RESET << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al menu principal." << endl << endl;
						system("pause");
					}
					break;

				case 5:
					try {
						system("cls");
						cout << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << "		|       Mostrar canciones del playlist       |" << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << endl;

						IteradorListaReproduccion = _listaReproduccion.obtenerIterador();
						_validaciones.mostrarListasCreadas(IteradorListaReproduccion);

						cout << endl << "Ingresa el nombre de la lista de reproducción:" << endl;
						getline(cin, nombreLista);
						cout << endl;

						while (!_validaciones.verificarLista2(_listaReproduccion.obtenerIterador(), nombreLista))
						{
							cout << RED << "El nombre de la lista ingresado no existe, favor volver a ingresar el nombre del playlist:" << RESET << endl;
							getline(cin, nombreLista);
						}

						IteradorListaReproduccion = _listaReproduccion.obtenerIterador();
						_validaciones.obtenerLista(IteradorListaReproduccion, nombreLista);
						cout << GREEN << "¡Las canciones de la lista de reproducción han sido cargadas con exito!" << RESET << endl << endl;
						system("pause");

					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << RESET << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al menu principal." << endl << endl;
						system("pause");
					}
					break;

				case 6:
					try {
						int numTipoSubscripcion = 0;

						system("cls");
						cout << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << "		|       Cambiar el tipo de subscripcion      |" << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << endl;

						_validaciones.mostrarUsuarios(_listaUsuario.obtenerIterador());

						cout << endl << "Ingresa el username del usuario:" << endl;
						getline(cin, username);

						while (_validaciones.verificarUsername(_listaUsuario.obtenerIterador(), username) == false)
						{
							cout << endl << RED << "El username ingresado no existe, vuelve a ingresar el username:" << RESET << endl;
							getline(cin, username);
						}

						cout << endl << "¿Que tipo de subscripcion quiere usar?" << endl;
						cout << YELLOW << "1) Gratuita:" << RESET << " Solo podrás ingresar 10 canciones por playlist." << endl;
						cout << YELLOW << "2) Premium:" << RESET << " No tendrás limite al ingresar canciones en cualquier playlist." << endl;
						cout << YELLOW << "3) Familiar:" << RESET << " Podrás compartir esta subscripción Premium con 5 miembros de tu familia." << endl;
						numTipoSubscripcion = stoi(_validaciones.ingresarNumeros());

						while (numTipoSubscripcion <= 0 || numTipoSubscripcion >= 4)
						{
							cout << RED << "El número ingresado no coincide con ninguna de las opciones, ingresa un número que coincida con las opciones: " << RESET << endl;
							numTipoSubscripcion = stoi(_validaciones.ingresarNumeros());
						}

						_usuario = _validaciones.obtenerUsuario(_listaUsuario.obtenerIterador(), username);

						switch (numTipoSubscripcion)
						{
						case 1:
							_usuario -> setTipoSubscripcion("Gratuita");
							break;

						case 2:
							_usuario -> setTipoSubscripcion("Premium");
							break;

						case 3:
							_usuario -> setTipoSubscripcion("Familiar");
							break;
						}

						cout << "-----------------------------------------------" << endl;
						cout << GREEN << "La subscripcion fue cambiada con exito" << RESET << endl << endl;
						system("pause");
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << RESET << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al menu principal." << endl << endl;
						system("pause");
					}

					break;

				case 7:

					try
					{
						exit(0);
					}
					catch (exception& e) {
						cout << RED << "Ha ocurrido un error: " << RESET << e.what() << endl;
						cout << "-------------------------" << endl;
						cout << "Volviendo al menu principal." << endl << endl;
						system("pause");
					}
					break;

				default:
					cout << RED << "Seleccione una opcion valida. " << RESET << endl;
				}

				break;	// Para salir del ciclo for
			}

			// Color por defecto de todas las opciones
			Set[0] = 7;				// 7 es el color blanco
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;
			Set[4] = 7;
			Set[5] = 7;
			Set[6] = 7;

			// Cambiar color basado en la opcion seleccionada
			switch (counter)
			{
			case 1:
				Set[0] = 12;		// 12 es el color rojo
				break;

			case 2:
				Set[1] = 12;		// 12 es el color rojo
				break;

			case 3:
				Set[2] = 12;		// 12 es el color rojo
				break;

			case 4:
				Set[3] = 12;		// 12 es el color rojo
				break;

			case 5:
				Set[4] = 12;		// 12 es el color rojo
				break;

			case 6:
				Set[5] = 12;		// 12 es el color rojo
				break;

			case 7:
				Set[6] = 12;		// 12 es el color rojo
				break;
			}
		}
	}

return 0;
}