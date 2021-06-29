#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define nl "\n"

const int N=20;
const int D=100;
double J[N][N];
double dp[1<<N];
int cnt;
double ans[D][N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ofstream out;

int main(){
	rep(C, 1, 1){
		string file="small_data"+to_string(C)+".csv";
		out.open(file.c_str());
		rep(n, 1, N){
  			normal_distribution<double> dist(0, (double)2.0/n);
  			double lim=-1.0*C*sqrt(2.0/n);
			cout << lim << " " << (double)2.0/(n) << nl;
  			rep(d, 1, 100){
  				cnt=0;
  				dp[0]=0;
  				rep(i, 0, n-1){
  					rep(j, i+1, n-1){
  						J[i][j]=dist(rng);
  						dp[0]+=J[i][j];
  					}
  				}
				if(dp[0]<=lim) cnt++;
  				// 00000 == all -1s
  				rep(mask, 1, (1<<n)-1){
  					int bit=0;
  					rep(j, 0, n-1){
  						if(mask&(1<<j)){
  							bit=j; break;
  						}
  					}
  					dp[mask]=dp[mask^(1<<bit)];
  					rep(i, 0, bit-1){
  						dp[mask]+=2.0*(mask&(1<<i)?1:-1)*J[i][bit];
  					}
  					rep(j, bit+1, n-1){
  						dp[mask]+=2.0*(mask&(1<<j)?1:-1)*J[bit][j];
  					}

  					if(dp[mask]<=lim) cnt++;
   				}
				ans[d-1][n-1]=double(cnt)/(1<<n);
  			}
			out << fixed;
 			rep(i, 0, D-1){
				rep(j, 0, N-1){
					out << 100.0*ans[i][j];
					if(j!=N-1) out << ",";
				}
				out << nl;
			}
		}
		out.close();
	}
}
// d=100
// d*(n^2 + n*2^n)
// n<=18
