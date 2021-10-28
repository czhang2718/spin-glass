// randomized greedy shit (attempt 1) tested in count_local.cpp
// try L starting strings
// random permutation 1..n
// also randomize FLIP
// k

// global: n, J, rng
auto randomized=[&]()->int{

    map<int, bool> vis; // map<ll, bool> for n>30
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);
 
    std::random_device rd;
    std::mt19937 g(rd());
 

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    int ans=0;
    while((std::chrono::duration_cast<std::chrono::seconds>(end - start).count() !=10)){
        int mask=uniform_int_distribution<int>(0, (1<<n))(rng);
        bool seen=0;
        while(true){
            if(vis[mask]){
                seen=1; break;
            }
            bool change=0;
            std::shuffle(perm.begin(), perm.end(), g);
            for(int i:perm){
                if(vis[mask]){
                    seen=1; break;
                }
                vis[mask]=1;
                int c0=0;
                int c1=0;
                for(int j=0; j<n; j++){
                    if(j==i) continue;
                    if(((mask&(1<<j))>0)^((mask&(1<<i))>0)) c1+=J[min(i, j)][max(i, j)];
                    else c0+=J[min(i, j)][max(i, j)];
                }
                if(c0>c1){
                    change=1;
                    mask^=(1<<i);
                }
            }
            if(!change || seen){
                break;
            }
        }  
        ans+=!seen;  
    }
    return ans;
};