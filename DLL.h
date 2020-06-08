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
  * @struct Tipo de dato abstracto llamado Nodo 
 */
typedef struct Node
{
   Producto item; 
   size_t cantidad; 

   struct Node* prev; 
   struct Node* next; 
} Node;

typedef Node* NodePtr;
/** 
  * @struct Tipo de dato abstracto llamado DLL(Lista Doblemente Enlazada).
 */
typedef struct
{
   NodePtr first; 
   NodePtr last;  
   NodePtr cursor;
   size_t len;
} DLL;

/**
 * @brief Crea una Lista Doblemente Enlazada.
 * @return referencia al tipo de dato abstracto DLL.
 */
DLL* DLL_New();

/**
 * @brief Destruye una Lista Doblemente Enlazada.
 * @param this referencia a un tipo de dato abstracto DLL.
 */
void DLL_Delete( DLL** this );

/**
 * @brief Inserta un nodo del lado derecho.
 * @param this referencia a un tipo de dato abstracto DLL.
 * @param p referencia a un objeto tipo Producto.
 * @param cant referencia a las unidades del Producto.
 */
void DLL_InsertBack( DLL* this, Producto* p, size_t cant );

/**
 * @brief Inserta un nodo del lado izquierdo.
 * @param this referencia a un tipo de dato abstracto DLL.
 * @param p referencia a un objeto tipo Producto.
 * @param cant referencia a las unidades del Producto.
 */
void DLL_InsertFront( DLL* this, Producto* p, size_t cant );

/**
 * @brief Extrae un nodo del lado izquierdo.
 * @param this referencia a un tipo de dato abstracto DLL.
 * @return un objeto tipo Producto.
 */
Producto DLL_RemoveFront( DLL* this );

/**
 * @brief Extrae un nodo del lado derecho.
 * @param this referencia a un tipo de dato abstracto DLL.
 * @return un objeto tipo Producto.
 */
Producto DLL_RemoveBack( DLL* this );

/**
 * @brief Extrae el nodo que apunta cursor.
 * @param this referencia a un tipo de dato abstracto DLL.
 * @return true si se completo con exito.
 */
bool DLL_Remove( DLL* this );

/**
 * @brief Indica la cantidad de productos.
 * @param this referencia a un tipo de dato abstracto DLL.
 * @return cantidad de producto dentro de DLL.
 */
size_t DLL_Len( DLL* this );

/**
 * @brief Indica si DLL esta vacia.
 * @param this referencia a un tipo abstracto DLL.
 * @return true o false dependiendo el caso.
 */
bool DLL_IsEmpty( DLL* this );

/**
 * @brief Busca una igualdad en la lista y posiciona a cursor donde la encontró.
 * @param this referencia a un tipo de dato abstracto DLL.
 * @param bar_code referencia a un tipo entero.
 * @return true o false dependiendo el caso.
 */
bool DLL_Search( DLL* this, int bar_code );

/**
 * @brief Regresa el producto al que apunta cursor.
 * @param this referencia a un tipo de dato abstracto DLL.
 * @return el tipo Producto al que apunta cursor.
 */
Producto DLL_Peek( DLL* this );