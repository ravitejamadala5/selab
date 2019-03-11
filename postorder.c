#include <stdio.h>
#include <stdlib.h>
 

#define MAX_SIZE 100
 

struct Node {
    int data;
    struct Node *left, *right;
};
 

struct Stack {
    int size;
    int top;
    struct Node** array;
};
 

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->size * sizeof(struct Node*));
    return stack;
}
 

struct Node *create_node(int n){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> data = n;
	new_node -> left = NULL;
	new_node -> right = NULL;

	return new_node;
}

struct Node *insert(struct Node *root, int n){
	struct Node *new_node = create_node(n);
	
	if( root == NULL){
		root = new_node;	
	}

	else {
		struct Node *temp = root;
		int flag = 1;
	
		while(flag == 1){			
			if(n <= temp -> data){

				if(temp -> left == NULL){
					temp -> left = new_node;
					flag = 0;			
				}

				temp = temp -> left;
			}
			else{
				if(temp -> right == NULL){
					temp -> right = new_node;
					flag = 0;				
				}		
				temp = temp -> right;	
			}
			
		}
		
	}
	printf("%d is inserted into the tree \n", n);
	// printf("%d", root -> data);
	return root;
}

int isFull(struct Stack* stack)
{
    return stack->top - 1 == stack->size;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
void push(struct Stack* stack, struct Node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
 
struct Node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
 

void postOrder(struct Node* root)
{
    if (root == NULL)
        return;
 

    struct Stack* s1 = createStack(MAX_SIZE);
    struct Stack* s2 = createStack(MAX_SIZE);
 

    push(s1, root);
    struct Node* node;
 

    while (!isEmpty(s1)) {

        node = pop(s1);
        push(s2, node);
 

        if (node->left)
            push(s1, node->left);
        if (node->right)
            push(s1, node->right);
    }
 

    while (!isEmpty(s2)) {
        node = pop(s2);
        printf("%d ", node->data);
    }
}
 

int main()
{

		struct Node *root = NULL;
	int n;
	printf("Enter the initial elements in the tree ");
	scanf("%d",&n);		
	int a[n];
	int i;	
	printf("Enter the numbers to be inserted \n");	

	for (i = 0 ; i < n ; i++){
		scanf("%d", &a[i]);
		root = insert(root, a[i]);		
	} 
    postOrder(root);
 
    return 0;
}