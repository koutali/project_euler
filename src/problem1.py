'''
Created on Jan 16, 2013

@author: senem
'''

def getSum(upperLimit, dividend):
    retSum = 0
    
    for i in range(upperLimit):
        if i < dividend:
            continue
        else:
            if (i % dividend) == 0:
                print(dividend, i)
                retSum += i
                
    return retSum

if __name__ == '__main__':
    retSum = getSum(1000, 3)
    retSum += getSum(1000, 5)
    retSum -= getSum(1000, 15)
    print("Result: ", retSum)