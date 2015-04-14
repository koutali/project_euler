'''
Created on 24 Oca 2013

@author: tr1u4323
'''

def getDivisors(number):
    divisors = []
    limit = (number//2) + 1
    for i in range(1, limit):
        if number % i == 0:
            divisors.append(i)
    #print(divisors)
    return divisors

def getAmigo(number):
    return sum(getDivisors(number))

if __name__ == '__main__':
    amigos = []
    for i in range(1, 10001):
        amigo1 = getAmigo(i)
        amigo2 = getAmigo(amigo1)
        
        if i != amigo1 and amigo2 == i:
            if i not in amigos and amigo1 not in amigos:
                amigos.append(i)
                amigos.append(amigo1)
                
    print(amigos)
    print(sum(amigos))