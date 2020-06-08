#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#define MAX_TAM 32

//----------------------------------------------------------------------
//  Producto
//----------------------------------------------------------------------
/**
 * @struct tipo de dato abstracto llamado Producto
*/
typedef struct
{
   int bar_code;
   float precio;
   char nombre[MAX_TAM];
   // ... quizás más campos 
} Producto;

