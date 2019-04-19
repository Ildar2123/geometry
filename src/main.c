#include "geometry.h"
#include "parser.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *myfile;
  myfile = fopen("coordinates.txt", "r");
  if (myfile == NULL)
  {
    printf("No file\n");
     
  }
  printf("You input:\n");
  int capacity = 100;
  int size = 0;
  char arr[256];
  int i = 0;
  Figure *new = (Figure *)malloc(sizeof(Figure) * capacity);
  if (new == NULL)
  {
    printf("Alloceted error\n");
  }
  while ((arr[i++] = fgetc(myfile)) != EOF)
  {
    if (size < capacity)
    {
      if (arr[i - 1] == '\n')
      {
        arr[i - 1] = '\0';

        if (!(First_Character(arr)) && !(Parser(&new[size], arr)))
        {
          Work(&new[size]);
        }
        size++;
        i = 0;
      }
    }
    else
    {
      capacity *= 2;
      new = (Figure *)realloc(new, capacity * sizeof(double));
      if (new == NULL)
      {
        printf("Alloceted error\n");
      }
    }
  }
  return 0;
}
