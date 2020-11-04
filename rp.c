#include <stdio.h>
#include <stdlib.h>

int main() {
	unruffini_unprufer(11, 196083774);
	return 0;
}

int unruffini_unprufer(int n, int ruffini){
	int i, j, k, min, mindex, prufer[n-2], arcos[n-1][2], aux[n];
	printf("residuo de ruffini:\n%d\n--\n",ruffini);
	for(i=n-3;i>0;i--){
		prufer[i] = ruffini%n;
		ruffini -= ruffini%n;
		ruffini /= n;
		printf("rufi %d\n",ruffini);
	}
	prufer[0] = ruffini;
	printf("secuencia de prufer:\n");
	for(i=0;i<n-2;i++){
		printf( \
			"%d ", \
			prufer[i] \
		);
	}
	printf("\n--\n");
	k = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n-2;j++){
			if(prufer[j] == i){
				break;
			}
		}
		if(j == n-2){
			aux[k++] = i;
		}
	}
	for(i=k;i<n;i++){
		aux[i] = n;
	}
	printf( \
		"lista auxiliar:\n" \
	);
	for(i=0;i<n;i++){
		printf("%d ",aux[i]);
	}
	printf("\n--\n");
	for(j=0;j<n-2;j++){
		min=n;
		mindex=0;
		for(i=0;i<n;i++){
			if(aux[i]<min){
				min=aux[i];
				mindex=i;
			}
		}
		arcos[j][0] = min;
		arcos[j][1] = prufer[j];
		for(i=j+1;i<n-2;i++){
			if(prufer[i] == prufer[j]){
				aux[mindex]=n;
				break;
			}
		}
		if(i == n-2){
			aux[mindex]=prufer[j];
		}
	}
	int c = 0;
	for(i=0;i<n;i++){
		if(aux[i]<n){
			arcos[n-2][c++]=aux[i];
		}
	}
	printf("--\n");
	printf("arco\tnodo\tnodo\n");
	for(i=0;i<n-1;i++){
		printf( \
			"%d\t%d\t%d\n", \
			i, \
			arcos[i][0], \
			arcos[i][1] \
		);
	}
	return 0;
}
