#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BILLION 1000000000L
//LABEL EVERYTHING
double startTime, stopTime;

main (){
 // cache size, assoc, block size
 // increase the size of the array and use gettime and day

	struct timespec start, end;
	uint32_t diff;
	int a, i, j, k, arraySize;
	int dummy_value = 3;
	int stride;

	int *arr = (int*)malloc(256*1024*1024 * sizeof(int*));

	for (arraySize = 4*1024; arraySize <= 8*1024*1024; arraySize *= 2){
   		for (stride = 4; stride <= arraySize/2; stride *= 2){
			//for(a = 0; a < 10; a++){
				clock_gettime(CLOCK_MONOTONIC, &start);     
				for (i = 0; i < arraySize; i += stride){
        		    		arr[i] = dummy_value;
				}
				clock_gettime(CLOCK_MONOTONIC, &end);
				//printf("\n\n");
				printf("Stide is %d\n", stride);
				printf("%dKB\n", arraySize/(1024));
				diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
				printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
			//}
    		}
	printf("\n");
	}
/*
		for (stride = 1; stride <= 512*1024; stride += 32*1024/20){
				clock_gettime(CLOCK_MONOTONIC, &start);     
				for (i = 1; i <= 32*1024*1024; i += stride){
        		    		arr[i] = dummy_value;
				}
				clock_gettime(CLOCK_MONOTONIC, &end);
				//printf("\n\n");
				printf("Stide is %d\n", stride);
				diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
				printf("%llu nanoseconds\n", (long long unsigned int) diff);
			
    		}
	printf("\n");
*/


}

