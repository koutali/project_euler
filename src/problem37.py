'''
Created on 31 Oca 2013

@author: tr1u4323
'''

def primes_sieve(limit):
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

def getModifiedNumber(number, fromStart):
    numberString = str(number)
    if fromStart:
        numberString = numberString[1:]
    else:
        numberString = numberString[:len(numberString)-1]
    
    return convertStringToInteger(numberString)

def areVariationsOfNumberPrime(number, primes):
        
    variationOfNumberIsPrime = True
    copyOfNumber = number
    
    # check from beginning
    while True:
        number = getModifiedNumber(number, True)
        if number <= 0:
            break
        
        if number not in primes:
            variationOfNumberIsPrime = False
            break
    
    if variationOfNumberIsPrime:
        number = copyOfNumber
        # check from end
        while True:
            number = getModifiedNumber(number, False)
            if number <= 0:
                break
        
            if number not in primes:
                variationOfNumberIsPrime = False
                break
        
        
    return variationOfNumberIsPrime

if __name__ == '__main__':
    
    primes = primes_sieve(1000000)
    print("All primes > 10: ", primes)
#    areVariationsOfNumberPrime(3797, primes)
#    
    numberOfMatches = 0
    sumOfAllMatchingNumbers = 0
    for each_prime in primes:
        if each_prime < 10:
            continue
        
        if numberOfMatches >= 11:
            break
        
        if areVariationsOfNumberPrime(each_prime, primes):
            print(each_prime, ": digits are also prime")
            numberOfMatches += 1
            sumOfAllMatchingNumbers += each_prime
            
    print("Sum of all matching numbers: ", sumOfAllMatchingNumbers)