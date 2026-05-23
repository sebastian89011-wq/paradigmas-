% Lista enlazada usando estructuras nodo(Valor, Siguiente).
% nil representa el final de la lista.

lista_ejemplo(nodo(10, nodo(20, nodo(30, nil)))).

vacia(nil).

cabeza(nodo(X, _), X).

cola(nodo(_, Resto), Resto).

pertenece(X, nodo(X, _)).
pertenece(X, nodo(_, Resto)) :-
    pertenece(X, Resto).

longitud(nil, 0).
longitud(nodo(_, Resto), N) :-
    longitud(Resto, N1),
    N is N1 + 1.

insertar_inicio(X, Lista, nodo(X, Lista)).

insertar_final(X, nil, nodo(X, nil)).
insertar_final(X, nodo(Y, Resto), nodo(Y, NuevaLista)) :-
    insertar_final(X, Resto, NuevaLista).

% Ejemplos:
% ?- lista_ejemplo(L), cabeza(L, X).
% ?- lista_ejemplo(L), pertenece(20, L).
% ?- lista_ejemplo(L), longitud(L, N).
% ?- lista_ejemplo(L), insertar_inicio(5, L, Nueva).
% ?- lista_ejemplo(L), insertar_final(40, L, Nueva).
