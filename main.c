#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./empleado/empleado.h"
#include "./empleado/id/id.h"

void imprimirMenu()
{
  printf("Ingrese la opcion que desea realizar: \n");
  printf("1.- Agregar Empleado\n");
  printf("2.- Consultar Empleado\n");
  printf("3.- Eliminar Empleado\n");
  printf("4.- Modificar Empleado\n");
  printf("5.- Consultar todos los Empleados\n");
}

int main(void)
{
  srand(time(NULL)); // Semilla del id aleatorio
  int opt;
  int bandera = 1;
  Empleado empleado;
  Empleado *empleados;
  char searchedid[10];

  do
  {

    do
    {
      imprimirMenu();

      scanf("%d", &opt);
    } while (opt < 1 || opt > 5);

    switch (opt)
    {
    case 1:

      char *newid = generarID();
      strcpy(empleado.id, newid); // Asignar el id generado a el id del struct

      printf("Ingrese el Nombre del Empleado\n");
      scanf("%s", empleado.nombre);

      printf("Ingrese el Apellido del Empleado\n");
      scanf("%s", empleado.apellido);

      printf("Ingrese la Edad del Empleado\n");
      scanf("%d", &empleado.edad);

      printf("Ingrese el Salario del Empleado\n");
      scanf("%d", &empleado.salario);

      agregarEmpleado(empleado); // Ejecutar la funcion agregarEmpleado

      break;

    case 2:

      printf("Ingrese el id del empleado que desea buscar: \n");
      scanf("%s", searchedid);
      empleado = consultarEmpleado(searchedid); // Asignar el valor encontrado en la func

      if (strcmp(empleado.id, "") == 0) // Comprobar si se encontro un empleado
      {
        printf("No se encontro un empleado con ese id\n");
        return 0;
      }

      printf("id: %s\n", empleado.id);
      printf("Nombre: %s\n", empleado.nombre);
      printf("Apellido: %s\n", empleado.apellido);
      printf("Edad: %d\n", empleado.edad);
      printf("Salario: %d\n", empleado.salario);

      break;
    case 3:
      printf("Ingrese el id del empleado que desea eliminar: \n");
      scanf("%s", searchedid);
      eliminarEmpleado(searchedid);

      break;
    case 4:
      printf("Ingrese el id del empleado que desea modificar: \n");
      scanf("%s", empleado.id);

      printf("Ingrese el Nombre del Empleado\n");
      scanf("%s", empleado.nombre);

      printf("Ingrese el Apellido del Empleado\n");
      scanf("%s", empleado.apellido);

      printf("Ingrese la Edad del Empleado\n");
      scanf("%d", &empleado.edad);

      printf("Ingrese el Salario del Empleado\n");
      scanf("%d", &empleado.salario);

      modificarEmpleado(empleado);
      break;
    case 5:
      imprimirEmpleados(empleados);
      break;
    }

    char selec;
    do
    {
      printf("Desea terminar el programa?(S/N)\n");
      scanf(" %c", &selec);
    } while (selec != 'S' && selec != 'N');

    if (selec == 'S')
    {
      bandera = 0;
    }
    else
    {
      bandera = 1;
    }
  } while (bandera);

  return 0;
}