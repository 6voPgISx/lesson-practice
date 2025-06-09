# words = ''
# for x in range(1, 10):
#     words = words + str(x) + '個'
#     if x % 3 == 0:
#         print(words + 'あります')
#         words = ''
# print('全部で10個あります')

# words = ''
# for x in range(10, 1, -1):
#     words = words + str(x) + '個'
#     if x % 3 == 2:
#         print(words + 'あります')
#         words = ''
# print('最後に1個あります')

! pip install ColabTurtlePlus
! pip install i4sect
from ColabTurtlePlus.Turtle import *
from i4sect import *
from math import * # 数学関数
clearscreen()
setup(500, 400)
発射台_x = -190
発射台_y = -130 # 発射台の位置が変更
bgcolor('black')

地面_y = -130
jumpto(-200, 地面_y)# 地面を描く
pencolor('white')
fd(400) # 地面を描く
標的_x = 160
jumpto(160, 地面_y) # 標的を描く
pencolor('yellow') # 標的を描く
pensize(10) # 標的を描く
fd(20) # 標的を描く(幅20)

jumpto(発射台_x, 発射台_y) # 発射台
角度 = int(input('角度: '))
速度 = int(input('速度: '))
                   
速度_x = 速度 * cos(radians(角度))
速度_y = 速度 * sin(radians(角度))
for t in range(100):
    x = 発射台_x + 速度_x * t
    y = 発射台_y + 速度_y*t-1/2* 4.9*t**2
    jumpto(x, y) # その場所に移動
    dot(10, 'white') # 点を描画する
    if y < 地面_y or x < -250 or 250 < x :
        break # 終了
    前の_x = x
    前の_y = y

交点 =intersect(x, y, 前の_x, 前の_y,-200, 地面_y, 200, 地面_y)
if 交点 == False:
    jumpto(0, 0)
    write('はずれ!')
else:
    jumpto(交点[0], 交点[1])
    dot(10, 'red')
    jumpto(0, 0)
    if 標的_x <= 交点[0] <= 標的_x + 20:
        write('当り!')
    else:
        write('はずれ!')