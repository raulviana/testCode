
from functools import reduce

with open('input.txt') as fp:
    line = fp.readline()
    line = fp.readline()
    trees = [0, 0, 0, 0, 0]
    size = len(line)
    initial_position = [1,3,5,7,1]
    position = [1, 3, 5, 7, 1]
    count = 1
    while line:
        for i in range(0, 5):
            if i == 4 and (count % 2 != 0):
                continue
            pointer = position[i] % (size - 1)
            position[i] += initial_position[i]
            if line[pointer] == '#':
                trees[i] += 1
        count += 1
        line = fp.readline()
print(trees)
res = reduce((lambda x, y: x*y), trees)
print('#Trees: ', res)