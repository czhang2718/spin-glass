library(tidyverse)
library(hrbrthemes)
library(viridis)
library(forcats)
library(plotly)

for(i in 3:3){ # 1:5
  data <- read.table(paste0("https://raw.githubusercontent.com/czhang2718/spin-glass/main/combined", i, ".csv"), header=TRUE, sep=",")
  for(j in 18:23){
    plot <- plot_ly(x = data[[paste0("N", j)]], type = "histogram", nbinsx = 40) %>% layout(title = paste0("n=", j))
    saveWidget(plot, paste0("plots/c", i, "n", j, ".html"), selfcontained = F, libdir = "lib")
  }
}
plot

set.seed(123)

df <- data.frame(x <- rchisq(1000, 5, 10),
                 group <-  sample(LETTERS[1:5], size = 1000, replace = T))

p <- ggplot(df, aes(x)) + 
  geom_histogram(aes(y = ..density..), alpha = 0.7, fill = "#333333") + 
  geom_density(fill = "#ff4d4d", alpha = 0.5) +
  theme(panel.background = element_rect(fill = '#ffffff')) +
  ggtitle(paste("n=", j))

fig <- ggplotly(p)

fig
