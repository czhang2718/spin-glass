library(pracma)
library(numDeriv)

assign("n", 23, envir = .GlobalEnv)
assign("c", -4, envir = .GlobalEnv)

inv <- function(x){
  sig=c*sqrt(n)/(sqrt(2)*erfinv(x/(2^(n-1))-1))
  return(sig^2)
}

unscale <- function(x){
  x*(n-1)/2
}

chi <- function(x){
  ans=dchisq(unscale(x), n*(n-1)/2)
  ans=ans*grad(unscale, x)
  ans
}


pdf <- function(x){
  pc<-c()
  for(y in x){
    p=chi(inv(y))
    p=p*grad(inv, y)
    pc=c(pc, p)
  }
  pc
}

calc <- function(xvals){
  y=c()
  for(i in xvals){
    if(i==0){
      y=c(y, 0)
      next
    }
    d=pdf(i)
    y=c(y, d)
  }
  return(y)
}


plot(calc(1:5000), type='l')

success <- 0:40
plot(success, dpois(success, lambda=5), type='h')
