#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <iso646.h>
#include <string.h>

#include "Producto.h"
#include "DLL.h"
#include "Stock.h"

//----------------------------------------------------------------------
//  Programa principal
//----------------------------------------------------------------------

size_t Cantidad( Stock* this )
{
    int bar_code = 0;
    size_t cant=0;
    printf("\nDigite el codigo del producto que va a Usar ");
    scanf("%i",&bar_code);
    if(Stock_search_by_bar_code( this, bar_code ) == true ){
        //Stock_get( this );
        printf("\nintroduzca el numero de unidades del producto seleccionado: ");
        scanf("%u", &cant);
        if( cant > this->list->cursor->cantidad ){
            printf("\nNumero Invalido");
            cant = 0;
        }else{
            printf("\nNumero Valido");
        }
    }else{
        printf("\nNo se encontro el Producto");
    }
    return cant;
}

void Abastecimiento( Stock* this )
{
    printf("==>Menu ==>Abastecimiento");
    Stock_report( this );
    int option;
    do {
        option = 0;
        size_t canti = Cantidad( this );
       
        this->list->cursor->cantidad += canti;
        
        printf("\nDesea abastecer otro producto?\n1)Si\n-1)No\nOpcion: ");
        scanf("%i", &option );        
        if( option != 1 && option !=-1 ){
            printf("\nIntrodusca un Numero valido");
        }
    }while(option >-1 );//Inventario();
    
}

void Venta( Stock* this )
{
    printf("==>Menu ==>Vender ");
    Stock_report( this );
    Stock* ticket = Stock_New();
    int produ;
    float total=0;
    do{
        produ = 0;
        size_t cant = Cantidad( this );
        
        if( cant <= this->list->cursor->cantidad ){
            this->list->cursor->cantidad -= cant;
            Producto p;
            p.bar_code = this->list->cursor->item.bar_code;
            p.precio = this->list->cursor->item.precio;
            strcpy(p.nombre ,this->list->cursor->item.nombre );
            Stock_add( ticket, &p , cant );
            total+=(cant*p.precio);
        }else{
            printf("\n Error");
        }
        while(produ != 1 && produ != 2){
            printf("\nDesea elegir otro producto?\n1)Si\n2)No\nOpcion: ");
            scanf("%i",&produ);        
            if( produ != 1 && produ != 2){
                printf("\nIntrodusca un Numero valido");
            }
        }
    }while(produ!=2);
    printf("========{ Ticket }========");
    Stock_report( ticket );
    printf("\nTotal es :\t%0.2f\n", total );
    Stock_Delete( &ticket );
    
}

void Agregar( Stock* this )
{
    printf("\n\n==>Menu ==>Agregar ");
    Stock_report( this );
    int opc;
    do{
        opc = 0;
        Producto p;
        p.bar_code = 0;
        p.precio = 0.0;
        char nombre[ 32 ];
        size_t cantidad;
        printf("\nDigite el Nombre del Producto: ");
        scanf("%s", nombre );
        strcpy( p.nombre , nombre );
        printf("\nDigite el codigo del Producto: ");
        scanf("%i", &p.bar_code );
        printf("\nDigite precio para el Producto: ");
        scanf("%f", &p.precio );
        printf("\nDigite el numero de unidades: ");
        scanf("%u", &cantidad);
        
        //si 1222 existe preguntar si quiere que vaya antes el nuevo 1221 y restarle 1 o si quiere que sea despues +1
        
        
        Stock_add( this, &p , cantidad );
        
        while(opc != 1 && opc != -1){
            printf("\nDesea Agregar otro Producto ?\n1)Si\n-1)No\nOpcion: ");
            scanf("%d", &opc );
            if(opc != 1 && opc != -1){
                printf("\n!!Error, Digite Un numero valido");
            }
        }
    }while( opc != -1);
}

void Eliminar( Stock* this )
{
    printf("\n\n==>Menu ==>Eliminar ");
    int opc;
    do{
        opc = 0;
        Stock_report( this );
        Producto p;
        p.bar_code = 0;
        printf("\nDigite el codigo del Producto que va a Eliminar");
        scanf("%i" , &p.bar_code );
        Stock_remove( this , &p );
        while( opc != 1 && opc != 2 ){
            printf("\nDesea Eliminar otro Producto?\n1)Si\n2)No\nOpcion elegida: ");
            scanf("%i", &opc );
        }
    }while( opc != 2 );

}

void Productos(Stock* this )
{
    Producto p1;
    p1.bar_code = 1234;
    p1.precio = 13.50;
    strcpy( p1.nombre, "Choco_Roles" );

    Stock_add( this , &p1, 10 );
    
    Producto p2;
    p2.bar_code = 1334;
    p2.precio = 13.50;
    strcpy( p2.nombre, "Chetos" );

    Stock_add( this , &p2, 9 );
    
    Producto p3;
    p3.bar_code = 1344;
    p3.precio = 9.50;
    strcpy( p3.nombre, "Sabritas" );

    Stock_add( this , &p3, 9 );

    Producto p4;
    p4.bar_code = 1222;
    p4.precio = 12.00;
    strcpy( p4.nombre, "Sabritones" );

    Stock_add( this , &p4, 9 );

    Producto p5;
    p5.bar_code = 1567;
    p5.precio = 2.50;
    strcpy( p5.nombre, "Carlos_V" );

    Stock_add( this , &p5, 10 );
}


void Menu(Stock* this )
{
   int opc;
    do{ 
        //El usuario debera de escojer Alguna de las 6 opciones presentadas a continuacion.
        printf("\n\n\t====={ Cremeria Los Angelos }=====\n ==> Menu");
        printf("\nBienvenido, en que le podemos ayudar ?:\n1.-Existencias\n2.-Abastecer\n3.-Vender Productos\n4.-Nuevo Producto\n5.-Desventurar un Producto\n6.-Salir\nFavor de escribir el numero de la opcion de su Preferencia: ");
        scanf("%d", &opc );
        switch ( opc ){
        case 1:
            //existencia
            Stock_report( this );
            printf("\n");
            break;
        case 2:
            //Aumentar la cantidad de unidades que se tiene
            Abastecimiento( this );
            break;
        case 3:
            //-Vender
            Venta( this );
            

            break;
        case 4:
            Agregar( this );
            //Agregar un nuevo producto
            break;
        case 5:
            //Quitar un producto ya existente
            Eliminar( this );
            break;
        default:
            printf("\nGracias Por usar Este Programa");
            break;
        }
    }while(opc != 6 );
}


int main()
{
    Stock* Inventario = Stock_New();
    // crea al inventario
    Productos( Inventario );
    Menu( Inventario );
  
    Stock_Delete( &Inventario );
    // destruye al inventario   
}