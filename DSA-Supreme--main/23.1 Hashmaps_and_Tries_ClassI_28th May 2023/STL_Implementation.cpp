/*
Approach:
-----------
This code demonstrates the basic usage of C++ STL unordered_map (hashmap) for storing key-value pairs, 
inserting elements, accessing values, searching for keys, and iterating over the map.

unordered_map provides average O(1) time complexity for insertion, deletion, and search operations.

Key Points:
- unordered_map stores unique keys in no particular order (hashing).
- Accessing a non-existent key with [] inserts it with default value (0 for int).
- at() throws exception if key not found, safer for access.
- count() checks if key exists (returns 1 if present, 0 otherwise).
- find() returns iterator to key if found, else m.end().
- Iteration order is not guaranteed.

Better Alternatives:
--------------------
- Use 'emplace' instead of 'insert' for in-place construction (faster, avoids unnecessary copies).
- Use 'map' instead of 'unordered_map' if you need sorted keys (O(log n) operations).
- Use 'const auto&' in range-based for loop to avoid unnecessary copies.
- Use try-catch with at() for safe access.
- For large data, reserve() can be used to avoid rehashing.

Below is the improved code with detailed comments and alternatives in comment blocks.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    // 1. Creation of unordered_map to store string keys and int values
    unordered_map<string,int> m; // O(1) average for all operations

    // 2. Insertion of key-value pairs

    // Method 1: Using make_pair and insert
    pair<string,int> p = make_pair("Scorpio",9); // Create a pair ("Scorpio", 9)
    m.insert(p); // Insert the pair into the map

    // Method 2: Direct pair initialization and insert
    pair<string,int> p2("A",10); // Create a pair ("A", 10)
    m.insert(p2); // Insert the pair into the map

    // Method 3: Using [] operator (inserts if key not present, updates if present)
    m["fortuner"] = 6; // Insert ("fortuner", 6) into the map

    // Alternative (Recommended): Use emplace for in-place construction (faster)
    // m.emplace("Innova", 8);

    // 3. Accessing values

    // Access value for key "A" using at() (throws exception if key not found)
    cout << m.at("A") << endl; // Output: 10

    // Access value for key "fortuner" using [] (inserts key with default value if not present)
    cout << m["fortuner"] << endl; // Output: 6

    // Safer alternative: Use find() before at() to avoid exceptions
    // if(m.find("A") != m.end()) cout << m.at("A") << endl;

    // 4. Searching for keys

    // Using count() to check if key exists (returns 1 if present, 0 otherwise)
    cout << m.count("A") << endl; // Output: 1 (present)
    cout << m.count("B") << endl; // Output: 0 (not present)

    // Using find() to search for a key
    if(m.find("A") != m.end()){ // If iterator is not at end, key exists
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }

    // 5. Iterating over the map

    // Using range-based for loop (order is not guaranteed in unordered_map)
    for(const auto& i : m){ // Use const auto& to avoid copying
        cout << i.first << " " << i.second << endl; // Print key and value
    }

    // Alternative: Iterating using iterator
    /*
    for(auto it = m.begin(); it != m.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
    */

    // 6. Deletion (not in original code, but useful)
    // m.erase("A"); // Removes key "A" if present

    return 0;
}

/*
Dry Run:
----------
unordered_map m after insertions:
{
    "Scorpio": 9,
    "A": 10,
    "fortuner": 6
}

cout << m.at("A") << endl;         // 10
cout << m["fortuner"] << endl;     // 6
cout << m.count("A") << endl;      // 1
cout << m.count("B") << endl;      // 0
if(m.find("A") != m.end())         // true, so prints "Found"
Iteration prints all key-value pairs (order may vary):
    Scorpio 9
    A 10
    fortuner 6
*/