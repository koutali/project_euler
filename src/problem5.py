'''
Created on 17 Oca 2013

@author: tr1u4323
'''

def getSmallestDivisibleNumber(upperLimit):
    number = 223092870
    
    while True:
        hits = 0
            
        for i in range(1, upperLimit + 1):
            if (number % i) != 0:
                break
            else:
                hits += 1
        
        if hits == upperLimit:
            break
        else:
            number += 1
    
    return number

def isPrime(number):
    for i in range(2, number):
        if (number % i) == 0:
            return False

    return True

def getNextPrime(number):
    nextPrime = number

    while True:
        nextPrime += 1;
        if isPrime(nextPrime):
            break
        
    return nextPrime

if __name__ == '__main__':
    print(getSmallestDivisibleNumber(20))
    
    prime = 1
    result = 1
    while prime <= 20:
        prime = getNextPrime(prime)
        result *= prime
    
    print(result)
        