library(pracma)

n=20
c=-3

x=c()
y=c()
for(r in 0:4000){
  x=c(x, r)
  sig=c*sqrt(n)/(sqrt(2)*erfinv(r/(2^(n-1))-1))
  if(sig<=0){
    y=c(y, 0)
    next
  }
  sig=sig*sig*(n-1)/2
  k=n*(n-1)/2
  p=(sig^(k/2-1))/(2^(k/2))
  p=p*exp(-sig/2)/gamma(k/2)
  y=c(y, p)
}

write.csv(y, "y.csv")

plot(x, y)
