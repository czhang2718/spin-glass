#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define nl "\n"

const int N=15;
const int D=150;
double J[N][N];
int cnt;
double ans[D][N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ofstream out;

int main(){
	rep(C, 1, 1){
		string file="test"+to_string(C)+".csv";
		out.open(file.c_str());
		rep(n, 5, N){
			out << "N" << n;
			if(n!=N) out << ",";
		}
		out << nl;
		out << fixed;
		rep(n, 5, N){
  			normal_distribution<double> dist(0, (double)2.0/n);
			double c=.2;
  			double lim=-1.0*c*sqrt(2.0/n);
			cout << lim << " " << (double)2.0/(n) << nl;
  			rep(d, 1, D){
  				cnt=0;
  				rep(i, 0, n-1){
  					rep(j, i+1, n-1){
  						J[i][j]=dist(rng);
  					}
  				}
  				rep(mask, 0, (1<<n)-1){
					double val=0;
					rep(i, 0, n-1){
						rep(j, i+1, n-1){
							val+=((mask&(1<<i))?1.0:-1.0)*((mask&(1<<j))?1.0:-1.0)*J[i][j];
						}
					}
					// cout << val << " " << lim << nl;
  					if(val<=lim) cnt++;
   				}
				ans[d-1][n-1]=double(cnt)/(1<<n);
  			}
		}
 		rep(i, 0, D-1){
			rep(j, 4, N-1){
				out << 100*ans[i][j];
				if(j!=N-1) out << ",";
			}
			out << nl;
		}

		out.close();
	}
}
// d=100
// d*(n^2 + n*2^n)
// n<=18
