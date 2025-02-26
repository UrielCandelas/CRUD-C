#include <stdlib.h>
#include <time.h>
#include "id.h"

int aleatorioEnRango(int min, int max)
{
  return min + rand() % (max - min + 1);
}

char *generarID()
{
  static char id[11];
  for (int i = 0; i < 10; i++)
  {
    if (i % 2 == 0)
    {
      char al = (char)aleatorioEnRango(48, 57);
      id[i] = al;
    }
    else
    {
      int x = aleatorioEnRango(1, 10);
      if (x % 2 == 0)
      {
        char al = (char)aleatorioEnRango(65, 90);
        id[i] = al;
      }
      else
      {
        char al = (char)aleatorioEnRango(97, 122);
        id[i] = al;
      }
    }
  }
  // id[10] = '\0';
  return id;
}
