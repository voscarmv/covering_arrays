#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nroot(int, int);
int factor(int);

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	int x = atoi(argv[2]);
	nroot(n,x);
	return 0;
}

int nroot(int n, int x) {
	int mat[n][n];
	int delta[n];
	int i,j,c;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			mat[i][j]=0;
		}
	}
	for(i=0;i<n;i++){
		mat[i][i]=factor(i+1);
	}
	for(i=1;i<n;i++){
		mat[i][0]=1;
	}
	for(i=2;i<n;i++){
		for(j=1;j<i+1;j++){
			mat[i][j] = (mat[i-1][j]+mat[i-1][j-1])*(j+1);
		}
	}
	for(i=1;i<n;i+=2){
		for(j=0;j<n-i;j++){
			mat[i+j][j]*=-1;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	int x2 = x;
	c = 0;
	while(x2>0){
		printf("mat[%d][%d]=%d\n",n-1,n-1,mat[n-1][n-1]);
		for(i=n-1;i>0;i--){
			mat[n-1][i-1]+=mat[n-1][i];
			printf("mat[%d][%d]=%d\n",n-1,i-1,mat[n-1][i-1]);
		}
	printf("--\n");
		x2-=mat[n-1][0];
		c++;
	}
	int power = pow(c-1,n);
	printf("%d a la %d es %d\n",c-1,n,power);
	printf("La raiz %d de %d es %d y sobran %d\n",n,x,c-1,x-power);
	printf("El residuo debe ser %d + %d = %d\n",x2,mat[n-1][0],x2+mat[n-1][0]);
	return 0;
}

int factor(int n) {
        int result = 1;
        while(n>0){
                result *= n--;
        }
        return result;
}
