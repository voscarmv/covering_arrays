#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, m, ceroextremo, cuentaunos, yaconteunos, unosconsecutivos, donde, cuantos, llenaceros;
	int k = 5;
	int t = 3;
	int B[k];
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
	B[0] = 0;
	B[1] = 1;
	B[2] = 1;
	B[3] = 1;
	B[4] = 1;
	while(1){
		if(i<k){
			printf("%d ", B[i]);
		}
		if(i>=k && i<k2){
			printf("\nPreparar edicion");
			j=i-k;
			if(B[k-j-1]==0 && j==0){
				printf("\nFlag: ceroextremo=1");
				printf("\nj=%d", j);
				ceroextremo=1;
				printf("\nHaz i=k2");
				i=k2;
				continue;
			}
			if(B[k-j-1]==1 && j==0){
				printf("\nFlag: cuentaunos=1 y cuantos++");
				printf("\nj=%d", j);
				cuentaunos=1;
				cuantos++;
				i++;
				continue;
			}
			if(cuentaunos == 1 && B[k-j-1] == 1){
				printf("\ncuantos++;");
				printf("\nj=%d", j);
				cuantos++;
				i++;
				continue;
			}
			if(cuentaunos == 1 && B[k-j-1] == 0){
				if(j==k-1){
					printf("\nDead.\n");
					break;
				}
				printf("\nFlag: yaconteunos=1");
				printf("\nj=%d", j);
				yaconteunos = 1;
				cuentaunos = 0;
				i++;
				continue;
			}
			if(yaconteunos == 1 && B[k-j-1] == 0 && j < k-1){
				printf("\nUbicando los 1s consecutivos...");
				printf("\nj=%d", j);
				i++;
				continue;
			}
			if(yaconteunos == 1 && B[k-j-1] == 1 ){
				printf("\nYa conte unos y me tope N ceros y un uno.");
				printf("\nFlag: unosconsecutivos=1, cuantos++");
				printf("\nj=%d", j);
				unosconsecutivos=1;
				donde=k-j;
				cuantos++;
				printf("\nSigue con edicion");
				printf("\ndonde=%d\ncuantos=%d",donde,cuantos);
				i=k2;
				continue;
			}
			if(yaconteunos == 1 && B[k-j-1] == 0 && j >= k-1){
				printf("\nDead x_x\n");
				break;
			}
		}
		if(i>=k2 && i<k3){
			printf("\nEditar");
			j=i-k2;
			if(unosconsecutivos == 1 && j == donde-1){
				printf("\nPoniendo un 0 en B[%d],j");
				B[j]=0;
				i++;
				continue;
			}
			if(unosconsecutivos == 1 && j>=donde && cuantos-- > 0 && ceroextremo == 0){
				printf("\nPoniendo un 1 en B[%d]",j);
				printf("\nj=%d", j);
				B[j]=1;
				i++;
				continue;
			}
			if(unosconsecutivos == 1 && cuantos < 0 && ceroextremo == 0){
				printf("\nFlag: llenaceros, B[%d]=0",j);
				printf("\nj=%d", j);
				unosconsecutivos = 0;
				llenaceros = 1;
				B[j]=0;
				i++;
				continue;
			}
			if(llenaceros == 1 && ceroextremo == 0){
				printf("\nPoniendo un 0 en B[%d]",j);
				printf("\nj=%d", j);
				B[j]=0;
				i++;
				continue;
			}
			if(ceroextremo == 1 && B[k-j-1] == 1){
				printf("\nCorriendo el 1 a la derecha.");
				ceroextremo = 0;
				printf("\nj=%d", j);
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
			printf("\n");
			continue;
		}
		i++;
	}
	return 0;
}
