#include<stdio.h>
#include<stdlib.h>
#define bool int
 

struct tNode
{
   int data;
   struct tNode* left;
   struct tNode* right;
};
 
struct sNode
{
  struct tNode *t;
  struct sNode *next;
};
 
void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);
 
void inOrder(struct tNode *root)
{
  struct tNode *current = root;
  struct sNode *s = NULL;  
  bool done = 0;
 
  printf("The Inorder Traversal \n");		
  while (!done)
  {
    if(current !=  NULL)
    {
      push(&s, current);                                               
      current = current->left;  
    }
        
    else                                                             
    {
      if (!isEmpty(s))
      {
        current = pop(&s);
        printf("%d ", current->data);
 
        current = current->right;
      }
      else
        done = 1; 
    }
  }
}     
 
void push(struct sNode** top_ref, struct tNode *t)
{
  struct sNode* new_tNode =
            (struct sNode*) malloc(sizeof(struct sNode));
 
  if(new_tNode == NULL)
  {
     printf("Stack Overflow \n");
     getchar();
     exit(0);
  }            
 
  new_tNode->t  = t;
 
  new_tNode->next = (*top_ref);   
 
  (*top_ref)    = new_tNode;
}
 
bool isEmpty(struct sNode *top)
{
   return (top == NULL)? 1 : 0;
}   
 
struct tNode *pop(struct sNode** top_ref)
{
  struct tNode *res;
  struct sNode *top;
 
  if(isEmpty(*top_ref))
  {
     printf("Stack Underflow \n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->t;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
 


struct tNode *create_node(int n){
	struct tNode *new_node = (struct tNode*)malloc(sizeof(struct tNode));
	new_node -> data = n;
	new_node -> left = NULL;
	new_node -> right = NULL;

	return new_node;
}

struct tNode *insert(struct tNode *root, int n){
	struct tNode *new_node = create_node(n);
	
	if( root == NULL){
		root = new_node;	
	}

	else {
		struct tNode *temp = root;
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

struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)
                       malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;
 
  return(tNode);
}
 
int main()
{

  struct tNode *root = NULL;
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
	inOrder(root);
 
  getchar();
  return 0;
}