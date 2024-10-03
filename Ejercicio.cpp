#include <iostream>
using namespace std;

struct Numeros{
    int number;
    Numeros *prox;
};

Numeros *ListaNumerica(int n){
    Numeros *lNum = new Numeros;
    lNum->number = n;
    lNum->prox = nullptr;
    return lNum;
}

bool listaVacia(Numeros *comienzo){
    return comienzo == nullptr;
}

int ValorListaNumerica(){
    int x;
    cout << endl << "Inserte un valor para la lista: ";
    cin >> x;

    return x;
}

void insertarListaNumerica(Numeros **principio, int valor){
    Numeros *nuevoValor = ListaNumerica(valor);
    nuevoValor->prox = *principio;
    *principio = nuevoValor;
}

void mostrarListaNumerica(Numeros *principio){
   Numeros *mover;

    if (!listaVacia(principio)){
        mover = principio;

        while (mover != NULL){
            cout << mover->number << endl;
            mover = mover->prox;
        }
    }else{
        cout<<"Lista esta vacia"<<endl;
    }

}

int main(){
    /*  Agregar un elemento X a una lista después de un valor N dado por el usuario. Ejemplo:
        3. L1= {1,33,7,22,1,4,5} N=7, X=777 => L1={1,33,7,777,22,1,4,5} . Realizar las validaciones
        pertinentes. 
    */
    int n, opcionMenu;
    Numeros *lnum = nullptr; 
    bool ciclo = true;
    string enter;

    while(ciclo){
        cout << "============ MENU ============" << endl << "1) Mostrar Lista Numerica" << endl << "2) Insertar al final de la lista" << endl << endl << "Eliga una opcion: ";
        cin >> opcionMenu;

        switch (opcionMenu)
        {
        case 1:
            if( !listaVacia(lnum) ){
                mostrarListaNumerica(lnum);
                cout << endl << "Presione la tecla ( + ) seguido de enter, para volver al menu: ";
                cin >> enter;
            }else{
                cout << "La Lista se encuentra vacia!" << endl;
                cout << endl << "Presione la tecla ( + ) seguido de enter, para volver al menu: ";
                cin >> enter;
            }

        break;

        case 2:
            insertarListaNumerica(&lnum, ValorListaNumerica());
            cout << endl << "Presione la tecla ( + ) seguido de enter, para volver al menu: ";
            cin >> enter;

        break;
        
        default:
            cout << "Opcion ingresada no valida!" << endl;
            cout << "Presione la tecla ( + ) seguido de enter, para volver al menu: ";
            cin >> enter;
            break;
        }
    }




    // cout << "========================" << endl << "Indique Un valor: ";
    // cin >> n;
    // cout << "========================";


}