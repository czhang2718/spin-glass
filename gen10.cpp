/*

p=4
brute force

*/


#include "bits/stdc++.h"
#include "spinglass.hpp"
using namespace std;
using namespace spin4;

#define nl '\n'
#define rep(i, a, b) for(int i=a; i<=b; i++)

int n=16;
// double L=-12.9;


int main(){
	cin.tie(0)->sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("p5.txt", "w", stdout);
	freopen("output1.txt", "w", stdout);

	cout << setprecision(6); 	
	cout << fixed;
	// go(-13, n);

	for(int i=-13; i>=-18; i--){
		for(int f=0; f<10; f++) go(i-double(f)/10, n);
	}	
}