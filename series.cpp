#include <iostream>
#include <string>
#include <limits>
using namespace std;

string red = "\033[31m";
string green = "\033[32m";
string yellow = "\033[33m";
string blue = "\033[34m";
string reset = "\033[0m";

struct Episodios{
    string Titulo;
    int Duracion;
    int numeroEpisodios;
    Episodios *prox;
};

struct Series{
    string nombre;
    string genero;
    int nivelAud;
    Episodios *listaEpisodios;
    Series *prox;
};


// Funciones de Series

Series *CrearSerie(string nombre, string genero, int nivelAud, Episodios *listaEpisodios){
    Series *nuevaSerie = new Series;
    nuevaSerie->nombre = nombre;
    nuevaSerie->genero = genero;
    nuevaSerie->nivelAud = nivelAud;
    nuevaSerie->listaEpisodios = listaEpisodios;
    nuevaSerie->prox = nullptr;
    return nuevaSerie;
}

bool ListaSeriesVacia(Series *lista){
    return lista == nullptr;
}

void AgregarSeries(Series **lista, string nombre, string genero, int nivelAud, Episodios *listaEpisodios){
    Series *nuevaSerie = CrearSerie(nombre, genero, nivelAud, listaEpisodios);
    nuevaSerie->prox = *lista;
    *lista = nuevaSerie;
}

// Funciones de Episodios

Episodios *CrearEpisodios(string titulo, int duracion, int numeroEpisodios){
    Episodios *nuevosEpisodios = new Episodios;
    nuevosEpisodios->Titulo = titulo;
    nuevosEpisodios->Duracion = duracion;
    nuevosEpisodios->numeroEpisodios = numeroEpisodios;
    nuevosEpisodios->prox = nullptr;
    return nuevosEpisodios;
}

bool ListaEpisodiosVacio(Episodios *listaEpi){
    return listaEpi == nullptr;
}

void AgregarEpisodios(Episodios **listaEpi, string titulo, int duracion, int numeroEpisodios){
    Episodios *nuevosEpisodios = CrearEpisodios(titulo, duracion, numeroEpisodios);
    nuevosEpisodios->prox = *listaEpi;
    *listaEpi = nuevosEpisodios;
}

void MenuPrincipal(){
    cout << green << "MENU" << reset << endl;
    cout << green << "1." << reset << " Agregar Serie" << endl;
    cout << green << "2." << reset << " Eliminar Serie con todos sus episodios" << endl;
    // cout << "3. Agregar Episodio a una serie" << endl;
    cout << green << "4." << reset << " Eliminar Episodio de una serie" << endl;
    cout << green << "5." << reset << " Lista de Series y episodios" << endl;
    cout << green << "6." << reset << " Buscar una Serie por nombre" << endl;
    // cout << "7. Ordenar las series de forma alfabetica" << endl;
    // cout << "8. Top 3 Series por nivel de audiencia" << endl;
    cout << green << "9." << reset << " Mostrar Series" << endl;
    cout << green << "10." << reset << " Salir" << endl;
}

void MostrarListadoSeries(Series *listaSeries){
  if(ListaSeriesVacia(listaSeries)){
    cout << yellow << "La lista de series esta vacia!" << reset << endl;
  }else{
    Series *actual = listaSeries;
    int contador = 1;
    while(actual != nullptr){
      cout << green << contador << ". " << reset << actual->nombre << endl;
      actual = actual->prox;
      contador++;
    }
  }

  system("pause");
}

string NombreEliminarSeries() {
    string nombre;
    bool ciclo = true;

    // Limpiar buffer una sola vez antes del bucle
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (ciclo) {
        cout << "Ingrese el nombre de la serie que desea eliminar: ";
        getline(cin, nombre);
        if (nombre.size() > 2) { 
            ciclo = false; // Salir del bucle si la longitud es válida
        } else {
            cout << red << "El nombre debe tener más de 2 caracteres. Intente nuevamente." << reset << endl;
        }
    }
    return nombre;
}

