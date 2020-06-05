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
Producto DLL_RemoveFront( DLL* this );
bool DLL_Remove( DLL* this );
size_t DLL_Len( DLL* this );
bool DLL_IsEmpty( DLL* this );
void DLL_MakeEmpty( DLL* this );
bool DLL_Search( DLL* this, int bar_code );
void DLL_Traverse( DLL* this, void (*pfun)( void ) );
//DLL_PeekBack( DLL* this );


//Definiciones de las funciones de DLL

static NodePtr New_node( Producto* p, size_t cant )
{
    NodePtr n = ( NodePtr )malloc( sizeof( Node ) );
    
    if( n ){
        n->cantidad = cant;
        n->item.bar_code = p->bar_code;
        strcpy( n->item.nombre, p->nombre );
        n->next = NULL;
        n->prev = NULL;
    }
    return n;
}


// las mismas operaciones que la DLL, no todas, sólo las necesarias, pero deben
// comenzar con Inventario en lugar de DLL:

static void reset( DLL* this )
{
    this->first = this->last = this->cursor = NULL;
    this->len = 0;
}

DLL* DLL_New()
{
    DLL*  list = ( DLL* )malloc( sizeof( DLL) );
    if( list ){
        reset( list );
    }
    return list;
}

void DLL_Delete( DLL** this )
{
    if( *this ){
        DLL* list = *this;
        while( DLL_Len( list ) != 0 ){
            NodePtr next = list->first->next;
            free( list->first );
            list->first = next;
            --list->len;
        }
        free( list );
        *this = NULL;
    }
}

void DLL_InsertBack( DLL* this, Producto* p, size_t cant )
{
    assert( this );
    
    NodePtr n = New_node( p , cant );
    if( n ){
        if( DLL_IsEmpty( this ) == false ){
            this->last->next = n;
            n->prev = this->last;
            this->last = n;
        }else{
            this->first = this->last = n;
        }
        ++this->len;
    }

}

Producto DLL_RemoveFront( DLL* this )
{
    assert( this );
    Producto p;
    if( !DLL_IsEmpty( this ) ){
        
        p.bar_code = this->first->item.bar_code;
        p.precio = this->first->item.precio;
        strcpy( p.nombre, this->first->item.nombre );
        
        NodePtr tmp = this->last->prev;
        free( this->last );
        this->last = tmp;

        if( NULL != this->last ){
            this->last->next = NULL;
            --this->len;
        }else{
            reset( this );
        }
    }
    return p;
}

bool DLL_Remove( DLL* this )
{
    assert( this );
     
    bool done = false;
     
    if( !DLL_IsEmpty( this ) && NULL != this->cursor ){
        done = true;
         
        NodePtr left = this->cursor->prev;
        NodePtr rigth = this->cursor->next;
        free( this->cursor );
         
        if( left == NULL && rigth == NULL ){
            reset( this );
        }else{
            this->cursor = left;
            this->cursor->next = rigth;
            rigth->prev = this->cursor;
            --this->len;
        }
    }
    return done;
}

size_t DLL_Len( DLL* this )
{
    return this->len;
}

bool DLL_IsEmpty( DLL* this )
{
    assert( this );
    return this->first == NULL;
}

void DLL_MakeEmpty( DLL* this )
{
    assert( this );
    while( NULL != this->first ){
        NodePtr tmp = this->first->next;
        free( this->first );
        this->first = tmp;
    }
    reset( this );
}

bool DLL_Search( DLL* this, int bar_code )
{
    assert( this );
    bool found = false;
    
    for( NodePtr it = this->first; it != NULL && found == false; it = it->next ){
        if( bar_code == it->item.bar_code ){
            this->cursor = it;
            found = true;
        }
    }
    return found;
}
/**
* @brief Recorre la lista ejecutando la acción dada por pfun.
*
* @param this Referencia a un objeto DLL.
* @param pfun Un apuntador a función. Esta función será llamada (callback) una
* vez por cada elemento de la lista.
*/
void DLL_Traverse( DLL* this, void (*pfun)( void ) )
{
    /** Pendiente */
    assert( this );
    for( NodePtr it = this->first; it != NULL; it = it->next ){
        //pfun( it );
    }
}

Producto DLL_PeekBack( DLL* this )
{
    assert( this );
    return this->cursor->item;
}

//----------------------------------------------------------------------
//  Inventario
//----------------------------------------------------------------------

typedef struct
{
   DLL* list;
} Stock; // <- Stock es más corto que Inventario

Stock* Stock_New()
{
    Stock* Inventario = ( Stock* )malloc( sizeof( Stock ) );
    if( Inventario ){
        Inventario->list = DLL_New();
    }
    return Inventario;
}

void Stock_Delete( Stock* this )
{
   // si *this existe{
    assert( this );
    if( this ){
        
    }
    DLL_Delete( this->list );
   // }

}

void Stock_add( Stock* this, Producto* p, size_t cant )
{
   if( DLL_Search( this->list, p->bar_code ) == false ){
        DLL_InsertBack( this->list, p, cant );
    } else {
        this->list->cursor->cantidad += cant;
    }
    //actualiza la cantidad (Search() colocó al cursor en la posición correcta ):
   //         * lee el campo 'cantidad' del nodo
   //         * le suma 'cant'
   //         * escribe 'cantidad' al nodo
}

// quita a un elemento de la lista
void Stock_remove( Stock* this, Producto* p )
{
   if( DLL_Search( this->list, p->bar_code ) != false ){
        DLL_Remove( this->list );
    } 
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
//  Opciones de Menu
//----------------------------------------------------------------------

void Menu_Existencia()
{
    
}

//----------------------------------------------------------------------
//  Programa principal
//----------------------------------------------------------------------

void DadaBase()
{
    
}

void Menu(Stock* stock )
{
   int opc;
    do{ 
        //El usuario debera de escojer Alguna de las 6 opciones presentadas a continuacion.
        printf("\n\a\t====={ Cremeria Los Angelos }=====\n ==> Menu");
        printf("\nBienvenido, en que le podemos ayudar ?:\n1.-Existencias\n2.-Abastecer\n3.-Vender Productos\n4.-Nuevo Producto\n5.-Desventurar un Producto\n6.-Salir\nFavor de escribir el numero de la opcion de su Preferencia:\t");
        scanf("%d", &opc );
        switch ( opc ){
        case 1:
            //Vender Producto/s
            
            break;
        case 2:
            //Aumentar la cantidad de unidades que se tiene
            
            break;
        case 3:
            //Agregar un nuevo producto
            
            

            break;
        case 4:
            //Quitar un producto ya existente
            
            break;
        case 5:
            
            break;
        default:
            printf("\nFavor de ingresar un Numero valido");
            break;
        }
    }while(opc != 6 );
}


int main()
{
   Stock* Inventario = Stock_New();
   // crea al inventario

   Producto p;
   p.bar_code = 1234;
   p.precio = 13.50;
   strcpy( p.nombre, "Choco Roles" );

   Stock_add( Inventario, &p, 10 );

   Stock_Delete( &Inventario );
   // destruye al inventario
}