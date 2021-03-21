
with open('input.txt') as fp:
    line = fp.readline()
    line = fp.readline()
    trees = 0
    size = len(line)
    position = 3
    while line:
        pointer = position % (size - 1)
        position += 3
        if line[pointer] == '#':
            trees += 1
        line = fp.readline()
       
print('#Trees: ', trees)

    