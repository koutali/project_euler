'''
Created on 31 Oca 2013

@author: tr1u4323
'''
import math

def getThirdLength(a, b):
    x = math.pow(a, 2) + math.pow(b, 2)
    return math.sqrt(x)

if __name__ == '__main__':
    
    for i in range(3, 1000):
        perimeter = i
        
        lists = {}
        matches = 0
        for a in range(1, perimeter):
            for b in range(1, perimeter - a):           
                c = perimeter - (a+b)
                calculatedC = getThirdLength(a,b)
                
                if calculatedC - c == 0:
                    matches += 1
                else:
                    continue

        if matches > 0:
            print("Number of matches for perimeter ", perimeter, " are: ", matches)      
            lists[perimeter] = matches
    
    print(lists)