void EliminarSerie(Series **listaSeries){
  system("cls");
  cout << "=======================================" << endl;
  cout << green << "Eliminar Serie con todos sus episodios" << reset << endl;
  cout << "=======================================" << endl;

  if(ListaSeriesVacia(*listaSeries)){
    cout << red << "No existen series para eliminar" << reset << endl;
  }else{
    Series *aux = *listaSeries, *anterior = nullptr;
    string nombre;

    cout << green << "Lista de series disponibles para eliminar: " << reset << endl;
    MostrarListadoSeries(*listaSeries);
    nombre = NombreEliminarSeries();

    while(aux != nullptr && aux->nombre != nombre){
      anterior = aux;
      aux = aux->prox;
    }

    if(aux == nullptr){
      cout << red << "La serie no fue encontrada o no existe" << reset << endl;
      return;
    }

    if(anterior == nullptr){
      *listaSeries = aux->prox;
    }else{
      anterior->prox = aux->prox;
    }

    
    cout << green << "La serie " << reset << aux->nombre << green << " se ha eliminado correctamente" << reset << endl;
    delete aux;
    system("pause");
  }
}

string tituloEpisodios() {
    string titulo;
    bool ciclo = true;

    // Limpiar buffer una sola vez antes del bucle
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (ciclo) {
      cout << "Ingrese el titulo del episodio: ";
      getline(cin, titulo);
      if (titulo.size() > 2){
        ciclo = false; // Salir del bucle si la longitud es válida
      } else {
        cout << red << "El titulo debe tener más de 2 caracteres. Intente nuevamente." << reset << endl;
      }
    }

    return titulo;
}

int Duracion() {
  int duracion;
  bool ciclo = true;

  while (ciclo) {
    cout << "Ingresa la duracion del episodio: ";
    cin >> duracion;

    if (duracion) { // Verifica si la entrada es válida (un número entero)
      if (duracion > 0) {
        ciclo = false; // Salir del bucle si el número es positivo
      } else {
        cout << red << "La duracion debe ser un número mayor a 0. Intente nuevamente." << reset << endl;
      }
    } else {
      // Si la entrada no es válida, limpiar el buffer y mostrar mensaje
      cout << red << "Entrada invalida. Por favor, ingrese un numero entero positivo." << reset << endl;
      cin.clear(); // Limpiar el estado de error
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada incorrecta
    }
  }

  return duracion;
}

int NumeroEpisodios() {
  int nEpisodios;
  bool ciclo = true;

  while (ciclo) {
    cout << "Ingresa el numero del episodio: ";
    cin >> nEpisodios;

    if (nEpisodios) { // Verifica si la entrada es válida (un número entero)
      if (nEpisodios > 0) {
        ciclo = false; // Salir del bucle si el número es positivo
      } else {
        cout << red << "El numero de episodio debe ser un número mayor a 0. Intente nuevamente." << reset << endl;
      }
    } else {
      // Si la entrada no es válida, limpiar el buffer y mostrar mensaje
      cout << red << "Entrada invalida. Por favor, ingrese un numero entero positivo." << reset << endl;
      cin.clear(); // Limpiar el estado de error
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada incorrecta
    }
  }

  return nEpisodios;
}

int NumeroEpisodiosEliminar() {
  int nEpisodios;
  bool ciclo = true;

  while (ciclo) {
    cout << "Ingresa el numero del episodio que desea eliminar: ";
    cin >> nEpisodios;

    if (nEpisodios) { // Verifica si la entrada es válida (un número entero)
      if (nEpisodios > 0) {
        ciclo = false; // Salir del bucle si el número es positivo
      } else {
        cout << red << "El numero de episodio debe ser un número mayor a 0. Intente nuevamente." << reset << endl;
      }
    } else {
      // Si la entrada no es válida, limpiar el buffer y mostrar mensaje
      cout << red << "Entrada invalida. Por favor, ingrese un numero entero positivo." << reset << endl;
      cin.clear(); // Limpiar el estado de error
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada incorrecta
    }
  }

  return nEpisodios;
}

bool EpisodioExiste(Episodios *listaEpisodios, int numeroEpisodio){
  if(ListaEpisodiosVacio(listaEpisodios)){
    return false;
  }else{
    bool encontrado = false;
    Episodios *actual = listaEpisodios;

    while(actual != nullptr){
      if(actual->numeroEpisodios == numeroEpisodio){
        encontrado = true;
      }
      actual = actual->prox;
    }

    return encontrado;
  }
}

