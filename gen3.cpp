#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(x, a) for(auto &x:a)
#define pb push_back
#define nl "\n"
typedef vector<int> vi;
typedef long double ld;

const int N=20;
const int Nlow=20;
const int D=200;
const int T=100; //100
double J[N][N];
double dp[1<<N];
int cnt;
double ans[D][N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ofstream out;
clock_t z = clock();

int main(){
	rep(C, 1, 7){ // 7
		string file="frequency"+to_string(C)+".csv";
		out.open(file.c_str());
		out << fixed;
		rep(n, Nlow, N){
  			normal_distribution<double> dist(0, sqrt(2.0/(n-1)));
  			double lim=-1.0*C*sqrt(n);
			rep(t, 1, T){
				vi freq;
				int sum=0;
	  			rep(d, 1, D){
	  				cnt=0;
	  				dp[0]=0;
	  				rep(i, 0, n-1){
	  					rep(j, i+1, n-1){
	  						J[i][j]=dist(rng);
	  						dp[0]+=J[i][j];
	  					}
	  				}
					if(dp[0]<=lim) cnt+=2;
	  				// 00000 == all -1s
	  				rep(mask, 1, (1<<n)-1){
	  					int bit=0;
						int ones=0;
	  					rep(j, 0, n-1){
	  						if(mask&(1<<j)){
	  							bit=j; break;
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
						if(2*ones==n) cnt++;
	  					if(dp[mask]<=lim) cnt+=2;
	   				}
					freq.pb(cnt);
					sum+=cnt;
	  			}
				double mean=(double)sum/double(D);
				long double var=0;
				trav(k, freq){
					cout << var << " ";
					var+=ld(k-mean)*(k-mean);
				}
				cout << nl;
				var/=(D-1);
				out << mean << "," << var << nl;
			}
		}
	}

	cout << "Total Time: %.3f\n" << (double)(clock() - z) / CLOCKS_PER_SEC;

}
// 7 * 100 * 200 * 2^20*20
// = 140000*1000000*

// 100*200*2^20*20 = 4*10^11
