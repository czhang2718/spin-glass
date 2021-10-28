/* 
10/22/21
stubbed with patterns.cpp (p=2)
test a dumb randomized, greedy algorithm
take random bit string
keep on switching bits until you get to local min
purpose: fast approximation
*/

#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define nl "\n"


const int N=22;
const int T=1;
double J[N][N];
double dp[1<<N];
int ans[T];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ofstream out;
clock_t z = clock();

int main(){
   // freopen("output.txt", "w", stdout);
   cout << fixed;

   for(int n=23; n<=23; n++){
      normal_distribution<double> dist(0, sqrt(2.0/(n-1)));

      

      // compare 2 methods
      for(int t=0; t<T; t++){
         double mean=0;
         double var=0;
         double sum=0;
         double ss=0;

         // create J
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

         auto brute=[&]()->int{
            dp[0]=0;
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
               // if(ok) cout << m << '\n';
               local_min+=2*ok;
            }
            return local_min;
         };

         auto randomized=[&]()->int{
             map<int, bool> vis; // map<ll, bool> for n>30
             vector<int> perm(n);
             for(int i=0; i<n; i++) perm[i]=i;
          
             std::random_device rd;
             std::mt19937 g(rd());
          

             int local_min=0;
             using ClockType = std::chrono::system_clock;
             auto start = ClockType::now();
             int k=0;
             while (std::chrono::duration_cast<std::chrono::seconds>(ClockType::now()-start).count()<1 && k<(1<<n)){
                 int mask=uniform_int_distribution<int>(0, (1<<n))(rng);
                 if(vis[mask]) continue;
                 k++;
                 // cout << "start with " << mask << '\n';
                 bool seen=0;
                 while(true){
                     bool change=0;
                     std::shuffle(perm.begin(), perm.end(), g);
                     for(int i:perm){
                         double c0=0;
                         double c1=0;
                         for(int j=0; j<n; j++){
                             if(j==i) continue;
                             if(((mask&(1<<j))>0)^((mask&(1<<i))>0)) c1+=J[min(i, j)][max(i, j)];
                             else c0+=J[min(i, j)][max(i, j)];
                             // cout << "J[" << min(i, j) << "][" << max(i, j) << "] = " << J[min(i, j)][max(i, j)] << '\n';
                         }
                         // cout << c0 << " " << c1 << '\n';
                         if(c0>c1){
                             change=1;
                             mask^=(1<<i);
                             if(vis[mask]){
                                 seen=1; break;
                             }
                             else{
                              vis[mask]=1;
                              k++;
                             }
                         }
                     }
                     if(!change || seen){
                         break;
                     }
                 }  
                 local_min+=!seen;  
                 if(!seen){
                  // cout << "minima " << mask << '\n';
                 }
             }
             return local_min;
         };
         cout << brute() << " " << randomized() << '\n'; 
         // cout << brute() << '\n';
         // cout << randomized() << '\n';
      }
   }

   cout << "Total Time: %.3f\n" << (double)(clock() - z) / CLOCKS_PER_SEC;
}
// d=100
// d*(n^2 + n*2^n)
// n<=18
