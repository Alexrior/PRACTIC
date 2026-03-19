s = input()
c = 0

for x in s:
    if x == '0':
        c += 1
    elif x == '1':
        c -= 1

if c == 0:
    print('yes')
else:
    print('no')