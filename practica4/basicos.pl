
% Hechos
persona(juan).
persona(maria).

estudia(juan).
trabaja(maria).

% Reglas
ocupado(X) :- estudia(X).
ocupado(X) :- trabaja(X).
