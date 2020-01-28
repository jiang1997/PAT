#include <iostream>
#include <cstdio>

using namespace std;

class Time {
public:
	int hh, mm, ss;
	string toString() {
		return "ddd";
	}
};

class record {
public:
	string name;
	Time t1;
	Time t2;
};

int main() {
	int M, tmp;
	cin >> M;
	record stu[M];
	for(int m = 0; m < M; ++m) {
		int hh, mm, ss;
		cin >> stu[m].name;

		scanf("%d:%d:%d", &hh, &mm, &ss);
		stu[m].t1.hh = hh;
		stu[m].t1.mm = mm;
		stu[m].t1.ss = ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		stu[m].t2.hh = hh;
		stu[m].t2.mm = mm;
		stu[m].t2.ss = ss;
		
	}

	tmp = 0;
	for(int m = 0; m < M; ++m) {
		if(stu[tmp].t1.hh > stu[m].t1.hh) {
			tmp = m;
		} else if(stu[tmp].t1.hh == stu[m].t1.hh) {
			if(stu[tmp].t1.mm > stu[m].t1.mm) {
				tmp = m;
			} else if(stu[tmp].t1.mm == stu[m].t1.mm) {
				if(stu[tmp].t1.ss > stu[m].t1.ss) {
					tmp = m;
				}
			}
		}
	}
	cout << stu[tmp].name << " ";
	tmp = 0;
	for(int m = 0; m < M; ++m) {
		if(stu[tmp].t2.hh < stu[m].t2.hh) {
			tmp = m;
		} else if(stu[tmp].t2.hh == stu[m].t2.hh) {
			if(stu[tmp].t2.mm < stu[m].t2.mm) {
				tmp = m;
			} else if(stu[tmp].t2.mm == stu[m].t2.mm) {
				if(stu[tmp].t2.ss < stu[m].t2.ss) {
					tmp = m;
				}
			}
		}
	}
	cout << stu[tmp].name;
	return 0;
}

