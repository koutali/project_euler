'''
Created on 06 Feb 2013

@author: tr1u4323
'''

def getNthPowerOfTen(n):
    product = 1
    for i in range(1,n+1):
        product *= 10
        
    return product

if __name__ == '__main__':
    for i in range(3, 1000):
        remainders = []
        
        nThPower = 0
        repeteadNTimes = 0
        calculate = True
        
        while calculate:
            power = getNthPowerOfTen(nThPower)
            newRemainder = power % i
            
            # divisible: no repetition
            if newRemainder == 0:
                repeteadNTimes = 0
                break
            else:
                # not divisible - check for period
                for remainder in remainders:
                    if newRemainder == remainder:
                        calculate = False
                        break
                
                if calculate:
                    repeteadNTimes += 1    
                    remainders.append(newRemainder)
                    nThPower += 1
                    
        print("Number ", i, " repeated ", repeteadNTimes, " times")        
        