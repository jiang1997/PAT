#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main() {
	map<int, double> mymap;
	map<int, double> ret;
	int K;
	cin >> K;
	while(K--) {
		int exponent;
		double coefficent;
		cin >> exponent >> coefficent;
		mymap[exponent] = coefficent;
	}

	cin >> K;
	while(K--) {
		int exponent;
		double coefficent;
		cin >> exponent >> coefficent;
		for(map<int, double>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
			int exp;
			double cof;
			exp = it->first + exponent;
			cof = it->second * coefficent;
			map<int, double>::iterator it2 = ret.find(exp);
			if(it2 == ret.end()) {
				ret[exp] = 0;
			}
			ret[exp] += cof;
			if(ret[exp] == 0) {
				ret.erase(exp);
			}
			//cout << exp << " " << cof << endl;
		}

	}

	cout << ret.size();
	if(ret.size() == 0) return 0;
	for(map<int, double>::reverse_iterator it = ret.rbegin(); it != ret.rend(); ++it) {
		printf(" ");
		printf("%d %0.1lf", it->first, it->second);
	}


}
