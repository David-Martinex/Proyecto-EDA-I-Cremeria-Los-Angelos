#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#define MAX_TAM 32
#define Max 12

//----------------------------------------------------------------------
//  Lista doblemente enlazada
//----------------------------------------------------------------------
 /** 
  * @struct un TAD llamado Nodo 
 */
typedef struct Node
{
   Producto item; /**referencia a un tipo objeto Producto */
   size_t cantidad; 

   struct Node* prev; /** referencia al anterior nodo.*/
   struct Node* next; /** referencia al siguiente nodo.*/
} Node;

typedef Node* NodePtr;
/** 
  * @struct un TAD llamado DLL(Lista Doblemente Enlazada).
 */
typedef struct
{
   NodePtr first; /** Primer elemento*/
   NodePtr last;  /** Ultimo elemento*/
   NodePtr cursor;/** cualquier elemento*/
   size_t len;/** cantidad de elementos en la lista*/
} DLL;

/**
 * @fn DLL_New().
 * @brief Crea una Lista Doblemente Enlazada.
 * @return una referencia a la DLL.
 */
DLL* DLL_New();

/**
 * @fn DLL_Delete().
 * @brief Destruye una Lista Doblemente Enlazada.
 * @param this referencia a un tipo abstracto DLL.
 */
void DLL_Delete( DLL** this );

/**
 * @fn DLL_InsertBack().
 * @brief Inserta un nodo del lado derecho.
 * @param this referencia a un tipo abstracto DLL.
 * @param p referencia a un objeto tipo Producto.
 * @param cant referencia a las unidades del Producto
 */
void DLL_InsertBack( DLL* this, Producto* p, size_t cant );

/**
 * @fn DLL_InsertFront();
 * @brief Inserta un nodo del lado izquierdo
 * @param this referencia a un tipo abstracto DLL
 * @param p referencia a un objeto tipo Producto
 * @param cant referencia a las unidades del Producto
 */
void DLL_InsertFront( DLL* this, Producto* p, size_t cant );

/**
 * @fn DLL_RemoveFront();
 * @brief Extrae un nodo del lado izquierdo
 * @param this referencia a un tipo abstracto DLL
 * @return un objeto tipo Producto
 */
Producto DLL_RemoveFront( DLL* this );

/**
 * @fn DLL_RemoveBack();
 * @brief Extrae un nodo del lado derecho
 * @param this referencia a un tipo abstracto DLL
 * @return un objeto tipo Producto
 */
Producto DLL_RemoveBack( DLL* this );

/**
 * @fn DLL_Remove();
 * @brief Extrae el nodo que apunta cursor 
 * @param this referencia a un tipo abstracto DLL
 * @return true si se completo con exito
 */
bool DLL_Remove( DLL* this );

/**
 * @fn DLL_Len();
 * @brief Indica la cantidad de productos
 * @param this referencia a un tipo abstracto DLL
 * @return cantidad de producto dentro de DLL
 */
size_t DLL_Len( DLL* this );

/**
 * @fn DLL_IsEmpty();
 * @brief Indica si DLL esta vacia
 * @param this referencia a un tipo abstracto DLL
 * @return true o false dependiendo el caso
 */
bool DLL_IsEmpty( DLL* this );
//void DLL_MakeEmpty( DLL* this );

/**
 * @fn DLL_Search();
 * @brief Busca una igualdad en la lista y pocisiona a cursor donde la encontro.
 * @param this referencia a un tipo abstracto DLL
 * @param bar_code referencia a un tipo entero
 * @return true o false dependiendo el caso
 */
bool DLL_Search( DLL* this, int bar_code );
//Producto DLL_Peek( DLL* this );