#include <iostream>
using namespace std;

struct Libros
{
    string titulo;
    string autor;
    string isbn;
    Libros *prox;
};

Libros* RegistrarLibro(string titulo, string autor, string isbn){
    Libros *libro = new Libros;
    libro->titulo = titulo;
    libro->autor = autor;
    libro->isbn = isbn;
    libro->prox = nullptr;
    return libro;
}

bool ListaVacia(Libros *p_inicial){
    return p_inicial == nullptr;
}

void MostrarLibros(Libros *p_inicial){
    if( !ListaVacia( p_inicial ) ){
        Libros *p_aux = p_inicial;
        int contadorLibros = 1;

        while( p_aux != nullptr ){
            cout << endl << "---------------\n" << "Libro #" << contadorLibros << "\n---------------\n";
            cout << "Titulo: " << p_aux->titulo << "\nAutor: " << p_aux->autor << "\nCodigo: " << p_aux->isbn << "\n--------------" << endl;
            contadorLibros++;
            p_aux = p_aux->prox;
        }
    }else{
        cout << endl << "La biblioteca se encuentra vacia!" << endl;
    }
}

void InsertarLibro(Libros **p_inicial, string titulo, string autor, string isbn){
    Libros *libro = RegistrarLibro(titulo, autor, isbn);
    libro->prox = *p_inicial;
    *p_inicial = libro;
}

string Nombre(){
    bool ciclo = true;
    string nombre;

    while( ciclo ){
        cout << "Ingrese el nombre del autor: ";
        cin >> nombre;

        if(nombre.length() >= 3 ){
            ciclo = false;
            return nombre;
        }else{
            cout << "\nEl nombre del autor ingresado, no es mayor o igual a 3 caracteres.\nIntente Nuevamente!\n";
        }
    }
}

string Titulo(){
    bool ciclo = true;
    string titulo;

    while( ciclo ){
        cout << "Ingrese el titulo del libro: ";
        cin >> titulo;

        if(titulo.length() >= 5 ){
            ciclo = false;
            return titulo;
        }else{
            cout << "\nEl titulo ingresado debe contener de 5 a mas caracteres.\nIntente Nuevamente!\n";
        }
    }
}

string CodigoISBN(){
    bool ciclo = true;
    string isbn;

    while( ciclo ){
        cout << "Ingrese el codigo de identificacion del libro: ";
        cin >> isbn;

        if(isbn.length() > 4 && isbn.length() < 6){
            ciclo = false;
            return isbn;
        }else{
            cout << "\nEl codigo de identificacion ingresado, tiene que ser de 5 caracteres.\nIntente Nuevamente!\n";
        }
    }
}

int main(){
    bool ciclo = true;
    int opcion;
    string titulo, autor, isbn;
    Libros *biblioteca = nullptr;

    while( ciclo ){
        cout << endl << "--------------------------" << endl << "|          MENU          |" << endl << "--------------------------" << endl;
        cout << "| 1. Libros disponibles  |" << endl << "| 2. Registrar libro \t |" << endl << "| 3. Salir \t\t |" << endl << "--------------------------" << endl << endl << "Ingrese una opcion del menu: ";
        cin >> opcion;

        switch (opcion){
            case 1:
                MostrarLibros(biblioteca);
            break;
            
            case 2:
                titulo = Titulo();
                autor = Nombre();
                isbn = CodigoISBN();

                InsertarLibro(&biblioteca, titulo, autor, isbn);
            break;

            case 3:
                ciclo = false;
                cout << "\nVuelva Pronto!" << endl;
            break;
            
            default:
                cout << endl << "Opcion ingresada invalida!" << endl; 
            break;
        }

    }

}