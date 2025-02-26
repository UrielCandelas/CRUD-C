# Compilar los archivos individuales main.c, empleado.c y id.c
gcc -c main.c -o ./compiled/main.o 
gcc -c ./empleado/empleado.c -o ./compiled/empleado.o
gcc -c ./empleado/id/id.c -o ./compiled/id.o

# Generar el ejecutable
gcc ./compiled/main.o ./compiled/id.o ./compiled/empleado.o -o ./compiled/programa

#Ejecutar el programa
./compiled/programa