int NumeroEpisodioNoExistente(Episodios *listaEpisodios, int nEpisodio){
  if(ListaEpisodiosVacio(listaEpisodios)){
    return nEpisodio;
  }else{
    int numeroEpisodios = nEpisodio;
    bool ciclo = true;
    
    while(ciclo){
      if(EpisodioExiste(listaEpisodios, numeroEpisodios)){
        cout << yellow << "El episodio" << reset << " #" << numeroEpisodios << yellow << ", ya existe dentro de la serie, intente nuevamente." << reset << endl;
      }else{
        ciclo = false;
        return numeroEpisodios;
      }
      numeroEpisodios = NumeroEpisodios();
    }

    return numeroEpisodios;
  }
}

Episodios *LlenarEpisodios(Episodios **listasEpisodios){
  int cantidad, duracion, numeroEpisodios, episodioExistente;
  string titulo;
  cout << "Ingrese la cantidad de episodios que desea agregar: ";
  cin >> cantidad;

  for(int i = 0; i != cantidad; i++){
    system("cls");
    cout << "===============" << endl;
    cout << green << "Agregar Serie" << reset << endl;
    cout << "===============" << endl;
    cout << green << "Cantidad episodios agregador: " << reset << i;
    cout << endl << endl;
    
    titulo = tituloEpisodios();
    duracion = Duracion();
    cout << "Ingrese el numero del episodio: ";
    cin >> episodioExistente;

    numeroEpisodios = NumeroEpisodioNoExistente(*listasEpisodios, episodioExistente);
    
    AgregarEpisodios(listasEpisodios, titulo, duracion, numeroEpisodios);
    cout << green << "Episodio agregado con exito!" << reset << endl;
    system("pause");
  }
  
  if(cantidad == 0){
    cout << yellow << "Despues puede agregar episodios a sus series si asi lo desea!" << reset << endl;
    return nullptr;
  }else{
    return *listasEpisodios;
  }
}


string NombreSeries() {
  string nombre;
  bool ciclo = true;

  // Limpiar buffer una sola vez antes del bucle
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while (ciclo) {
    cout << "Ingrese el nombre de la serie: ";
    getline(cin, nombre);
    if (nombre.size() > 2) { 
      ciclo = false; // Salir del bucle si la longitud es válida
    } else {
      cout << red << "El nombre debe tener más de 2 caracteres. Intente nuevamente." << reset << endl;
    }
  }
  return nombre;
}

string NombreEliminarEpisodios() {
    string nombre;
    bool ciclo = true;

    // Limpiar buffer una sola vez antes del bucle
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (ciclo) {
      cout << "Ingrese el nombre de la serie para eliminar su episodio: ";
      getline(cin, nombre);
      if (nombre.size() > 2) { 
        ciclo = false; // Salir del bucle si la longitud es válida
      } else {
        cout << red << "El nombre debe tener más de 2 caracteres. Intente nuevamente." << reset << endl;
      }
    }
    return nombre;
}

int NivelAudiencia() {
  int audiencia;
  bool ciclo = true;

  while (ciclo) {
    cout << "Ingresa el numero de audiencia de la serie: ";
    cin >> audiencia;

    if (audiencia) { // Verifica si la entrada es válida (un número entero)
      if (audiencia > 0) {
        ciclo = false; // Salir del bucle si el número es positivo
      } else {
        cout << red << "La audiencia debe ser un número mayor a 0. Intente nuevamente." << reset << endl;
      }
    } else {
      // Si la entrada no es válida, limpiar el buffer y mostrar mensaje
      cout << red << "Entrada invalida. Por favor, ingrese un numero entero positivo." << reset << endl;
      cin.clear(); // Limpiar el estado de error
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada incorrecta
    }
  }

  return audiencia;
}

string GeneroSeries(){
    string genero;
    bool ciclo = true;
    while (ciclo) {
      cout << "Ingrese el genero de la serie: ";
      getline(cin, genero);
      if (genero.size() > 2) { 
        ciclo = false; // Salir del bucle si la longitud es válida
      } else {
        cout << red << "El genero debe tener más de 2 caracteres. Intente nuevamente." << reset << endl;
      }
    }
    return genero;
}

