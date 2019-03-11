#include <iostream>
#include <stdlib.h>

using namespace std;

#define N 3

void get_cofactor(int A[N][N],int  temp[N][N], int p  ,int q, int n){

	int i = 0;
	int j = 0;

	for(int row = 0 ; row < n ; row++){
		for(int col = 0 ; col < n; col ++){
			if(row != p && col != q){
				temp[i][j++] = A[row][col];
			}


			if( j == n-1){
				i++;
				j = 0;
			}
			
		}
	
	
	}


}

int get_determinant(int A[N][N], int n){


	int d = 0;
	int sign = 1;

	if(n == 1)
		return A[0][0];


	int temp[N][N];

	for(int f = 0 ; f < n ; f++){
		get_cofactor(A, temp, 0 , f , n);

		d += sign*A[0][f]*get_determinant(temp, n-1);
		sign = - sign;
	}

	return d;

}


void get_adjoint(int A[N][N], int adj[N][N]){

	if(N == 1){
		adj[0][0] = 1;
		return;
	}

	int sign = 1, temp [N][N];

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			get_cofactor(A, temp, i , j , N);
			sign = ((i+j)%2 == 0)? 1 : -1;
			adj[j][i] = (sign) * (get_determinant(temp, N - 1));

		}

	}

}


bool inverse(int A[N][N] , float inverse[N][N]){

	int det = get_determinant(A,N);

	if(det == 0){
		cout << "It has no inverse" << endl;
		return false;
	}

	int adj[N][N];
	get_adjoint(A, adj);

	for(int i = 0; i < N; i++)
		for(int j = 0 ; j < N ; j++)
			inverse[i][j] = adj[i][j]/ float(det);
	
	return true;

}


template <class T>

void display(T A[N][N]){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
		
			cout << A[i][j] << "  ";
		
		}
		cout << endl;
	
	}

}


int main(){

	int A[N][N] = {{7, 2, 1},{0, 3, -1},{-3, 4, -2}}; 

	cout<< "Enter the elements of the matrix"<< endl;

	int adj[N][N];
	float inv[N][N];

//	cout << "Adjoint Matrix is " << endl;
//	get_adjoint(A, adj);
//	display(adj);

	cout << "The invese Matrix is " << endl;
	if(inverse(A, inv))
			display(inv);

	return 0;
}

