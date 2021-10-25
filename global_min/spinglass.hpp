#include "bits/stdc++.h"
using namespace std;
#define nl '\n'

const int D=200; //CHANGE

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

auto count_bits=[&](int n)->int{
   int ans=0;
   while(n){
      if(n&1) ans++;
      n>>=1;
   }
   return ans;
};

namespace spin5
{
   const int N=14;
   double J[N][N][N][N][N];
   int p=5;

   normal_distribution<double> dist(0, sqrt(120.0/(N-1)/(N-2)/(N-3)/(N-4)));

   void go(double L, int n){
      auto solve=[&](int mask)->double{
         double x=0;
         for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
               for(int k=j+1; k<n; k++){
                  for(int l=k+1; l<n; l++){
                     for(int m=l+1; m<n; m++){
                        x+=J[i][j][k][l][m]*((mask&(1<<i))?1:-1)*((mask&(1<<j))?1:-1)*((mask&(1<<k))?1:-1)*((mask&(1<<l))?1:-1)*((mask&(1<<m))?1:-1);
                     }
                  }
               }
            }
         }
         return x;
      };
      

      double mean=0;
      vector<int> vec;
      for(int t=0; t<D; t++) {
         for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
               for(int k=j+1; k<n; k++){
                  for(int l=k+1; l<n; l++){
                     for(int m=l+1; m<n; m++){
                        J[i][j][k][l][m]=dist(rng);
                     }
                  }
               }
            }
         }

         double cnt=0;
         for(int m=0; m<(1<<n); m++){
            int bits=count_bits(m);
            if(bits>n/2) continue;
            if(p%2==1){
               if(n%2==0){
                  if(bits==n/2) cnt+=solve(m)<L;
                  else if(abs(solve(m))>=abs(L)) cnt++;
               }
               else{
                  if(abs(solve(m))>=abs(L)) cnt++;
               }
            }
            else{
               if(n%2==0){
                  if(bits==n/2) cnt+=solve(m)<L;
                  else if(solve(m)<L) cnt+=2;
               }
               else{
                  if(solve(m)<L) cnt+=2;
               }
            }
         }
         mean+=cnt;
         vec.push_back(cnt);
      }

      mean/=(double)D;
      double var=0;
      for(int k:vec){
         var+=double(k-mean)*(k-mean);
      }
      var/=D;
      cout << L << " " << mean << " " << var << nl;
   }
}



// p=4
namespace spin4
{
   const int N=16;
   double J[N][N][N][N];
   int p=4;

   normal_distribution<double> dist(0, sqrt(24.0/(N-1)/(N-2)/(N-3)));

   void go(double L, int n){
      auto solve=[&](int mask)->double{
         double x=0;
         for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
               for(int k=j+1; k<N; k++){
                  for(int l=k+1; l<N; l++){
                     x+=J[i][j][k][l]*((mask&(1<<i))?1:-1)*((mask&(1<<j))?1:-1)*((mask&(1<<k))?1:-1)*((mask&(1<<l))?1:-1);
                  }
               }
            }
         }
         return x;
      };

      double mean=0;
      vector<int> vec;
      for(int t=0; t<D; t++) {
         for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
               for(int k=j+1; k<n; k++){
                  for(int l=k+1; l<n; l++){
                     J[i][j][k][l]=dist(rng);
                  }
               }
            }
         }

         double cnt=0;
         for(int m=0; m<(1<<n); m++){
            int bits=count_bits(m);
            if(bits>n/2) continue;
            if(p%2==1){
               if(n%2==0){
                  if(bits==n/2) cnt+=solve(m)<L;
                  else if(abs(solve(m))>=abs(L)) cnt++;
               }
               else{
                  if(abs(solve(m))>=abs(L)) cnt++;
               }
            }
            else{
               if(n%2==0){
                  if(bits==n/2) cnt+=solve(m)<L;
                  else if(solve(m)<L) cnt+=2;
               }
               else{
                  if(solve(m)<L) cnt+=2;
               }
            }
         }
         mean+=cnt;
         vec.push_back(cnt);
      }

      mean/=(double)D;
      double var=0;
      for(int k:vec){
         var+=double(k-mean)*(k-mean);
      }
      var/=D;
      cout << L << " " << mean << " " << var << nl;
   }
}



namespace spin3
{
   const int N=18; // make  sure N=n
   double J[N][N][N];
   int p=3;

   normal_distribution<double> dist(0, sqrt(6.0/(N-1)/(N-2)));

   void go(double L, int n){ // make  sure N=n
      auto solve=[&](int mask)->double{
         double x=0;
         for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
               for(int k=j+1; k<n; k++){
                  x+=J[i][j][k]*((mask&(1<<i))?1:-1)*((mask&(1<<j))?1:-1)*((mask&(1<<k))?1:-1);
               }
            }
         }
         return x;
      };
      

      double mean=0;
      vector<int> vec;
      for(int t=0; t<D; t++) {
         for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
               for(int k=j+1; k<n; k++){
                  J[i][j][k]=dist(rng);
               }
            }
         }

         double cnt=0;
         for(int m=0; m<(1<<n); m++){
            int bits=count_bits(m);
            if(bits>n/2) continue;
            if(p%2==1){
               if(n%2==0){
                  if(bits==n/2) cnt+=solve(m)<L;
                  else if(abs(solve(m))>=abs(L)) cnt++;
               }
               else{
                  if(abs(solve(m))>=abs(L)) cnt++;
               }
            }
            else{
               if(n%2==0){
                  if(bits==n/2) cnt+=solve(m)<L;
                  else if(solve(m)<L) cnt+=2;
               }
               else{
                  if(solve(m)<L) cnt+=2;
               }
            }
         }
         mean+=cnt;
         vec.push_back(cnt);
      }

      mean/=(double)D;
      double var=0;
      for(int k:vec){
         var+=double(k-mean)*(k-mean);
      }
      var/=D;
      cout << L << " " << mean << " " << var << nl;
   }
}