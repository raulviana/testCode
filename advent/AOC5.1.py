
def getID(line):
    low = 0
    high = 127
    row = getRow(low, high, line)
    column = getColumn(line)
    return row * 8 + column

def getColumn(line):
    low = 0
    high = 7
    pos = -4
    while pos != -1:
        token = line[pos]
        if token == 'R':
            low = (low + high) // 2
            pos += 1
            if pos == -1: return high
        else:
            high = (low + high) // 2
            pos += 1
            if pos == -1: return low

def getRow(low, high, line):
    if line[0] == 'F':
        high = (low + high) // 2
        if len(line) == 5:
            res = high
            return res
        else:
            return getRow(low, high, line[1:])
    else:
        low = (low + high) // 2
        if len(line) == 5: 
            res = low
            return res
        else:
            return getRow(low, high, line[1:])


max = 0
count = 0
with open('input5.txt') as fp:
    line = fp.readline()
    while line:
        currID = getID(line)
        if max < currID:
            max = currID
        count += 1
        line = fp.readline()
        
    print('Highest seat ID: ', max)  
