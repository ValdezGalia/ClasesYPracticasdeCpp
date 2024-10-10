#include <iostream>
using namespace std;

struct Numbers
{
    int numero;
    Numbers *prox;
};

Numbers *CrearNumber(int numero){
    Numbers *nuevoNumero = new Numbers;
    nuevoNumero->numero = numero;
    nuevoNumero->prox = NULL;
    return nuevoNumero;
}

void InsertarNuevoNumero(Numbers **p_inicial, int valor){
    Numbers *numero = CrearNumber(valor);
    numero->prox = *p_inicial;
    *p_inicial = numero; 
}

bool ListaVacia(Numbers *p_inicial){
    return p_inicial == NULL;
}

void MostrarListaNumerica(Numbers *p_inicial){
    if( !ListaVacia(p_inicial) ){
        Numbers *p_aux = p_inicial;

        while( p_aux != nullptr ){
            cout << " -> " <<  p_aux->numero;
            p_aux = p_aux->prox;
        }
    }else{
        cout << "La lista se encuentra vacia!" << endl;
    }
}

int ValorNumerico(){
    int valor;
    cout << "Ingrese el valor que desea insertar: ";
    cin >> valor;
    return valor;
}

void BuscarPorValor(Numbers *p_inicial, int valor){
    if(ListaVacia(p_inicial)){
        cout << "La lista se encuentra vacia!" << endl;
    }else{
        Numbers *p_aux = p_inicial;

        while( p_aux != nullptr){
            if( p_aux->numero == valor ){
                cout << "El numero fue encontrado: " << p_aux->numero << endl;
            }
            p_aux = p_aux -> prox;
        }

        
    }
}

void EliminarNumero(Numbers *p_inicial, int valor){

    if(ListaVacia(p_inicial)){
        cout << "La lista se encuentra vacia!" << endl;
    }else{
        Numbers *p_aux = p_inicial;

        // while(){}

        
    }


}

int main(){
    Numbers *listaNumeros = nullptr;
    int opcion, valor;
    bool ciclo = true;
    
    while(ciclo){
        cout << "\n===============" << endl << " MENU " << endl << "===============" << endl;
        cout << "1. Mostrar Lista" << endl << "2. Insertar elemento en la lista" << endl << "3. Buscar Elemento" << endl << "4. Salir" << endl << endl << "Ingrese una opcion del menu: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                MostrarListaNumerica(listaNumeros);
            break;

            case 2:
                valor = ValorNumerico();
                InsertarNuevoNumero(&listaNumeros, valor);
            break;

            case 3:
                valor = ValorNumerico();
                BuscarPorValor(listaNumeros, valor);
            break;

            case 4:
                cout << endl << "Usted ha salido de la app" << endl;
                ciclo = false;
            break;

            default:
                cout << endl << "Opcion ingresada invalida!" << endl << "Vuelva a intentarlo: " << endl;
            break;
        }
    }
}