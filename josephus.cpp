#include <iostream>

using namespace std;

struct node {
	int data;
	struct node *next;
};

struct node *newnode(int n){
	struct node *temp= new node;
	temp -> next = temp;
	temp -> data = n;	
}

void josephus(int m, int n){
	struct node *head = newnode(1);
	struct node *temp = head;

	for(int i = 2 ; i <= n ; i++){
		temp -> next = newnode(i);
		temp = temp -> next;
	}
	
	temp -> next = head;

	struct node *n1 = head;
	struct node *n2 = head;


	while( n1 -> next != n1){
		int count = 1;
		while(count != m){
			n2 = n1;
			n1 = n1 -> next;
			count ++;		
		}
		n2 -> next = n1 -> next;
		n1 = n2 -> next;						
	}

	cout <<  "The Last Man surviving is -" << n1 -> data;

}


int main(){
	int n , m;
	cout <<  "Enter the number of persons - " ;
	cin >> n;
	cout << "Enter the mth person to be killed - " ;
	cin >> m;
	josephus(m,n);

	return 0;
}

	
