#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Queue{
	int height;
	struct Node *node;
	struct Queue *next;
};

void enqueue(struct Queue **queue, struct Node * temp){
	if(!temp){	
		return;
	}
	struct Queue *help = NULL;
	struct Queue *start = NULL;
	struct Queue *newnode =(struct Queue*)malloc(sizeof(struct Queue));	
	
	newnode -> next = NULL;
	newnode -> node = temp;
	*queue  = newnode;
	newnode -> height = 1;
	help = start = newnode;
	
	while(help){
		if(help -> node -> left){
			newnode = (struct Queue*)malloc(sizeof(struct Queue));
			newnode -> height = help -> height + 1;
			newnode -> next = NULL;
			newnode -> node = help -> node -> left;
			start -> next = newnode;
			start = newnode;
		}
		if(help -> node -> right){
			newnode = (struct Queue*)malloc(sizeof(struct Queue));
			newnode -> height = help -> height + 1;
			newnode -> next = NULL;
			newnode -> node = help -> node -> right;
			start -> next = newnode;
			start = newnode;
		}
	help = help -> next;
	}

}

void count_height(struct Queue *temp){
	
	int height = 0;
	if(temp)	{
		while(temp){
			if(height < temp -> height){
				height = temp -> height;
			}
			temp = temp -> next;
			height = (height >0)?(height-1):0;		
		}
		printf("The height of the tree is %d \n", height);	
	}
	else
		printf("Empty tree \n");
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

void inorder(struct Node *root){
	if(root == NULL){
		return;
	}
	inorder(root -> left);
	printf("%d \n", root -> data);
	inorder(root -> right);
}

struct Node* minimum_key(struct Node *curr){
	while(curr -> left != NULL){
		curr = curr -> left;	
	}
	return curr;
}


void search_key(struct Node *curr, int key, struct Node *parent){
	while(curr != NULL && curr -> data != key){
		parent = curr;
	if(key < curr -> data)
		curr = curr -> left;
	else 
		curr = curr -> right;
	}
}

void search(struct Node *root, int n){
	int flag = 0;
	struct Node *temp = root;
	while(temp != NULL){ 
		if(n == temp -> data){
			flag = 1;
			break;		
		}
		else if(n < temp -> data)
			temp = temp -> left;
		else 
			temp = temp -> right;
	}
	if(flag == 1){
		printf("Found \n");
	}
	else 	
		printf("Not Found \n");
}

void delete_node(struct Node *root, int key) {
	struct Node *parent = NULL;
	struct Node *curr = root;
	search_key(curr, key, parent);
	if(curr == NULL)
		return;
	if(curr -> left == NULL && curr -> right == NULL){
		if(curr != root){
			if(parent -> left = curr)
				parent -> left = NULL;
			else 
				parent -> right = NULL;		
		}
		else 
			root = NULL;
		free (curr);
	}	
	else if(curr -> left && curr -> right){
		struct Node *successor = minimum_key(curr -> right);
		int val = successor -> data;
		delete_node(root, successor -> data);
		curr -> data = val;	
	}
	else{
		struct Node *child = (curr -> left)? (curr -> left): (curr -> right);
		if(curr != root){
			if(curr == parent -> left)
				parent -> left = child;	
			else 	
				parent -> right = child;		
		}

		else root = child;
		free(curr);	
	}
}



int main(){
	struct Node *root = NULL;
	struct Queue *height = NULL;
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
	inorder(root);
	int d;
	printf("Enter a number to delete \n");
	scanf("%d", &d);
	delete_node(root, d);
	inorder(root);
	enqueue(&height, root);
	count_height(height);
	int s;
	printf("Enter an element to be searched \n");
	scanf("%d", &s);
	search(root, s);
return 0;
}	
