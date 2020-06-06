#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <iso646.h>
#include <string.h>

//----------------------------------------------------------------------
//  Producto
//----------------------------------------------------------------------

typedef struct
{
   int bar_code;
   float precio;
   char nombre[32];
   // ... quizás más campos
} Producto;

// Los productos NO tienen operaciones, accesaremos directamente a los campos
