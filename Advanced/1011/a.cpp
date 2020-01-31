#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	double profit = 1;
	for(int n = 0; n < 3; ++n) {
		double num1, num2, num3;
		char result = 'W';
		cin >> num1 >> num2 >> num3;
		if(num2 > num1) {
			result = 'T';
			num1 = num2;
		}
		if(num3 > num1) {
			result = 'L';
			num1 = num3;
		}
		profit *= num1;
		
		cout << result << " ";


	}
	//cout << (profit * 0.65 - 1) * 2;
	printf("%0.2lf", (profit * 0.65 - 1) * 2);
	return 0;
}
