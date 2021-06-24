# prettier, can set # bins
library(tidyverse)
library(hrbrthemes)

# hist(data)
# mean(dat)
# var(dat)

data <- scan("data19.1.txt")
df <- data.frame(y=data)

p <- df %>%
  # filter( y<50 ) %>%
  ggplot( aes(x=y)) +
  geom_histogram(binwidth=5) +
  theme_ipsum() +
  labs(title="N=15", x="E") +
  theme(
    plot.title = element_text(size=10)
  )
p