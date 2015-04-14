'''
Created on 23 Oca 2013

@author: tr1u4323
'''

fibs = {0: 0, 1: 1}
def fibonacci(n):
    if n in fibs: return fibs[n]
    if n % 2 == 0:
        fibs[n] = ((2 * fibonacci((n / 2) - 1)) + fibonacci(n / 2)) * fibonacci(n / 2)
        return fibs[n]
    else:
        fibs[n] = (fibonacci((n - 1) / 2) ** 2) + (fibonacci((n+1) / 2) ** 2)
        return fibs[n]

if __name__ == '__main__':
    initialStart = 100
    fib = fibonacci(initialStart)
    stringFibonacci = str(fib)
    
    while len(stringFibonacci) < 1000:
        initialStart += 1
        fib = fibonacci(initialStart)
        stringFibonacci = str(fib)
    
    print(initialStart)
    print(stringFibonacci)