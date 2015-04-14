'''
Created on Jan 16, 2013
@author: senem
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

def getLargestPrimeDivisor(number):
    prime = 1
    largestPrime = 0
    while True:
        if number <= 1:
            largestPrime = prime
            break
        else:
            prime = getNextPrime(prime)
            if (number % prime) == 0:
                while True:
                    number /= prime
                    if(number % prime) != 0:
                        break
    
    return largestPrime     
                   
if __name__ == '__main__':
    print(getLargestPrimeDivisor(2520))