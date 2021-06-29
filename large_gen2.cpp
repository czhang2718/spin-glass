#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(x, a) for(auto x:a)
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define f first
#define s second
#define nl '\n'
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	

template< size_t size>
typename std::bitset<size> random_bitset( double p = 0.5) {

    typename std::bitset<size> bits;
    std::bernoulli_distribution d( p);

    for( int n = 0; n < size; ++n) {
        bits[ n] = d(rng);
    }

    return bits;
}

const int N=60;
const int D=200;
const int K=100;
const int C=1;
double J[N][N];
int ans[D][N];
int cnt;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("large_data4.csv", "w", stdout);

	rep(n, 19, 60){
		// cout << "sd " << C*6.0/n/n << nl;
		normal_distribution<double> dist(0, 6.0/n/n);
		double lim=-4.0*sqrt(6.0)/n;
		rep(d, 1, D){
			cnt=0;
			rep(i, 0, n-1){
				rep(j, i+1, n-1){
					J[i][j]=dist(rng);
				}
			}
			
			int cnt=0;
			rep(k, 1, K){
				auto b=random_bitset<60>(.5);
				ld sum=0; //ll?
				for(int i=0; i<n; i++){
				for(int j=i+1; j<n; j++){
						sum +=ld (b[i]?1:-1)*(b[j]?1:-1)*J[i][j];
					}
				}
				if(sum <= lim) cnt++;
			}
			ans[d-1][n-1]=cnt;
			// cout <<  cnt << " ";
  		}
		// cout << nl;
	}

	rep(i, 0, D-1){
		rep(n, 19, 60){
			cout << ans[i][n-1];
			if(n!=60) cout << ",";
		}
		cout << nl;
	}
}

