/* Inteligencia artificial Tarea1  

- Dado un arreglo de N números (Donde N tiene que ser mayor igual a 1000), buscar el numero Par mas grande, siguiendo las siguientes reglas.
- Debe exponerse cuantas veces es divisible
- El siguiente número a él debe ser impar.
- La suma del número anterior y posterior, deben de dar el numero que se encuentra posicionado.
- El resultado de la division entre 2 del numero par analizado deberá ser igual al número siguiente siguiente en el arreglo. 

- Uriel Jesus Ventura Hernandez
- Semestre: Desconocido
*/



//librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//funcion para determinar cuantas veces se logra dividir entre 2
int Num_div (int Numero)
{
	int Contador = 1, Act = 0, Mary = 0;  //variables declaradas, un contador una bandera y una variable
	                  					  //para guardar el resultado de la division

	while(Act == 0) //inicio del while
	{
		Mary = Numero/2; //dividimos y guardamos

		if (Mary %2 == 0)	//comparamos si aun es par
		{
			Contador++;		//aumentamos de ser correcto
			Numero = Mary;	//guardamos el resultado de la division para realizar el ciclo de nuevo
		}

		if (Mary %2 != 0)	//si es impar detenemos el ciclo
		{
			Act = 1;		//cambiamos el valor de act
			break;			//igual para vernos rudos frenamos todo
		}
	}	//fin del while

	return Contador;	//regresamos el contador de divisiones
}

//Programa Principal
int main()	
{	

	int i = 1,n = 1,con = 1,Ari = 0, ParMayor = 0,arreglo[999],posicion = 0;	//Declaramos nuestras variables

	srand(time(NULL)); //funcion que nos permite generar numeros aleatorioa en base a nuestra hora del ordenador


	printf("Programa para la localizacion del numero par mayor en un arreglo\n");

	//creacion del arreglo random
	while (i<=1000) //creamos los valores random dentro de un arreglo de 1000 datos
	{
		arreglo[i] = rand()%10+1; //indicamos que el arreglo con posicion "i" tenga un numero del 1 al 10
		printf("%d) %d \n",i,arreglo[i]);	//imprimimos
		i++;	//incrementamos el contador
	} //fin del while y creacion del arreglo


	//ciclo de comparativas, cuerpo del programa
	while (n<=1000)		//avanzaremos lo que es todo el arreglo del 1 al 1000
	{//inicio del while	

		if ( (n != 1) && (n <= 998) ) //primer comparativa---> "Explicacion en la parte posterior del programa"
		{

			if (arreglo[n] %2 == 0 && arreglo[n+1] %2 != 0) //	segunda explicacion abajo
			{
				if(arreglo[n+1] + arreglo[n-1] == arreglo[n] && arreglo[n]/2 == arreglo[n+2]) //tercera explicacion abajo
				{
					if (ParMayor <= arreglo[n]) //si arreglo n es mayor al valor de par, este lo remplazara a el y alos demas datos
					{
						ParMayor = arreglo[n]; //par toma el valor del NumeroPar mas Grande
						Ari = Num_div(arreglo[n]); //mandamos el valor de arreglo a la funcion Num_div
						posicion = n; //guardamos el Numero de posicion del numero par para buscarlo en la lista
					}

				}
				
			}
					
		}

		n++; //incrementamos n y por lo tanto avanzamos una casilla mas en el arreglo

	}//fin del while principal


	//imprimimos los ultimos datos guardados de ParMayor, de numero de posicion y de # de veces divisibles
	printf("Numero Par Mayor %d localizado en la posicion: %d con el numero %d de veces divisible entre 2\n",ParMayor,posicion,Ari);



	return 0;
}	///fin del programa




/* Primera explicacion: Debido a que una de las condiciones de la tarea es sumar el numero "Anterior" y el numero siguiente
del actual numero posicionado, vi que no tenia caso comparar la posicion 0 del arreglo ya que esta regla no podia realizarse 
debido a que no hay un numero antes de arreglo[0] y tampoco hay un numero Despues de la posicion arreglo[999] tambien otra 
comparativa decia que "El Numero Siguiente Del Siguiente" por lo cual al estar en la posicion 999 no habria otro numero si-
guiente de la posicion 1000.

En resumen, delimite el rango de las comparaciones del arreglo por no tener numeros anteriores o siguientes para realizar las
comparaciones pedidas en el caso de que el numero fuera Par.

Segunda Explicacion: comparamos si el numero actual posicionado es par, y si su siguiente es impar

Tercera Explicacion: comparamos si la suma del numero siguiente y anterior del actual numero posicionado nos da este mismo
y tambien comparamos si la division del numero actual entre 2, nos da al siguiente siguiente.
*/