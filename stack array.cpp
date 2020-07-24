#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Stack
{
		int top;
		unsigned capacity;
		int *array;
		 
};
//fn to create stack and initialize size of stack to 0

struct Stack *createstack(unsigned capacity)
{
	struct Stack *stack= (struct Stack*) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top=-1;
	stack->array=(int*)malloc(stack->capacity*sizeof(int));
	
}

int isFull(struct Stack* stack)
{
	return stack->top==stack->capacity -1;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}
void push(struct Stack* stack, int item)
{
	if(isFull(stack))
		return;
	stack-> array[++stack->top]=item;
	printf("%d pushed to stack\n",item);
}

int pop(struct Stack* stack)
{
	if(isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}
int peek(struct Stack*stack)
{
	if(isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}
int main()
{
	int n;
	printf("Enter the number of elements : \n");
	scanf("%d",&n);
	struct Stack*stack=createstack(n);
	while(1)
	{
	printf("1.Push 2.Pop 3.Peek 4. display 5. Exit\n");
	int ch;
	printf("Enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:for(int j=0;j<n;j++)
				{
				printf("enter element to push:");
				int nn;
				scanf("%d",&nn);
				push(stack,nn);
				}
				break;
				
		case 2: int m;
				m= pop(stack);
				printf("%d popped out\n",m);
				break;
		case 3: int p;
				p=peek(stack);
				printf("%d on top\n",p);
				break;
		case 4:for(int i=0;i<=stack->top;i++)
					printf("%d",stack->array[i]);
				break;
		case 5: exit(0);
	}	
	}
}
