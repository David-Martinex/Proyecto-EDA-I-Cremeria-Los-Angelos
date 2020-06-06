#include "Producto.h"
#include "DLL.h"
#include "Stock.h"

//----------------------------------------------------------------------
//  Inventario
//----------------------------------------------------------------------


Stock* Stock_New()
{
    Stock* Inventario = ( Stock* )malloc( sizeof( Stock ) );
    if( Inventario ){
        Inventario->list = DLL_New();
    }
    return Inventario;
}

void Stock_Delete( Stock** this )
{
   // si *this existe{
    assert( *this );
    if( *this ){
        Stock* n = *this;
        DLL_Delete( &n->list );
        free( n );
        *this = NULL;
    }
}

void Stock_add( Stock* this, Producto* p, size_t cant )
{
   if( DLL_Search( this->list, p->bar_code ) == false ){
        DLL_InsertBack( this->list, p, cant );//DLL_InsertFront( this->list, p, cant );
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
        if(DLL_Remove( this->list ) == true ){
            printf("\nSe elimino con exito");
        }else{
            printf("\nNo se pudo Eliminar");
        }
        
    }else{
        printf("\n!!No se encontro El producto deseado.");
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
/*Producto Stock_get( Stock* this )
{
   Producto p = DLL_PeekBack( this->list );
   return p;
}*/

void Stock_report( Stock* this )
{
   // imprime todos los productos de la lista
   assert( this );
    for(NodePtr it = this->list->first; it != NULL ; it = it->next ){
        printf("\n=====================");
        printf("\nProducto: ");
        for( size_t i = 0 ; i < 12 ; ++i ){
            printf("%c", it->item.nombre[ i ] );   
        }
        printf("\nCodigo de Barras: %d\nPrecio: %0.2f\nUnidades: %ld",it->item.bar_code, it->item.precio, it->cantidad );
    }
    printf("\n\nCuentas con %ld Poductos" , DLL_Len( this->list ) );
}
