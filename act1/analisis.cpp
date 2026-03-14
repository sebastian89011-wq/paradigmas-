#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
	int dato;
	struct node_s* siguiente;
} node_t;

node_t* crearNodo(int dato) {
	node_t* nuevoNodo = (node_t*)malloc(sizeof(node_t));

	if (nuevoNodo == NULL) {
		printf("...\n");
		return NULL;
	}

	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = NULL;

	return nuevoNodo;
}

void insertarNodo(node_t** cabeza, int dato) {
	node_t* nuevoNodo = crearNodo(dato);

	if (*cabeza == NULL) {
		*cabeza = nuevoNodo;
	} else {
		node_t* actual = *cabeza;
		while(actual->siguiente != NULL) 
        {
			actual = actual->siguiente;
		}

		actual->siguiente = nuevoNodo;
	}
}

void imprimirLista(node_t* cabeza) {
	node_t* actual = cabeza;

	printf("HEAD -> ");

	while(actual != NULL) {
		printf("%d -> ", actual->dato);
		actual = actual->siguiente;
	}
	printf("NULL\n");
}

int main() {
	node_t* cabeza = NULL;

	insertarNodo(&cabeza, 1);
	insertarNodo(&cabeza, 3);
	insertarNodo(&cabeza, 5);
	imprimirLista(cabeza);

	return 0;
}

/*
IDENT: dato, siguiente, crearNodo, insertarNodo, actual, cabeza, imprimirLista, node_S, printf, main, malloc , null
SIMBOLO: ; , * , ** , & , (), {}, > , < ,# , .
constantes: 1,3,5
Literales: "HEAD ->" , "NULL\n" ,"...\n"
Operadores: =,==,!=, ->
Keywords: int , return, void,while, if ,struct, sizeof, include

*/