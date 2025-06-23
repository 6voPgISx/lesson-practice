# 画像=[[1, 1, 1, 0, 1],
#     [1, 1, 0, 0, 1],
#     [1, 0, 1, 0, 1],
#     [0, 0, 0, 0, 0],
#     [1, 1, 1, 0, 1]]
# # 画像を表示する
# line = '' # 横一行文の□と■
# for 画素列 in 画像: # 画像列には画像のサブリスト(例えば、[1, 1, 1, 0, 1])
#     for 画素 in 画素列: # 画素には、1とか0が取り出される
#         if 画素 == 1:
#             print('□', end='')
#         else:
#             print('■', end='')
#     print('')

# name_point = [
#     ['Mr.A', 58, 80, 72], ['Mr.B', 81, 75, 82],
#     ['Mr.C', 97, 90, 69], ['Mr.D', 30, 48, 96]
# ]

# EML_sum = [0, 0, 0]
# for na_po in name_point:
#     EML_sum[0] = EML_sum[0] + na_po[1]
#     EML_sum[1] = EML_sum[1] + na_po[2]
#     EML_sum[2] = EML_sum[2] + na_po[3]
# for point in EML_sum:
#     print(point/len(name_point))

test = [['A', 70, 83],['B', 41, 90],['C', 67, 50], ['D', 61, 60]]
for i in range(len(test)):
    sum = test[i][1] + test[i][2]
    if  sum < 120:
        print(test[i][0])