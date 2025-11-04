class Solution {
    public:
        int countPrimes(int n) {
            // Sieve of Eratosthenes (Optimal) (This is one of the algorithm)
            if(n<=2) return 0;
            vector<bool> isPrime(n, true);
            isPrime[0] = false;
            isPrime[1] = false;
    
            // Start checking from 1 upto sqrt n
            for(int i=2; i<= sqrt(n); i++){
                if(isPrime[i]){
                    for(int j=i*i; j<n; j+=i ){
                        isPrime[j] = false;
                    }
                }
            }
    
            // now count number of non primes
            int count = 0;
            for(int i=2; i<n; i++){
                if(isPrime[i]) count++;
            }
    
            return count;
        }
    };