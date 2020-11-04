#include <stdio.h>
#include <stdlib.h>

#define ROWS 1024
#define COLS 2

int main() {
	int n = 11;
	int arcos[ROWS][COLS] = {
		{ 1,	0 },
		{ 3,	0 },
		{ 9,	0 },
		{ 0,	7 },
		{ 7,	4 },
		{ 8,	7 },
		{ 10,	7 },
		{ 2,	10 },
		{ 8,	5 },
		{ 5,	6 },
	};
	arcos[n-1][0] = arcos[n-1][1] = -2;
	prufer_ruffini(n, arcos);
	return 0;
}

int prufer_ruffini(int n, int arcos[ROWS][COLS]) {
	int i, j, min, prufer[n-2];
	int grados[n+1];
	int k;
	for(k=0;k<n-2;k++){
		for(i=0;i<n+1;i++){
			grados[i] = 0;
		}
		printf("arco\tnodo\tnodo\n");
		for(i=0;i<n-1;i++){
			printf( \
				"%d\t" \
				"%d\t%d\n", \
				i, \
				arcos[i][0], \
				arcos[i][1] \
			);
		}
		printf("--\n");
		for(i=0;i<n-1;i++){
			for(j=0;j<n;j++){
				if(arcos[i][0] == j || arcos[i][1] == j){
					grados[j]++;
				}
			}
		}
		printf("nodo\tgrado\n");
		for(i=0;i<n+1;i++){
			printf( \
				"%d\t%d\n", \
				i, \
				grados[i] \
			);
		}
		printf("^\nEl ultimo no es un nodo. Es un basurero.\n");
		printf("--\n");
		min = n-1;
		for(i=0;i<n-1;i++){
			if(grados[i] == 1 && i < min){
				min = i;
			}
		}
		printf( \
			"eliminar nodo %d\n", \
			min \
		);
		printf("--\n");
		grados[min] = 0;
		for(i=0;i<n-1;i++){
			if(arcos[i][0] == min || arcos[i][1] == min){
				if(arcos[i][0] == min){
					prufer[k] = arcos[i][1];
				} else {
					prufer[k] = arcos[i][0];
				}
				arcos[i][0] = arcos[i][1] = n;
			}
		}
		printf( \
			"prufer=%d\n", \
			prufer[k] \
		);
		printf("--\n");
	}
	printf("secuencia de prufer:\n");
	for(i=0;i<n-2;i++){
		printf("%d ", prufer[i]);
	}
	printf("\n--\n");
	int ruffini = prufer[0] * 11;
	for(i=1;i<n-2;i++){
		ruffini *= n;
		ruffini += prufer[i];
		printf("rufi %d\n",ruffini);
	}
	printf( \
		"residuo de ruffini:\n%d\n", \
		ruffini \
	);
	return 0;
}
