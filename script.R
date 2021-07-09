library(tidyverse)
library(hrbrthemes)
library(viridis)
library(forcats)

# gallery
for(i in 1:7){
  data <- read.table(paste0("https://raw.githubusercontent.com/czhang2718/spin-glass/main/combined", i, ".csv"), header=TRUE, sep=",")
  data <- data %>%
    gather(key="text", value="value") %>%
    mutate(text = gsub("\\.", " ",text)) %>%
    mutate(value = round(as.numeric(value),0))
  p <- data %>%
    mutate(text = fct_reorder(text, value)) %>%
    ggplot( aes(x=value, color=text, fill=text)) +
    geom_histogram(alpha=0.6, binwidth = 1000) +
    scale_fill_viridis(discrete=TRUE) +
    scale_color_viridis(discrete=TRUE) +
    facet_wrap(~text)
  
  jpeg(paste0("c", i, ".jpg"))
  plot(p)
  dev.off()
}

p


# individual
data<- read.table("https://raw.githubusercontent.com/czhang2718/spin-glass/main/large_data.txt", header=FALSE)
data<- as.data.frame(data)

for(i in 19:60){
  p <- hist(as.numeric(data[i-18,]), breaks=10)
  jpeg(paste0("hist", i, ".jpg"))
  plot(p)
  dev.off()
}

