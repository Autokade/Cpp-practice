options_vector<-c("succ", "fail")
probabilities <-c(0.9, 0.1)
sample_result<-sample(options_vector, size = 10, replace = TRUE, prob= probabilities)

print(sample_result)