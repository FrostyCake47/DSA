#include<stdio.h>

struct tuple{
	int row;
	int col;
	int val;
};


void display(struct tuple t[], int nz){
	printf("Row\tCol\tval\n");
	for(int i=0; i<nz; i++){
		printf("%d\t%d\t%d\n", t[i].row, t[i].col, t[i].val);
	}
}

void toTuple(int mat[6][5], int m, int n,struct tuple[] *t, int* nz){
	*nz = 1;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(mat[i][j] != 0){
				(t+*(nz))->row = i;
				(t+*(nz))->col = j;
				(t+*(nz))->val = mat[i][j];
				*(nz)++;
			}		
		}
	}

	t->row = m;
	t->col = n;
	t->val = *nz;
}

int main(){
	int mat1[6][5] = {{1, 0, 5, 0, 0},
					   {0, 3, 0, 1, 0},
					   {0, 0, 0, 0, 0},
					   {0, 0, 4, 0, 0},
					   {0, 7, 0, 0, 0},
					   {0, 0, 0, 0, 9},};

	int m=6, n=5, nz1 = 0;
	struct tuple t1[100];
	struct tuple *ptr1 = t1;
	
	toTuple(mat1, m, n, ptr1, &nz1);
	display(t1, nz1);




}