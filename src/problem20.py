'''
Created on 21 Oca 2013

@author: tr1u4323
'''
import math

def getNumberFromString(string):
    return int(float(string))

if __name__ == '__main__':
    string = str(math.factorial(100))
    summed = 0
    for ch in string:
        summed += getNumberFromString(ch)
        
    print(summed)