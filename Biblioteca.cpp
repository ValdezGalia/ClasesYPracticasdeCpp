#include <iostream>
using namespace std;

struct Libros
{
    string titulo;
    string autor;
    string isbn;
    Libros *prox;
};

bool esVacia(Libros *p_inicial){
    return p_inicial == nullptr;
}

Libros *CrearLibro(string titulo, string autor, string isbn){
    Libros *libro = new Libros;
    libro->titulo = titulo;
    libro->autor = autor;
    libro->isbn = isbn;
    libro->prox = nullptr;
    return libro;
}

void RegistrarLibro(Libros **p_inicial, string titulo, string autor, string isbn){
    Libros *libro = CrearLibro(titulo, autor, isbn);
    libro->prox = *p_inicial;
    *p_inicial = libro;
    cout << "Libro registrado con exito!\n" << endl;
    system("pause");
}

void MostrarLibros(Libros *p_inicial){
    if( esVacia(p_inicial) ){
        cout << "\nNo hay libros registrados" << endl;
    }else{
        Libros *aux = p_inicial;
        int count = 1;

        while( aux != nullptr ){
            cout << "\n\n-------------\n" << "   Libro #" << count << "\n-------------" << endl;
            cout << "Titulo: " << aux->titulo << endl << "Autor: " << aux->autor << endl << "ISBN CODE: " << aux->isbn << endl << "-------------------\n";
            count++;
            aux = aux->prox;
        }

        system("pause");
    }
}

string Nombre(){
    bool ciclo = true;
    string nombre;

    while( ciclo ){
        cout << "Ingrese el nombre del autor: ";
        getline(cin, nombre);

        if(nombre.length() >= 3 ){
            ciclo = false;
            return nombre;
        }else{
            cout << "\nEl nombre del autor ingresado, no es mayor o igual a 3 caracteres.\nIntente Nuevamente!\n";
        }
    }

    return nombre.empty() ? "" : nombre;
}

string Titulo(){
    bool ciclo = true;
    string titulo;

    while( ciclo ){
        cout << "Ingrese el titulo del libro: ";
        getline(cin, titulo);

        if(titulo.length() >= 5 ){
            ciclo = false;
            return titulo;
        }else{
            cout << "\nEl titulo ingresado debe contener de 5 a mas caracteres.\nIntente Nuevamente!\n";
        }
    }

    return titulo.empty() ? "" : titulo;
}

string CodigoISBN(){
    bool ciclo = true;
    string isbn;

    while( ciclo ){
        cout << "Ingrese el codigo de identificacion del libro: ";
        getline(cin, isbn);

        if(isbn.length() > 4 && isbn.length() < 6){
            ciclo = false;
            return isbn;
        }else{
            cout << "\nEl codigo de identificacion ingresado, tiene que ser de 5 caracteres.\nIntente Nuevamente!\n";
        }
    }

    return isbn.empty() ? "" : isbn;
}

void BuscarLibroPorAutor(Libros *p_inicial, string autor){
    if( esVacia(p_inicial) ){
        cout << "\nNo hay libros registrados" << endl;
        system("pause");
    }else{
        Libros *aux = p_inicial;
        int count = 1;

        while ( aux != nullptr ){
            if( aux->autor == autor){
                cout << "\n\n-------------\n" << "   Libro #" << count << "\n-------------" << endl;
                cout << "Titulo: " << aux->titulo << endl << "Autor: " << aux->autor << endl << "ISBN CODE: " << aux->isbn << endl << "-------------------\n";
                count++;
            }

            aux = aux->prox;
        }

        cout << "\nLibros encontrados: " << count - 1 << endl;

        system("pause");
    }
}

void EliminarLibro(Libros *p_inicial, string isbn){
    if( esVacia(p_inicial) ){
        cout << "\nNo hay libros registrados" << endl;
        return;
    }

    Libros *actual = p_inicial;
    Libros *anterior = nullptr;

    while( actual != nullptr && actual->isbn != isbn ){
        anterior = actual;
        actual = actual->prox;
    }

    if( actual == nullptr ){
        cout << "\nNo se encontro el libro con el ISBN: " << isbn << endl;
        return;
    }

    if( actual == p_inicial ){
        p_inicial = p_inicial->prox;
    }else{
        anterior->prox = actual->prox;
    }

    delete actual;
    cout << "\nLibro eliminado con exito!" << endl;
    system("pause");
}

int main(){
    Libros *biblioteca = nullptr;
    bool ciclo = true;
    string titulo, autor, isbn;
    int opcion;

    while( ciclo ){
        cout << "-------------------\n" << "         MENU    " << "\n-------------------" << endl;
        cout << "1. Registrar Libro" << endl << "2. Mostrar Libros" << endl << "3. Buscar libro por Autor" << endl << "4. Eliminar Libro por ISBN" <<endl << "5. Salir" << endl;
        cout << "-------------------" << endl << endl << "Ingrese una opcion del menu: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                titulo = Titulo();
                autor = Nombre();
                isbn = CodigoISBN();
                RegistrarLibro(&biblioteca, titulo, autor, isbn);
            break;

            case 2:
                MostrarLibros(biblioteca);
            break;

            case 3:
                autor = Nombre();
                BuscarLibroPorAutor(biblioteca, autor);
            break;

            case 4:
                isbn = CodigoISBN();
                EliminarLibro(biblioteca, isbn);
            break;
            
            case 5:
                ciclo = false;
                cout << "Adios!" << endl;
            break;
            
            default:
                cout << "Opcion no valida!\nIntente nuevamente\n\n";
            break;
        }


    }
}