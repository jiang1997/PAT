#include <iostream>
#include <deque>

using namespace std;

class Node {
public:
	int father;
	bool isLeft;
	Node() {
		father = 0;
		isLeft = true;
	}
};

int main() {
	Node node[105];
	deque<int> que;
	int N, M, flag = 0;
	cin >> N >> M;
	//if(N == 0) return 0;
	//ID K ID[1] ID[2] ... ID[K]
	for(int m = 0; m < M; ++m){
		int ID, K;
		cin >> ID >> K;
		for(int k = 0; k < K; ++k) {
			int ID_i;
			cin >> ID_i;
			node[ID_i].father = ID;
			node[ID].isLeft = false;
			
		}
	}
	
	que.push_back(1);
	while(!que.empty()) {
		int num = 0;
		deque<int> que2;
		while(!que.empty()) {
			int id = que.front();
			if(node[id].isLeft == true) {
				++num;
				que.pop_front();
				continue;
			}

			
			for(int n = que.back() + 1; n <= N; ++n) {
                if(node[n].father == id) {
                    que2.push_back(n);
                }
				
			}

			que.pop_front();

		}
		que.insert(que.end(), que2.begin(), que2.end());
		if(flag == 1) cout << " ";
		cout << num;
		flag = 1;
		//cout << que.size() << " size" << endl;
	}


	return 0;
}

