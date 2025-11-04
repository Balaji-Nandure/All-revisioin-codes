Modulo Arithmetic

(a % n) -> [0, ..., n - 1]

Generally, to avoid overflow while storing Integer we do modulo with a Large number.

(a + b) % M = a % M + b % M

a % M - b % M = (a - b) % M

((a % M) % M) % M = a % M

a % M * b % M = (a * b) % M