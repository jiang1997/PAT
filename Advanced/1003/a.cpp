#include <iostream>

using namespace std;

int find_the_mini();
void update_the_path(int mini);

class path {
public:
	int Distance;
	int NumOfTeams;
	int NumOfPaths;
	bool flag;
	path() {
		Distance = 0;
		NumOfTeams = 0;
		NumOfPaths = 0;
		bool flag = false;
	}
};

path *ArrPaths;
int map[500][500] = {0};
int Teams[500] = {0};
int N, M, C1, C2;

int main() {
	cin >> N >> M >> C1 >> C2;
	ArrPaths = new path[N];
	for(int n = 0; n < N; ++n) {
		cin >> Teams[n];
		ArrPaths[n].NumOfTeams = Teams[n];
	}
	if(C1 == C2) {
        cout << 1 << " " << Teams[C1];
        return 0;
    }
	for(int m = M; m--; ) {
		int c1, c2, l;
		cin >> c1 >> c2 >> l;
		map[c1][c2] = l;
		map[c2][c1] = l;
	}

	for(int n = 0; n < N; ++n) {
		if(map[C1][n] != 0) {
			ArrPaths[n].Distance = map[C1][n];
			ArrPaths[n].NumOfPaths = 1;
			ArrPaths[n].NumOfTeams += Teams[C1];
		}
	}
	ArrPaths[C1].flag = true;
	// find the minimal
	// update the ArrPaths
	for(int n = N; n--; ) {
		int mini = find_the_mini();
		update_the_path(mini);	
	}
/*
	for(int n = 0; n < N; ++n) {
		cout << n << endl;
		cout << "Distance:" << ArrPaths[n].Distance << endl;
		cout << "NumOfPaths:" << ArrPaths[n].NumOfPaths << endl;
		cout << "NumOfTeams:" << ArrPaths[n].NumOfTeams << endl;
	}
*/
	cout << ArrPaths[C2].NumOfPaths << " " << ArrPaths[C2].NumOfTeams;

	return 0;
}

int find_the_mini() {
	int mini = 0;
	for(int n = 0; n < N; ++n) {
		if(ArrPaths[n].Distance != 0 && ArrPaths[n].flag == false){
			if(ArrPaths[mini].Distance == 0 || ArrPaths[mini].flag == true){
				mini = n;
			}
			if(ArrPaths[n].Distance < ArrPaths[mini].Distance) {
				mini = n;
			}
		}
	}
	return mini;
}

void update_the_path(int mini) {
	ArrPaths[mini].flag = true;
	//update
	for(int n = 0; n < N; ++n) {
		if(map[mini][n] != 0 && ArrPaths[n].flag == false) {
			if(ArrPaths[n].Distance == 0) {
				ArrPaths[n].Distance = map[mini][n] + ArrPaths[mini].Distance;
				ArrPaths[n].NumOfTeams += ArrPaths[mini].NumOfTeams;
				ArrPaths[n].NumOfPaths = ArrPaths[mini].NumOfPaths;
			} else if(map[mini][n] + ArrPaths[mini].Distance < ArrPaths[n].Distance) {
				ArrPaths[n].Distance = ArrPaths[mini].Distance + map[mini][n];
				ArrPaths[n].NumOfTeams += ArrPaths[mini].NumOfTeams;
				ArrPaths[n].NumOfPaths = ArrPaths[mini].NumOfPaths;
			} else if(map[mini][n] + ArrPaths[mini].Distance == ArrPaths[n].Distance) {
				ArrPaths[n].NumOfPaths += ArrPaths[mini].NumOfPaths;
                if(ArrPaths[mini].NumOfTeams + Teams[n] > ArrPaths[n].NumOfTeams)
				    ArrPaths[n].NumOfTeams = ArrPaths[mini].NumOfTeams + Teams[n];
				
			}
		}
	}
}

