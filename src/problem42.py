'''
Created on 25 Oca 2013

@author: tr1u4323
'''
import math

def createFileList(file_name):
    names = []
    
    file_content = ""
    fileToReadFrom = open(file_name, 'r')
    file_content = fileToReadFrom.read()
    fileToReadFrom.close()
    
    file_content = file_content.replace("\"", "")
    file_content = file_content.split(",")
    
    for name in file_content:
        names.append(name)
    
    return names
    
alphabet = {"a":1, "b":2, "c":3, "d":4, "e":5, "f": 6, "g": 7, "h":8, "i":9,
        "j":10, "k":11, "l":12, "m":13, "n":14, "o":15, "p":16,"q":17, "r":18,
        "s":19, "t":20, "u":21, "v":22, "w":23, "x":24, "y":25, "z":26}

def getNameValue(name):
    value = 0
    for ch in name:
        value += alphabet[ch.lower()]
    
    return value

def isNumberTriangular(value):
    b = 1
    a = 2
    c = (-1) * value
    
    determinant = math.pow(b, 2) - 4*a*c   
    solution = ((-1) * b + math.sqrt(determinant)) / (2 * a)
    delta1 = abs(solution - round(solution))
    
    solution = ((-1) * b - math.sqrt(determinant)) / (2 * a)
    delta2 = abs(solution - round(solution))
    
    return not (delta1 > 0 and delta2 > 0)

def listTriangulars(limit):
    triangulars = []
    for i in range(0, limit):
        num = 2*i*i + i
        triangulars.append(num)
    
    return triangulars

if __name__ == '__main__':
    names = createFileList("words.txt")
    
    triangularCount = 0
    for each_name in names:
        value = getNameValue(each_name)
        if isNumberTriangular(value):
            triangularCount += 1
        
    print("Triangular count: ", triangularCount)