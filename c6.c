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

void add(struct tuple t1[], struct tuple t2[], int nz1, int nz2){
	struct tuple t3[100];
	t3[0].row = t1[0].row;
	t3[0].col = t1[0].col;


	int i=1, j=1, k=1;
	if(t1[0].row == t2[0].row && t1[0].col == t2[0].col){        //if rows and coloumns are equal
		while(i <t1[0].val && j < t2[0].val){
			if(t1[i].row == t2[j].row && t1[i].col == t2[j].col){
				t3[k].row = t1[i].row;
				t3[k].col = t1[i].col;
				t3[k].val = t1[i].val + t2[j].val;
				i++;
				j++;
				k++;
			}

			else if(t1[i].row < t2[j].row || (t1[i].row == t2[j].row && t1[i].col < t2[j].col)){
				t3[k].row = t1[i].row;
				t3[k].col = t1[i].col;
				t3[k].val = t1[i].val;
				i++;
				k++;
			}

			//else if(t1[i].row >= t2[j].row || (t1[i].row == t2[j].row && t1[i].col >= t2[j].col)){
			else{
				t3[k].row = t2[j].row;
				t3[k].col = t2[j].col;
				t3[k].val = t2[j].val;
				j++;
				k++;
			}
		}
	}
	
	while(i < nz1){
		t3[k].row = t1[i].row;
		t3[k].col = t1[i].col;
		t3[k].val = t1[i].val;
		i++;
		k++;
	}

	while(j < nz2){
		t3[k].row = t1[j].row;
		t3[k].col = t1[j].col;
		t3[k].val = t1[j].val;
		j++;
		k++;
	}

	t3[0].val = k;
	printf("sum of t1 and t2\n");
	display(t3, k);
}

void transpose(struct tuple t[], int m, int n, int nz){
	struct tuple trans[100];
	trans[0].row = n;
	trans[0].col = m;
	trans[0].val = t[0].val;

	int k=1;
	for(int i=0; i<n; i++){
		for(int j=1; j<nz; j++){
			if(t[j].col == i){
				trans[k].row = t[j].col;
				trans[k].col = t[j].row;
				trans[k].val = t[j].val;
				k++;
			}
		}
	}
	printf("transpose tuple: \n");
	display(trans, k);
}

void toTuple(int mat[6][5], int m, int n,struct tuple t[], int *nz){
	t[0].row = m;
	t[0].col = n;
	
	*nz = 1;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(mat[i][j] != 0){
				t[*nz].row = i;
				t[*nz].col = j;
				t[*nz].val = mat[i][j];
				(*nz)++;
			}
		}
	}
	t[0].val = *nz;
}

int main(){
	int mat1[6][5] = {{1, 0, 5, 0, 0},
					   {0, 3, 0, 1, 0},
					   {0, 0, 7, 0, 0},
					   {0, 0, 4, 0, 0},
					   {0, 7, 0, 0, 0},
					   {0, 0, 0, 0, 9}};

	int mat2[6][5] = {{2, 0, 6, 0, 0},
					  {0, 1, 0, 2, 0},
					  {0, 0, 0, 0, 0},
					  {3, 0, 5, 0, 6},
					  {0, 0, 3, 0, 0},
					  {0, 0, 0, 1, 7},};

	int m=6, n=5, nz1 = 0;
	int * nz1ptr = &nz1;
	struct tuple t1[100];

	int a=6, b=5, nz2 = 0;
	int * nz2ptr = &nz2;
	struct tuple t2[100];
	
	toTuple(mat1, m, n, t1, nz1ptr);
	display(t1, nz1);
	transpose(t1, m, n, nz1);

	toTuple(mat2, a, b, t2, nz2ptr);
	display(t2, nz2);
	transpose(t1, m, n, nz1);

	add(t1, t2, nz1, nz2);
}