void LlenarListaSeries(Series **listaSeries, Episodios *listaEpisodios){
  // Variables de las series
  system("cls");
  cout << "===============" << endl;
  cout << green << "Agregar Serie" << reset << endl;
  cout << "===============" << endl;
  string nombre, genero;
  int nivelAudi, opcion;
  bool agregarEpisodio = true;
  Episodios *episodios = nullptr;
  
  // Llamamos a funciones auxiliares que controlan el tema del buffer he impiden que el programa se salte las variables string
  nombre = NombreSeries();
  genero = GeneroSeries();
  nivelAudi = NivelAudiencia();
  
  cout << green << "Deseas agregar episodios a tu serie?" << reset << green << "\n1)" << reset <<" Si" << green << "\n2)" << reset << " No\nIngrese una opcion: ";
  cin >> opcion;
  
  cin.clear(); // Limpiar posibles errores de entrada
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer restante

  if (opcion != 1) {
    agregarEpisodio = false;
  }

  if (!agregarEpisodio) {
    cout << yellow << "Puedes ingresarles episodios despues a las series!" << reset << endl;
  } else {
    episodios = LlenarEpisodios(&listaEpisodios);
  }
  
  AgregarSeries(listaSeries, nombre, genero, nivelAudi, episodios);
  cout << green << "Serie agregada con exito" << reset << endl << endl;
  system("pause");
}

int OpcionElegidaM(){
  int opcion;
  cout << endl << "Elija una opcion: ";
  cin >> opcion;
  return opcion;
}

void MostrarEpisodios(Episodios *listaEpisodios){
  if(ListaEpisodiosVacio(listaEpisodios)){
    cout << "La lista de episodios esta vacia!" << endl;
  }else{
    Episodios *actual = listaEpisodios;
    while(actual != nullptr){
      cout << "----------------------" << endl;
      cout << green << "Numero de episodios: " << reset << actual->numeroEpisodios << endl;
      cout << green << "Titulo: " << reset << actual->Titulo << endl;
      cout << green << "Duracion: " << reset << actual->Duracion << " minutos" << endl;
      cout << "----------------------" << endl;
      actual = actual->prox;
    }
  }
}

int NumeroEpisodios(Episodios *listaEpisodios){
  if(ListaEpisodiosVacio(listaEpisodios)){
    return 0;
  }else{
    Episodios *actual = listaEpisodios;
    int contador = 0;

    while(actual != nullptr){
      contador++;
      actual = actual->prox;
    }

    return contador;
  }
}

void MostrarSeriesYEpisodios(Series *listaSeries){
  if(ListaSeriesVacia(listaSeries)){
    cout << yellow << "La lista de series esta vacia!" << reset << endl;
  }else{
    Series *actual = listaSeries;
    int contador = 1;
    int nEpisodios = 0;

    while(actual != nullptr){
      nEpisodios = NumeroEpisodios(actual->listaEpisodios);
      cout << "SERIE #" << contador << " -------------" << endl;
      cout << green << "Nombre de serie: " << reset << actual->nombre << endl;
      cout << green << "Genero: " << reset << actual->genero << endl;
      cout << green << "Nivel de audiencia: " << reset << actual->nivelAud << endl;
      cout << green << "Episodios: " << reset << nEpisodios << endl;
      MostrarEpisodios(actual->listaEpisodios);
      contador++;
      actual = actual->prox;
    }
  }

  system("pause");
}

