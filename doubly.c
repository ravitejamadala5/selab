#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
	
};

struct node* head = NULL;

void insert()
{
	int num;
	printf("\nEnter a number to insert\n");
	scanf("%d",&num);
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode -> data = num;

	if(head == NULL)
	{
		newnode -> prev = NULL;
		head = newnode;
		newnode -> next = NULL;

	}
	else //Not first element
	{
		struct node* temp1 = head;
		struct node* temp2;
		struct node* temp3;
		
		if(temp1 -> data > num)
		{
			
			newnode -> next = head;
			head = newnode;
		}
		else
		{
			while((temp1 -> next) && (temp1 -> next -> data < num))
			{	
				temp1 = temp1 -> next;
			}
		
		
			temp2 = temp1 -> next;
			temp1 -> next = newnode;		
			newnode -> prev = temp1;
			newnode -> next = temp2;

		}
	}
	return;
}

void display()
{
	struct node* temp = head;
	while(temp)
	{
		printf("%d ->",temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

void  search()
{
	int num,s;
	printf("Enter a number to search");
	scanf("%d",&num);					
	
	int flag = 0;
	struct node* temp = head;
	while(temp)
	{
		if(temp -> data == num)
			flag = 1;
		temp = temp -> next;
	}
	if(flag)
	printf("%d is in list",num);					
	else
	printf("%d is not in list",num);	

}

void delete()
{
	int num,s;
	struct node *temp = head;
	printf("Enter a number to delete");
	scanf("%d",&num);					
	
	
	
	printf("came here 1");
	if(temp==NULL){
	
		printf(" List is empty \n");
		return;
	}
	
	
	printf("came here 2");
	
	printf("came here 3");
	while(temp != NULL){
	
		if(temp->data==num){
			
	printf("came here 4");
			temp->prev->next=temp->next;
				temp -> next -> prev = temp -> prev;	
		printf("%d is deleted \n", num); 
			return ;
		
		}
		
	printf("came here 5");
		temp=temp->next;
		
		
	
	}
}

int main()
{

	printf("1.insert \n 2.delete\n3.search\n4.display\n5.exit\n");
	while(1)
	{
		int choice;
		printf("enter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					insert();
					break;
			case 2:
					delete();
					break;
			case 3:	
					search();
					break;
			case 4:
					display();
					break;
			case 5:
				exit(-1);
			default:
				printf("choose a valid option\n");
		}


	}
}