/*

p=4
brute force

*/


#include "bits/stdc++.h"
using namespace std;

#define nl '\n'

const int D=200;
int n=15;
const int N=15;
double J[N][N][N][N];
int ans[D];
double L=-14.05;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	cin.tie(0)->sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	freopen("p4.txt", "w", stdout);
	// freopen("output1.txt", "w", stdout);

	normal_distribution<double> dist(0, sqrt(24.0/(n-1)/(n-2)/(n-3))); // var = n/ (n choose p)
	

	auto solve=[&](int m)->double{
		double x=0;
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				for(int k=j+1; k<N; k++){
					for(int l=k+1; l<N; l++){
						x+=J[i][j][k][l]*((m&(1<<i))?1:-1)*((m&(1<<j))?1:-1)*((m&(1<<k))?1:-1)*((m&(1<<l))?1:-1);
					}
				}
			}
		}
		return x;
	};

	auto count_bits=[&](int n)->int{
		int ans=0;
		while(n){
			if(n&1) ans++;
			n>>=1;
		}
		return ans;
	};

	double mean=0;
	for(int t=0; t<D; t++) {
		
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				for(int k=j+1; k<N; k++){
					for(int l=k+1; l<N; l++){
						J[i][j][k][l]=dist(rng);
					}
				}
			}
		}

		double cnt=0;
		double x;
		for(int m=0; m<(1<<n); m++){
			int bits=count_bits(m);
			if(bits>n/2) continue;
			x=solve(m);
			cnt+=x<L;
			if(n&1 || bits!=n/2) cnt+=x<L;
			ans[t]=cnt;
		}
		mean+=cnt;
	}

	mean/=D;
	// cout << "mean " << mean << nl;

	for(int i=0; i<D; i++){
		cout << ans[i] << nl;
	}
}