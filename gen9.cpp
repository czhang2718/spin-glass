/*

p=4
brute force

*/


#include "bits/stdc++.h"
using namespace std;

int D=200;
int n=14;
const int N=14;
double J[N][N][N][N][N];
double L=-30;

int count_bits(int n){
	int ans=0;
	while(n){
		if(n&1) ans++;
		n>>=1;
	}
	return ans;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);

	normal_distribution<double> dist(0, sqrt(2.0/(n-1)));
	double sum=0;
	double var=0;
	vector<int> vec;
	for(int t=0; t<D; t++) {
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				for(int k=j+1; k<N; k++){
					for(int l=k+1; k<N; k++){
						for(int m=l+1; )
						J[i][j][k][l]=dist(rng);
					}
				}
			}
		}

		double cnt=0;
		double x;
		for(int m=0; m<(1<<n); m++){
			x=0;
			int bits=count_bits(m);
			if(bits>n/2) continue;
			for(int i=0; i<N; i++){
				for(int j=i+1; j<N; j++){
					for(int k=j+1; k<N; k++){
						for(int l=k+1; k<N; k++){
							x+=J[i][j][k][l]*((m&(1<<i))?1:-1)*((m&(1<<j))?1:-1)*((m&(1<<k))?1:-1)*((m&(1<<l))?1:-1);
						}
					}
				}
			}
			if(n&1 && bits==n/2+1) cnt+=x<L;
			else cnt+=2.0*(x<L);
		}
		cout << cnt << '\n';
		vec.push_back(cnt);
		sum+=cnt;
	}
	cout << "mean " << sum/D << '\n';
	for(int k:vec){
		var+=(sum/D-k)*(sum/D-k);
	}
	cout << "var " << var/D << '\n';
}