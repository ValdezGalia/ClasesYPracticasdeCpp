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
    cout << green << "4." << reset << " Eliminar Episodio de una serie" << endl;
    cout << green << "11." << reset << " Mostrar Series" << endl;
    cout << green << "10." << reset << " Salir" << endl;
    // cout << "3. Agregar Episodio a una serie" << endl;
    // cout << "5. Lista de Series y episodios" << endl;
    // cout << "6. Buscar una Serie por nombre" << endl;
    // cout << "7. Ordenar las series de forma alfabetica" << endl;
    // cout << "8. Top 3 Series por nivel de audiencia" << endl;
    // cout << "9. Mostrar Series" << endl;
}

void EliminarSerie(Series **listaSeries, string nombre){
  if(ListaSeriesVacia(*listaSeries)){
    cout << red << "No existen series para eliminar" << reset << endl;
  }else{
    Series *aux = *listaSeries, *anterior = nullptr;
    

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

    
    delete aux;
    cout << green << "La serie se ha eliminado correctamente" << reset << endl;
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

Episodios *LlenarEpisodios(Episodios **listasEpisodios){
    int cantidad, duracion, numeroEpisodios;
    string titulo;
    cout << "Ingrese la cantidad de episodios que desea agregar: ";
    cin >> cantidad;

    for(int i = 0; i != cantidad; i++){
        titulo = tituloEpisodios();
        duracion = Duracion();
        numeroEpisodios = NumeroEpisodios();

        AgregarEpisodios(listasEpisodios, titulo, duracion, numeroEpisodios);
        cout << green << "Episodio agregado con exito!" << reset << endl;
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

    // Limpiar buffer una sola vez antes del bucle
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

void MostrarSeries(Series *listaSeries){
  if(ListaSeriesVacia(listaSeries)){
    cout << "La lista de series esta vacia!" << endl;
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

    system("pause");
  }
}

void EliminarEpisodioSerie(Series **listaSeries){
  if(ListaSeriesVacia(*listaSeries)){
    cout << red << "No existen series para eliminar el episodio" << reset << endl;
    return;
  }
  
  Series *actualSeries = *listaSeries, *moverEpisodios = *listaSeries;
  
  while(moverEpisodios != nullptr){
    if(ListaEpisodiosVacio(moverEpisodios->listaEpisodios)){
      cout << red << "No existen episodios para eliminar en la serie: " << reset << moverEpisodios->nombre << endl;
    }
    moverEpisodios = moverEpisodios->prox;
  }

  string nombreSerie;
  Episodios *actualEpisodios = nullptr, *anteriorEpisodios = nullptr;

  nombreSerie = NombreSeries();

  while(actualSeries != nullptr && actualSeries->nombre != nombreSerie){
    actualSeries = actualSeries->prox;
  }

    actualEpisodios = actualSeries->listaEpisodios;

  if(actualSeries == nullptr){
    cout << red << "No se encontro serie para eliminar episodios!" << reset << endl;
    return;
    }else{
      int numeroEpisodio = NumeroEpisodios();
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
        delete actualEpisodios;
        cout << green << "El episodio se ha eliminado correctamente" << reset << endl;
        system("pause");
      }
    }
  }

  int main(){
    Series *listaSeries = nullptr;
    Episodios *listaEpisodios = nullptr;
    bool EjecutandoPrograma = true;
    int opcion;
  string nombre;

  while(EjecutandoPrograma){
    MenuPrincipal();
    opcion = OpcionElegidaM();

    switch (opcion)
    {
      case 1:
        LlenarListaSeries(&listaSeries, listaEpisodios);
      break;

      case 2:
        nombre = NombreSeries();
        EliminarSerie(&listaSeries, nombre);
      break;

      case 4:
        EliminarEpisodioSerie(&listaSeries);
      break;

      case 11:
        MostrarSeries(listaSeries);
      break;

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