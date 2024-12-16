#include<stdio.h>
#include<stdlib.h>

void createMatrix(int n, int edge, int matrix[n][n]){
	// Khoi tao ma tran ke co gia tri la 0
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			matrix[i][j] = 0;
		}
	}
	
	printf("Nhap danh sach cac canh cua dinh:\n ");
	for(int i=0; i<edge; i++){	
		int u, v;
		printf("Canh %d: ", i+1);
		scanf("%d %d", &u, &v);
		
		if(u < 1 || v < 1 || u > n || v > n){
			printf("Khong hop le. Vui long nhap lai!");
			i--;
			continue;
		}
		
		// Danh dau canh trong ma tran ke
		matrix[u-1][v-1] = 1;
		matrix[v-1][u-1] = 1;
	}
}

void printMatrix(int n, int matrix[n][n]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int isSymmetry(int n, int matrix[n][n]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(matrix[i][j] != matrix[j][i]){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	int n, edge;
	
	printf("Nhap so luong dinh va canh: ");
	scanf("%d %d", &n, &edge);
	
	int matrix[n][n];
	createMatrix(n, edge, matrix);
	
	printMatrix(n, matrix);
	
	if(isSymmetry(n, matrix)){
		printf("Ma tran doi xung");
	}else{
		printf("Ma tran khong doi xung");
	}
	return 0;
}
