#include <iostream>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

class Time {
public:
	int month;
	int dd;
	int hh;
	int mm;
	string flag;
	Time(int mth, int d, int h, int m, string f):month(mth),dd(d),hh(h),mm(m),flag(f) {
	}

	bool operator < (const Time &t2) const {
		if(dd != t2.dd) return dd < t2.dd;
		if(hh != t2.hh) return hh < t2.hh;
		return mm < t2.mm;
	}

	void tick() {
		mm += 1;
		if(mm == 60) {
			mm = 0;
			++hh;
		}

		if(hh == 24) {
			hh = 0;
			++dd;
		}

	}

};

class Records {
public:
	set<Time> lines;
};


int main() {
	int tolls[24] = {0};
	int N;
	int month;
	map<string, Records> cus;
	for(int n = 0; n < 24; ++n) {
		int rate;
		cin >> rate;
		tolls[n] = rate;
	}
	cin >> N;
	while(N--) {
		string name, flag;
		int dd, hh, mm;
		cin >> name;
		scanf("%d:%d:%d:%d", &month, &dd, &hh, &mm);
		cin >> flag;
		cus[name].lines.insert(Time(month, dd, hh, mm, flag));
	}
	
	for(auto iterator = cus.begin(); iterator != cus.end(); ++iterator) {
		bool exist = false;
		string name = (*iterator).first;
		auto pre_it = cus[name].lines.begin();
		//printf("%s", name.c_str());
		//printf(" %02d\n", month);
		double total = 0;
		for(auto it = cus[name].lines.begin(); it != cus[name].lines.end(); ++it) {
			if((*it).flag == "off-line" && (*pre_it).flag== "on-line") {
				if(exist == false) {
					exist = true;
					printf("%s", name.c_str());
					printf(" %02d\n", month);
				}

				double sum = 0;
				int count = 0;
				Time t1 = *pre_it;
				Time t2 = *it;
				while(t1 < t2) {
					sum += tolls[t1.hh];
					++count;
					t1.tick();
				}
				sum /= 100;
				total += sum;
				printf("%02d:%02d:%02d ", (*pre_it).dd, (*pre_it).hh, (*pre_it).mm);
				printf("%02d:%02d:%02d", (*it).dd, (*it).hh, (*it).mm);

				printf(" %d $%0.2lf\n", count, sum);
			}
			pre_it = it;
		}
			if(exist) printf("Total amount: $%.2lf\n", total);
	}

/*
	cout << cus.size() << endl;	
	for(auto iterator = cus.begin(); iterator != cus.end(); ++iterator) {
		string name = (*iterator).first;
		cout << name << endl;
		for(auto it = cus[name].lines.begin(); it != cus[name].lines.end(); ++it) {
			cout << (*it).month << ":" << (*it).dd << ":" << (*it).hh << ":" << (*it).mm << " " << (*it).flag  << endl;
		}
	}
*/
	return 0;
}
