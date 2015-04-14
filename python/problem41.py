'''
Created on 06 Feb 2013

@author: tr1u4323
'''
def convertStringToInteger(string):
    integer = 0
    try:
        integer = int(string)
    except ValueError:
        integer = -1
    
    return integer

def getNumberAsArray(number):
    string = str(number)
    numList = []
    for ch in string:
        numList.append(convertStringToInteger(ch))
    
    return numList

def primeSieve(limit):
    limitn = limit
    primes = dict()
    for i in range(2, limitn): primes[i] = True

    for i in primes:
        factors = range(i,limitn, i)
        for f in factors[1:]:
            primes[f] = False
    return [i for i in primes if primes[i]==True]

def isPandigital(n):
    nAsArray = getNumberAsArray(n)
    integers = [x for x in range(1, len(nAsArray) + 1)]
    
    intersection = set(nAsArray) & set(integers)
    return len(intersection) == len(nAsArray)

if __name__ == '__main__':
    
    print("Generating primes list")
        
    primes = primeSieve(10000000)
    primes.reverse()
    
    print("Done!")
        
    for prime in primes:
        if isPandigital(prime):
            print("Largest pandigital prime: ", prime)
            break
        else:
            print("Skipping ", prime)