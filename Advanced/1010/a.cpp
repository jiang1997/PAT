#include <iostream>
#include <algorithm>

using namespace std;

long long value(long num, int radix) {
	long long sum = 0;
	int coefficient = 1;
	while(num != 0) {
		sum += num % 10 * coefficient;
		num /= 10;
		coefficient *= radix;
	}
	return sum;
}

int max_digit(long long num) {
	int ret = 0;
	while(num != 0) {
		ret = max((int)(num % 10), ret);
		num /= 10;
	}
	return ret;
}

int main() {
	long long n1, n2, tmp;
	long long num1 = 0, num2 = 0;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if(tag == 2) {
		tmp = n1;
		n1 = n2;
		n2 = n1;
	}
	n1 = value(n1, radix);
/*
	if(n2 < 10) {
		if(n1 == n2) {
			cout << n2 + 1 << endl;
		} else {
			cout << "Impossible" << endl;
		}
		return 0;
	}
*/

	tmp = max_digit(n2) + 1;

	for(; tmp <= 36; ++tmp) {
		if(value(n2, tmp) == n1) {
			cout << tmp << endl;
			return 0;
		}
	}
	

	cout << "Impossible" << endl;
	return 0;
}
