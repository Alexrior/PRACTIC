s = input() + " "
a = b = c = 0
tmp = ""
count = 0

for char in s:
    if char != " ":
        tmp += char
    else:
        if tmp != "":
            num = int(tmp)
            if count == 0: a = num
            elif count == 1: b = num
            else: c = num
            tmp = ""
            count += 1
if (b <= a <= c) or (c <= a <= b):
    print(a)
elif (a <= b <= c) or (c <= b <= a):
    print(b)
else:
    print(c)