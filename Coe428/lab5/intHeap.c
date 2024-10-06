#include <tgmath.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
extern int pop();
extern void push(int);
/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */


/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
static int amount = 0;
int fullHeap[100];
int tmp[100];

int heapDelete()
{
  int i,tTmp=amount,temporary=fullHeap[1];
	for(i=0;i<tTmp-1;i++)
		tmp[i]=fullHeap[i+2];
	amount=0;
	for(i=0;i<100;i++)
		fullHeap[i]=0;
	for(i=0;i<tTmp;i++)
		addHeap(tmp[i]);
	return temporary; //A dummy return statement
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
  int i, temporary;
  amount += 1;
  fullHeap[amount] = thing2add;
  fullHeap[0] = fullHeap[amount];
  for(i=amount/2;i>=1;i--){
    if((2*i+0<=amount)&&(fullHeap[i]<fullHeap[2*i])){
      temporary = fullHeap[i];
      fullHeap[i] = fullHeap[2*i];
      fullHeap[2*i] = temporary;
      if(2*i<=amount/2)
      i = 2*i+1;
    }
    else if((2*i+1<=amount)&&(fullHeap[i]<fullHeap[2*i+1])){
			temporary=fullHeap[i];
			fullHeap[i]=fullHeap[2*i+1];
			fullHeap[2*i+1]=temporary;
			if (2*i+1<=amount/2)
				i=2*i+2;
    }
  }
}

void printTree(int hlpr){
	while (hlpr<=amount){
		printf("<node id = \"%d\"> ",fullHeap[hlpr]);
		if (hlpr*2<= amount)
			printTree(hlpr*2);
		if (hlpr*2+1<=amount)
			printTree(hlpr*2+1);
		hlpr=amount+1;
	}
	printf( "</node> ");
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return amount;  //A dummy return statement
}


