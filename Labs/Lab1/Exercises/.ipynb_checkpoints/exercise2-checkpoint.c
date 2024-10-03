#include <omp.h>
#include <stdio.h>
#include <stdlib.h>



int main() {
    int Array[100]; // Use rand() % 10000 for init
    int max = 0;
    int min = 100000; 
    int sum = 0;
    int avg;

    #pragma omp parallel for 
    for(int i = 0 ; i<100; i++){
        Array[i] = rand() % 10000;
    }

    #pragma omp parallel for reduction(max:max) reduction(min:min) reduction(+:sum)
    for (int i = 0; i < 100; i++) {
        if (Array[i] > max) {
            max = Array[i];
        }
        if (Array[i] < min) {
            min = Array[i];
        }
        sum += Array[i];
    }

    // Calcular el promedio
    avg = sum / 100;

    // Imprimir resultados
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("Average: %d\n", avg);


    return 0;
}