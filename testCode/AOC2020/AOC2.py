
import re

def processLine(line):
    line = line.split(' ')
    numbers = re.findall(r'\d+', line[0])
    letter = line[1]
    letter = letter[0]
    password = line[2]
    count = 0
    for curr_letter in password:
        if letter == curr_letter:
            count += 1
    if count < int(numbers[0]) or count > int(numbers[1]):
         return False
    else:
         return True

number = 0
count = 0
with open('passwords.txt') as fp:
    line = fp.readline()
    while line:
        if processLine(line):
            number += 1
        count += 1
        if(count % 10 == 0):
            print(count/10)
        line = fp.readline()

print('Result: ', number)