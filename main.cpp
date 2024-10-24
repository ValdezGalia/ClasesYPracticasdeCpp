#include <iostream>
using namespace std;

struct Pila{
	bool fregar;
	int nPlato;
	char tipoP;
	Pila *prox;
};

// CREACION DE PLATO

Pila* CrearPila(bool fregar, int nPlato, char tipoP){
	Pila *plato = new Pila;
	plato->fregar = fregar;
	plato->nPlato = nPlato;
	plato->tipoP = tipoP;
	plato->prox = nullptr;
	return plato;
}

// ME INDICA SI MI PILA SE ENCUENTRA VACIA

bool PilaVacia(Pila *p){
	return p == nullptr;
}

// ME INSERTA UN NUEVO DATO A MI PILA ESTE VACIA O NO | UTILIZANDO REGLAS LIFO = EL PRIMERO EN ENTRAR ES EL ULTIMO EN SALIR
void Apilar(Pila **p, bool fregar, int nPlato, char tipoP){
	Pila *plato = CrearPila(fregar, nPlato, tipoP);
	plato->prox = *p;
	*p = plato;
}

// ME QUITA UN ELEMENTO DE MI PILA SIGUIENDO EL MISMO CONCEPTO LIFO 

void Desapilar(Pila **p){
	if(!PilaVacia(*p)){
		*p = (*p)->prox;
	}else{
		cout << "La pila se encuentra vacia!" << endl;
	}
}

// SIEMPRE ME VA A DAR EL PRIMER ELEMENTO DE LA PILA
Pila* Tope(Pila *p){
	if(!PilaVacia(p)){
		return p;
	}else{
		return nullptr;
	}
}

void MostrarPila(Pila *p){
	if(PilaVacia(p)){
		cout << "El lavabo se encuentra sin platos\nVuelva cuando hayan platos sucios :)" << endl;
		system("pause");
	}else{
		string tipoPlato;
	    
		while(!PilaVacia(p)){
			if(Tope(p)->tipoP == 'p'){
				Tope(p)->fregar = true;
				cout << "Necesita limpiar los platos de porcelana!" << endl;
				return;
			}else if( Tope(p)->tipoP == 'c' ){
				tipoPlato = "Carton";
				cout << "Tipo de plato: " << tipoPlato << endl;
			}else{
				tipoPlato = "Desechable";
				cout << "Tipo de plato: " << tipoPlato << endl;
			}
			Desapilar(&p);
		}
		system("pause");
	}
	
}

int main() {
	Pila *platos = nullptr;
	int opcion;
	bool fregar, ciclo = true;
	int tipoP, i = 0;
	
	while(ciclo){
		cout << "Menu" << endl;
		cout << "1. Mostrar platos" << endl << "2. Meter plato en el lavabo" << endl << "3. Salir" << endl << endl << "Ingrese una opcion del menu: ";
		cin >> opcion;

		switch (opcion)
		{
			case 1:
				MostrarPila(platos);
			break;

			case 2:
				cout << "Ingrese el tipo de plato a ingresar al labavo\ntomando en cuenta que existen 3 casos\nCarton(1), Porcelana(2), Desechable(3): ";
				cin >> tipoP;
				

				if(tipoP == 2){ 
					fregar = true;
					Apilar(&platos, fregar, i+=1, 'p');
				}else{
					fregar = false;
					if(tipoP == 1){
						Apilar(&platos, fregar, i+=1, 'c');
					}else{
						Apilar(&platos, fregar, i+=1, 'd');
					}
				}
			break;
				
			case 3:
				ciclo = false;
				cout << "Hasta luego" << endl;
			break;
			
			default:
				cout << "Opcion ingresada no valida!\nIntente nuevamente:\n\n";
			break;
		}
	}
}