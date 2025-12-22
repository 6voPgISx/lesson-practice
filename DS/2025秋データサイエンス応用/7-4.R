data <- read.csv("data/7-4.csv")
str(data)
set.seed(123)
index_num <- sample(seq_len(nrow(data)), size = 0.7 * nrow(data))
train_data <- data[index_num, ]
test_data <- data[-index_num, ]
table(train_data$is_canceled)
data_logistic <- glm(is_canceled ~ ., data = train_data, family = binomial(link= "logit"))
summary(data_logistic)
data_logistic2 <- glm(
    is_canceled ~ lead_time +
        previous_cancellations +
        previous_bookings_not_canceled +
        adr +
        total_of_special_requests +
        meal_HB,
    data = train_data,
    family = binomial(link = "logit")
)
summary(data_logistic2)

library(glmnet)
library(tidyverse)
