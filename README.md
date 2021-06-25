# Low energy distribution in Sherrington-Kirkpatrick model
```cpp
E[i][j] = J[i][j] * spin[i] * spin[j]
```
E = sum of all E[i][j] (0<i<j<n).
J is a random variable drawn from normal dist. centered at 0, with standard deviation 6/n^2.
Spins are either 1 or -1.
We look at distribution of counts of spin sequences such that E <= [threshold := C * sqrt(6/n^2)], for fixed n. Computation is done differently for small and large n.

## Methods

|Small n|Large n| 
|-------|-------|
|1<=n<=18| 19<=n<=60|    
|Brute force all spin sequences and count the number that produce E<=threshold| Approximate the ratio of sequences that produce small enough E with a random sample|
|D trials for each n|D trials; K randomly chosen representatives| 

### Constants
* 1<=n<=60
* D=100 (for small n)
* D=200 (for large n)
* K=100 (for large n)
* C=1, 2, 3, 4 (for all n)

