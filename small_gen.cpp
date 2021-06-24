#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a:x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define f first
#define s second
#define nl "\n"
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD=1e9+7;
template<class T> using pqg=priority_queue<T, vector<T>, greater<T>>;

const int N=18;
const int C=1;
double J[N][N];
double dp[1<<N];
int cnt;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  freopen("input.txt", "r", stdin); 
  freopen("small_data.csv", "w", stdout);

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  rep(n, 1, N){
  	cout << "n=" << n << ",";
  }
  cout << nl;

  rep(n, 1, N){
  	// cout << "sd " << C*6.0/n/n << nl;
  	normal_distribution<double> dist(0, C*6.0/n/n);
  	double lim=-sqrt(6.0*C)/n;
  	rep(d, 1, 100){
  		cnt=0;
  		dp[0]=0;
  		rep(i, 0, n-1){
  			rep(j, i+1, n-1){
  				J[i][j]=dist(rng);
  				dp[0]+=J[i][j];
  			}
  		}
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
  			// cout << "comp " << dp[mask] << ' ' << lim << nl;
  		}
  		cout << cnt << ", ";
  	}
  	cout << nl;
  }
}

// d=100
// d*(n^2 + n*2^n)
// n<=18
