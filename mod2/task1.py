s = input()
i = 0
while s[i] != ',':
    i += 1
a = int(s[:i])
b = int(s[i + 1:])

print(a % b)