# Distribution of low-lying states in Sherrington-Kirkpatrick model
```cpp
E[i][j] = J[i][j] * spin[i] * spin[j]
```
E = sum of all E[i][j] (0<i<j<n).
J is a random variable drawn from normal dist. centered at 0, with variance ~2/(n-1).
Spins are either 1 or -1.
We look at distribution of counts of spin sequences such that E <= [threshold := C * sqrt(6/n^2)], for fixed n.

### Constants
* 1<=n<=22
* D=200
* C=1, 2, 3, 4

