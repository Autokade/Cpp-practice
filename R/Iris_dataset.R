# Load the iris dataset and rename it dat
dat <- iris

# Print the first 6 observations
head(dat)


# Structure of the dataset
str(dat)


# Range of sepal length
rng <- range(dat$Sepal.Length)
rng


# Median of sepal length
median_sepal_length <- median(dat$Sepal.Length)
median_sepal_length


# First quartile of sepal length
first_quartile <- quantile(dat$Sepal.Length, 0.25)

# Third quartile of sepal length
third_quartile <- quantile(dat$Sepal.Length, 0.75)

# Interquartile range of sepal length
iqr_sepal_length <- IQR(dat$Sepal.Length)

first_quartile
third_quartile
iqr_sepal_length



# Standard deviation of sepal length
sd_sepal_length <- sd(dat$Sepal.Length)

# Variance of sepal length
var_sepal_length <- var(dat$Sepal.Length)

sd_sepal_length
var_sepal_length



# Mean, median, range, quartiles, IQR, standard deviation, and variance for sepal.width
mean(dat$Sepal.Width)
median(dat$Sepal.Width)
range(dat$Sepal.Width)
quantile(dat$Sepal.Width, 0.25)
quantile(dat$Sepal.Width, 0.75)
IQR(dat$Sepal.Width)
sd(dat$Sepal.Width)
var(dat$Sepal.Width)

# Mean, median, range, quartiles, IQR, standard deviation, and variance for petal.length
mean(dat$Petal.Length)
median(dat$Petal.Length)
range(dat$Petal.Length)
quantile(dat$Petal.Length, 0.25)
quantile(dat$Petal.Length, 0.75)
IQR(dat$Petal.Length)
sd(dat$Petal.Length)
var(dat$Petal.Length)

# Mean, median, range, quartiles, IQR, standard deviation, and variance for petal.width
mean(dat$Petal.Width)
median(dat$Petal.Width)
range(dat$Petal.Width)
quantile(dat$Petal.Width, 0.25)
quantile(dat$Petal.Width, 0.75)
IQR(dat$Petal.Width)
sd(dat$Petal.Width)
var(dat$Petal.Width)
