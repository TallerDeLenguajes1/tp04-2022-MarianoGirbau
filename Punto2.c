#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;

void cargarTareas (Tarea **Tareas, int cantTareas);

int main (){
    int cantTareas;
    Tarea **Tareas;

    do
    {
        printf("Ingrese cantidad de Tareas a realizar:");
        scanf("%i",&cantTareas);
        fflush(stdin);
    } while (cantTareas<=0);

    Tareas = (Tarea **) malloc(sizeof(Tarea*)*cantTareas);

    cargarTareas(Tareas,cantTareas);

    free(Tareas);
    return 0;
}

void cargarTareas (Tarea **Tareas, int cantTareas)
{
    char *buff = (char *) malloc (100*sizeof(char));

    for (int i = 0; i < cantTareas; i++)
    {
        (*(Tareas+i))= (Tarea *) malloc(sizeof (Tarea));
        (*(Tareas+i))->TareaID = i+1;
        printf("\n Ingrese la descripcion de la tarea a realizar: ");
        gets(buff);
        (*(Tareas+i))->Descripcion = (char *) malloc ((strlen(buff)+1)*sizeof(char));
        strcpy((*(Tareas+i))->Descripcion,buff);
        printf("\n Ingrese cuanto dura la tarea: ");
        scanf("%d",&(*(Tareas+i))->Duracion);
        fflush(stdin);   
    }
    free(buff);
    

}