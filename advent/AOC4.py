
import re

def data_validation(code, line):
    line = re.split(':| ', line)
    if code == 'byr':
        index = line.index(code)
        data = line[index + 1]
        year = int(data)
        if year >= 1920 and year <= 2002:
            return 1
    if code == 'iyr':
        index = line.index(code)
        data = line[index + 1]
        year = int(data)
        if year >= 2010 and year <= 2020:
            return 1
    if code == 'eyr':
        index = line.index(code)
        data = line[index + 1]
        year = int(data)
        if year >= 2020 and year <= 2030:
            return 1
    if code == 'hgt':
        index = line.index(code)
        data = line[index + 1]
        unit = re.search('cm|in', data)
        if unit is not None and unit.group(0) == 'cm':
            value = re.search(r'\d+', data)
            print(value.group(0))
            if value is not None and int(value.group(0)) >= 150 and int(value.group(0)) <= 193:
                return 1
        else:
            value = re.search(r'\d+', data)
            print(value.group(0))
            if value is not None and int(value.group(0)) >= 59 and int(value.group(0)) <= 76:
                return 1
    if code == 'hcl':
        index = line.index(code)
        data = line[index + 1]
        result = re.search('#[a-z0-9]{6}', data)
        if result is not None:
            return 1
    if code == 'ecl':
        colors = ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']
        index = line.index(code)
        data = line[index + 1]
        if data in colors:
            return 1
    if code == 'pid':
        index = line.index(code)
        data = line[index + 1]
        result = re.search('[0-9]{9}', data)
        if result is not None:
            return 1
    return 0



codes = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid', 'cid']
confirm = [0,0,0,0,0,0,0,0]
count = 0
with open('input4.txt') as fp:
    line = fp.readline()
    while line:
        while line.strip() != '':
            tempLine = re.split(':| ', line)
            for i in range(0, 8):
                if codes[i] in tempLine:
                    confirm[i] = data_validation(codes[i], line)
            line = fp.readline()
        will_count = True
        for i in range(0, 7):
            if confirm[i] == 1:
                continue
            else:
                will_count = False
        if will_count:
            count += 1
        confirm = [0,0,0,0,0,0,0,0]
        will_count = True
        line = fp.readline()
    print('#Valid bis: ', count)


# byr (Birth Year) - four digits; at least 1920 and at most 2002.
# iyr (Issue Year) - four digits; at least 2010 and at most 2020.
# eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
# hgt (Height) - a number followed by either cm or in:
#   If cm, the number must be at least 150 and at most 193.
#   If in, the number must be at least 59 and at most 76.
# hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
# ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
# pid (Passport ID) - a nine-digit number, including leading zeroes.
# cid (Country ID) - ignored, missing or not.
      
