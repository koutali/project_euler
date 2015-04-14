'''
Created on 18 Oca 2013

@author: tr1u4323
'''
def isEven(number):
    return (number % 2) == 0

def collatzConjecture(number):
    numberOfIterations = 1
            
    while number > 1:        
        if isEven(number):
            number /= 2
        else:
            number = 3*number + 1
            
        numberOfIterations += 1
        
    return numberOfIterations

class CollatzPair:
    def __init__(self, num, collatz):
        self.num = num
        self.collatz = collatz

if __name__ == '__main__':
    iterations = []
    i = 1000000
    while i > 1:
        pair = CollatzPair(i, collatzConjecture(i))
        iterations.append(pair)
        i -= 1
     
    iterations.sort(key=lambda x: x.collatz, reverse=True)   
    print(iterations[0].num)