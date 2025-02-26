#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "empleado.h"

// Funcion para agregar empleado
void agregarEmpleado(Empleado empleado)
{
  FILE *archivo = fopen("./files/empleados.csv", "a"); // Abrir un archivo csv
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    return;
  }
  // Imprimir el empleado en el csv
  fprintf(archivo, "%s,%s,%s,%d,%d\n", empleado.id, empleado.nombre, empleado.apellido, empleado.edad, empleado.salario);

  fclose(archivo); // Cerrar el archivo
  printf("El empleado se guardo correctamente \n");
}

// Funcion para consultar empleado
Empleado consultarEmpleado(char id[10])
{
  FILE *archivo = fopen("./files/empleados.csv", "r"); // Leer un archivo csv
  Empleado empleado = {"", "", "", 0, 0};              // Crear un struct empleado vacio
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    return empleado;
  }
  char linea[100];

  while (fgets(linea, sizeof(linea), archivo)) // Leer linea por linea
  {
    char *token = strtok(linea, ","); // Leer el primer valor(id) hasta la coma

    if (strcmp(token, id) == 0) // Comparar el id ingresado con el id del empleado
    {
      // Asignar valores al struct empleado
      strcpy(empleado.id, token);

      /*
      Token lee todos los caracteres despues de la primer coma hasta la siguiente
      y asi sucesivamente, osea cada "token = strtok(NULL, ",");" lee cada valor del archivo csv
      Ej. 1a2b3c4d5e,Uriel,Candelas,19,1900
      Cada vez que se ejecute esta instruccion: token = strtok(NULL, ",");
      va a leer primero Uriel, en la siguente asignacion leera Candelas
      */
      token = strtok(NULL, ",");
      strcpy(empleado.nombre, token);

      token = strtok(NULL, ",");
      strcpy(empleado.apellido, token);

      token = strtok(NULL, ",");
      empleado.edad = atoi(token);

      token = strtok(NULL, ",");
      empleado.salario = atoi(token);

      // Cerrar el archivo
      fclose(archivo);

      return empleado;
    }
  }
  fclose(archivo);

  return empleado;
}

// Funcion para eliminar empleado
void eliminarEmpleado(char id[10])
{
  // Inicializar el archivo de los empleados
  FILE *archivo = fopen("./files/empleados.csv", "r");
  // Inicializar un archivo temporal
  FILE *temp = fopen("./files/temp.csv", "w");

  if (archivo == NULL || temp == NULL)
  {
    printf("Error al abrir el archivo\n");
    return;
  }

  // Inicializar un array para una linea
  char linea[100];
  // Inicializar un contador de veces que se elimino un usuario
  int contador = 0;

  while (fgets(linea, sizeof(linea), archivo))
  {
    // Crear una copia de la linea actual
    char copia[100];
    strcpy(copia, linea);
    char *token = strtok(copia, ",");

    // Verificar que el id no coincide con el actual
    if (strcmp(id, token) != 0)
    {
      // Copia la linea al archivo temporal
      fprintf(temp, "%s", linea);
    }
    else
    {
      // Se añade uno al contador cuando se encuentra la coincidencia del id
      // En otras palabras copia todas las lineas excepto la del id al nuevo archivo
      contador++;
    }
  }
  // Cerrar archivos
  fclose(archivo);
  fclose(temp);

  // Eliminar empleados.csv
  remove("./files/empleados.csv");
  // Renombra temp.csv como el nuevo empleados.csv
  rename("./files/temp.csv", "./files/empleados.csv");

  // Imprimir si el empleado se elmino o si no se encontró
  if (contador)
  {
    printf("El empleado se elimino correctamente\n");
  }
  else
  {
    printf("El empleado no se encontro\n");
  }

  return;
}

// Funcion para modificar empleado
void modificarEmpleado(Empleado empleado)
{
  // Abrir empleados y temp
  FILE *archivo = fopen("./files/empleados.csv", "r");
  FILE *temp = fopen("./files/temp.csv", "w");

  if (archivo == NULL || temp == NULL)
  {
    printf("Error al abrir el archivo\n");
    return;
  }
  // Incializar la linea y el contador
  char linea[100];
  int contador = 0;

  // Recorrer todas las lineas del archivo
  while (fgets(linea, sizeof(linea), archivo))
  {
    char copia[100];
    strcpy(copia, linea);
    char *token = strtok(copia, ",");

    // Verificar si el id de esa linea concuerda con el id entrante
    if (strcmp(empleado.id, token) == 0)
    {
      // Copiar el id y los nuevos datos al archivo temp
      fprintf(temp, "%s,%s,%s,%d,%d\n", empleado.id, empleado.nombre, empleado.apellido, empleado.edad, empleado.salario);
      contador++;
    }
    else
    {
      // Copiar todos los datos asi como estan
      fprintf(temp, "%s", linea);
    }
  }
  fclose(archivo);
  fclose(temp);

  remove("./files/empleados.csv");
  rename("./files/temp.csv", "./files/empleados.csv");
  if (contador)
  {
    printf("El empleado se modifico correctamente\n");
  }
  else
  {
    printf("El empleado no se encontro\n");
  }

  return;
}

// Funcion para consultar a todos los empleados
void imprimirEmpleados(Empleado *empleados)
{
  FILE *archivo = fopen("./files/empleados.csv", "r"); // Leer un archivo csv
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    return;
  }
  char linea[100]; // Array para leer toda una linea

  // Recorre todas las lineas del archivo
  for (int i = 0; fgets(linea, sizeof(linea), archivo); i++)
  {
    // Leer un string hasta la coma
    char *token = strtok(linea, ",");

    // Imprimir valores del usuario
    printf("Empleado: %d\n", i + 1);

    printf("id: %s\n", token);

    token = strtok(NULL, ",");
    printf("Nombre: %s\n", token);

    token = strtok(NULL, ",");
    printf("Apellido: %s\n", token);

    token = strtok(NULL, ",");
    printf("Edad: %d\n", atoi(token));

    token = strtok(NULL, ",");
    printf("Salario: %d\n", atoi(token));

    printf("----\n");
  }

  fclose(archivo);
}
