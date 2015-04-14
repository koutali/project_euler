'''
Created on 23 Oca 2013

@author: tr1u4323
'''
import math

def getNewList(elementToExclude, originalList):
    newList = []
    
    for each in originalList:
        if each != elementToExclude:
            newList.append(each)
            
    return newList
 
def getListOfPermutations():
    toBePermutated = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]    elementToReturn = 1000000 - 1

    length = math.factorial(len(toBePermutated) - 1)
    string = ""
    newList = list(toBePermutated)
    
    while len(string) < len(toBePermutated):
        elementToSelect = (elementToReturn // length)
        string += str(newList[elementToSelect])
        newList = getNewList(newList[elementToSelect], newList)
        
        if len(newList) > 0:
            elementToReturn = elementToReturn % length
            length = math.factorial(len(newList) - 1)
                return string


if __name__ == '__main__':
    print(getListOfPermutations())