'''
Created on 17 Oca 2013

@author: tr1u4323
'''

def primes_sieve1(limit):
    limitn = limit+1
    primes = dict()
    for i in range(2, limitn): primes[i] = True

    for i in primes:
        factors = range(i,limitn, i)
        for f in factors[1:]:
            primes[f] = False
    return [i for i in primes if primes[i]==True]

if __name__ == '__main__':
    print (primes_sieve1(1000000))