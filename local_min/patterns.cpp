/*taken from gen7 (hope it's correct)
just want to look at the values being outputted for p=2
see if there's patterns between distant binary strings*/

#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define nl "\n"


const int N=22;
const int T=50;
double J[N][N];
double dp[1<<N];
int ans[T];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ofstream out;
clock_t z = clock();

int main(){
	// freopen("output.txt", "w", stdout);
	cout << fixed;

	for(int n=2; n<=N; n++){
		normal_distribution<double> dist(0, sqrt(2.0/(n-1)));
		double mean=0;
		double var=0;
		for(int t=0; t<T; t++){
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

			// 00000 == all -1s
			rep(mask, 1, (1<<n)-1){
				int bit=0;
				rep(j, 0, n-1){
					if(mask&(1<<j)){
						bit=j; 
						break;
					}
				}
				dp[mask]=dp[mask^(1<<bit)];
				rep(i, 0, bit-1){
					dp[mask]+=2.0*(mask&(1<<i)?1:-1)*J[i][bit];
				}
				rep(j, bit+1, n-1){
					dp[mask]+=2.0*(mask&(1<<j)?1:-1)*J[bit][j];
				}
			}

			auto bin=[&](int p)->string{
				string ret="";
				for(int i=0; i<n; i++){
					if(p&(1<<i)) ret+='1';
					else ret+='0';
				}
				reverse(ret.begin(), ret.end()); return ret;
			};

			int local_min=0;
			for(int m=0; m<(1<<n); m++){
				if(m>(((1<<n)-1)^m)) continue;
				bool ok=1;
				for(int k=0; k<n; k++){
					if(dp[m^(1<<k)]<dp[m]){
						ok=0; break;
					}
				}
				// if(ok) cout << bin(m) << " " << dp[m] << " " << __builtin_popcount(m) << '\n';
				local_min+=2*ok;
			}
			mean+=local_min;
			ans[t]=local_min;
		}
		mean/=T;
		for(int i=0; i<T; i++){
			var+=(ans[i]-mean)*(ans[i]-mean);
		}
		var=sqrt(var/n);
		cout << (double)mean << " " << var << "\n";
		
	}

	cout << "Total Time: %.3f\n" << (double)(clock() - z) / CLOCKS_PER_SEC;
}
// d=100
// d*(n^2 + n*2^n)
// n<=18
