'''
Created on 17 Oca 2013

@author: tr1u4323
'''

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
    primes = []
    
    prime = 1
    while len(primes) < 10001:
        prime = getNextPrime(prime)
        primes.append(prime)
        
        primes.sort(key=None, reverse=False)
    
    print(primes)