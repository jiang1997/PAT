#include <iostream>
#include <algorithm>

using namespace std;

int digit(char c) {
    if(c >= '0' && c <= '9') return c - '0';
    return c - 'a' + 10;
}


long long value(string num, long long radix) {
	long long sum = 0;
	long long coefficient = 1;

	for(int idx = num.length() - 1; idx >= 0; --idx) {
        if(coefficient < 0) return -1; //处理溢出
		int tmp = digit(num[idx]);	

		sum += tmp * coefficient;
		coefficient *= radix;
	}
	return sum;
}

int max_digit(string num) {
	int ret = '0';
	for(int idx = num.length() - 1; idx >= 0; --idx) {
		ret = max((int)num[idx], ret);
	}

	return digit(ret);
}

int main() {

	string n1, n2;
	long long tmp;
	long long num1 = 0, num2 = 0;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if(tag == 2) {
		string tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
	num1 = value(n1, radix);
    //处理个位数

	tmp = max_digit(n2) + 1;
    long long left = tmp, right = max(tmp, num1);
    // if(left == right && value(n2, left) == num1) {
    //     cout << left << endl;
    //     return 0;
    // }
    while(left <= right) {
        long long medium = (left + right) / 2;
        long long cur = 0;

        cur = value(n2, medium);
        if(cur < 0) {
            right = medium - 1;
            continue;
        }
        if(cur > num1) {
            right = medium - 1;
        } else if(cur < num1) {
            left = medium + 1;
        } else {
            cout << medium << endl;
            return 0;
        }
        
	}


	
	cout << "Impossible" << endl;
	return 0;
}
