/**
 * Program illustrating sieve of Eratosthenes.
 *
 **/

#include <stdio.h>

#define N 100

int main(int argc, char *argv[]) {
	int nums[N];

	for (int i = 2; i < N; ++i) {
		nums[i] = i;
	}

	for (int i = 2; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			if (i != j && nums[j] != 0 && (nums[j] % i == 0)) {
				nums[j] = 0;
			}
		}
	}

	for (int k = 2; k < N; ++k) {
	    if (nums[k] != 0) {
	    	printf("%d\n", nums[k]);
	    }
	}

}
