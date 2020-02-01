#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Customer {
public:
	int rest;
	int finish;
	Customer(int r):rest(r) {
		finish = 0;
	}
};

bool hasCus(vector<Customer> &cus) {
    for(int n = cus.size() - 1; n >= 0; --n) {
        if(cus[n].rest != 0) return true;
    }
    return false;
}

int main() {
	int N, M, K, Q;
	int count = 0;
	int last_time = 0;
	cin >> N >> M >> K >> Q;
	deque<Customer*> cus_ques[N];
	vector<Customer> cus;
	for(int k = 0; k < K; ++k) {
		int tmp;
		cin >> tmp;
		cus.push_back(Customer(tmp));
	}

	
	for(int m = 0; m < M; ++m) {
		for(int n = 0; n < N && count < K; ++n) {
			cus_ques[n].push_back(&(cus[count++]));
		}
	}

	while(hasCus(cus)) {
		// find the min
		// subtract the min for each line
		int min = 0;
		for(int n = 0; n < N; ++n) { //check all the que's front
			if(cus_ques[n].empty()) continue;
			if(cus_ques[min].empty()) {
				min = n;
				continue;
			}
			if(cus_ques[n].front()->rest < cus_ques[min].front()->rest) {
				min = n;
			}
		}

		int tmp = cus_ques[min].front()->rest;
		last_time += tmp;

		for(int n = 0; n < N; ++n) { //subtract que's front
			if(cus_ques[n].empty()) continue;
			cus_ques[n].front()->rest -= tmp;
		}

		cus_ques[min].front()->finish = last_time;
		cus_ques[min].pop_front();

		if(count < K) {
			cus_ques[min].push_back(&(cus[count++]));
		}
	}
	
	while(Q--) {
		int n;
		cin >> n;
		--n;
		int hh, mm;
		hh = cus[n].finish / 60;
		mm = cus[n].finish % 60;
		if(cus[n].finish > 540) {
			printf("Sorry\n");
		} else {
			printf("%02d:%02d\n", hh+8, mm);
		}
	}


	return 0;
}
