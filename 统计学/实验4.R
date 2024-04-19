# 导入数据
times <- c(3.3,3.1,6.2,5.8,2.3,4.1,5.4,4.5,3.2,4.4,2.0,5.4,2.6,6.4,1.8,3.5,5.7,
           2.3,2.1,1.9,1.2,5.1,4.3,4.2,3.6,0.8,1.5,4.7,1.4,1.2,2.9,3.5,2.4,0.5,
           3.6,2.5)

# 计算样本均值
mean_time <- mean(times)

# 计算标准差
std_dev <- sd(times)  

# 计算样本量
n <- length(times)

# 90% 置信区间
alpha <- 0.1
z_value <- qnorm(1 - alpha/2)
margin_error <- z_value * std_dev / sqrt(n)
lower_bound <- mean_time - margin_error
upper_bound <- mean_time + margin_error
cat("90% 置信区间为: [", lower_bound, ",", upper_bound, "]\n\n")

# 95% 置信区间 
alpha <- 0.05
z_value <- qnorm(1 - alpha/2)
margin_error <- z_value * std_dev / sqrt(n)
lower_bound <- mean_time - margin_error
upper_bound <- mean_time + margin_error
cat("95% 置信区间为: [", lower_bound, ",", upper_bound, "]\n\n") 

# 99% 置信区间
alpha <- 0.01  
z_value <- qnorm(1 - alpha/2)
margin_error <- z_value * std_dev / sqrt(n)
lower_bound <- mean_time - margin_error
upper_bound <- mean_time + margin_error
cat("99% 置信区间为: [", lower_bound, ",", upper_bound, "]")





# 导入数据
data <- c(16.4,17.1,17.0,15.6,16.2,14.8,16.0,15.6,17.3,17.4,15.6,15.7,17.2,16.6,
          16.0,15.3,15.4,16.0,15.8,17.2,14.6,15.5,14.9,17.7,16.3)

# 计算样本均值
mean_value <- mean(data)  

# 计算标准差
std_dev <- sd(data)

# 计算样本量  
n <- length(data) 

# 99% 置信区间
alpha <- 0.01
z_value <- qnorm(1 - alpha/2)  
margin_error <- z_value * std_dev / sqrt(n)
lower_bound <- mean_value - margin_error
upper_bound <- mean_value + margin_error

cat("总体均值的 99% 置信区间为: [", lower_bound, ",", upper_bound, "]")





# 导入数据
wait_time1 <- c(6.5,6.6,6.7,6.8,7.1,7.3,7.4,7.7,7.7,7.7)
wait_time2 <- c(4.2,5.4,5.8,6.2,6.7,7.7,7.7,8.5,9.3,10.0)

# 定义方差区间估计函数
variance.test <- function(x, conf.level=0.95) {
  alpha <- 1 - conf.level
  n <- length(x)
  S2 <- var(x)
  df <- n - 1
  chisq_left <- qchisq(alpha/2, df)
  chisq_right <- qchisq(1 - alpha/2, df)
  lower <- (n - 1) * S2 / chisq_right
  upper <- (n - 1) * S2 / chisq_left
  c(lower, upper)
}

# (1) 构建第一种排队方式等待时间方差的95%置信区间
res1 <- variance.test(wait_time1, 0.95)
cat("第一种排队方式等待时间方差的 95% 置信区间为: [", res1[1], ",", res1[2], "]\n\n")

# (2) 构建第二种排队方式等待时间方差的95%置信区间
res2 <- variance.test(wait_time2, 0.95) 
cat("第二种排队方式等待时间方差的 95% 置信区间为: [", res2[1], ",", res2[2], "]\n\n")

# (3) 根据结果,哪种排队方式更好?
if (res1[2] < res2[1]) {
  cat("根据方差区间估计结果,第一种排队方式等待时间方差更小,因此第一种排队方式更好。")
} else if (res2[2] < res1[1]) {
  cat("根据方差区间估计结果,第二种排队方式等待时间方差更小,因此第二种排队方式更好。")  
} else {
  cat("根据方差区间估计结果,两种排队方式等待时间方差没有显著差异。")
}









# 导入数据
method1 <- c(78,63,72,89,91,49,68,76,85,55)
method2 <- c(71,44,61,84,74,51,55,60,77,39)

# 计算两组平均值
mean1 <- mean(method1)
mean2 <- mean(method2)

# 计算两组标准差
std_dev1 <- sd(method1)
std_dev2 <- sd(method2)

# 计算样本量
n1 <- length(method1)
n2 <- length(method2)

# 计算差值的标准差
std_error <- sqrt(std_dev1^2/n1 + std_dev2^2/n2)

# 构建95%置信区间
alpha <- 0.05
z_value <- qnorm(1 - alpha/2)
margin_error <- z_value * std_error
lower_bound <- mean1 - mean2 - margin_error
upper_bound <- mean1 - mean2 + margin_error

cat("两种方法平均自信心分数之差的 95% 置信区间为: [", lower_bound, ",", upper_bound, "]")






# 导入数据
machine1 <- c(3.45,3.22,3.9,3.2,2.98,3.7,3.22,3.75,3.28,3.5,3.38,3.55,2.95,3.45,
              3.2,3.16,3.48,3.12,3.2,3.18,3.25)
machine2 <- c(3.22,3.28,3.35,3.38,3.19,3.3,3.3,3.2,3.05,3.3,3.29,3.33,3.34,3.35,
              3.27,3.28,3.16,3.28,3.3,3.34,3.25)

# 计算样本方差
var1 <- var(machine1)
var2 <- var(machine2)

# 计算自由度
n1 <- length(machine1)
n2 <- length(machine2)
df1 <- n1 - 1
df2 <- n2 - 1

# 构造F统计量的分位数
alpha <- 0.05
f_lower <- qf(alpha/2, df1, df2)
f_upper <- qf(1-alpha/2, df1, df2)

# 构造置信区间
lower_bound <- var1 / (var2 * f_upper)
upper_bound <- var1 / (var2 * f_lower)

cat("两个总体方差比的 95% 置信区间为: [", lower_bound, ",", upper_bound, "]")
