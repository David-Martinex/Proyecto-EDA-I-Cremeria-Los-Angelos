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
 * @brief Crea un Inventario( Stock ).
 * @return una referencia a la Stock.
 */
Stock* Stock_New();

/**
 * @brief Destruye un Inventario( Stock ).
 * @param this referencia a un TAD Stock.
 */
void Stock_Delete( Stock** this );

/**
 * @brief Agrega un nuevo producto y lee y guarda su cantidad.
 * @param this referencia a un TAD Stock.
 * @param p referencia a un objeto tipo Producto.
 * @param cant referencia a un tipo entero sin signo
 */
void Stock_add( Stock* this, Producto* p, size_t cant );

/**
 * @brief Retira un Producto.
 * @param this referencia a un TAD Stock.
 * @param p referencia a un objeto tipo Producto.
 */
void Stock_remove( Stock* this, Producto* p );

/**
 * @brief Busca un producto apartir de bar_code.
 * @param this referencia a un TAD Stock.
 * @param bar_code referencia a un tipo entero.
 * @return true o false dependiendo de la situacion
 */
bool Stock_search_by_bar_code( Stock* this, int bar_code );

/**  
 * @brief Imprime cursor.
 * @param this referencia a un TAD Stock.
 */
//void Stock_get( Stock* this );
/**
 * @brief Imprimer todos los productos dentro del inventario.
 * @param this referencia a un TAD Stock.
 */
void Stock_report( Stock* this );
