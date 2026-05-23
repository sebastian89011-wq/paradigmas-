
% Máximo entre dos números
maximo(X, Y, X) :- X >= Y.
maximo(X, Y, Y) :- X < Y.

% Mínimo entre dos números
minimo(X, Y, X) :- X =< Y.
minimo(X, Y, Y) :- X > Y.