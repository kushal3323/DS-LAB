#include <stdio.h>
#include <ctype.h>  
#define SIZE 50

char stack[SIZE];
int top = -1;


void push(char elem) {
    stack[++top] = elem;
}


char pop() {
    return stack[top--];
}


int precedence(char symbol) {
    if(symbol == '*' || symbol == '/')
        return 2;
    else if(symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;  
}

int main() {
    char infix[SIZE], postfix[SIZE];
    char ch, elem;
    int i = 0, k = 0;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    while((ch = infix[i++]) != '\0') {
        if(ch == '(') {
            push(ch);  
        }
        else if(isalnum(ch)) { 
            postfix[k++] = ch;
        }
        else if(ch == ')') {   
            while(top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();  
        }
        else {  
            while(top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    
    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';  

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
