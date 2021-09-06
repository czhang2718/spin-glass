x<-scan("mean_small.txt")
y<-scan("var_small.txt")
plot(x, y)
abline(lm(y~x), col="red")


title="p4_some"
dat <- read.csv(paste0(title, ".csv"))
dat=as.data.frame(dat)
colnames(dat)=c("mean", "var")


fit <- lm(var ~ mean, data = dat)

library(plotly)
library(htmlwidgets)
plot <-
  plot_ly(data=dat, x = ~mean) %>% 
  add_markers(y = ~var) %>% 
  add_lines(x = ~mean, y = fitted(fit))


saveWidget(plot, paste0(paste0(title, ".html")), selfcontained = F, libdir = "lib")
summary(fit)$coefficients


