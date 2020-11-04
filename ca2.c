#include <stdio.h>
#include <stdlib.h>

int coef_bin2(int, int);

int main(int argc, char *argv[]) {
	int i, j, m, ceroextremo, cuentaunos, yaconteunos, \
unosconsecutivos, donde, cuantos, llenaceros, coef, r, c;
	int N = atoi(argv[1]);
	int k = N-1;
	int t = (N/2)+(N%2);
	int B[k];
	coef=coef_bin2(k, t);
	int CA[k+1][coef];
	for(i=0;i<t;i++){
		B[i]=1;
	}
	for(i=t;i<k;i++){
		B[i]=0;
	}
	int k1 = k;
	int k2 = 2*k;
	int k3 = 3*k;
	i=0;
	j=0;
	ceroextremo=0;
	cuentaunos=0;
	yaconteunos=0;
	unosconsecutivos=0;
	donde=0;
	cuantos=0;
	llenaceros=0;
	c = 0;
	r = k;
	while(1){
		if(i<k1){
			CA[r--][c]=B[i];
		}
		if(i>=k && i<k2){
			j=i-k;
			if(B[k-j-1]==0 && j==0){
				ceroextremo=1;
				i=k2;
				continue;
			}
			if(B[k-j-1]==1 && j==0){
				cuentaunos=1;
				cuantos++;
				i++;
				continue;
			}
			if(cuentaunos == 1 && B[k-j-1] == 1){
				cuantos++;
				i++;
				continue;
			}
			if(cuentaunos == 1 && B[k-j-1] == 0){
				if(j==k-1){
					break;
				}
				yaconteunos = 1;
				cuentaunos = 0;
				i++;
				continue;
			}
			if(yaconteunos == 1 && B[k-j-1] == 0 && j < k-1){
				i++;
				continue;
			}
			if(yaconteunos == 1 && B[k-j-1] == 1 ){
				unosconsecutivos=1;
				donde=k-j;
				cuantos++;
				i=k2;
				continue;
			}
			if(yaconteunos == 1 && B[k-j-1] == 0 && j >= k-1){
				break;
			}
		}
		if(i>=k2 && i<k3){
			j=i-k2;
			if(unosconsecutivos == 1 && j == donde-1){
				B[j]=0;
				i++;
				continue;
			}
			if(unosconsecutivos == 1 && j>=donde && \
			cuantos-- > 0 && ceroextremo == 0){
				B[j]=1;
				i++;
				continue;
			}
			if(unosconsecutivos == 1 && cuantos < 0 && \
			ceroextremo == 0){
				unosconsecutivos = 0;
				llenaceros = 1;
				B[j]=0;
				i++;
				continue;
			}
			if(llenaceros == 1 && ceroextremo == 0){
				B[j]=0;
				i++;
				continue;
			}
			if(ceroextremo == 1 && B[k-j-1] == 1){
				ceroextremo = 0;
				B[k-j-1]=0;
				B[k-j]=1;
				i++;
				continue;
			}
		}
		if(i>=k3){
			i=0;
			j=0;
			ceroextremo=0;
			cuentaunos=0;
			yaconteunos=0;
			unosconsecutivos=0;
			donde=0;
			cuantos=0;
			llenaceros=0;
			r=k;
			c++;
			continue;
		}
		i++;
	}
	for(i=0;i<coef;i++){
		CA[0][i]=0;
	}
	for(i=0;i<k+1;i++){
		for(j=0;j<coef;j++){
			printf("%d",CA[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int coef_bin2(int n, int k) {
	int c = 1;
	int limit = k-1;
	int stop = n-limit;
	int result = n;
	while(n>stop){
		result *= --n;
		result /= c++;
	}
	return result/c;
}
