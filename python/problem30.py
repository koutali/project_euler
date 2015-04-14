'''
Created on 31 Oca 2013

@author: tr1u4323
'''

def baseN(num,b,numerals="0123456789abcdefghijklmnopqrstuvwxyz"):
    return ((num == 0) and  "0" ) or ( baseN(num // b, b).lstrip("0") + numerals[num % b])

def getNumberArray(number):
    numberString = str(number)
    numberArray = []
    for ch in numberString:
        numberArray.append(ch)
    
    return numberArray

def isPalindrome(array):
    palindromeDetected = True
    
    i = 0
    j = len(array) - 1
    mid = len(array) // 2
    
    while i <= mid and j >= mid:
        if array[i] != array[j]:
            palindromeDetected = False
            break

        i += 1
        j -= 1
    
    return palindromeDetected

if __name__ == '__main__':
#    isPalindrome(getNumberArray(51))
    
    limit = 1000000
    sumOfAllPalindromes = 0
    for i in range(1, limit):
        if isPalindrome(getNumberArray(i)):
            
            numberInBase2 = baseN(i, 2)
            if isPalindrome(getNumberArray(numberInBase2)):
                print(str(i), "is palindromic both in base 10 and base 2")
                sumOfAllPalindromes += i
    
    print("Sum of all palindromes below ", limit, " is ", sumOfAllPalindromes)