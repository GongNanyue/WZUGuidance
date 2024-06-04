def rev(s):
    return s[::-1]

def add(s1, s2):
    carry = 0
    result = ""
    for i in range(len(s1)-1, -1, -1):
        digit_sum = int(s1[i]) + int(s2[i]) + carry
        result = str(digit_sum % 10) + result
        carry = digit_sum // 10
    if carry > 0:
        result = "1" + result
    return result

s = input()
if s == rev(s):
    print(s, "is a palindromic number.")
else:
    n = 10
    while n > 0:
        sum_ = add(s, rev(s))
        print(s, "+", rev(s), "=", sum_)
        if sum_ == rev(sum_):
            print(sum_, "is a palindromic number.")
            break
        s = sum_
        n -= 1
    else:
        print("Not found in 10 iterations.")
