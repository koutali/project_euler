'''
Created on 17 Oca 2013

@author: tr1u4323
'''
import math

def sumOfSquares(upperLimit):
    summed = 0
    for i in range(1, upperLimit + 1):
        summed += (i *i)
    
    return summed

def squaredSum(upperLimit):
    summed = 0
    for i in range(1, upperLimit + 1):
        summed += i
        
    summed *= summed
    return summed

if __name__ == '__main__':
    difference = math.fabs(sumOfSquares(100) - squaredSum(100))
    print(difference)