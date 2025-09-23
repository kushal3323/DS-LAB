#include<stdio.h>
#define n 5
int stack[5];
int top=-1;

void push(){
  int x;
  printf("Enter the no:");
  scanf("%d",&x);
  if(top==n-1){
    printf("overflow");
  }
  else{
      ++top;
    stack[top]=x;
    
    printf("%d",stack[top]);
  }
}
void pop(){
    int item;
    if(top==-1){
        printf("Stack is empty,underflow");
    }
    else{
        item=stack[top];
        top--;
        printf("%d",item);

    }
}
int peek(){
    if(top==-1){
        printf("Stack is empty");

    }
    else{
        return stack[top];
    }
}
 void display(){
   if(top==-1){
    printf("empty stack,underflow");
   }
   else{
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
   }
 }
 int main(){
    int choice;
    
        printf("1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            
            default: printf("Invalid choice");
        }
 

}

