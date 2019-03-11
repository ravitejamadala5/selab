#include<iostream>
#include<list>

using namespace std;

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
   //cout<<data<<" is inserted"<<endl;

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


void bfs(int graph[4][4],int s){


	int visited[4]={0,0,0,0};
	
	
	visited[s]=1;
	struct queue *q=createQueue();
	enQueue(q,s);

	while(!isEmpty(q)){
		

		s=peek(q);
		cout<<s<<" ";
		deQueue(q);
		
		

		for(int j=0;j<4;j++){

			if(graph[s][j]==1 && visited[j]==0){
				visited[j]=1;
				enQueue(q,j);

			}
		}
	}


	/*list<int> queue;

	visited[s]=1;
	queue.push_back(s);

	while(!queue.empty()){

		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();

		for(int j=0;j<4;j++){

			if(graph[s][j]==1 && visited[j]==0){
				visited[j]=1;
				queue.push_back(j);

			}
		}

	}*/



}


int main(int argc, char const *argv[])
{
	int graph[4][4]={
		{0,1,1,0},
		{0,0,1,0},
		{1,0,0,1},
		{0,0,0,1}
	};

	bfs(graph,2);
	return 0;
}