def rearrange_to_minimize(integer):
    # 将正整数的每一位数字提取出来
    digits = [int(digit) for digit in str(integer)]

    # 对数字进行排序
    sorted_digits = sorted(digits)

    # 组合排序后的数字，形成新的正整数
    result = int(''.join(map(str, sorted_digits)))

    return result


# 例子
original_integer = 7382900000100
result_integer = rearrange_to_minimize(original_integer)

print(f"原始正整数: {original_integer}")
print(f"重排后的正整数: {result_integer}")
