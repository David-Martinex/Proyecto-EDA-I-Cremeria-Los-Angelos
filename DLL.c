#include "Producto.h"
#include "DLL.h"

//Definiciones de las funciones de DLL

static NodePtr New_node( Producto* p, size_t cant )
{
    NodePtr n = ( NodePtr )malloc( sizeof( Node ) );
    
    if( n ){
        n->cantidad = cant;
        n->item.bar_code = p->bar_code;
        n->item.precio = p->precio;
        strcpy( n->item.nombre, p->nombre );
        n->next = NULL;
        n->prev = NULL;
    }
    return n;
}

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

void DLL_InsertFront( DLL* this, Producto* p, size_t cant )
{
    assert( this );
    
    NodePtr n = New_node( p , cant );
    if( n ){
        if( DLL_IsEmpty( this ) == false ){
            this->first->prev = n;
            n->next = this->first;
            this->first = n;
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
        
        NodePtr tmp = this->first->next;
        free( this->first );
        this->first = tmp;

        if( NULL != this->first ){
            this->first->prev = NULL;
            --this->len;
        }else{
            reset( this );
        }
    }
    return p;
}

Producto DLL_RemoveBack( DLL* this )
{
    assert( this );
    Producto p;
    if( !DLL_IsEmpty( this ) ){
        
        p.bar_code = this->last->item.bar_code;
        p.precio = this->last->item.precio;
        strcpy( p.nombre, this->last->item.nombre );
        
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
// Quitar el nodo que apunte cursor
bool DLL_Remove( DLL* this )
{
    assert( this );
     
    bool done = false;
     
    if( !DLL_IsEmpty( this ) && NULL != this->cursor ){
        done = true;
         
        if(this->cursor==this->first){
            DLL_RemoveFront( this );
        }else if( this->cursor == this->last ){
            DLL_RemoveBack( this );
        }else{
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

/*void DLL_MakeEmpty( DLL* this )
{
    assert( this );
    while( NULL != this->first ){
        NodePtr tmp = this->first->next;
        free( this->first );
        this->first = tmp;
    }
    reset( this );
}*/

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
/*
Producto DLL_Peek( DLL* this )
{
    assert( this );
    return this->cursor->item;
}*/