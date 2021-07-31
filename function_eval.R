library(pracma)
library(numDeriv)


assign("n", 19, envir = .GlobalEnv)
assign("c", -3, envir = .GlobalEnv)

inv <- function(x){
  sig=c*sqrt(n)/(sqrt(2)*erfinv(x/(2^(n-1))-1))
  return(sig^2)
}

phi <- function(y){
  if(y==0) return(0)
  return(2^(n-1)*(1+erf(c*sqrt(n)/sqrt(2*y))))
}

xc=c()
yc=c()
sum=0

for(y in 140000:230000){
  xc=c(xc, y)
  
  p=chi(inv(y))
  # print(paste("grad", grad(inv, y)))
  p=p*grad(inv, y)
  yc=c(yc, p)
  sum=sum+p
}

plot(xc, yc)

unscale <- function(x){
  x*(n-1)/2
}

scale <- function(y){
  y*2/(n-1)
}

chi <- function(x){
  ans=dchisq(unscale(x), n*(n-1)/2)
  ans=ans*grad(unscale, x)
  ans
}


xc=c()
yc=c()
for(x in 0:8000){
  xc=c(xc, x)
  sig=phi(x)*(n-1)/2
  k=n*(n-1)/2
  p=dchisq(sig, k)
  yc=c(yc, p)
}



chi <-function(x){
  y=c()
  for(i in x){
    y=c(y, dchisq(i*(n-1)/2, n*(n-1)/2))
  }
  return(y)
}

# A=integrate(chi, 0, 10000)
# 
# 
# y=c()
# x=c()
# for(i in 0:400){
#   x=c(x, i)
#   y=c(y, dchisq(i*(n-1)/2, n*(n-1)/2))
# }
# plot(x, y)
# 
# 
# 
# 
# 
# 
# pdf <- function(x){
#   y<-c()
#   for(r in x){
#     x=c(x, r)
#     sig=c*sqrt(n)/(sqrt(2)*erfinv(r/(2^(n-1))-1))
#     if(sig<=0){
#       y=c(y, 0)
#       next
#     }
#     sig=sig*sig
#     p=(sig^(n/2-1))/(2^(n/2))
#     p=p*exp(-sig/2)/gamma(n/2)
#     y=c(y, p)
#   }
#   return(y)
# }
# 
# A=integrate(pdf, 0, 10000)
# 
# xc=c()
# yc=c()
# for(x in 1:400){
#   y=inv(x)
#   xc=c(xc, x)
#   yc=c(yc, y)
# }
# plot(xc, yc)
