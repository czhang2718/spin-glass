/*

p=2
2^n n dp optimized
still brute force

*/

#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define nl "\n"


const int N=20;
int n=20;
const int D=1;
double J[N][N];
double dp[1<<N];
// double L=-20.95;
// int cnt;
double ans[D][N];


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
normal_distribution<double> dist(0, sqrt(2.0/(n-1)));

void go(double L){

	memset(dp, 0, sizeof(dp));
	vector<int> vec;
	double mean=0;

	rep(d, 1, D){
		int cnt=0;
		dp[0]=0;
		double sum=0;
		double ss=0;
		rep(i, 0, n-1){
			rep(j, i+1, n-1){
				J[i][j]=dist(rng);
				ss+=J[i][j]*J[i][j];
			}
		}
		rep(i, 0, n-1){
			rep(j, i+1, n-1){
				J[i][j]*=sqrt((double)n/ss);
				sum+=J[i][j];
			}
		}
		dp[0]=sum;
		if(dp[0]<=L) cnt+=2;
		rep(mask, 1, (1<<n)-1){
			int bit=0;
			int ones=0;
			rep(j, 0, n-1){
				if(mask&(1<<j)){
					bit=j; 
				ones++;
				}
			}
			if(2*ones>n) continue;
			dp[mask]=dp[mask^1];
			rep(i, 0, bit-1) dp[mask]+=2.0*(mask&(1<<i)?1:-1)*J[i][bit];
			rep(j, bit+1, n-1) dp[mask]+=2.0*(mask&(1<<j)?1:-1)*J[bit][j];
			if(2*ones==n && dp[mask]<L) cnt++;
			else if(dp[mask]<L) cnt+=2;
			cout << dp[mask] << nl;
		}
		cout <<cnt << nl;
		vec.push_back(cnt);
		mean+=cnt;
	}
	mean/=D;
	double var=0;
	for(int k:vec) var+=(k-mean)*(k-mean);
	var/=D;
	cout << mean << " " << var << nl;
}



int main(){
	freopen("output1.txt", "w", stdout);
	cout << fixed;
	go(-10);
}
