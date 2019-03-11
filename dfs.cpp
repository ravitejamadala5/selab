#include<iostream>
using namespace std;

//Structure to define a node or cell in the stack....
struct stackcell
{
   int data;
   struct stackcell* next;
};

struct stackcell* top=NULL;//This is pointing to the topmost element of the stack....

//Creating a new cell.....
struct stackcell* createNewNode(int data)
{
   struct stackcell* newnode=(struct stackcell*)malloc(sizeof(struct stackcell));
   newnode->data=data;
   newnode->next=top;
   return newnode;
}

//inserting an element in the stack
void push(int data)
{
   struct stackcell* newnode=createNewNode(data);
   top=newnode;
   //cout<<data<<" is pushed to the stack"<<endl;
}

//checking whether a stack is empty...
bool isEmpty()
{
   return !top;
}

//returning the top element in the stack
int topElement()
{
   if(isEmpty())
   {
      cout<<"Stack is empty"<<endl;    
   }
   return top->data;
}

//popping out the element in the stack
int pop()
{
   //checking for underflow
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


void dfs(int graph[5][5],int s){

   int visit[5]={0,0,0,0,0};

   push(s);
   
   while(!isEmpty()){

         s=pop();

         if(visit[s]!=1){
            visit[s]=1;
            cout<<s<<" ";
         }

         for(int j=0;j<5;j++){

            if(graph[s][j]!=0 && visit[j]==0){

               
               push(j);
            }
         }


   }
}


int main(int argc, char const *argv[])
{
   int graph[5][5]={

      {0,0,1,1,0},
      {1,0,0,0,0},
      {0,1,0,0,0},
      {0,0,0,0,1},
      {1,0,0,0,0}
   };
   dfs(graph,0);
   return 0;
}