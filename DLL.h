#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <iso646.h>
#include <string.h>

//----------------------------------------------------------------------
//  Lista doblemente enlazada
//----------------------------------------------------------------------
typedef struct Node
{
   Producto item;
   size_t cantidad;

   struct Node* prev;
   struct Node* next;
} Node;

typedef Node* NodePtr;

typedef struct
{
   NodePtr first;
   NodePtr last;
   NodePtr cursor;
   size_t len;
} DLL;

// Prototipos de DLL
DLL* DLL_New();
void DLL_Delete( DLL** this );
void DLL_InsertBack( DLL* this, Producto* p, size_t cant );
void DLL_InsertFront( DLL* this, Producto* p, size_t cant );
Producto DLL_RemoveFront( DLL* this );
Producto DLL_RemoveBack( DLL* this );
bool DLL_Remove( DLL* this );
size_t DLL_Len( DLL* this );
bool DLL_IsEmpty( DLL* this );
void DLL_MakeEmpty( DLL* this );
bool DLL_Search( DLL* this, int bar_code );
void DLL_Traverse( DLL* this, void (*pfun)( void ) );
Producto DLL_Peek( DLL* this );