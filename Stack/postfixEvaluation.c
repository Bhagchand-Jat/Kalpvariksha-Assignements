#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef  struct stack
{
      int arr[MAX_SIZE];
      int top;
   
}Stack;



void initializeStack(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, int data);
int pop(Stack *stack);




int postfixEvaluation(char input[]){
  
    Stack stack;
    initializeStack(&stack);
 
        
    int i=0;
    while(input[i]!='\0'){
        
        if(input[i]==' '){
            i++;
        }else if(input[i]>='0' && input[i]<='9'){
          
                int value=0;
             while(input[i]!=' ' && input[i]!='\0'){
               value=value*10+(input[i++]-'0');
              }  
         
            push(&stack,value);

            i++;
            
        }else{
      
            if(stack.top<1){
                return 0;
            }

            int val1=pop(&stack);
            int val2=pop(&stack);
           switch(input[i]) {
               case '+':
                   push(&stack,val1+val2);
                   break;
               case '-':
                    push(&stack,val2-val1);
                   break;
               case '*':
                    push(&stack,val1*val2);
                   break;
               case '/':
                    if(val1==0){
                        return 0;
                    }
                    push(&stack,val2/val1);
                   break;  
               default:
                   break;      
           }
            i++;
        } 
       
    }
    
    if(stack.top==0){
        return pop(&stack);
    }else{
       return 0;
    }
    
}



int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    char input[MAX_SIZE];
    
    scanf("%[^\n]s",input);
    int result=postfixEvaluation(input);
    printf("%d",result);
    return 0;
}


void initializeStack(Stack *stack){
    stack->top=-1;
}

int isEmpty(Stack *stack){
    return stack->top==-1;
}

int isFull(Stack *stack){
    return stack->top==MAX_SIZE-1;
}

void push(Stack *stack, int data){
    
    if(isFull(stack)){
        return ;
    }
    stack->arr[++stack->top]=data;

    
}

int pop(Stack *stack){
    if(isEmpty(stack)){
    
        return -1;
    }
    return stack->arr[stack->top--];
   
}
