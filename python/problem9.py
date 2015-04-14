'''
Created on 17 Oca 2013

@author: tr1u4323
'''
import math

def getPythagorianTriplet():
    result = 0
        
    a = 0
    b = 0
    c = 0
    for n in range(1, 100):
        for m in range(n + 1, 100):
            a = math.pow(m, 2) - math.pow(n, 2)
            b = 2 * m * n
            c = math.pow(m, 2) + math.pow(n, 2)
            
            if (a + b + c) == 1000:
                print(a, b, c)
                result = a*b*c
    
    return result

if __name__ == '__main__':
    print(getPythagorianTriplet())