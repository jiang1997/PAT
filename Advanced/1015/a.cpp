#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long num) {
	int tmp = sqrt(num);
	if(num == 1) return false;
	for(int factor = 2; factor <= tmp; ++factor) {
		if(num % factor == 0) {
			return false;
		}
	}
	return true;
}

long long getValue(long long num, int radix) {
	long long ret = 0;
	int cof = 1;
	while(num != 0) {
		int tmp = num % 10 * cof;
		num /= 10;
		ret += tmp;
		cof *= radix;
	}
	return ret;
}

long long reverse(long long num) {
	long long ret = 0;
	while(num != 0) {
		ret *= 10;
		ret += num % 10;
		num /= 10;
	}
	return ret;
}

long long inRadix(long long num, int radix) {
	long long ret = 0;
	long long digit = 1;
	while(num != 0) {
		int tmp = num % radix;
		num /= radix;
		ret += tmp * digit;
		digit *= 10;
	}
	return ret;
}


int main() {
	long long N, D;
    
	while(cin >> N) {
        if(N < 0) break;
        cin >> D;
        
		int num1 = N;
		int num2;
		long long R_N = reverse(inRadix(N, D));
		num2 = getValue(R_N, D);
		//cout << N << " in radix " << D << " is " << inRadix(N, D) << " rev " << reverse(inRadix(N, D)) << " " << num2;
		if(isPrime(num1) && isPrime(num2)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
