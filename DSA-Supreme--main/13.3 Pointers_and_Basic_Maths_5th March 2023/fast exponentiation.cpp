
// Approach: Use binary exponentiation to compute (a^b) % m efficiently in O(log b) time.
// Formula: If b is even, (a^b) = (a^(b/2))^2; if b is odd, (a^b) = a * (a^(b-1))


long long fastExpo(long long a, long long b, long long m) { 
    // Function to compute (a^b) % m efficiently
    // Uses binary exponentiation for fast calculation
    long long result = 1; // Initialize result to 1 (multiplicative identity)
    // Will store the final answer in result

    a = a % m;  // Reduce a modulo m to prevent overflow
    // Ensures a is within the range [0, m-1]

    while (b > 0) { // Loop until all bits of b are processed
        // Each iteration processes one bit of b

        if (b & 1) { // If current bit of b is 1 (b is odd)
            // Multiply result by current a if bit is set
            result = (result * a) % m; // Update result modulo m
            // Ensures result stays within bounds
        }

        a = (a * a) % m; // Square a for next bit, take modulo m
        // Prepares a for the next higher power of 2

        b >>= 1;  // Shift b right by 1 (divide b by 2)
        // Moves to the next bit of b
    }

    return result; // Return the computed (a^b) % m
    // Final answer after processing all bits
}
