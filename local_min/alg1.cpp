// randomized greedy shit (attempt 1) tested in count_local.cpp
// try L starting strings
// random permutation 1..n
// k

// global: n, J, rng
auto randomized=[&]()->int{

    auto check=[&](int )
    map<int, bool> vis; // map<ll, bool> for n>30
    int L=20;
    while(L--){
        int mask=uniform_int_distribution<int>(0, (1<<n))(rng);
        while(check(mask)){}         
         
    }
};