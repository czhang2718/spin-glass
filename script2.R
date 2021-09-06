x<-scan("mean_small.txt")
y<-scan("var_small.txt")
plot(x, y)
abline(lm(y~x), col="red")
