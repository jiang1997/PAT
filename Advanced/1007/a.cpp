#include <iostream>
#include <cstdio>

using namespace std;
int main() {
	int K, *arry;
	int sum, l, r;
	cin >> K;
	arry = new int[K + 1];
	arry[0] = 0;
	for(int k = 1; k <= K; ++k) {
		scanf("%d", &(arry[k]));
		arry[k] += arry[k - 1];
	}

	sum = arry[1];
	l = 0;
	r = 1;
	
	for(int k = 0; k < K; ++k) {
		int max_t = k + 1;
		for(int i = max_t; i <= K; ++i) {
			if(arry[i] > arry[max_t]) {
				max_t = i;
			}
		}

		if(arry[max_t] - arry[k] > sum) {
			sum = arry[max_t] - arry[k];
			l = k;
			r = max_t;
		}

	}
	if(sum < 0) {
		sum = 0;
		l = 0;
		r = K;
	}
	cout << sum << " " << arry[l + 1] - arry[l] << " " << arry[r] - arry[r - 1];
	
}
