#include "mySort.h"


void merge(int arr[], int x1, int y1, int x2, int y2){
    int temp[MAX_SIZE_N_TO_SORT];
    int x, y, z;
    x = x1;
    y = x2;
    z = 0;

    while(x<=y1 && y<=y2){
        if(myCompare(arr[x], arr[y])<0)
            temp[z++] = arr[x++];
        else
            temp[z++] = arr[y++];

    }

    while(x<=y1)
        myCopy(&arr[x++], &temp[z++]);
    while(y<=y2)
        myCopy(&arr[y++], &temp[z++]);

    for(x = x1, z=0; x<= y2; x++,z++)
        mySwap(&arr[x], &temp[z]);
}


void mySort(int array[], unsigned int first, unsigned int last)
    {
        int mid;
        if(first < last){
            mid = (first+last)/2;
            mySort(array, first, mid);
            mySort(array, mid+1, last);
            merge(array, first, mid, mid+1, last);
        }
    }
