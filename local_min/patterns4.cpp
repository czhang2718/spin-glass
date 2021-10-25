/*
taken from patterns.cpp
modified for p=4
10/25
*/

#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define nl "\n"


const int N=20;
const int P=4;
const int T=100;
double J[N][N][N][N];
double dp[1<<N];
int ans[T];
int A[P];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ofstream out;
clock_t z = clock();

int main(){
	// freopen("output.txt", "w", stdout);
	cout << fixed;

	for(int n=10; n<=N; n++){
		normal_distribution<double> dist(0, sqrt(24.0/(n-1)*(n-2)*(n-3)));
		double mean=0;
		double var=0;
		for(int t=0; t<T; t++){
			dp[0]=0;
			double sum=0;
			double ss=0;
			rep(i, 0, n-1){
				rep(j, i+1, n-1){
					rep(k, j+1, n-1){
						rep(l, k+1, n-1){
							J[i][j][k][l]=dist(rng);
							ss+=J[i][j][k][l]*J[i][j][k][l];
						}
					}
				}
			}
			rep(i, 0, n-1){
				rep(j, i+1, n-1){
					rep(k, j+1, n-1){
						rep(l, k+1, n-1){
							J[i][j][k][l]*=sqrt((double)n/ss);
							sum+=J[i][j][k][l];
						}
					}
				}
			}
			dp[0]=sum;

			// 00000 == all -1s
			rep(mask, 1, (1<<n)-1){
				if(mask>(((1<<n)-1)^mask)) continue;
				int bit=0;
				rep(j, 0, n-1){
					if(mask&(1<<j)){
						bit=j; 
						break;
					}
				}
				dp[mask]=dp[mask^(1<<bit)];
				for(int i=0; i<n; i++){
					for(int j=i+1; j<n; j++){
						for(int k=j+1; k<n; k++){
							if(i==bit || j==bit || k==bit) continue;
							int cnt=(bit>i)+(bit>j)+(bit>k);
							if(cnt==0) A[0]=bit, A[1]=i, A[2]=j, A[3]=k;
							if(cnt==1) A[0]=i, A[1]=bit, A[2]=j, A[3]=k;
							if(cnt==2) A[0]=i, A[1]=j, A[2]=bit, A[3]=k;
							if(cnt==3) A[0]=i, A[1]=j, A[2]=k, A[3]=bit;
							int cont=(mask&(1<<i)?1:-1)*(mask&(1<<j)?1:-1)*(mask&(1<<k)?1:-1);
							dp[mask]-=2.0*cont*J[A[0]][A[1]][A[2]][A[3]];
						}
					}
				}
				dp[((1<<n)-1)^mask]=dp[mask];
			}

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
			// cout << ans[i] << " " << mean << '\n';
		}
		var/=T;
		cout << (double)mean << " " << var << "\n";
		
	}

	cout << "Total Time: %.3f\n" << (double)(clock() - z) / CLOCKS_PER_SEC;
}
// d=100
// d*(n^2 + n*2^n)
// n<=18
