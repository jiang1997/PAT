#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int stack[16] = {0};
	int sp = 0;
	int a, b;
	int N = 343500000;
	int signal = 0;
	scanf("%d %d", &a, &b);
	N = a + b;
	
	signal = N >= 0? 1: -1;
	N = N * signal;


	do {
		stack[sp++] = N % 1000;
		N /= 1000;
	} while(N > 0);

	if(signal == -1) {
		printf("-");
	}

	printf("%d", stack[--sp]);
	for(--sp ;sp >= 0 ;--sp) {
		printf(",");
		printf("%03d", stack[sp]);
		
	}


	return 0;
}
