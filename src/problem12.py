'''
Created on Jan 17, 2013

@author: senem
'''

def getTriangularNumber(rank):
    triangularNumber = 0
    
    for i in range(1, rank):
        triangularNumber += i
        
    return triangularNumber

def getListOfTriangularNumbers(upperLimit):
    triangularNumbers = []
    
    for i in range(1, upperLimit):
        triangularNumbers.append(getTriangularNumber(i))
        
    return triangularNumbers

from math import sqrt


##############################################################
### cartesian product of lists ##################################
##############################################################

def appendEs2Sequences(sequences,es):
    result=[]
    if not sequences:
        for e in es:
            result.append([e])
    else:
        for e in es:
            result+=[seq+[e] for seq in sequences]
    return result


def cartesianproduct(lists):
    """
    given a list of lists,
    returns all the possible combinations taking one element from each list
    The list does not have to be of equal length
    """
    return reduce(appendEs2Sequences,lists,[])

##############################################################
### prime factors of a natural ##################################
##############################################################

def primefactors(n):
    '''lists prime factors, from greatest to smallest'''  
    i = 2
    while i<=sqrt(n):
        if n%i==0:
            l = primefactors(n/i)
            l.append(i)
            return l
        i+=1
    return [n]      # n is prime


##############################################################
### factorization of a natural ##################################
##############################################################

def factorGenerator(n):
    p = primefactors(n)
    factors={}
    for p1 in p:
        try:
            factors[p1]+=1
        except KeyError:
            factors[p1]=1
    return factors

def divisors(n):
    factors = factorGenerator(n)
    divisors=[]
    listexponents=[map(lambda x:k**x,range(0,factors[k]+1)) for k in factors.keys()]
    listfactors=cartesianproduct(listexponents)
    for f in listfactors:
        divisors.append(reduce(lambda x, y: x*y, f, 1))
    divisors.sort()
    return divisors

if __name__ == '__main__':
    i = 0
    divisorList = []
    triangularNumber = 1
    
    while len(divisorList) <= 501:
        triangularNumber = getTriangularNumber(i)
        divisorList = divisors(triangularNumber)
        i += 1
    
    print(len(divisorList))
    print(triangularNumber)
    print(divisorList)