'''
Created on 24 Oca 2013

@author: tr1u4323
'''

def getListOfDivisors(number):
    divisors = []
    limit = (number // 2) + 1
    
    for i in range(1, limit):
        if number % i == 0:
            divisors.append(i)
    
    return divisors

def getSumOfDivisors(number):
    return sum(getListOfDivisors(number))

def isNumberAbundant(number):
    return number < getSumOfDivisors(number)
    
def findAllAbundantNumbersToLimit(limit):
    print("Finding all abundant numbers")
    
    abundantNumbers = []
    for i in range(2, limit):
        if isNumberAbundant(i):
            abundantNumbers.append(i)
        
    return abundantNumbers  

if __name__ == '__main__':
    abundantNumbers = findAllAbundantNumbersToLimit(30000)
    print("Abundant numbers: ", abundantNumbers)
    print("Abundant length: ", len(abundantNumbers))
    
    allNumbers = [i for i in range(1, 30000)]
    
    symDif = set(allNumbers).symmetric_difference(set(abundantNumbers))
    
    for each in abundantNumbers:
        for eachOther in abundantNumbers:
            sumOfNumbers = each + eachOther
            if sumOfNumbers in symDif:
                symDif.remove(sumOfNumbers)
    
    print("Symmetric difference: ", symDif)
    print("Symmetric difference length: ", len(symDif))
    
    print("Sum of symmetric differences: ", sum(symDif))
    print("Execution complete")
    
    
    