#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b ;i++)

int main(){
	freopen("output1.txt", "r", stdin);

	int n=100;
	rep(i, 1, 101*14){
		if(i%101==0){
			double a, b, c;
			cin >> a >> b >> c;
			cout << a << " " << b << " " << c << '\n';
		}
		else{
			string s; int x; cin >> s >> x;
		}
	}
}