#include <stdlib.h>
#include <string.h>
int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;
    for(int i=0;i<tokensSize;i++){
        char *token = tokens[i];
        if(strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 ||strcmp(token, "/") == 0){
            int b = stack[top--];
            int a = stack[top--];
            switch(token[0]){
                case '+':stack[++top]= a+b; break;
                case '-':stack[++top]= a-b; break;
                case '*':stack[++top]= a*b; break;
                case '/':stack[++top]= a/b; break;
            }
        }
        else{
            stack[++top]=atoi(token);
        }
    }
    return stack[top];    
}