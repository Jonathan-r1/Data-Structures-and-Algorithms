#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern void isEmpty();
extern void sortHeap(int);
extern int heapDelete();
extern int heapSize();
extern void printTree();
extern void addHeap();


int main(int argc, char * argv[])
{
  int value, i, removed, k;
  while (scanf("%d", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
    k +=1;
    addHeap(value);
    //
    
    
    
  }
  printTree(1);
  printf("\n");
  k = heapSize();
  for(i=0;i<k;i++){
    removed=heapDelete();
    push(removed);
    printf("%d, \n", removed);
  }
  printf("\n");
  for(i=0;i<k;i++){
    printf("%d \n", pop());
  }
  exit(0);
}
