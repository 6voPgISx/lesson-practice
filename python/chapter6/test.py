# for x in [1,2,3]:
#     print(x)
# print('over')

# for x in range(4,5):
#     print(x)

# t = 0
# for c in range(1, 19):
#     if c % 5 != 0:
#         t += 3000
#     else:
#         t += 2700
# print(t)

t = 0
for x in range(1, 11):
    if 4 <= x <= 8:
        continue
    t += x
print(t)