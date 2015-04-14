'''
Created on Jan 16, 2013

@author: senem
'''
def FibonacciSum(nNumber):
    c = 0 
    first = 0
    second = 1
    nextT = 0
    
    sumFibonacci = 0
    
    for c in range(nNumber):
        if c <= 1:
            nextT = c
        else:
            nextT = first + second
            first = second
            second = nextT
        
        if nextT >= 4000000:
            break
        else:
            if (nextT % 2) == 0:
                sumFibonacci += nextT
                
    return sumFibonacci

if __name__ == '__main__':
    print(FibonacciSum(50))