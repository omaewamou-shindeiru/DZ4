#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define N 100

void bs(int *Arr, int *c, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = Arr[(left + right) / 2];
			do
		{
			while (Arr[left] < middle) left++;
			while (Arr[right] > middle) right--;
			if (left <= right)
			{ int time = Arr[left];
				Arr[left] = Arr[right];
				Arr[right] = time;
				int ttime = c[left];
				c[left] = c[right];
				c[right] = ttime;
				left++;
				right--;
			}
		}
		while (left <= right);
			bs(Arr, c, first, right);
		bs(Arr, c, left, last);
	}
}


int main(void)
{
int node,rebr,cnt,i,j,a;
char a1,b1;
FILE *f;
f=fopen("graph.gv","w");
fputs("graph G {\n",f);

printf("Enter number of nodes:\n");
scanf("%d", &node);
printf("Enter number of edges:\n");
scanf("%d", &rebr);
int arr[node][node];

printf("Enter:\n\t0 - if not connected\n\t1 - if connected\n\n");
for( j=0; j<node; j++){
	a1='A';
	b1='A';
	a1=a1+j;
	for(i=0; i<node; i++){
		printf("Node %d connected to node %d: ", j+1,i+1);
		scanf("%d", &a);
		if (arr[j][i]!=1){
			if (a==1){
				arr[j][i] =arr[i][j]= 1;
				fprintf(f,"%c--%c;\n",a1,b1);
				}
			if (a==0){
				arr[j][i]=0;
				}
			}
		b1++;
		}
	}
for( j=0; j<node; j++){
	a1='A';
	b1='A';
	a1=a1+j;
	cnt=0;
	for(i=0; i<node; i++){
		if (arr[j][i]==0)
			cnt++;
			if (cnt==node) {
				fprintf(f,"%c\n",b1);
				}
			b1++;
		}
	}


printf("\n\tAdjacency matrix:\n");
for( i=0; i<node; i++){
	printf("\t");
	for( j=0; j<node; j++){
		printf("%2d ", arr[j][i]);
		}
	printf("\n");
	}
fputs("}",f);
fclose(f);

int c=0, k=0, n;

for( i=0; i<node; i++){
	for( j=0; j<node; j++){
		c=arr[i][j]+c;
		}
	if(c%2!=0){
		k++;
		}
	c=0;
	}

n=k;
int A[n], C[n];
k=0;
for( i=0; i<node; i++){
	for( j=0; j<node; j++){
		c=arr[i][j]+c;
		}
	if((c%2!=0)){
		A[k]=i+1;
		C[k]=c;
		k++;
		}
	c=0;
	}
bs(C, A, 0, k-1);
for (i = 0; i<n; i++)
        printf("Node %4d (%d) \n", A[i], C[i]);
return 0;
}
