#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {
int i, j,number;
    for(i = first; i <= last; i++){
		number = array[i];
	    j = i-1;

	    while(j >= 0 && (myCompare(array[j], number) >0)){
        mySwap(&array[j+1], &array[j]);

		j = j - 1;
	}
     myCopy(&number, &array[j+1]);
		//d[j+1] = number;

	}
}
    
