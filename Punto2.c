#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;

void cargarTareas(Tarea **Tareas, int cantTareas);
void realizarTareas(Tarea **Tareas,Tarea **tareasRealizadas, int cantTareas);
void mostrarTareas(Tarea **Tareas,Tarea **tareasRealizadas, int cantTareas);

int main (){
    int cantTareas;
    Tarea **Tareas,**tareasRealizadas;

    do
    {
        printf("Ingrese cantidad de Tareas a realizar:");
        scanf("%i",&cantTareas);
        fflush(stdin);
    } while (cantTareas<=0);

    Tareas = (Tarea **) malloc(sizeof(Tarea*)*cantTareas);

    cargarTareas(Tareas,cantTareas);
    realizarTareas(Tareas,tareasRealizadas,cantTareas);
    free(Tareas);
    return 0;
}

void cargarTareas(Tarea **Tareas, int cantTareas)
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
        printf("\n Ingrese cuanto dura la tarea (en horas): ");
        scanf("%d",&(*(Tareas+i))->Duracion);
        fflush(stdin);   
    }
    free(buff);
    

}

void realizarTareas(Tarea **Tareas,Tarea **tareasRealizadas, int cantTareas)
{
    int realizado;
    for (int j = 0; j < cantTareas; j++)
    {
        printf("\n ID %d",(*(Tareas+j))->TareaID);
        printf("\n Descripcion: %s",(*(Tareas+j))->Descripcion);
        printf("\n Duracion: %i horas",(*(Tareas+j))->Duracion);
        printf("\n====================================");
        printf("¿Ya se realizó la tarea? \n 0.No \n1.Si");
        scanf("%i",&realizado);
        if (realizado=1)
        {
            *(tareasRealizadas+j)=*(Tareas+j);
            *(Tareas+j)=NULL;
        }else{
            *(tareasRealizadas+j)=NULL;
        }
        
    }
    
}

void mostrarTareas(Tarea **Tareas,Tarea **tareasRealizadas, int cantTareas)
{
    for (int i = 0; i < cantTareas; i++)
    {
        /* code */
    }
    
}