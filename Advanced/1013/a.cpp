#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, K;
int map[1005][1005] = {{0}};
int block_city = 0;

int traverse(int *record) {
	//memset(record, 0, N * sizeof(int));
	int count = 0;
	deque<int> que;
	for(int n = 1; n <= N; ++n) {
		if(n == block_city) continue;

		if(record[n] == 0) {
			record[n] = ++count;
			que.push_back(n);

			while(!que.empty()) {
				int c1 = que.front();
				que.pop_front();

				for(int n2 = 1; n2 <= N; ++n2) {
					if(n2 == block_city || record[n2] != 0) continue;
					if(map[c1][n2] != 0) {
						record[n2] = record[c1];
						que.push_back(n2);
					}
				}
			}
		}

	/*
		if(n == block_city) continue;

		if(record[n] == 0) {
			record[n] = ++count;
		}
		for(int n2 = 1; n2 <= N; ++n2) {
			if(n2 == block_city) continue;
			if(map[n][n2] != 0) {
				record[n2] = record[n];
			}
		}
	*/
	}
	return count;
}

int main() {
	cin >> N >> M >> K;
	while(M--) {
		int c1, c2;
		cin >> c1 >> c2;
		map[c1][c2] = 1;
		map[c2][c1] = 1;
	}

	while(K--) {
		cin >> block_city;
		int record[1005] = {0};
		int tmp = traverse(record) - 1;
		tmp = max(tmp, 0);
		cout << tmp << endl;
	}

	return 0;
}
