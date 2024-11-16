#include <iostream>
using namespace std;
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
    cout << "MENU" << endl;
    cout << "1. Agregar Serie" << endl;
    cout << "2. Mostrar Series" << endl;
    // cout << "2. Eliminar Serie con todos sus episodios" << endl;
    // cout << "3. Agregar Episodio a una serie" << endl;
    // cout << "4. Eliminar Episodio de una serie" << endl;
    // cout << "5. Lista de Series y episodios" << endl;
    // cout << "6. Buscar una Serie por nombre" << endl;
    // cout << "7. Ordenar las series de forma alfabetica" << endl;
    // cout << "8. Top 3 Series por nivel de audiencia" << endl;
    // cout << "9. Mostrar Series" << endl;
    cout << "10. Salir" << endl;
}

Episodios *LlenarEpisodios(Episodios **listasEpisodios){
    int cantidad, duracion, numeroEpisodios;
    string titulo;
    cout << "Ingrese la cantidad de episodios que desea agregar: ";
    cin >> cantidad;

    for(int i = 0; i != cantidad; i++){
        cout << "Ingrese el titulo del episodio: ";
        cin >> titulo;

        cout << "Ingrese la duracion del episodio: ";
        cin >> duracion;

        cout << "Ingrese el numero del episodio: ";
        cin >> numeroEpisodios;

        AgregarEpisodios(listasEpisodios, titulo, duracion, numeroEpisodios);
    }
    
    if(cantidad == 0){
      cout << "Despues puede agregar episodios a sus series si asi lo desea!" << endl;
      return nullptr;
    }else{
      return *listasEpisodios;
    }
}


string NombreSeries(){
  string nombre;
  bool ciclo = true;
  
  while(ciclo){
    cout << "Ingrese el nombre de la serie: ";
    getline(cin, nombre);
    
    if(nombre.size() < 2){
      cout << "El nombre de la serie no puede ser menor a 2 caracteres" << endl << "Intente nuevamente: " << endl;
    }else{
      ciclo = false;
      return nombre;
    }
  }
}

string GeneroSeries(){
  string genero;
  bool ciclo = true;
  
  while(ciclo){
    cout << "Ingrese el nombre de la serie: ";
    getline(cin, genero);
    
    if(genero.size() < 2){
      cout << "El genero de la serie no puede ser menor a 2 caracteres" << endl << "Intente nuevamente: " << endl;
    }else{
      ciclo = false;
      return genero;
    }
  }
}

int NivelAudiencia(){
  int audiencia;
  bool ciclo = true;
  
  while(ciclo){
    cout << "Ingresa el numero de audiencia de la serie: ";
    cin >> audiencia;
    
    if(audiencia < 0){
      cout << "El numero de la audiencia no puede ser un numero negativo!" << endl << "Intente nuevamente: " << endl;
    }else{
      ciclo = false;
      return audiencia;
    }
  }
}

void LlenarListaSeries(Series **listaSeries, Episodios **listaEpisodios){
    // Variables de las series
    string nombre, genero;
    int nivelAudi, opcion;
    Episodios *episodios = nullptr;
    bool agregarEpisodio = true;
    
    nombre = NombreSeries();
    genero = GeneroSeries();
    nivelAudi = NivelAudiencia();
    
    cout << "¿Deseas agregar episodios a tu serie?\n1) Si\n2) No\nIngrese una opcion: ";
    cin >> opcion;
    
    if(opcion != 1){
      
    }
    
    
    if(!agregarEpisodio){
      cout << "Puedes ingresarles episodios despues a las series!" << endl;
    }else{
      episodios = LlenarEpisodios(listaEspisodios);
    }
    
    AgregarSeries(listaSeries, nombre, genero, nivelAudi, episodios);
    cout << "Serie agregada con exito" << endl << endl;
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
            cout << "\tNumero de episodios: " << actual->numeroEpisodios << endl;
            cout << "\tTitulo: " << actual->Titulo << endl;
            cout << "\tDuracion: " << actual->Duracion << endl;
            cout << "----------------------" << endl;
            actual = actual->prox;
        }
    }
}

void MostrarSeries(Series *listaSeries){
    if(ListaSeriesVacia(listaSeries)){
        cout << "La lista de series esta vacia!" << endl;
    }else{
        Series *actual = listaSeries;

        while(actual != nullptr){
            cout << "Nombre de serie: " << actual->nombre << endl;
            cout << "Genero: " << actual->genero << endl;
            cout << "Nivel de audiencia: " << actual->nivelAud << endl;
            cout << "Episodios: " << endl;
            MostrarEpisodios(actual->listaEpisodios);
            actual = actual->prox;
        }
    }
}

int main(){
    Series *listaSeries = nullptr;
    Episodios *listaEpisodios = nullptr;
    bool EjecutandoPrograma = true;
    int opcion;

    while(EjecutandoPrograma){
        MenuPrincipal();
        opcion = OpcionElegidaM();

        switch (opcion)
        {
            case 1:
                LlenarListaSeries(&listaSeries, &listaEpisodios);
            break;
            case 2:
                MostrarSeries(listaSeries);
            break;


            case 10:
                cout << "Programa finalizado" << endl;
                EjecutandoPrograma = false;
            break;
            
            default:
                cout << "Opcion no valida" << endl;
            break;
        }
    }

}