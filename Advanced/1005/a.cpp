#include <iostream>

using namespace std;

int main() {
	int sum = 0, stack[101], top = 0;
	bool flag = false;
	string str;
	cin >> str;
	for(int n = 0; n < str.length(); ++n) {
		sum += str[n] - '0';
	}
    if(sum == 0) {
        cout << "zero";
        return 0;
    }

	while(sum != 0) {
		stack[top++] = sum % 10;
		sum /= 10;
	}

	--top;
	while(top >= 0) {
		if(flag == true) cout << " ";
		switch(stack[top]) {
			case 0:	cout << "zero";
			break;
			case 1:	cout << "one";
			break;
			case 2:	cout << "two";
			break;
			case 3:	cout << "three";
			break;
			case 4:	cout << "four";
			break;
			case 5:	cout << "five";
			break;
			case 6:	cout << "six";
			break;
			case 7:	cout << "seven";
			break;
			case 8:	cout << "eight";
			break;
			case 9:	cout << "nine";
			break;
		}
		flag = true;
		--top;
	}

	
	return 0;
}
