#ifndef EMPLEADO_H
#define EMPLEADO_H

typedef struct
{
  char id[11];
  char nombre[50];
  char apellido[50];
  int edad;
  int salario;
} Empleado;

void imprimirEmpleados(Empleado *empleados);

void modificarEmpleado(Empleado empleado);

void eliminarEmpleado(char id[10]);

void agregarEmpleado(Empleado empleado);

Empleado consultarEmpleado(char id[10]);

#endif
