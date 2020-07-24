#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct StackNode
{
		int data;
		struct StackNode* next;
		 
};
struct StackNode* newNode(int data)
{
	struct StackNode* stackNode=(struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data =data;
	stackNode->next=NULL;
	return stackNode;
}
int isEmpty(struct StackNode*root)
{
	return !root; 
}
void push(struct StackNode** root, int data)
{
	struct StackNode* stackNode = newNode(data);
	stackNode->next =*root;
	*root=stackNode;
	printf("%d pushed to stack\n",data);
}
int pop(struct StackNode** root)
{
	if(isEmpty(*root))
		return INT_MIN;
	struct StackNode*temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}
int peek(struct StackNode* root)
{
	if(isEmpty(root))
		return INT_MIN;
	return root->data;		
}
int main()
{
	struct StackNode* root = NULL;
	push(&root,10);
	push(&root,2);
	push(&root,30);
	push(&root,40);
	printf("%d",pop(&root));
	printf("%d",peek(root));
	return 0;
	
}
