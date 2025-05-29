# # i = 1
# # while i <= 10:
# #     print("夏休み！")
# #     i = i + 1

# # for i in range(10):
# #     print('夏休み！')

# # money = 10000
# # while money > 0:
# #     price = int(input('商品の値段：'))
# #     print(price,'値段購入')
# #     if money >= price:
# #         money = money - price
# #         print(money,'円残ってます')
# #     else:
# #         print('お金が足りません')
# # print('買い物終了')


# height = 1.78
# weight = 75
# while True:
#     bmi = weight/(height*height)
#     print(weight, bmi)
#     weight = weight-1
#     if bmi <= 22:
#         break


x = 10
s1 = 0
s2 = 5
while x < 100:
    if x >= 50:
        s1 += x
    else:
        s2 += x 
    x += 10
print(s1)
print(s2)