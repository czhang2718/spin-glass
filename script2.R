x<-scan("mean_small.txt")
y<-scan("var_small.txt")
plot(x, y)
abline(lm(y~x), col="red")


title="p5_all"
dat <- read.csv(paste0(title, ".csv"))
dat=as.data.frame(dat)
colnames(dat)=c("L", "mean", "var")

sum=0
for(i in 1:dim(dat)[1]){
  sum = sum + (dat$mean[i]-dat$var[i])*(dat$mean[i]-dat$var[i])/dat$mean[i]
}
sum #= 111.531
# idk how poisson chi sq test works
# p value is 96% though, so apparently not significant?


fit <- lm(var ~ mean, data = dat)

library(plotly)
library(htmlwidgets)
plot <-
  plot_ly(data=dat, x = ~mean) %>% 
  add_markers(y = ~var) %>% 
  add_trace(
    type = 'scatter',
    mode = 'markers',
    x = ~mean,
    y = ~var,
    text=~L,
    showlegend = FALSE
  ) %>%
  add_lines(x = ~mean, y = fitted(fit))
plot

saveWidget(plot, paste0(paste0(title, ".html")), selfcontained = F, libdir = "lib")
summary(fit)$coefficients


# n mean
x<- (2:22)
y<-c(1.000000,1.000000,1.250000,1.650000,1.950000,1.850000,2.500000,3.000000,3.650000,4.650000,5.300000,7.850000,8.450000,10.350000,12.550000,19.250000,17.500000,23.900000,28.850000,34.800000,49.300000)

plot(x, y)

# mean var
dat <- read.csv("Book1.csv", header=TRUE)
colnames(dat)=c("mean", "var")
x<-dat$mean
y<-dat$var
plot(x, y)



