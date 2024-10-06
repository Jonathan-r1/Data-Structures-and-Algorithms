#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char * argv[])
{

int data[100000]; 
int nDataItems;
int i;

if(argc == 1){

	nDataItems = 4;
	data[0] = 20;
	data[1] = 10;
	data[2] = 40;
	data[3] = 30;
	mySort(data, nDataItems);

for(i = 0; i < nDataItems-1; i++){
	printf("%d\n", data[i]);
}
}

else if(argc >1){
	nDataItems = argc-1;

for(i = 1; i < argc ; i++){
	data[i-1] = atoi(argv[i]);
}


for(i = 0; i < nDataItems; i++){
mySort(data,nDataItems);
}
for(i=0; i< nDataItems; i++){
printf("%d\n", data[i]);
}
} 
exit(0);
}
	
