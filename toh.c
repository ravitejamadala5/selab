#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct tower{
	unsigned capacity;
	int top;
	int *array;
};


struct tower *create_stack(unsigned capacity) {
	struct tower* stack = (struct tower*)malloc(sizeof(struct tower));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array = (int*)malloc(stack -> capacity * sizeof(int));
	return stack; 	
}

int is_full(struct tower *stack){
	return(stack -> top == stack -> capacity - 1);
}


int is_empty(struct tower *stack){
	return(stack -> top == -1);
}

void push(struct tower *stack, int item){
	if(is_full(stack)){
		return;	
	}
	stack -> array[++stack -> top] = item;
}

int pop(struct tower *stack){
	if(is_empty(stack)){
		return INT_MIN;	
	}
	return stack -> array[stack -> top --];
}

void printer_move_disks(char from, char to, int disk){
	printf("Move the disk %d from %c to %c \n", disk, from, to);
}

void move_disks(struct tower *src, struct tower *dest, char s, char d){
	int p1 = pop(src);
	int p2 = pop(dest);
	if(p1 == INT_MIN) {
		push(src, p2);
		printer_move_disks(d, s , p2);
			
	}
	else if(p2 == INT_MIN) {
		push(dest, p1);
		printer_move_disks(s, d , p1);
			
	}
	
	else if(p1 > p2){
		push(src, p1);
		push(src, p2);
		printer_move_disks(d, s , p2);
	}

	else {
		push(dest, p2);
		push(dest, p1);
		printer_move_disks(s, d ,p1);
	}
}

void tower_solution( int num_disks, struct tower *src, struct tower *aux, struct tower *des){
	int i, total_moves;
	char s = 'S';
	char d = 'D';
	char a = 'A';

	if(num_disks % 2 == 0){
		char temp = d;
		d = a;
		a = temp;
	}

	total_moves = pow(2, num_disks) - 1;
	
	for(i = num_disks; i >= 1; i--){
		push(src, i);
	}

	for(i = 1 ; i <= total_moves; i++){
		if(i % 3 == 1)
		move_disks(src, des, s, d);
		
		else if( i % 3 == 2)
		move_disks(src, aux, s, a);
	
		else if(i % 3 == 0)
		move_disks(aux, des, a, d);

		
	}

} 

int main(){
	int n;
	printf("Enter the number of disks \n");
	scanf("%d", &n);
	struct tower *src, *dest, *aux;
		
	src = create_stack(n);
	aux = create_stack(n);
	dest = create_stack(n);

	tower_solution(n, src, aux, dest);
	return 0;
}
