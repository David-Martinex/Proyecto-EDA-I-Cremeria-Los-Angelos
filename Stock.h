#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#define MAX_TAM 32
#define Max 12

//----------------------------------------------------------------------
//  Inventario
//----------------------------------------------------------------------
/**
 * @struct estructura llamada Stock<-- es mas corto que inventario.
*/
typedef struct
{
   DLL* list; /**referencia a un TAD DLL*/
} Stock; 

/**
 * @fn Stock_New().
 * @brief Crea un Inventario( Stock ).
 * @return una referencia a la Stock.
 */
Stock* Stock_New();

/**
 * @fn Stock_Delete().
 * @brief Destruye un Inventario( Stock ).
 * @param this referencia a un TAD Stock.
 */
void Stock_Delete( Stock** this );

/**
 * @fn Stock_add().
 * @brief Agrega un nuevo Nodo que contendra los datos de un producto.
 * @param this referencia a un TAD Stock.
 * @param p referencia a un objeto tipo Producto.
 * @param cant referencia a un tipo entero sin signo
 */
void Stock_add( Stock* this, Producto* p, size_t cant );

/**
 * @fn Stock_remove.
 * @brief Retira un Producto.
 * @param this referencia a un TAD Stock.
 * @param p referencia a un objeto tipo Producto.
 */
void Stock_remove( Stock* this, Producto* p );

/**
 * @fn Stock_search_by_bar_code().
 * @brief Busca un producto apartir de bar_code.
 * @param this referencia a un TAD Stock.
 * @param bar_code referencia a un tipo entero.
 * @return true o false dependiendo de la situacion
 */
bool Stock_search_by_bar_code( Stock* this, int bar_code );

/**
 * @fn Stock_get().
 * @brief Imprime cursor.
 * @param this referencia a un TAD Stock.
 */
//void Stock_get( Stock* this );
/**
 * @fn Stock_report().
 * @brief Imprimer todos los productos dentro del inventario.
 * @param this referencia a un TAD Stock.
 */
void Stock_report( Stock* this );
