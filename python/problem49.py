'''
Created on 28 Oca 2013

@author: tr1u4323
'''

import random
import math

def primes_sieve1(limit):
    limitn = limit
    primes = dict()
    for i in range(2, limitn): primes[i] = True

    for i in primes:
        factors = range(i,limitn, i)
        for f in factors[1:]:
            primes[f] = False
    return [i for i in primes if primes[i]==True]

def convertStringToInteger(string):
    integer = 0
    try:
        integer = int(string)
    except ValueError:
        integer = -1
    
    return integer
    
def getNumbersAsArray(number):
    string = str(number)
    numberAsArray = []
    for ch in string:
        numberAsArray.append(ch)
    
    return numberAsArray

def getPermutationCount(listToPermutate):
    listToPermutate.sort()
    
    numbersAndRepetitions = {}
    
    for i in range(0, len(listToPermutate)):
        repetitionCount = 1
        for j in range(i+1, len(listToPermutate)):
            if listToPermutate[i] == listToPermutate[j]:
                repetitionCount += 1
        
        if listToPermutate[i] not in numbersAndRepetitions:
            numbersAndRepetitions[listToPermutate[i]] = repetitionCount
    
    permutationCountDenominator = 1
    for repetitionCount in numbersAndRepetitions.values():
        permutationCountDenominator *= math.factorial(repetitionCount)
        
    permutationCountNominator = math.factorial(len(listToPermutate))
    return permutationCountNominator // permutationCountDenominator

def getValidPermutation(number):
    numberAsArray = getNumbersAsArray(number)

    shuffled = []
    copyList = list(numberAsArray) 
    
    while len(shuffled) < getPermutationCount(numberAsArray):
        random.shuffle(copyList)
        shuffledString = "".join(copyList)
        toAppend = convertStringToInteger(shuffledString)
        
        if toAppend not in shuffled:
            shuffled.append(toAppend)
    
    shuffled.sort(key=None, reverse=False)
    return shuffled 
    
if __name__ == '__main__':        
    allPrimes = primes_sieve1(10000)
    primes = [prime for prime in allPrimes if prime > 1000]
    
    for prime in primes:
        matchingPermutations = []
        permutations = getValidPermutation(prime)
        
        matches = 0
        for permutation in permutations:
            if permutation in primes:
                matches += 1
                matchingPermutations.append(permutation) 
        
        for match in matchingPermutations:
            for otherMatch in matchingPermutations:
                if match == otherMatch:
                    continue
                else:
                    diff = abs(otherMatch - match)
                    if match > otherMatch:
                        temp = match + diff
                    else:
                        temp = otherMatch + diff
                    
                    if temp in matchingPermutations:
                        print("Match: ", match, otherMatch, temp)
                        
#        if matches >= 3:
#            print("Prime: ", prime)
#            matchingPermutations.sort(key=None, reverse=False)
#            print("Matching permutations: ", matchingPermutations)