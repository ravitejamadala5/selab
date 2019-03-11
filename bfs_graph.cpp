#include <iostream>
#include<stdlib.h>
#include<list>

using namespace std;

struct stackcell
{
   int data;
   struct stackcell* next;
};

struct stackcell* top=NULL;


struct stackcell* createNewNode(int data)
{
   struct stackcell* newnode=(struct stackcell*)malloc(sizeof(struct stackcell));
   newnode->data=data;
   newnode->next=top;
   return newnode;
}


void push(int data)
{
   struct stackcell* newnode=createNewNode(data);
   top=newnode;

}


bool isEmpty()
{
   return !top;
}

int topElement()
{
   if(isEmpty())
   {
      cout<<"Stack is empty"<<endl;    
   }
   return top->data;
}

int pop()
{

   if(isEmpty())
   {
      cout<<"stack is empty"<<endl;
   }
   struct stackcell* temp=top;
   top=top->next;
   int popped=temp->data;
   free(temp);
   return popped;
      
}


void dfs(int graph[7][7],int s){

   int visit[7]={0,0,0,0};

   push(s);
   	cout << " The DFS Order is -- >" << endl;
   while(!isEmpty()){

         s=pop();

         if(visit[s]!=1){
            visit[s]=1;

            cout<<s<<" ";
         }

         for(int j=0;j<7;j++){

            if(graph[s][j]!=0 && visit[j]==0){

               
               push(j);
            }
         }


   }
	cout << endl;
}

struct queueNode
{
   int data;
   struct queueNode* next;
};

struct queue
{
   struct queueNode  *front,*rear;
   
};

struct queueNode* newNode(int data)
{
   struct queueNode* newNode=(struct queueNode*)malloc(sizeof(struct queueNode));
   newNode->data=data;
   newNode->next=NULL;
}

struct queue* createQueue()
{
   struct queue* q=(struct queue*)malloc(sizeof(struct queue));
   q->front=q->rear=NULL;
   return q;
}

void enQueue(struct queue* q,int data)
{
   struct queueNode* temp=newNode(data);
   if(q->rear==NULL)
      q->front=q->rear=temp;

   q->rear->next=temp;
   q->rear=temp;


}

struct queueNode* deQueue(struct queue* q)
{
   if(q->front==NULL)
      return NULL;
   struct queueNode* temp=q->front;
   q->front=q->front->next;
   if(q->front==NULL)
      q->rear=NULL;
   
   
}

bool isEmpty(struct queue *q){

	if(q->rear==NULL&& q->front==NULL)
		return true;

	else
		return false;
}

int peek(struct queue *q){

	return q->front->data;
}


void bfs(int graph[7][7],int s, int visited[7], int j){


	// int visited[4]={0,0,0,0};
	
	if( j == 0){
	list<int> queue;

	visited[s]=1;
	queue.push_back(s);

	cout << "The BFS Order is --> " << endl;
	while(!queue.empty()){

		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();

		for(int j=0;j<7;j++){

			if(graph[s][j]==1 && visited[j]==0){
				visited[j]=1;
				queue.push_back(j);

			}
		}

	}
	cout << endl;

	}

}

void bfscycle(int graph[7][7],int s, int visited[7], int j){


	// int visited[4]={0,0,0,0};
	

	list<int> queue;


	queue.push_back(s);


	while(!queue.empty()){

		s=queue.front();

		queue.pop_front();
		visited[s]=1;
		for(int j=0;j<7;j++){

			if(graph[s][j]==1 && visited[j]==0){
				visited[j]=1;
				queue.push_back(j);

			}
			if(graph[s][j]==1 && visited[j]==1){
				cout << "Its a cyclic Graph " << endl;
				return;
			}
		}

	}
	cout << endl;


}

void bfstraversal(int graph[7][7]){

	int visited[7]= {0,0,0,0,0,0,0};
	int j = 0; 
		
	for(int i = 0 ; i < 7 ; i++){
		if(visited[i] == 0){

		bfs(graph,i , visited , j);
		bfscycle(graph,i , visited , j);
		j++;	
	}
	if(j == 1){
	cout << "Disconnected Graph" << endl;
	return;
	}

	}

}


int main(int argc, char const *argv[])
{
	int graph[7][7]={
		{0, 1, 0, 1, 0 ,0 ,0},
		{1, 0,1, 0, 0, 0, 0},
		{0,1,0,1, 0 ,0 ,0},
		{1,0,1,0, 0 , 0 , 0},
		{0,0,0,0, 0 , 1, 1},
		{0,0,0,0 , 1 ,0 ,0},
		{0,0,0,0,1 , 0, 0}

	};

	bfstraversal(graph);
	dfs(graph,0);
	return 0;
}


