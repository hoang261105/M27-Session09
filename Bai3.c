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

int DFSFunction(int node, int parent, int visited[], int n, int matrix[n][n]){
	visited[node] = 1; // Danh dau dinh da tham
	
	for(int i=0; i<n; i++){
		if(matrix[node][i]){ // Neu co canh
			if(!visited[i]){ // Neu dinh chua duoc tham
				if (DFSFunction(i, node, visited, n, matrix)) {
                    return 1; // Phat hien chu ki
                }
			}else if(i != parent){ // Neu dinh da tham nhm k phai cua cha
				return 1;
			}
		}
	}
	
	return 0;
}

void detectCycle(int n, int matrix[n][n]) {
	int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0; 
    }
	for (int i = 0; i < n; i++) {
        if (!visited[i]) { 
            if (DFSFunction(i, -1, visited, n, matrix)) {
                printf("Do thi co chu ki.\n");
                return;
            }
        }
    }

    printf("Do thi khong co chu ki.\n");
}

int main(){
	int n, edge;
	
	printf("Nhap so luong dinh va canh: ");
	scanf("%d %d", &n, &edge);
	
	int matrix[n][n];
	createMatrix(n, edge, matrix);
	
	printMatrix(n, matrix);
	
	detectCycle(n, matrix);
	return 0;
}
