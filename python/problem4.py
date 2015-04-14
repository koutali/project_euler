'''
Created on 17 Oca 2013

@author: tr1u4323
'''

def largestPalindrom():
    palindromList = []
    
    for i in range(100, 1000):
        for j in range (100, 1000):
            tempPalindrom = i * j
            palindromString = str(tempPalindrom)
            reversedPalindrom = palindromString[::-1]
            
            if(palindromString == reversedPalindrom):
                palindromList.append(tempPalindrom)
    
    palindromList.sort(key=None, reverse=False)
    return palindromList
            

if __name__ == '__main__':
    print(largestPalindrom())