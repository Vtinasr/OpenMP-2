#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel num_threads(10)
    {
        int thread = omp_get_thread_num();

        if(thread%2==0){
            printf("This thread is pair %d\n", omp_get_thread_num());
        }else{
           printf("This thread is odd %d\n", omp_get_thread_num()); 
        }
        
    }
    return 0;
}