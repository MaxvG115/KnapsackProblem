/*Programa elaborado por:
Maximiliano Villegas García
Emma Gabriela Alfaro de la Rocha
Emmanuel Humberto Solórzano Cabrera
Pablo Gutiérrez Costales 
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Estructura para definir el tipo de objeto item, cada item tiene un valor y un peso
struct Item{
  int value;
  int weight;
};

// Con esta funcion de comparacion podremos ordenar los valores por el puntaje que tengan en base a su valor/peso
bool Scompare(struct Item a, struct Item b)
{
    float item1 = (float)a.value / (float)a.weight;
    float item2 = (float)b.value / (float)b.weight;
    return item1 > item2;
}

// La funcion para resolver el problema reecibira lo siguiente:
// Item arr[] = un arreglo con los items
// int W = el peso maximo que soporta nuestra mochila, se le asigna la W de weight(peso)
// int H = entero que funciona como indice para nuestra funcion de sort, se le asigna la H de helper(ayudante)
float knapSack(Item arr[], int W, int H){

  // Variable para asignar el total de valor que podemos conseguir
  float result = 0.0;

  // Ordenamos los items basandonos en su puntaje
  sort(arr, arr + H, Scompare);

  // Recorremos todos los items con un ciclo
  for (int i = 0; i < H; i++) {
    
    // Verificamos si es posible agregar un item sin exceder nuestro peso limite
    // Si es posible lo agregamos
    if (arr[i].weight <= W) {
      W -= arr[i].weight;
      result += arr[i].value;
    }
 
    // Si no podemos agregar el item en su totalidad, agregamos la parte fraccional
    else {
      result += arr[i].value * ((float)W / (float)arr[i].weight);
      break;
    }
  }
  
  // La funcion arrojara el mayor valor posible como resultado
return result;
}


int main() {
  //Ejemplo visto en clase
  int W = 100;
  Item arr[] = { { 20, 10 }, { 30, 20 }, { 66, 30 }, { 40, 40 }, { 60, 50 }};
  int H = sizeof(arr) / sizeof(arr[0]);
 

  cout << "La mayor cantidad de valor que podemos insertar en la mochila es " << knapSack(arr, W, H);
  return 0;
}

/*Programa elaborado por:
Maximiliano Villegas García
Emma Gabriela Alfaro de la Rocha
Emmanuel Humberto Solórzano Cabrera
Pablo Gutiérrez Costales 
*/
