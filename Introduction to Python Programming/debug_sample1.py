def min_2(x, y):
    if x < y:

        r = x
    else:

        r = y
    return r

def min_3(x, y, z):

    m = min_2(x, y)

    n = min_2(y, z)
    return min_2(m, n)


a = 1
b = 2
c = 3
min_num = min_3(a, b, c)
print('a={} b={} c={}'.format(a, b, c))
print('最小の数は{}です'.format(min_num))