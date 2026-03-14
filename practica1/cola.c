#include <stdio.h>
#include "sebas.h"

#define MAX_JOBS 10


typedef struct datos
{
    int id;
    char usuario[40];
    char titulos[40];
    int total_pag;
    int restantes;
    int copias;
    Tf_prioridad prioridad;
    Tf_estado estado;

} Ts_datos;

typedef struct
{
    Ts_datos data[MAX_JOBS];
    int size; // cantidad actual de elementos
} QueueStatic_t;

typedef enum
{
    NORMAL,
    URGENTE
} Tf_prioridad;

typedef enum
{
    EN_COLA,
    IMPRIMIENDO,
    COMPLETADO
} Tf_estado;

void qs_init(QueueStatic_t *q);
int qs_is_empty(const QueueStatic_t *q);
int qs_is_full(const QueueStatic_t *q);
int qs_enqueue(QueueStatic_t *q, Ts_datos job);
int qs_peek(const QueueStatic_t *q, Ts_datos *out);
int qs_dequeue(QueueStatic_t *q, Ts_datos *out);
void qs_print(const QueueStatic_t *q);

int main()
{
    int opcion;
    QueueStatic_t q;
    Ts_datos datos;

    qs_init(&q);

    do
    {
        printf("\n===== MENU IMPRESORA =====\n");
        printf("1. Agregar trabajo (enqueue)\n");
        printf("2. Ver siguiente trabajo (peek)\n");
        printf("3. Procesar trabajo (dequeue)\n");
        printf("4. Mostrar cola\n");
        printf("5. Ver si esta vacia\n");
        printf("6. Ver si esta llena\n");
        printf("0. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            qs_enqueue(&q, datos);
            break;

        case 2:
            qs_peek(&q, &datos);
            break;

        case 3:
            qs_dequeue(&q, &datos);
            break;

        case 4:
            qs_print(&q);
            break;

        case 5:
            qs_is_empty(&q);
            break;

        case 6:
            qs_is_full(&q);
            break;

        case 0:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opcion invalida\n");
        }

    } while (opcion != 0);

    return 0;
}

void qs_init(QueueStatic_t *q)
{
    q->size = 0;
}

int qs_is_empty(const QueueStatic_t *q)
{
    if (q->size == 0)
    {
        printf("\nCola vacia\n");
        return 1;
    }

    return 0;
}

int qs_is_full(const QueueStatic_t *q)
{
    if (q->size == MAX_JOBS)
    {
        printf("\nCola llena");
        return 1;
    }

    return 0;
}

int qs_enqueue(QueueStatic_t *q, Ts_datos job)
{
    static int id = 0;
    if (qs_is_full(q) == 0)
    {
        printf("\nNombre: ");
        my_gets(job.usuario, 40);
        printf("\nNombre del documento: ");
        my_gets(job.titulos, 40);
        printf("\nNumero de paginas: ");
        scanf("%d", &job.total_pag);
        printf("\nNumero de copias: ");
        scanf("%d", &job.copias);
        job.restantes = job.total_pag;
        job.prioridad = NORMAL;
        job.estado =EN_COLA;
        job.id = ++id;
        q->data[q->size] = job;
        q->size++;
        return 1;
    }

    return 0;
}

int qs_peek(const QueueStatic_t *q, Ts_datos *out)
{
    if (qs_is_empty(q) == 0)
    {
        *out = q->data[0];

        return 1;
    }
    else
    {
        return 0;
    }
}

int qs_dequeue(QueueStatic_t *q, Ts_datos *out)
{
    if (qs_is_empty(q) == 0)
    {
        *out = q->data[0];
        for (int i = 0; i < q->size - 1; i++)
        {
            q->data[i] = q->data[i + 1];
        }
        q->size--;
        return 1;
    }

    return 0;
}

void qs_print(const QueueStatic_t *q)
{
    int j = 0;
    int restante = 0;
    int contador = 1;
    
    if (qs_is_empty(q) == 0)
    {
        for (int i = 0; i < q->size; i++)
        {
            printf("ID: %d  Usuario: %s  Documento: %s", q->data[i].id, q->data[i].usuario, q->data[i].titulos);
            while( j < q->data[i].copias)
            {

                j++;
                printf("\nCopia %d",j);
                restante = q->data[i].restantes;
                while(restante > 0)
                {
                    
                    printf("\npagina %d de %d",contador,q->data[i].restantes);
                    restante--;
                    contador++;
                    Sleep(300);

                }
                contador = 1;
            }
            j = 0;
            
        }
    }
}