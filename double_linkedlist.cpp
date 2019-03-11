#include<iostream>

using namespace std;

struct node{
	
	int data;
	struct node *prev;
	struct node *next;

};

void insert(struct node **head,int data){

	struct node * newnode=new node;
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=NULL;
	
	
	//If list is empty....
	if(*head==NULL){
	
		*head=newnode;
		cout<<data<<" is inserted"<<endl;
		return;
	}
	
	
	struct node *temp=*head;
	
	if(data < (*head)->data){
		
			newnode->next=*head;
			*head=newnode;
			cout<<data<<" is inserted"<<endl;

			return;
		}
	
	
	//If there is only one node in list.....
	
	if((*head)->next==NULL){
	
		if(data < (*head)->data){
		
			newnode->next=*head;
			*head=newnode;
		}
		
		else{
			newnode->prev=*head;
			(*head)->next=newnode;
			
		
		}
	
	}
	
	
	else{
	
	while(temp){
	
		
		if(temp->data < data){
			temp=temp->next;
			
			if(temp->next==NULL){
				newnode->next=NULL;
				newnode->prev=temp;
				temp->next=newnode;
				cout<<data<<" is inserted"<<endl;
				return;
				
			}
		}
		
		
	}
	
	newnode->next=temp;
	temp->prev->next=newnode;
	
	
	}
	
	cout<<data<<" is inserted"<<endl;


}


void printlist(struct node *head){

	struct node *temp=head;
	
	while(temp){
	
		cout<<temp->data<<"->";
		temp=temp->next;
	
	}
	
	cout<<endl;

}


void search(struct node *head,int data){

	
	struct node *temp=head;
	
	while(temp){
		
		if(temp->data==data){
		
			cout<<data <<" found in list"<<endl;
			return;
		
		}
		temp=temp->next;
	
	}
	
	cout<<data <<" not found"<<endl;

}


void delete_(struct node **head,int data){

	struct node *temp=*head;
	
	if(temp==NULL){
	
		cout<<" List is empty"<<endl;
		return;
	}
	
	
	if(temp->data==data){
	
		*head=(*head)->next;
		cout<<data  <<" is deleted"<<endl;
		return;
	
	}
	
	while(temp){
	
		if(temp->data==data){
			
			temp->prev->next=temp->next;
			cout<<data <<" is deleted";
			return;
		
		}
		
		temp=temp->next;
		
		
	
	}

}


int main(){

	struct node *head=NULL;
	
	insert(&head, 19);
	insert(&head, 29);
	insert(&head, 12);
	insert(&head, 5);

	
	insert(&head, 0);
	printlist(head);
	search(head,0);
	search(head,1);
	
	
	delete_(&head,12);
	
	return 0;


}


















