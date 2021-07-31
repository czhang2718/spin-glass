library(numDeriv)
library(MASS)

D=200
assign("n", 19, envir = .GlobalEnv)
assign("c", -3, envir = .GlobalEnv)
inf=10000
hist_area=0
assign("f_area", 0, envir = .GlobalEnv)

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

for(n in 18:23){
  for(c in 1:5){
    data <- read.table(paste0("https://raw.githubusercontent.com/czhang2718/spin-glass/main/combined", c, ".csv"), header=TRUE, sep=",")
    x <- data[[paste0("N", n)]]
    xfit<-seq(0, max(x),length=200)
    yfit<-calc(xfit)
    png(file=paste0("plots/overlay/n", n, "c", c, ".png"),
        width=600, height=350)
    truehist(x)
    lines(xfit, yfit, col="blue", lwd=2)
    lines(density(x))
    dev.off()
  }
}


truehist(x)
lines(xfit, yfit, col="blue", lwd=2)
lines(density(x))




integrate(calc, 0, 10000) # 1 :)


