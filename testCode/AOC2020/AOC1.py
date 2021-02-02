
numbers = []
with open('input.txt') as fp:
    line = fp.readline()
    while line:
        numbers.append(int(line))
        line = fp.readline()

for first in numbers:
    for second in numbers:
        for third in numbers:
            if (first + second + third) == 2020:
                print(first * second * third)