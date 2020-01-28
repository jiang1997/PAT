#include <iostream>

using namespace std;

int main() {
	int N, sum = 0, pre = 0, cur = 0;
	cin >> N;
	sum += N * 5;
	while(N--) {
		int tmp;
		cin >> cur;
		tmp = cur - pre;
		pre = cur;
		if(tmp > 0) {
			sum += tmp * 6;
		} else {
			sum += tmp * -4;
		}

	}
	cout << sum;
	return 0;
}
