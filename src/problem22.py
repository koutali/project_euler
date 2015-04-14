'''
Created on Jan 19, 2013

@author: senem
'''

def createFileList(file_name):
    names = []
    
    file_content =""
    fileToReadFrom = open(file_name, 'r')
    file_content = fileToReadFrom.read()
    fileToReadFrom.close()
    
    file_content = file_content.replace("\"", "")
    file_content = file_content.split(",")
    
    for name in file_content:
        names.append(name)
    
    names.sort(cmp=None, key=None, reverse=False)
    return names
    
alphabet = {"a":1, "b":2, "c":3, "d":4, "e":5, "f": 6, "g": 7, "h":8, "i":9,
        "j":10, "k":11, "l":12, "m":13, "n":14, "o":15, "p":16,"q":17, "r":18,
        "s":19, "t":20, "u":21, "v":22, "w":23, "x":24, "y":25, "z":26}

def getNameValue(name, index):
    value = 0
    for ch in name:
        value += alphabet[ch.lower()]
    
    index += 1
    value *= index
    return value

if __name__ == '__main__':
    names = createFileList("names.txt")
    total_value = 0
    
    i = 0
    for name in names:
        total_value += getNameValue(name, i)
        i += 1
        
    print(total_value)