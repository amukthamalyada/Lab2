#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main() {
   unsigned long long number_circle = 0;
   unsigned long long number_tosses = 100000000;

#pragma omp parallel for num_threads(12) reduction(+:number_circle)
   for (unsigned long long toss = 0; toss < number_tosses; toss++) {
       double x = (double) rand() * 2 / (double) (RAND_MAX) - 1;
       double y = (double) rand() * 2 / (double) (RAND_MAX) - 1;
       double distance_squar = x * x + y * y;
       if (distance_squar <= 1) number_circle++;
   }


   printf("Pi estimation: %f", 4 * number_circle / ((double) number_tosses));
   return 0;
}
