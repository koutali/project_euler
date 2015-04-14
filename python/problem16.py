'''
Created on 21 Oca 2013

@author: tr1u4323
'''
import math

def getNumber():
    return math.pow(2, 1000)

def createStringFromNum(num):
    string = ""
    remainder = 0
    
    while num > 1:
        remainder = int(num % 10);
        num = num // 10;
        string = str(remainder) + string
    
    string = str(num) + string
    return string

def getNumberFromString(string):
    return int(float(string))

if __name__ == '__main__':
    string = "10715086071862673209 484250490600018105614 0481170553360744375 038837035105112493 612249319837881569 585812759467291755 314682518714528569 231404359845775746 985748039345677748 242309854210746050 623711418779541821 530464749835819412 6739876755916554394 607706291457119647 768654216766042983165 2624386837205668069376"
    print(string)
    print(createStringFromNum(getNumber()))
    
    sum = 0
    for ch in string:
        if ch == " ":
            continue
        else:
            sum += getNumberFromString(ch)
            
    print(sum)