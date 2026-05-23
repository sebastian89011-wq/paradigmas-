% El mono y el platano
% Problema clasico: el mono necesita mover la caja,
% subirse y tomar el platano.

% estado(PosMono, PosCaja, MonoEnCaja, TienePlatano)
estado_inicial(estado(puerta, ventana, no, no)).
estado_final(estado(_, _, si, si)).

accion(
    estado(centro, centro, si, no),
    tomar_platano,
    estado(centro, centro, si, si)
).

accion(
    estado(Pos, Pos, no, no),
    subir_caja,
    estado(Pos, Pos, si, no)
).

accion(
    estado(Pos, Pos, no, no),
    empujar_caja(Pos, NuevaPos),
    estado(NuevaPos, NuevaPos, no, no)
) :-
    lugar(NuevaPos),
    Pos \== NuevaPos.

accion(
    estado(PosMono, PosCaja, no, no),
    caminar(PosMono, NuevaPos),
    estado(NuevaPos, PosCaja, no, no)
) :-
    lugar(NuevaPos),
    PosMono \== NuevaPos.

lugar(puerta).
lugar(ventana).
lugar(centro).

resolver(Estado, [], Estado, _) :-
    estado_final(Estado).

resolver(Estado, [Accion | Pasos], Final, Visitados) :-
    accion(Estado, Accion, NuevoEstado),
    no_visitado(NuevoEstado, Visitados),
    resolver(NuevoEstado, Pasos, Final, [NuevoEstado | Visitados]).

solucion(Pasos) :-
    estado_inicial(Inicio),
    resolver(Inicio, Pasos, _, [Inicio]).

no_visitado(_, []).

no_visitado(Estado, [Visitado | Resto]) :-
    Estado \== Visitado,
    no_visitado(Estado, Resto).

% Ejemplo:
% ?- solucion(Pasos).