void EliminarEpisodioSerie(Series **listaSeries){
  if(ListaSeriesVacia(*listaSeries)){
    cout << red << "No existen series para eliminar el episodio" << reset << endl;
    return;
  }
  
  Series *actualSeries = *listaSeries, *moverEpisodios = *listaSeries;
  bool hayEpisodios = false;
  
  while(moverEpisodios != nullptr){
    if(!ListaEpisodiosVacio(moverEpisodios->listaEpisodios)){
      hayEpisodios = true;
    }
    moverEpisodios = moverEpisodios->prox;
  }
  if(!hayEpisodios){
    cout << red << "No existen episodios para eliminar en ninguna serie!" << reset << endl;
    return;
  }
  
  moverEpisodios = *listaSeries;
  string nombreSerie;
  Episodios *actualEpisodios = nullptr, *anteriorEpisodios = nullptr;

  cout << green << "Lista de series con episodios: " << reset << endl;

  for(int i = 1; moverEpisodios != nullptr; i++){
    if(!ListaEpisodiosVacio(moverEpisodios->listaEpisodios)){
      cout << green << i << ". " << reset << moverEpisodios->nombre << endl;
    }
    moverEpisodios = moverEpisodios->prox;
  }
  
  cout << endl;
  nombreSerie = NombreEliminarEpisodios();

  while(actualSeries != nullptr && actualSeries->nombre != nombreSerie){
    actualSeries = actualSeries->prox;
  }

  actualEpisodios = actualSeries->listaEpisodios;

  if(actualSeries == nullptr){
    cout << red << "No se encontro serie para eliminar episodios!" << reset << endl;
    return;
  }else{
    cout << green << "Lista de episodios de la serie " << actualSeries->nombre << ":" << reset << endl;
    MostrarEpisodios(actualSeries->listaEpisodios);
    int numeroEpisodio = NumeroEpisodiosEliminar();

    while(actualEpisodios != nullptr && actualEpisodios->numeroEpisodios != numeroEpisodio){
      anteriorEpisodios = actualEpisodios;
      actualEpisodios = actualEpisodios->prox;
    }

    if(actualEpisodios == nullptr){
      cout << red << "No se encontro el episodio para eliminar!" << reset << endl;
      return;
    }else{
      if(anteriorEpisodios == nullptr){
        actualSeries->listaEpisodios = actualEpisodios->prox;
      }else{
        anteriorEpisodios->prox = actualEpisodios->prox;
      }
      cout << green << "El episodio" << reset << " #" << actualEpisodios->numeroEpisodios << green << " se ha eliminado correctamente de la serie " << reset << actualSeries->nombre << endl;
      delete actualEpisodios;
      system("pause");
    }
  }
}

void BuscarSeriePorNombre(Series *listaSeries){
  if(ListaSeriesVacia(listaSeries)){
    cout << "No existen series para buscar!" << endl;
  }else{
    string nombreSerie = NombreSeries();
    Series *actual = listaSeries;

    while(actual != nullptr && actual->nombre != nombreSerie){
      actual = actual->prox;
    }

    if(actual == nullptr){
      cout << red << "No se encontro la serie!" << reset << endl;
    }else{
      int opcion, nEpisodios = NumeroEpisodios(actual->listaEpisodios);

      cout << green << "Serie encontrada!" << reset << endl;
      cout << green << "Nombre: " << reset << actual->nombre << endl;
      cout << green << "Genero: " << reset << actual->genero << endl;
      cout << green << "Nivel de audiencia: " << reset << actual->nivelAud << endl;
      cout << green << "Episodios: " << reset << nEpisodios << endl;

      cout << "\n" << yellow << "Desea mostrar los episodios de la serie?" << reset << endl << yellow << "1."<< reset << " Si" << yellow << "\n2." << reset << " No" << endl;
      cout << yellow << "Opcion: " << reset;
      cin >> opcion;

      if(opcion != 2) MostrarEpisodios(actual->listaEpisodios);
    }
  }
  system("pause");
}

int main(){
  Series *listaSeries = nullptr;
  Episodios *listaEpisodios = nullptr;
  bool EjecutandoPrograma = true;
  int opcion;

  while(EjecutandoPrograma){
    system("cls");
    MenuPrincipal();
    opcion = OpcionElegidaM();

    switch (opcion)
    {
      // Agregar series
      case 1:
        LlenarListaSeries(&listaSeries, listaEpisodios);
      break;

      // Eliminar series con todos sus episodios
      case 2:
        EliminarSerie(&listaSeries);
      break;

      // Eliminar episodios de una serie concreta
      case 4:
        EliminarEpisodioSerie(&listaSeries);
      break;

      // Mostrar listado de series y episodios de las series
      case 5:
        MostrarSeriesYEpisodios(listaSeries);
      break;

      // Buscar una serie por su nombre
      case 6:
        BuscarSeriePorNombre(listaSeries);
      break;

      // Muestra unicamente el listado de las series por su nombre
      case 9:
        cout << green << "Listado de series:" << reset << endl;
        MostrarListadoSeries(listaSeries);
      break;

      // Terminar con la ejecucion de la aplicacion
      case 10:
        cout << "Programa finalizado" << endl;
        EjecutandoPrograma = false;
      break;
      
      default:
        cout << red << "Opcion no valida" << reset << endl;
      break;
    } 
  }
}