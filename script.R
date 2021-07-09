library(tidyverse)
library(hrbrthemes)
library(viridis)
library(forcats)

# gallery
library(plotly)
library(withr)
library(htmlwidgets)

for(i in 1:7){
  data <- read.table(paste0("https://raw.githubusercontent.com/czhang2718/spin-glass/main/combined", i, ".csv"), header=TRUE, sep=",")
  for(j in 18:23){
    plot <- plot_ly(x = data[[paste0("N", j)]], type = "histogram") %>% layout(title = paste0("n=", j))
    saveWidget(plot, paste0("plots/c", i, "n", j, ".html"), selfcontained = F, libdir = "lib")
  }
}

# data <- read.table(paste0("https://raw.githubusercontent.com/czhang2718/spin-glass/main/combined", 1, ".csv"), header=TRUE, sep=",")
# p <- plot_ly(x=data[["N18"]], type="histogram")
# p

# individual
data<- read.table("https://raw.githubusercontent.com/czhang2718/spin-glass/main/large_data.txt", header=FALSE)
data<- as.data.frame(data)

for(i in 19:60){
  p <- hist(as.numeric(data[i-18,]), breaks=10)
  jpeg(paste0("hist", i, ".jpg"))
  plot(p)
  dev.off()
}

