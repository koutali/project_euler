'''
Created on 17 Oca 2013

@author: tr1u4323
'''

def removePrimesFromBeginning(primes, biggestPrime, summed):
    for i in range(0, len(primes)):
        summed -= primes[i]
        if (summed <= biggestPrime):
            break
        
    return summed, i + 1

def sumOfPrimesStartingFromZeroIndex(primes, biggestPrime):
    summed = 0
    for i in range(0, len(primes)):
        summed += primes[i]
        
        if summed >= biggestPrime:
            break
        
    return summed, i + 1


def primes_sieve1(limit):
    limitn = limit
    primes = dict()
    for i in range(2, limitn): primes[i] = True

    for i in primes:
        factors = range(i,limitn, i)
        for f in factors[1:]:
            primes[f] = False
    return [i for i in primes if primes[i]==True]

if __name__ == '__main__':
    primes = primes_sieve1(1000000)
    
    indexPrime = -1
    biggestPrime = 0
    validPrimes = {}
    
    while indexPrime >= (-1)*(len(primes)):
        biggestPrime = primes[indexPrime]
    
        added = 0
        removed = 0
        
        summed, added = sumOfPrimesStartingFromZeroIndex(primes, biggestPrime)       
        if summed > biggestPrime:
            summed, removed = removePrimesFromBeginning(primes, biggestPrime, summed)
            
        if summed == biggestPrime:
            #if numberOfUsedNumbers > previousMaxUsedNumbers:
            validPrimes[biggestPrime] = added - removed
        
        indexPrime -=1
     
    validPrimes = sorted([(value,key) for (key,value) in validPrimes.items()])     
    print("Biggest prime: ", validPrimes[-1])