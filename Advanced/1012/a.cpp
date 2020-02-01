#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class STU {
public:
	int ID;
	int grades[4];
	STU(int id, int c, int m, int e, int a):ID(id),grades{a,c,m,e} {  }
};

vector<STU> stus;

bool sort_C(int idx1, int idx2) {
	return stus[idx1].grades[1] > stus[idx2].grades[1];
}
bool sort_M(int idx1, int idx2) {
	return stus[idx1].grades[2] > stus[idx2].grades[2];
}
bool sort_E(int idx1, int idx2) {
	return stus[idx1].grades[3] > stus[idx2].grades[3];
}
bool sort_A(int idx1, int idx2) {
	return stus[idx1].grades[0] > stus[idx2].grades[0];
}

int getRank(int *arry, int N, int ID, int t) {
    int pre = -1;
    bool flag = false;
	int count = 0;
    for(int n = 0; n < N; ++n) {
        int idx = arry[n];
		if(ID == stus[idx].ID) {
			int n1 = n;
			while(stus[arry[n1]].grades[t] == stus[idx].grades[t] && n1 >= 0) {
					++count;
					--n1;
					
			}
			count = n + 1 - count + 1;
			flag = true;
			break;
		}
    }
	if(flag) {
		return count;
	}
	return -1;
}

int main() {
	int N, M;
	int *C_idx, *M_idx, *E_idx,  *A_idx;
	cin >> N >> M;

	C_idx = new int[N];
	M_idx = new int[N];
	E_idx = new int[N];
	A_idx = new int[N];
	for(int n = 0; n < N; ++n) {
		int id, c, m, e, a;
		cin >> id >> c >> m >> e;
		a = ((c + m + e) / 3.0);
		stus.push_back(STU(id, c, m, e, a));
		C_idx[n] = M_idx[n] = E_idx[n] = A_idx[n] = n;
	}
	sort(C_idx, &(C_idx[N]), sort_C);
	sort(M_idx, &(M_idx[N]), sort_M);
	sort(E_idx, &(E_idx[N]), sort_E);
	sort(A_idx, &(A_idx[N]), sort_A);

	while(M--) {
		int id;
		bool flag = false;
		cin >> id;


		int rank = 20000, type = 0;
		int *major_idx_arry[] = {A_idx, C_idx, M_idx, E_idx};

		for(int t = 0; t < 4; ++t) {
			int tmp = getRank(major_idx_arry[t], N, id, t);
			if(tmp < 0) {
				rank = tmp;
				break;
			}
			if(tmp < rank) {
				rank = tmp;
				type = t;
			}
		}
		if(rank < 0) {
			cout << "N/A" << endl;
		} else {
			char tab[] = {'A', 'C', 'M', 'E'};
			cout << rank << " " << tab[type] << endl;
		}
	}

	return 0;
}
