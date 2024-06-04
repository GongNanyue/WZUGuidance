def is_float(s):
    try:
        float(s)
        return True
    except ValueError:
        return False


def too_long(s: str):
    idx = s.find('.')
    if idx != -1:
        if len(s) - idx > 3:
            return True
    return False


n = int(input())
a = input().split()
sum = 0
count = 0
for i in a:
    if not is_float(i) or too_long(i) or float(i) < -1000 or float(i) > 1000:
        print("ERROR: %s is not a legal number" % i)
    else:
        sum += float(i)
        count += 1
if count == 0:
    print("The average of 0 numbers is Undefined")
elif count == 1:
    print("The average of 1 number is %.2f" % sum)
else:
    print("The average of %d numbers is %.2f" % (count, sum / count))
