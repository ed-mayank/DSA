# Sieve of Eratosthenes

It is an algorithm to find all prime numbers less than n.  
Create a list of number from 2 to n. Now start with 2 and mark all the multiple of 2 upto n. Now in that list start with first unmarked number after 2 and mark all its multiple upto n. Repeat this upto sqrt(n) step. Now all unmarked numbers will be prime factors of n.  
Time complexity: O(n*log(log(n)))  
See the code [Here](./code/sieve.cpp)

# Binary Exponentiation  
Time Complexity: O(log(exponent))  
See the code [Here](./code/binary_exponent.cpp)  

# Simple Eucleadean Algorithm  
This algorithm says that gcd(a,b) = gcd(b%a, a) where b>a  
See the code [Here](./code/simple_eucleadean.cpp)  

# Extended Eucleadean Algorithm  
a and b are given and calculate x and y such that ax+by=gcd(a,b)  -- eq-1
=> gcd(a,b) can always be written in linear combination of a and b.  

By simple Eucleadean Algorithm gcd(a,b) = gcd(b%a, a) = b%a*x1 + a*y1  -- eq-2  
b%a = b - floor(b/a)*a  --eq-3  
substituting eq-3 into eq-2  
(b-floor(b/a)*a)*x1 + a*y1 = gcd(a,b)  
b*x1 + a*(y1-floor(b/a)*x1) = gcd(a,b)  --eq-4  
On comparing eq-1 and eq-4 we found:  
x = y1-floor(b/a)*x1  
y = x1  

See the code [Here](./code/Extended_eucleadenan.cpp)  

# Prime Factors of a number  
In case of composite number, we know that one of its factor will always less than its square root.  
Now to calculate all prime factors of a number n, we will start with 2. If n is even, 2 is its prime factor and now remove all repetition of 2 from n by dividing n with 2 untill n become odd.  
Now start a loop from 3 to sqrt(n) and increment by 2 since prime number after 2 can only be odd. 
See the code [Here](./code/primeFactors.cpp)  

# Fermat's Little Theorem:  
```if n is a prime numbers then for every number a where 1<a<(n-1) a^(n-1) = 1 (mod n)```  

# Wilson's Theorem:  
```Wilson's Theorem states that a natural number p>1 is a prime number if and only if  (p-1)! = (p-1) mod p```  








