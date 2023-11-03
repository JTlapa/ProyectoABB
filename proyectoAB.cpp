#include <iostream>
using namespace std;

class Arbol;

class Nodo{
    string nombre;
    int frecuencia;
    Nodo* izq;
    Nodo* der;
    friend class Arbol;
    public:
	    Nodo();
	    Nodo(string nom);
		void setNombre(string nom);
		void setFrecuencia(int fr);
		void setIzq(Nodo *p);
		void setDer(Nodo *p);
		string getNombre();
		int getFrecuencia();
		Nodo* getIzq();
		Nodo* getDer();
};
Nodo::Nodo(){
    nombre = "A";
    frecuencia = 1;
    izq = NULL;
    der = NULL;
}
Nodo::Nodo(string nom){
    nombre = nom;
    frecuencia = 1;
    izq = NULL;
    der = NULL;
}
typedef Nodo* pNodo;

class Arbol{
	pNodo raiz;
	public:
		Arbol();
		~Arbol();//metodo pendiente
		int estaVacio();
		void insertaNodo(pNodo &p, string nom);
		void insertar(string nom);
		void eliminaNodo(pNodo &p, string nom);
		void eliminar(string nom);
		
		void mostrarPreOrden(pNodo p);
		void mostrarInOrden(pNodo p);
		void mostrarPosOrden(pNodo p);
		void mostrar(int a);
};

Arbol::Arbol(){
	raiz = NULL;
}
int Arbol::estaVacio(){
	return raiz==NULL;
}
void Arbol::insertaNodo(pNodo &p, string nom){
	if(p==NULL){
		p = new Nodo(nom);
		
	}
	else if(p->nombre == nom){
		p->frecuencia ++;
	}
	else if(nom < p->nombre){
		insertaNodo(p->izq,nom);
	}
	else if(nom > p->nombre){
		insertaNodo(p->der,nom);
	}
}
void Arbol::insertar(string nom){
	insertaNodo(raiz,nom);
}
void Arbol::mostrarPreOrden(pNodo p){
	if(p!=NULL){
		cout<<"["<<p->nombre<<","<<p->frecuencia<<"] ";
		mostrarPreOrden(p->izq);
		mostrarPreOrden(p->der);
	}
}
void Arbol::mostrarInOrden(pNodo p){
	if(p!=NULL){
		mostrarInOrden(p->izq);
		cout<<"["<<p->nombre<<","<<p->frecuencia<<"] ";
		mostrarInOrden(p->der);
	}
}
void Arbol::mostrarPosOrden(pNodo p){
	
}
void Arbol::mostrar(int a){
	
	switch(a){
		case 1:
			cout<<"\tArbol en pre-orden:\n";
			mostrarPreOrden(raiz);
			break;
		case 2:
			cout<<"\tArbol en in-orden:\n";
			mostrarInOrden(raiz);
			break;
		case 3:
			cout<<"\tArbol en pos-orden:\n";
			mostrarPosOrden(raiz);
			break;
	}
}

int main(){
	int n;
	cin>>n;
	Arbol* arbol = new Arbol();
	cin.ignore();
	for(int i=0;i<n;i++){
		string nombre;
		getline(cin,nombre);
		arbol->insertar(nombre);
		
	}
	
	arbol->mostrar(2);
	
	return 0;
}
