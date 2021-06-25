library(tidyverse)
library(hrbrthemes)
library(viridis)
library(forcats)

# gallery
data <- read.table("https://raw.githubusercontent.com/czhang2718/spin-glass/main/large_data4.csv", header=FALSE, sep=",")
data <- data %>%
  gather(key="text", value="value") %>%
  mutate(text = gsub("\\.", " ",text)) %>%
  mutate(value = round(as.numeric(value),0))
p <- data %>%
  mutate(text = fct_reorder(text, value)) %>%
  ggplot( aes(x=value, color=text, fill=text)) +
  geom_histogram(alpha=0.6, binwidth = 1) +
  scale_fill_viridis(discrete=TRUE) +
  scale_color_viridis(discrete=TRUE) +
  facet_wrap(~text)
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

