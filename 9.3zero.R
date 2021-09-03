library(stats)

L=5 # or whatever K=20 implies

chisq_pdf<- function(x){
  return(dchisq((n-2)/2*x, n*(n-1)/2))
}


integrand <- function(x){
  return(chisq_pdf((n-1)*x/2)*(1+erf(L/(x*sqrt(2)))))
}

get_mean <- function(){
  return(.5*integrate(integrand, -Inf, Inf))
}

# binary search the L for K

l=