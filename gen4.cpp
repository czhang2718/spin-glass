#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define nl "\n"

const int N=18;
const int Nlow=18;
const int D=5;
const int C=2;
double J[N][N];
double dp[1<<N];
int cnt;
double ans[(1<<N)][D+1];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ofstream out;
clock_t z = clock();

int main(){
		string file="n18.csv";
		out.open(file.c_str());
		rep(n, 1, D){
			out << "N" << n;
			if(n!=N) out << ",";
		}
		out << nl;
		out << fixed;
		int n=18;
		rep(d, 1, D) {
  			normal_distribution<double> dist(0, 1);
  			double lim=-1.0*C*sqrt(n);
			// cout << lim << " " << (double)2.0/(n-1) << nl;
			cnt=0;
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
					J[i][j]=sqrt(J[i][j]*(double)n/ss);
					sum+=J[i][j];
				}
			}
			dp[0]=sum;
			ans[0][d]=sum;
			if(dp[0]<=lim) cnt++;
				// 00000 == all -1s
			rep(mask, 1, (1<<n)-1){
				int bit=0;
				rep(j, 0, n-1){
					if(mask&(1<<j)){
						bit=j; 
					}
				}
				dp[mask]=dp[mask^(1<<bit)];
				rep(i, 0, bit-1){
					dp[mask]+=2.0*(mask&(1<<i)?1:-1)*J[i][bit];
				}
				rep(j, bit+1, n-1){
					dp[mask]+=2.0*(mask&(1<<j)?1:-1)*J[bit][j];
				}
				ans[mask][d]=dp[mask];
  			}
			cout << "DONE WITH d=" << d << nl;
		}
 		rep(i, 0, (1<<18)-1) {
			rep(j, 1, D){
				out << ans[i][j];
				if(j!=D) out << ",";
			}
			out << nl;
		}

	cout << "Total Time: %.3f\n" << (double)(clock() - z) / CLOCKS_PER_SEC;

}
// d=100
// d*(n^2 + n*2^n)
// n<=18
