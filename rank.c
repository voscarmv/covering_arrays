#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int coef_bin2(int, int);
int factor(int);

int main(int argc, char *argv[]) {
	int i, n, k, sum;
	sum = 0;
	for(i=0;i<argc-1;i++){
		n = atoi(argv[i+1]);
		k = i+1;
		sum += coef_bin2(n,k);
	}
	printf("sum=%d\n",sum);
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

int factor(int n) {
	int result = 1;
	while(n>0){
		result *= n--;
	}
	return result;
}
