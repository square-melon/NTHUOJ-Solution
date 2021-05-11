#include <iostream>
#include <string>
#include "13178_function.cpp"
using namespace std;
int main() {
	/* I/O optimization */
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		List *row = new List[n + 1];
		for(int i=1;i<=n;i++) {
			int sz;
			cin >> sz;
			if(sz > 0) {
				string s;
				cin >> s;
				row[i].init(s);
			}
		}
		
		int q;
		cin >> q;
		while(q--) {
			int type, a, b;
			cin >> type >> a;
			if(type != 4)   cin >> b;
			if(type == 1) {
				row[b].merge(row[a], row[b]);
				row[a].clear();
			}
			else if(type == 2) {
				row[b].merge(row[b], row[a]);
				row[a].clear();
			}
			else if(type == 3) {
				row[a].swap(row[b]);
			}
			else {
				row[a].reverse();
			}
		}
		for(int i=1;i<=n;i++)
			row[i].output();
			
		delete[] row;
	}
	return 0;
}
