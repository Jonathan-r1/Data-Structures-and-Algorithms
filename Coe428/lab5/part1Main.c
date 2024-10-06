//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//extern char *  pop();
//extern void push(char *);

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int ch;
  int var, popped;
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    //
    else if(ch=='<'){
      ch = getchar();
      if(isalpha(ch)){
        var = getchar();
        if((var =='>')&& (var !=EOF)){
          push(ch);
        }
        else{
          printf("Incomplete tag. Run again");
          exit(1);
        }
      }
      else if(ch =='/'){
        ch = getchar();
        if(isalpha(ch)){
          var = getchar();
          if((var =='>')&&(var != EOF)){
            if((isEmpty()) == 1){
              fprintf(stderr, "The stack is empty");
              exit(0);
            }
            else if((popped = pop())== ch){
              continue;
            }
            else
            fprintf(stderr, "Invalid");
            exit(1);
            {

            }
          }
          else{
            fprintf(stderr, "Closing not detected");
            exit(1);
          }
        }
      }
    }else{
      exit(0);
    }
  }
  if((isEmpty())==1){
    printf("Valid\n");
    exit(0);
  }else{
    printf("Invalid\n");
      exit(1);
  }

}