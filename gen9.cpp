/*

p=5
brute force

*/


#include "bits/stdc++.h"
using namespace std;

#define nl '\n'

const int D=100;
int n=14;
const int N=14;
double J[N][N][N][N][N];
int ans[D];
// double L=-12.9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
normal_distribution<double> dist(0, sqrt(120.0/(n-1)/(n-2)/(n-3)/(n-4)));

void go(int L){
	auto solve=[&](int mask)->double{
		double x=0;
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				for(int k=j+1; k<N; k++){
					for(int l=k+1; l<N; l++){
						for(int m=l+1; m<N; m++){
							x+=J[i][j][k][l][m]*((mask&(1<<i))?1:-1)*((mask&(1<<j))?1:-1)*((mask&(1<<k))?1:-1)*((mask&(1<<l))?1:-1)*((mask&(1<<m))?1:-1);
						}
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
	vector<int> vec;
	for(int t=0; t<D; t++) {
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				for(int k=j+1; k<N; k++){
					for(int l=k+1; l<N; l++){
						for(int m=l+1; m<N; m++){
							J[i][j][k][l][m]=dist(rng);
						}
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
		vec.push_back(cnt);
	}

	mean/=D;
	double var=0;
	for(int k:vec){
		var+=(k-mean)*(k-mean);
	}
	cout << mean << "," << var/D << nl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("p5.txt", "w", stdout);
	freopen("output1.txt", "w", stdout);

	// for(int i=0; i<10; i++){
	// 	double x=1-double(rand()%100)/50;
	// 	double l=12.9;
	// 	go(-l);
	// }
	for(int i=0; i<20; i++){
		go(-13);
		go(-12.9);
	}
	
}