% Torre de Hanoi
% Mueve N discos desde una torre origen hasta una torre destino,
% usando una torre auxiliar.

hanoi(N) :-
    mover(N, izquierda, derecha, centro).

mover(1, Origen, Destino, _) :-
    write('Mover disco de '),
    write(Origen),
    write(' a '),
    write(Destino),
    nl.

mover(N, Origen, Destino, Auxiliar) :-
    N > 1,
    M is N - 1,
    mover(M, Origen, Auxiliar, Destino),
    mover(1, Origen, Destino, Auxiliar),
    mover(M, Auxiliar, Destino, Origen).

% Ejemplos:
% ?- hanoi(3).
% ?- mover(2, a, c, b).
