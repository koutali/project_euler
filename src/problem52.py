'''
Created on 02 Feb 2013

@author: tr1u4323
'''

def modifiedNumberContainsSameDigits(number, multiplyBy):
    timesArray = getNumberAsArray(number * multiplyBy)
    numberArray = getNumberAsArray(number)
    intersection = set(timesArray) & set(numberArray)
    
    return len(intersection) == len(numberArray)

def convertStringToInteger(string):
    integer = 0
    try:
        integer = int(string)
    except ValueError:
        integer = -1
    
    return integer

def getNumberAsArray(number):
    string = str(number)
    numberAsArray = []
    for ch in string:
        integerCharacter = convertStringToInteger(ch)
        numberAsArray.append(integerCharacter)
    
    return numberAsArray

if __name__ == '__main__':
    matches = []
    
    for number in range(2, 125874):
        print("Checking: ", number)
        
        for multiplyBy in range(2, 7):
            if modifiedNumberContainsSameDigits(number, multiplyBy):
                print("Match found: ", number)
                matches.append(number)
            else:
                print("Skipping ", number)
                break
                
    matches.sort(key=None, reverse=False)
    print("Minimum element: ", matches[0])
            
            