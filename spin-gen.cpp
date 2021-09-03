#include "bits/stdc++.h"
using namespace std;
 
const int N=15; // number of dimensions; ie. i,j,k < N
double J[N][N][N];

int main(){
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
	normal_distribution<double> distribution(0, 1.0); // (mean, sd)

	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			for(int k=j+1; k<N; k++){
				J[i][j][k]=distribution(rng);
			}
		}
	}
  	for(int spin=0; spin<(1<<N); spin++){
  		double sum=0;
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				for(int k=j+1; k<N; k++){
		  			int sig_i=((spin&(1<<i))?1:-1); 
					int sig_j=((spin&(1<<j))?1:-1);
					int sig_k=((spin&(1<<k))?1:-1);
		  			sum+=J[i][j][k]*sig_i*sig_j*sig_k;
				}
			}
		}
		cout << sum << '\n';
    }
}