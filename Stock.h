#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <iso646.h>
#include <string.h>

//----------------------------------------------------------------------
//  Inventario
//----------------------------------------------------------------------

typedef struct
{
   DLL* list;
} Stock; // <- Stock es más corto que Inventario

Stock* Stock_New();
void Stock_Delete( Stock** this );
void Stock_add( Stock* this, Producto* p, size_t cant );
// quita a un elemento de la lista
void Stock_remove( Stock* this, Producto* p );
bool Stock_search( Stock* this, Producto* p );
bool Stock_search_by_bar_code( Stock* this, int bar_code );

//void Stock_get( Stock* this );

void Stock_report( Stock* this );
