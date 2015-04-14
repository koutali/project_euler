'''
Created on 25 Oca 2013

@author: tr1u4323
'''

def generateDifferences(limit):
    differences = []
    
    for i in range(1,limit):
        toAppend = 12*i+5
        differences.append(toAppend)
    
    return differences

def generateSums(limit):
    sums = []
    
    for i in range(1, limit):
        toAppend = 12*i*i+10*i+5
        sums.append(toAppend)
        
    return sums

def generatePentagons(limit):
    pentagons = []
    
    for i in range(1, limit):
        toAppend = 6*i*i-i
        pentagons.append(toAppend)
        
    return pentagons

if __name__ == '__main__':
    limit = 5000000
    differences = generateDifferences(limit)
    pentagons = generatePentagons(limit)
    sums = generateSums(limit)
    
    intersection = set(differences) & set(pentagons) & set(sums)
    if len(intersection) > 0:
        print(min(intersection))
    else:
        print("No intersection found")
    