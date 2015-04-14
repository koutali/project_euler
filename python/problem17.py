'''
Created on 22 Oca 2013

@author: tr1u4323
'''

def countLettersInString(string):
    letterCount = 0
    for ch in string:
        if ch == " " or ch == "-":
            continue
        else:
            letterCount += 1
        
    return letterCount

firstDigitDictionary = {1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six", 7:"seven", 
                            8: "eight", 9:"nine"}
    
secondDigitDictionary =  {10: "ten", 11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen", 
                      15: "fifteen", 16: "sixteen", 17: "seventeen", 18: "eighteen", 19: "nineteen", 
                      2: "twenty", 3: "thirty", 4: "forty", 5: "fifty", 6: "sixty", 7: "seventy", 
                      8:"eighty", 9: "ninety"}

def createListOfDigits(number):
    listDigits = []
    
    while number >= 1:
        remainder = number % 10
        number = number // 10
        listDigits.append(remainder) 
    
    listDigits = listDigits[::-1]
    return listDigits

def getNumberFromList(listDigits):
    string = ""
    for each in listDigits:
        string += str(each)
        
    return int(float(string))

def createNumberString(number):    
    listDigits = createListOfDigits(number)
    numberString = ""
    
    index = len(listDigits)
    
    for digit in listDigits:
        if digit == 0:
            index -= 1
            continue
        
        if index == 4:
            numberString += firstDigitDictionary[digit] + " thousand"
        elif index == 3:
            numberString += firstDigitDictionary[digit] + " hundred"
            
            if listDigits[-1] > 0 or listDigits[-2] > 0:
                numberString += " and "
                        
        elif index == 2:
            if digit > 1:
                numberString += secondDigitDictionary[digit]
                if listDigits[-1] > 0:
                    numberString += "-"
            else:
                lastTwoDigits = getNumberFromList(listDigits[-2:])
                numberString += secondDigitDictionary[lastTwoDigits]
                break
                
        elif index == 1:
            numberString += firstDigitDictionary[digit]
            
        index -= 1
    
    return numberString

if __name__ == '__main__':
    numberOfTotalLetters = 0
    
    for i in range(1, 1001):
        numberString = createNumberString(i)
        numberOfTotalLetters += countLettersInString(numberString)
        
    #numberOfTotalLetters += countLettersInString("one hundred and fifteen")
    print(numberOfTotalLetters)