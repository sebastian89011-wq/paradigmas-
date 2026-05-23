% Circuitos resistivos
% Formula en serie: Req = R1 + R2
% Formula en paralelo: Req = (R1 * R2) / (R1 + R2)

resistencia(r1, 10).
resistencia(r2, 20).
resistencia(r3, 30).
resistencia(r4, 40).

serie(R1, R2, Req) :-
    Req is R1 + R2.

paralelo(R1, R2, Req) :-
    Req is (R1 * R2) / (R1 + R2).

serie_nombre(A, B, Req) :-
    resistencia(A, R1),
    resistencia(B, R2),
    serie(R1, R2, Req).

paralelo_nombre(A, B, Req) :-
    resistencia(A, R1),
    resistencia(B, R2),
    paralelo(R1, R2, Req).

% Ejemplos:
% ?- serie(10, 20, X).
% ?- paralelo(10, 20, X).
% ?- serie_nombre(r1, r2, X).
% ?- paralelo_nombre(r3, r4, X).
