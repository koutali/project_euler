'''
Created on 31 Oca 2013

@author: tr1u4323
'''

import math

def convertStringToInteger(string):
    integer = 0
    try:
        integer = int(string)
    except ValueError:
        integer = -1
    
    return integer

def getNumberArray(number):
    numberString = str(number)
    numberArray = []
    for ch in numberString:
        numberArray.append(convertStringToInteger(ch))
    
    return numberArray

def isNumberSumOfDigitFactorials(number):
    numberArray = getNumberArray(number)
    
    sumOfDigitFactorials = 0
    for digit in numberArray:
        sumOfDigitFactorials += round(math.factorial(digit))
    
    return sumOfDigitFactorials == number

if __name__ == '__main__':
    
    sumOfAllMatchingNumbers = 0
    for i in range(3, 500000):
        if isNumberSumOfDigitFactorials(i):
            print(i, "is equal to sum of its digit factorials")
            sumOfAllMatchingNumbers += i
    
    print("Sum of all matching numbers: ", sumOfAllMatchingNumbers)
    pass