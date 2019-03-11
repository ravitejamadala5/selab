#include <stdlib.h>
#include <stdio.h>
#include <stack>
 
using namespace std;
 

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 

struct node *create_node(int n){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = n;
	new_node -> left = NULL;
	new_node -> right = NULL;

	return new_node;
}

struct node *insert(struct node *root, int n){
	struct node *new_node = create_node(n);
	
	if( root == NULL){
		root = new_node;	
	}

	else {
		struct node *temp = root;
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
void Preorder(node *root)
{

    if (root == NULL)
       return;
 

    stack<node *> nodeStack;
    nodeStack.push(root);
 
    while (nodeStack.empty() == false)
    {

        struct node *node = nodeStack.top();
        printf ("%d ", node->data);
        nodeStack.pop();
 

        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}
 
int main()
{
   
	struct node *root = NULL;
	
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
 
  Preorder(root);
  return 0;
}