'''
Created on 24 Oca 2013

@author: tr1u4323
'''
def getNextTriangularNumber(number):
    return number * (number + 1) //2

def getNextPentagonalNumber(number):
    return number * (3 * number - 1) // 2

def getNextHexagonalNumber(number):
    return number * (2 * number - 1)

if __name__ == '__main__':
    
    triangularStart = 286
    pentagonalStart = 166
    hexagonalStart = 144
    
    triangularList = []
    pentagonalList = []
    hexagonalList = []
    
    while True:
        triangularList.append(getNextTriangularNumber(triangularStart))
        pentagonalList.append(getNextPentagonalNumber(pentagonalStart))
        hexagonalList.append(getNextHexagonalNumber(hexagonalStart))
        
        intersection = set(triangularList) & set(pentagonalList) & set(hexagonalList)
        if len(intersection) > 0:
            break
        else:
            triangularStart += 1
            pentagonalStart += 1
            hexagonalStart += 1
    
    print(getNextTriangularNumber(55385))