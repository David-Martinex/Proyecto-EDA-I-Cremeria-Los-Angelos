
/*
 * esqueleto para la creación de un sistema de inventario. Ni de chiste está
 * cerca de ser una versión compilable y funcional.
 */


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


//----------------------------------------------------------------------
//  Lista doblemente enlazada
//----------------------------------------------------------------------
typedef struct Node
{
   Producto item;
   size_t cantidad;

   Node* prev;
   Node* next;
} Node;

typedef Node* NodePtr;

typedef struct
{
   NodePtr first;
   NodePtr last;
   NodePtr cursor;
   size_t len;
} DLL;

static new_node( Producto *p, size_t cant )
{
   NodePtr n = malloc( sizeof( node ) );

   // si sí se creó el nodo:

   n->cantidad = cant;
   n->item.bar_code = p->bar_code;
   strcpy( n->item.nombre, p->nombre );
   // ...

   return n;
}


// las mismas operaciones que la DLL, no todas, sólo las necesarias, pero deben
// comenzar con Inventario en lugar de DLL:

void DLL_InsertBack( DLL* this, Producto* p, size_t cant )
{
   // ...

   new_node( p, cant );

   // ...
}

Producto DLL_RemoveBack( DLL* this )
{
   // ...

   Producto p;
   p.bar_code = this->last->item.bar_code;
   strcpy( p.nombre, this->last->item.nombre );

   // ...

   return p;
}

bool DLL_Search( DLL* this, int bar_code )
{

}


//----------------------------------------------------------------------
//  Inventario
//----------------------------------------------------------------------

typedef struct
{
   DLL* list;
} Stock; // <- Stock es más corto que Inventario

Stock* Stock_new()
{
   list = DLL_new();

   // ...
}

void Stock_delete( Stock* this )
{
   // si *this existe{
      DLL_delete( this->list );
   // }

}

void Stock_add( Stock* this, Producto* p, size_t cant )
{
   // if( DLL_Search( this->list, p->bar_code ) == NULL ){
   //     DLL_InsertBack( this->list, p, cant );
   // } else {
   //     actualiza la cantidad (Search() colocó al cursor en la posición correcta ):
   //         * lee el campo 'cantidad' del nodo
   //         * le suma 'cant'
   //         * escribe 'cantidad' al nodo
   // }
}

// quita a un elemento de la lista
void Stock_remove( Stock* this, Producto* p )
{
   // if( DLL_Search( this->list, p->bar_code ) != NULL ){
   //     DLL_RemoveBack( this->list );
   // } 
}

bool Stock_search( Stock* this, Producto* p )
{
   return DLL_Search( this->list, p->bar_code );
}

bool Stock_search_by_bar_code( Stock* this, int bar_code )
{
   return DLL_Search( this->list, bar_code );
}


// devuelve una copia del producto al que apunta el 'cursor'
Producto Stock_get( Stock* this )
{
   return DLL_PeekBack( this->list );
}

void Stock_report( Stock* this )
{
   // imprime todos los productos de la lista
}

//----------------------------------------------------------------------
//  Programa principal
//----------------------------------------------------------------------

int main()
{
   Stock* stock = Stock_new();
   // crea al inventario

   Producto p;
   p.bar_code = 1234;
   p.precio = 13.50;
   strcpy( p.nombre, "Choco Roles" );

   Stock_add( inventario, &p, 10 );


   Stock_delete( stock );
   // destruye al inventario
}
