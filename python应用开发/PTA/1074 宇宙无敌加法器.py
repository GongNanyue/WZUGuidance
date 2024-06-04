def pat_addition(radix, num1, num2):
    radix = list(map(int, radix[::-1]))
    num1 = list(map(int, num1[::-1]))
    num2 = list(map(int, num2[::-1]))

    len_diff = len(num1) - len(num2)
    if len_diff > 0:
        num2.extend([0]*len_diff)
    elif len_diff < 0:
        num1.extend([0]*(-len_diff))

    result = []
    carry = 0
    for i in range(len(num1)):
        temp = num1[i] + num2[i] + carry
        if radix[i] == 0:
            radix[i] = 10
        carry, temp = divmod(temp, radix[i])
        result.append(temp)

    if carry != 0:
        result.append(carry)

    while len(result) > 1 and result[-1] == 0:
        result.pop()
    return ''.join(map(str, result[::-1]))

radix = input().strip()
num1 = input().strip()
num2 = input().strip()
print(pat_addition(radix, num1, num2))
