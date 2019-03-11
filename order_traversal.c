# include <stdio.h>
# include <stdlib.h>

struct node{
        int data;
        struct node *left;
        struct node *right;
};

struct link{
        struct node *t;
        struct link *next;
};

void push(struct link **top, struct node *root){
        struct link *newnode =(struct link*)malloc(sizeof(struct link));
        newnode -> t = top;
        newnode -> next = (*top);
        *top = newnode;
}

struct node *pop(struct link **topref){
	struct node *res;
	struct link *top;

	if(isempty(top)){
		
	}

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

void inorder( struct node *root){
        struct node *current = root;
        struct link *s = NULL;
        int flag = 1;
        while(flag == 1){
                if(current != NULL){
                        push(&s, current);
                        current = current -> left;
                }

                else{
                        if(!isempty(s)){
                                current = pop(&s);
                                printf("%d  ", current -> data);
				current = current -> right;
                        }

                }

        }
}


int main(){
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

	inorder(root);
}
