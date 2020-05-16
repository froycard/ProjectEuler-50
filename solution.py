def is_prime(n):
    if (n <= 1):
        return False
    if (n == 2):
        return True
    if (n % 2 == 0):
        return False
    i = 3
    while i <= n**(0.5)+1:
        if n % i == 0:
            return False
        i = i + 2

    return True

def prime_generator():
    n = 1
    while True:
        n += 1
        if is_prime(n):
            yield n
upperBound=1000000
generator = prime_generator()
primes=list()
for i in prime_generator():
    if i > upperBound: break
    primes.append(i)
#print(primes)
maxim=0
number = 0
for i in range(len(primes)):
    if i+maxim > len(primes): break
    chain=primes[i:i+maxim]
    for j in range(len(chain)+i,len(primes)):
        chain.append(primes[j])
        primeSum=sum(chain)
        if primeSum>upperBound: break
        if primeSum in primes:
            counter=len(chain)
            if counter > maxim:
                number = primeSum
                maxim = counter   
print("Sol. ", number)      
        
