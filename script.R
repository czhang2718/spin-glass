library(tidyverse)
library(hrbrthemes)
library(viridis)
library(forcats)
library(plotly)

d <- read.table("https://raw.githubusercontent.com/czhang2718/spin-glass/main/n18.csv", header=T)
data <- read.table("n18_fix.txt", header=TRUE, sep=",")
data <- data %>%
  gather(key="text", value="value") %>%
  mutate(text = gsub("\\.", " ",text)) %>%
  mutate(value = as.double(value))
p <- data %>%
  mutate(text = fct_reorder(text, value)) %>%
  ggplot( aes(x=value, color=text, fill=text)) +
  geom_histogram(alpha=0.6, binwidth = .8) +
  scale_fill_viridis(discrete=TRUE) +
  scale_color_viridis(discrete=TRUE) +
  facet_wrap(~text)
p

fig <- plot_ly(alpha=.6, nbinsx=50) %>% 
  add_histogram(x=data$N1)%>% 
  add_histogram(x=data$N2)%>% 
  add_histogram(x=data$N3)%>% 
  add_histogram(x=data$N4)%>% 
  add_histogram(x=data$N5)
fig




# gallery
library(plotly)
library(withr)
library(htmlwidgets)

for(i in 1:5){
  data <- read.table(paste0("https://raw.githubusercontent.com/czhang2718/spin-glass/main/combined", i, ".csv"), header=TRUE, sep=",")
  for(j in 18:23){
    plot <- plot_ly(x = data[[paste0("N", j)]], type = "histogram", nbinsx = 40) %>% layout(title = paste0("n=", j))
    saveWidget(plot, paste0("plots/c", i, "n", j, ".html"), selfcontained = F, libdir = "lib")
  }
}
plot

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


# 9/3 new data
data <- read.table("https://raw.githubusercontent.com/czhang2718/spin-glass/main/new_dat.csv", header=TRUE, sep=",")
for(j in 18:23){
  plot <- plot_ly(x = data[[paste0("N", j)]], type = "histogram", nbinsx = 40) %>% layout(title = paste0("n=", j))
  saveWidget(plot, paste0("plots2/n", j, ".html"), selfcontained = F, libdir = "lib")
}


