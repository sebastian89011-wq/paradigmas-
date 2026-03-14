#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>





char *my_gets(char *cadena, int tamano)
{
    size_t longitud;
    fflush(stdin);
    if (fgets(cadena, tamano, stdin) == NULL)
        return NULL;
    longitud = strlen(cadena);
    if (longitud > 0 && cadena[longitud - 1] == '\n')
    {
        cadena[longitud - 1] = '\0';
    }
    return cadena;
}
void copiar_str_seguro(char cadena1[], const char cadena2[], int tam_destino)
{
    int i;
    for (i = 0; i < tam_destino - 1 && cadena2[i] != '\0'; i++)
    {
        cadena1[i] = cadena2[i];
    }
    cadena1[i] = '\0';  
}
void limpiar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        
    }
        
}
int validar(int min, int max, const char *mensaje)
{
    int num;
    do
    {
        printf("%s", mensaje);
        if (scanf("%d", &num) != 1)
        {
            limpiar_buffer();
            printf("Entrada invalida. Intenta de nuevo.\n");
            continue;
        }
        limpiar_buffer();
        if (num < min || num > max)
        {
            printf("Valor fuera de rango (%d - %d). Intenta de nuevo.\n", min, max);
        }
        else
            break;
    } while (1);
    return num;
}
int validar_num()
{
    char cadena[30];
    int valor = 0, i = 0;
    if (fgets(cadena, 30, stdin) == NULL)
        return -1;
    while (cadena[i] == ' ' || cadena[i] == '\t')
        i++;
    if (cadena[i] == '\n' || cadena[i] == '\0')
        return -1;
    for (; cadena[i] != '\0' && cadena[i] != '\n'; i++)
    {
        if (cadena[i] >= '0' && cadena[i] <= '9')
        {
            valor = valor * 10 + (cadena[i] - '0');
        }
        else
        {
            return -1;
        }
    }
    return valor;
}
/*

int busqueda_secuencial_vector(Ts_indice vector[], int *n, Tkey valor)
{
    int i;
    for (i = 0; i < *n; i++)
    {
        if (vector[i].llave == valor)
        {
            return i;
        }
    }
    return -1;
}

int busqueda_secuencial_matriz(int matriz[4][4], int valor)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (matriz[i][j] == valor)
            {
                return 1;
            }
        }
    }
    return -1;
}


void copiar_str(char cadena1[], char cadena2[])
{
    int i;
    for (i = 0; cadena2[i] != '\0'; i++)
    {
        cadena1[i] = cadena2[i];  
    }
    cadena1[i] = '\0';
}


int buscar_valor(int vector[], int n, int valor)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vector[i] == valor)
        {
            return i;
        }
    }
    return -1;
}




void convertir_mayusculas(char cadena[])
{
    int i;
    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - 32;
        }
    }
}



int validar_fecha(int anio, int mes, int dia)
{
    int cantidad;

    int ano[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (anio % 4 == 0)
    {
        ano[2] = 29;
    }
    cantidad = ano[mes];
    if (dia > cantidad)
    {
        printf("\nFecha incorrecta , favor de volver a ingresar");
        return 1;
    }

    return 0;
}


int validar_edad(int anio , int edad)
{
    if(edad != (2025 - anio))
    {
        printf("\nLa edad y la fecha no corresponden");
        return -1;

    }

    return 0;

}



void burbuja(Ts_indice vector[], int *n)
{
    Ts_indice temp;
    int j;
    for (int i = 0; i < *n; i++)
    {
        for (j = 0; j < *n - 1; j++)
        {
            if (vector[j].llave > vector[j + 1].llave)
            {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}


void seleccion(Ts_indice vector[], int *n)
{
    int i, j, aux;
    Ts_indice temp;
    for (i = 0; i < *n; i++)
    {
        aux = i;
        for (j = i + 1; j < *n; j++)
        {
            if (vector[j].llave < vector[aux].llave)
            {
                aux = j;
            }
        }
        temp = vector[i];
        vector[i] = vector[aux];
        vector[aux] = temp;
    }
}

void insercion(Ts_indice vector[], int *n)
{
    int i;
    Ts_indice temp;
    for (i = 1; i < *n; i++)
    {
        int j = i;
        temp = vector[i];
        while (j > 0 && temp.llave < vector[j - 1].llave)
        {
            vector[j] = vector[j - 1];
            j--;
        }
        vector[j] = temp;
    }
}

int busqueda_binaria(Ts_indice vector[], int *fin, int valor)
{
    int mitad, inicio = 0;
    while (inicio <= *fin)
    {
        mitad = (inicio + *fin) / 2;
        if (valor == vector[mitad].llave)
        {
            return mitad;
        }
        else
        {
            if (valor > vector[mitad].llave)
            {
                inicio = mitad + 1;
            }
            else
            {
                *fin = mitad - 1;
            }
        }
    }
    return -1;
}
int verificar_orden(Ts_indice alumnos[], int *max) {
    int i, cont = 0;
    for (i = 0; i < *max - 1; i++) {   
        if (alumnos[i].llave < alumnos[i + 1].llave) {
            cont++;
        }
    }
    if (cont == *max - 1) {  
        printf("\nVECTOR YA ORDENADO ");
        return 1;
    }
    return -1;
}




void nombres_aleatorios(char nombre[], char paternos[], char maternos[])
{
    int i = rand() % 107;
    int i2 = rand() % 90;
    int i3 = rand() % 97;

    char nombres[107][20] = {
        "Carlos","Pedro","Yepiz","Leonardo","Fernando","Filoberto","Juan","Maria","Carlos","Ana","Luis","Sofia","Pedro","Valeria",
        "Jose","Camila","Miguel","Lucia","Fernando","Isabela","Diego",
        "Martina","Ricardo","Natalia","Andres","Paula","Santiago",
        "Julieta","Javier","Fernanda","Alejandro","Carolina","Manuel",
        "Gabriela","Hector","Mariana","Raul","Daniela","Victor","Renata",
        "Oscar","Laura","Pablo","Francisco","Elena","Emilio","Patricia",
        "Enrique","Claudia","Roberto","Veronica","Eduardo","Monica",
        "Diego","Lorena","Antonio","Juliana","Ricardo","Sandra","Mario",
        "Cecilia","Hugo","Silvia","Alberto","Beatriz","Jorge","Carla",
        "Miguel","Natalia","Cristian","Adriana","Raul","Fabiola",
        "Sergio","Marcela","Alfonso","Daniela","Andres","Vanessa",
        "Guillermo","Clara","Rafael","Lorena","Roberto","Marisol",
        "Eduardo","Jessica","Victor","Camila","Jose","Carolina",
        "Fernando","Maria","Angel","Valentina","Pablo","Gabriela",
        "Luis","Antonella","Diego","Fernanda","Ricardo","Isabella",
        "Sebastian","Paola","Juan","Daniela"
    };

    copiar_str_seguro(nombre, nombres[i], 20);

    char paterno[90][20] = {
        "Garcia","Hernandez","Lopez","Martinez","Gonzalez","Perez","Sanchez","Ramirez",
        "Torres","Flores","Rivera","Gomez","Diaz","Vargas","Romero","Rojas",
        "Castillo","Ortiz","Silva","Jimenez","Morales","Cruz","Mendoza","Aguilar",
        "Medina","Castro","Suarez","Ramos","Vega","Guerrero","Reyes","Soto",
        "Navarro","Dominguez","Chavez","Paredes","Delgado","Herrera","Roman","Valencia",
        "Palacios","Cordero","Cabrera","Cisneros","Marin","Escobar","Quintero","Aguirre",
        "Salazar","Bonilla","Carrillo","Figueroa","Barrera","Hurtado","Cardenas","Pena",
        "Sandoval","Gutierrez","Mora","Saenz","Luna","Mejia","Bravo","Parra","Castaneda",
        "Montoya","Vargas","Pinto","Maldonado","Palma","Cruz","Orozco","Rios","Varela",
        "Camacho","Lara","Pacheco","Leon","Cordova","Escalante","Rincon","Valenzuela",
        "Solis","Carrasco","Bravo","Torres","Villanueva","Chavez","Barrios","Arias"
    };

    copiar_str_seguro(paternos, paterno[i2],20);

    char materno[97][20] = {
        "Gomez","Ramirez","Torres","Flores","Vargas","Rojas","Castillo","Ortiz",
        "Silva","Jimenez","Morales","Cruz","Mendoza","Aguilar","Medina","Castro",
        "Suarez","Ramos","Vega","Guerrero","Reyes","Soto","Navarro","Dominguez",
        "Chavez","Paredes","Delgado","Herrera","Roman","Valencia","Palacios","Cordero",
        "Cabrera","Cisneros","Marin","Escobar","Quintero","Aguirre","Salazar","Bonilla",
        "Carrillo","Figueroa","Barrera","Hurtado","Cardenas","Pena","Sandoval","Gutierrez",
        "Mora","Saenz","Luna","Mejia","Bravo","Parra","Castaneda","Montoya","Varela",
        "Camacho","Lara","Pacheco","Leon","Cordova","Escalante","Rincon","Valenzuela",
        "Solis","Carrasco","Villanueva","Barrios","Arias","Caceres","Acosta","Benitez",
        "Farias","Ojeda","Tapia","Palacios","Caceres","Saenz","Rebolledo","Ramos",
        "Vallejo","Guevara","Bermudez","Meza","Pizarro","Galarza","Chavarria","Fuentes",
        "Alvarado","Cordero","Ponce","Guzman","Montes","Orellana","Bravo","Carranza"
    };

    copiar_str_seguro(maternos, materno[i3],20);
}

void puesto_aleatorio(char puesto[]) 
{
    int i = rand() % 20;

    char puestos[20][30] = {
        "Ingeniero", "Analista", "Programador", "Diseñador", "Administrador",
        "Gerente", "Director", "Supervisor", "Secretaria", "Contador",
        "Consultor", "JefeProyecto", "Asistente", "Tecnico", "Operador",
        "Coordinador", "Desarrollador", "Especialista", "Encargado", "Recepcionista"
    };

    copiar_str_seguro(puesto, puestos[i], 30);
}

void validar_estado(char estado[])
{
    int i = rand() % 33;
    char estados[33][3] = {
        "AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH", "DF", "DG",
        "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC",
        "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ",
        "YN", "ZS", "NE"};

    copiar_str_seguro(estado,estados[i],3);

}


void telefono_aleatorio(char numero[])
{
    int i;

 
    for(i = 0;i<=11;i++)
    {
        numero[i] = rand() % 10 + '0';
    }
    numero[i] = '\0';
    

}

*/