% Segmentos de recta

punto(a, 0, 0).
punto(b, 4, 0).
punto(c, 4, 3).
punto(d, 0, 3).

segmento(ab, a, b).
segmento(bc, b, c).
segmento(cd, c, d).
segmento(da, d, a).
segmento(ac, a, c).

longitud(P1, P2, L) :-
    punto(P1, X1, Y1),
    punto(P2, X2, Y2),
    DX is X2 - X1,
    DY is Y2 - Y1,
    L is sqrt((DX * DX) + (DY * DY)).

longitud_segmento(S, L) :-
    segmento(S, P1, P2),
    longitud(P1, P2, L).

punto_medio(P1, P2, X, Y) :-
    punto(P1, X1, Y1),
    punto(P2, X2, Y2),
    X is (X1 + X2) / 2,
    Y is (Y1 + Y2) / 2.

pendiente(P1, P2, M) :-
    punto(P1, X1, Y1),
    punto(P2, X2, Y2),
    X1 =\= X2,
    M is (Y2 - Y1) / (X2 - X1).

vertical(P1, P2) :-
    punto(P1, X, _),
    punto(P2, X, _),
    P1 \== P2.

horizontal(P1, P2) :-
    punto(P1, _, Y),
    punto(P2, _, Y),
    P1 \== P2.

% Ejemplos:
% ?- longitud(a, c, L).
% ?- longitud_segmento(ab, L).
% ?- punto_medio(a, c, X, Y).
% ?- horizontal(a, b).
% ?- vertical(b, c).
