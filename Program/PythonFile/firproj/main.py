from sympy import *
# 定义符号变量
x = symbols('x')

# 计算 arctan(x) 的积分
integral_result = integrate(atan(x), x)

# 打印结果
print("The integral of arctan(x) is:", integral_result)
