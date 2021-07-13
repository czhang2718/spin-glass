#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define nl "\n"

const int N=23;
const int Nlow=18;
const int D=200;
double J[N][N];
double dp[1<<N];
int cnt;
double ans[D][N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ofstream out;
clock_t z = clock();

int main(){
//	rep(t, 1, 100){
//
//	}
	rep(C, 1, 5){
		cout << "C " << C << nl;
		string file="combined"+to_string(C)+".csv";
		out.open(file.c_str());
		rep(n, Nlow, N){
			out << "N" << n;
			if(n!=N) out << ",";
		}
		out << nl;
		out << fixed;
		rep(n, Nlow, N){
  			normal_distribution<double> dist(0, 1);
  			double lim=-1.0*C*sqrt(n);
			// cout << lim << " " << (double)2.0/(n-1) << nl;
  			rep(d, 1, D){
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
						J[i][j]*=sqrt((double)n/ss);
						sum+=J[i][j];
					}
				}
				dp[0]=sum;
				if(dp[0]<=lim) cnt++;
  				// 00000 == all -1s
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
  					dp[mask]=dp[mask^(1<<bit)];
  					rep(i, 0, bit-1){
  						dp[mask]+=2.0*(mask&(1<<i)?1:-1)*J[i][bit];
  					}
  					rep(j, bit+1, n-1){
  						dp[mask]+=2.0*(mask&(1<<j)?1:-1)*J[bit][j];
  					}
					if(2*ones==n && dp[mask]<=lim) cnt++;
  					else if(dp[mask]<=lim) cnt+=2;
   				}
				ans[d-1][n-1]=cnt;
  			}
			cout << "DONE WITH n=" << n << nl;
		}
 		rep(i, 0, D-1){
			rep(j, Nlow-1, N-1){
				out << ans[i][j];
				if(j!=N-1) out << ",";
			}
			out << nl;
		}
		out.close();
	}

	cout << "Total Time: %.3f\n" << (double)(clock() - z) / CLOCKS_PER_SEC;

}
// d=100
// d*(n^2 + n*2^n)
// n<=18
