#include <stdio.h>
#include <stdbool.h>

bool esPrimo(int numero){

    if (numero <= 1){ //si el numero es uno o menos, no es primo

        return false;
    }
   
    if (numero ==2 ){ // si el numero es 2, es primo
        return true;
    }

    if (numero != 2 && numero % 2 == 0){ // si el numero (diferente a 2) es múltiplo de 2, no es primo

        return false;
    }

    for (int i=3;i*i<= numero; i+=2){ //verificaar la divisibilidad de los numeros impares
                                    //hasta su raíz cuadrada
        if (numero % i== 0){
            return false;
        }
    }

    return true;    //si nada de lo anterior se cumple, es primo
}

int siguientePrimo(int numero){ //Encontrar el siguiente número primo
    int siguiente = numero + 1;
    while (!esPrimo(siguiente)){

        siguiente++;
    }
    return siguiente;
}


int main(){
    int numero;

    printf("ingrese un número entre 1 y 1000: ");
    scanf("%d", &numero);
    
    if (numero<1 || numero>1000){
        printf("El numero debe estar entre 1 y 1000.\n");
        return 1;

    }

    int proximoPrimo = siguientePrimo(numero);
    printf("El siguiente número primo después de %d es: %d\n", numero, proximoPrimo);
    

    return 0;
}
