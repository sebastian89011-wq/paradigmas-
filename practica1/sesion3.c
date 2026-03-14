#include <stdio.h>
#include "sebas.h"

#define MAX_JOBS 10

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

typedef struct Node_t
{
    Ts_datos job;
    struct Node_t *next;
} Node_t;

typedef struct
{
    Node_t *head;
    Node_t *tail;
    int size;
} QueueDynamic_t;

Node_t *crear_nodo(Ts_datos job);
void qd_init(QueueDynamic_t *q);
int qd_is_empty(const QueueDynamic_t *q);
int qd_enqueue(QueueDynamic_t *q, Ts_datos job);
int qd_peek(const QueueDynamic_t *q, Ts_datos *out);
int qd_dequeue(QueueDynamic_t *q, Ts_datos *out);
int mostrar_cola(QueueDynamic_t *q);
void qd_destroy(QueueDynamic_t *q);

int main()
{
    int opcion;
    QueueDynamic_t q;
    Ts_datos datos;
    int id = 1;

    qd_init(&q);

    do
    {
        printf("\n===== MENU IMPRESORA =====\n");
        printf("1. Agregar trabajo (enqueue)\n");
        printf("2. Ver siguiente trabajo (peek)\n");
        printf("3. Procesar trabajo (dequeue)\n");
        printf("4. Mostrar cola\n");
        printf("5. Ver si esta vacia\n");
        printf("6. vaciar lista\n");
        printf("0. Salir\n");
        printf("Seleccione opcion: ");
        opcion = validar(0,6,"");
       

        switch (opcion)
        {
        case 1:
            datos.id = id++;
            printf("Ingrese Usuario: ");
            my_gets(datos.usuario, 40);

            printf("Ingrese Título: ");
            my_gets(datos.titulos, 40);

            printf("Ingrese Total de páginas: ");
            scanf("%d", &datos.total_pag);

            printf("Ingrese Copias: ");
            scanf("%d", &datos.copias);
            datos.estado = EN_COLA;
            printf("\nCual es la prioridad de su impresion (1.NORMAL, 2. URGENTE)");
            getchar();
            if (getchar() == '1')
            {
                datos.prioridad = NORMAL;
            }
            else
            {
                datos.prioridad = URGENTE;
            }

            qd_enqueue(&q, datos);
            break;

        case 2:
            qd_peek(&q, &datos);
            break;

        case 3:
            qd_dequeue(&q, &datos);
            break;

        case 4:
            mostrar_cola(&q);
            break;

        case 5:
            qd_is_empty(&q);
            break;

        case 6:
            qd_destroy(&q);
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

void qd_init(QueueDynamic_t *q)
{
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
}

int qd_is_empty(const QueueDynamic_t *q)
{
    if (q->size == 0)
    {
        printf("\nCola vacia\n");
        return 1;
    }

    return 0;
}

Node_t *crear_nodo(Ts_datos job)
{
    Node_t *nuevo_nodo = (Node_t *)malloc(sizeof(Node_t));
    static int id = 1;
    if (nuevo_nodo == NULL)
    {
        printf("\nError al asignar memoria");
        return NULL;
    }

    nuevo_nodo->job.copias = job.copias;
    nuevo_nodo->job.id = id++;
    nuevo_nodo->job.restantes = job.total_pag;
    nuevo_nodo->job.total_pag = job.total_pag;
    strcpy(nuevo_nodo->job.titulos, job.titulos);
    strcpy(nuevo_nodo->job.usuario, job.usuario);
    nuevo_nodo->next = NULL;

    return nuevo_nodo;
}

int qd_enqueue(QueueDynamic_t *q, Ts_datos job)
{
    Node_t *nuevo_nodo = crear_nodo(job);

    if (nuevo_nodo == NULL)
    {
        printf("\nError al asignar memoria");
        return 0;
    }

    if (job.estado == NORMAL)
    {
      
        if (q->tail == NULL)
        {
            q->tail = nuevo_nodo;
            q->head = nuevo_nodo;
        }
        else
        {
            q->tail->next = nuevo_nodo;
            q->tail = nuevo_nodo;
        }
    }
    else
    {
        if(q->tail == NULL)
        {
            q->tail = nuevo_nodo;
            q->head = nuevo_nodo;
        }
        else
        {
            nuevo_nodo = q->head;
            q->head = nuevo_nodo;
        }
    }
    
    q->size++;
    return 1;
}

int qd_peek(const QueueDynamic_t *q, Ts_datos *out)
{
    if (qd_is_empty(q) == 0)
    {
        *out = q->head->job;
        printf("ID: %d\nUsuario: %s\nTítulo: %s\nTotal páginas: %d\nCopias: %d\nPrioridad: %d\nEstado: %d\n", q->head->job.id, q->head->job.usuario, q->head->job.titulos, q->head->job.total_pag, q->head->job.copias, q->head->job.prioridad, q->head->job.estado);
    }
}

int qd_dequeue(QueueDynamic_t *q, Ts_datos *out)
{
    Node_t *aux;
    if (qd_is_empty(q) == 0)
    {
        aux = q->head;
        if (q->size == 1)
        {
            q->head = NULL;
            q->tail = NULL;
        }
        else
        {
            *out = q->head->job;
            q->head = q->head->next;
        }
        free(aux);
        q->size--;
        return 1;
    }
    return 0;
}

int mostrar_cola(QueueDynamic_t *q)
{
    Node_t *actual;
    int restantes = 0;
    int contador = 0;
    actual = q->head;
    while (actual != NULL)
    {
        printf("ID: %d\nUsuario: %s\nTítulo: %s\nTotal páginas: %d\nCopias a realizar: %d", q->head->job.id, q->head->job.usuario, q->head->job.titulos, q->head->job.total_pag, q->head->job.copias);
        for (int i = 1; i <= actual->job.copias; i++)
        {
            printf("\nCopia %d: ", i);
            restantes = actual->job.restantes;
            while (restantes > 0)
            {
                contador++;
                printf("\npagina %d de %d", contador, actual->job.total_pag);
                restantes--;
                Sleep(300);
            }
            contador = 0;
        }

        actual = actual->next;
    }
}

void qd_destroy(QueueDynamic_t *q)
{

    if (qd_is_empty(q) == 0)
    {
        Node_t *aux;
        while (q->tail != NULL)
        {
            aux = q->head;
            q->head = q->head->next;
            free(aux);
        }
    }
}