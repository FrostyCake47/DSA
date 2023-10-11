#include<stdio.h>

struct poly{
	int exp;
	int coef;
};

void display(struct poly p1[], int len){
	for(int i=0; i<len; i++){
		printf("%dx^%d + ", p1[i].coef, p1[i].exp);
	}
	printf("\n");
}

void add(struct poly p1[], struct poly p2[], int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(p1[i].exp == p2[j].exp){
				p1[i].coef += p2[j].coef;
			}
		}
	}

	for(int i=0; i<n; i++){
		int isExist = 0;
		for(int j=0; j<m; j++){
			if(p2[i].exp == p1[j].exp){
				isExist = 1;
			}
		}

		if(isExist == 0){
			p1[m].exp = p2[i].exp;
			p1[m].coef = p2[i].coef;
			m++;
		}

	}
	
	printf("poly1 + poly2 = ");
	display(p1, m);

}

int main(){
	struct poly p1[10], p2[10];
	int m, n;

	printf("Enter length of poly1 and poly2: ");
	scanf("%d %d", &m, &n);

	printf("Enter poly1 coef and exp: ");
	for(int i=0; i<m; i++){
		scanf("%d %d", &p1[i].coef, &p1[i].exp);
	}

	printf("Enter poly2 coef and exp: ");
	for(int i=0; i<n; i++){
		scanf("%d %d", &p2[i].coef, &p2[i].exp);
	}

	printf("poly1 = ");
	display(p1, m);
	printf("poly2 = ");
	display(p2, n);

	add(p1, p2, m, n);

}