'''
Created on 24 Oca 2013

@author: tr1u4323
'''
import math

if __name__ == '__main__':
    powers= []
    
    for a in range(2, 101):
        for b in range(2, 101):
            result = math.pow(a, b)
            if result not in powers:
                powers.append(result)
    
    print(len(powers))