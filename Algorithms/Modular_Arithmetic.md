# Euler's Totient Function  
Φ(n) for an input n is count of numbers in {1,2,3...n} that are relatively prime to n.  

=> if n is prime then Φ(n)=n-1;  

Brute force solution is iterate to all elemets of array and compute GCD of every elements with n. If GCD comes out 1 then increment the count.  

Other solution is using Euler's product formula Φ(n)= n* π(1-1/p) where p are all prime numbers of n.  

See the code [Here](./code/Euler_Totient.cpp)  

__Property of Totient function:__  
if a and b are prime numbers then Φ(a.b)=Φ(a).Φ(b)=(a-1)*(b-1)  

# Euler's Totient function for all number from 1 to n:  
Similar to concept of sieve of Eratosthenes;  
See the code [Here](./code/Totient_1_to_n.cpp)  

# Modular Exponentiation:  
Property:  (ab)mod p = ((a mod p)*(b mod p)) mod p  

Time complexity: O(log(exponent))  
See the code [Here](./code/modular_exponentiation.cpp)  

# Multiplicative Order:  
If A is an integer and N is a positive number such that A and N are relatively prime numbers. The mulitplicative order of modullo N is a smallest positive number k such that (A^k)mod N = 1  

# Modular Inverse:  
Inverse of 'a' modullo m is x then it can be represented as a*x = 1 (mod m)  
It is possible only when gcd(a,m) = 1  
=> a*x + m*y = 1  (By extended eucleadean algorithm) 
Time Complexity: O(log(m))   
See the code [Here](./code/Modular_Inverse.cpp)  

# Chinese Remainder Theorem:  
Chinese Remainder theorem is used to solve different congruent equations with one variable but different modulli which are relatively prime.  
X = a1 (mod m1)  
X = a2 (mod m2)  
...  
X = an (mod mn)  

where m1, m2, ... mn are relatively prime numbers.  
Calculate X using Chinese Remainder theorem.  
CRT says that if modulli are relatively prime then there exist a unique solution which satisfy the given equations.  

X = (a1*M1*M1^-1 + a2*M2*M2^-1 + .........+ a_n*M_n*M_n^-1) mod M  
where  
M = m1*m2*.....*m_n  
M1 = M1/m1 , M2/m1 , .........., M_n/m_n  
M_i^-1 = inverse of M_i with modullo m_i.  

Time complexity: O(n*log(n))  
See the code [Here](./code/chinese_remainder.cpp)  

# Primitive root of a prime number n modullo n  
Given a prime number n. Task is to find its primitive root modullo n.  
__Primitive Root:__ Primitive number of a prime number n is an integer r between [1,n-1] such that r^x(mod n) where x is in range [0,n-2] are all different.  

**Fact**  
If the multiplicative order of number r modullo n is equal to Euler Totient function (Φ(n)), then r is a primitive root.  
Algorithm:  
1. Calculate all prime factors of Φ(n) if n is prime.  
2. For r in range [2,n-1] check if r^(Φ(n)/prime_factor) == 1 then that r is not a primitive root. 
3. If for all prime factor r^(Φ(n)/prime_factor) != 1 then that r is a primitive root of n.  

For smallest primitive root, see the code [Here](./code/primitive_root.cpp)

  






