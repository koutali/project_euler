'''
Created on 28 Oca 2013

@author: tr1u4323
'''

import math

def primeSieve(limit):
    limitn = limit
    primes = dict()
    for i in range(2, limitn): primes[i] = True

    for i in primes:
        factors = range(i,limitn, i)
        for f in factors[1:]:
            primes[f] = False
    return [i for i in primes if primes[i]==True]

#def convertStringToInteger(string):
#    integer = 0
#    try:
#        integer = int(string)
#    except ValueError:
#        integer = -1
#    
#    return integer
#    
def getNumberAsArray(number):
    string = str(number)
    numList = []
    for ch in string:
        numList.append(ch)
    
    return len(numList)

#def getPermutationCount(listToPermutate):
#    listToPermutate.sort()
#    
#    numbersAndRepetitions = {}
#    
#    for i in range(0, len(listToPermutate)):
#        repetitionCount = 1
#        for j in range(i+1, len(listToPermutate)):
#            if listToPermutate[i] == listToPermutate[j]:
#                repetitionCount += 1
#        
#        if listToPermutate[i] not in numbersAndRepetitions:
#            numbersAndRepetitions[listToPermutate[i]] = repetitionCount
#    
#    permutationCountDenominator = 1
#    for repetitionCount in numbersAndRepetitions.values():
#        permutationCountDenominator *= math.factorial(repetitionCount)
#        
#    permutationCountNominator = math.factorial(len(listToPermutate))
#    return permutationCountNominator // permutationCountDenominator

def getValidPermutation(number, primes):
    
    permutations = []
    permutations.append(number)
    for i in range(0, getNumberAsArray(number)):
        toAppend = number
        
        if toAppend not in permutations:
            if toAppend in primes:
                permutations.append(toAppend)
            else:
                permutations = []
                break
    
    return permutations 
    
if __name__ == '__main__':
    
    print("Calculating primes")
    primes = primeSieve(1000)
    
#    permutations = []
#    for prime in primes:
#        toPrint = "Calculating permutations for " + str(prime)
#        print(toPrint)
#        
#        permutations += getValidPermutation(prime, primes)
#        matches = 0
#                    
#    print("Eliminating duplicates")
#    permutations = list(set(permutations)) 
#    
#    print("Sorting ascending")  
#    permutations.sort(key=None, reverse=False)
#                    
#    print("Matching permutations: ", permutations)
#    print("Length of finalized list: ", len(permutations))
    
    print(getValidPermutation(197, primes))

#    print(getValidPermutation(2))
#    print(getValidPermutation(11))
#    print(getValidPermutation(123))
#    print(getValidPermutation(1123))
#    print(getValidPermutation(1122))