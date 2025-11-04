/*
Approach:
- Demonstrate basic usage of std::map in C++ for mapping integer keys to character values.
- Show how insertion and access works, especially the behavior when accessing a non-existent key.
- Highlight the default initialization of value when accessing a missing key.
- Discuss better alternatives and best practices in comments.
*/

#include<iostream>
#include<map>
using namespace std;

int main(){
    // Create a map that maps int keys to char values
    map<int, char> myMap; // std::map stores key-value pairs in sorted order of keys

    // Insert a key-value pair: key=0, value='a'
    myMap[0] = 'a'; // If key 0 doesn't exist, it is created and assigned 'a'

    // Access and print the value at key 0
    cout << myMap[0] << endl; // Output: a

    // Access and print the value at key 1 (which does not exist yet)
    // This will insert key 1 with default value '\0' (null character) and print it (may appear empty)
    cout << myMap[1] << endl; // Output: (empty line, as '\0' is non-printable)

    // Print the size of the map to show that both keys now exist
    cout << "Size of map: " << myMap.size() << endl; // Output: 2

    // Print all key-value pairs to show the contents of the map
    cout << "Contents of map:" << endl;
    for(const auto& pair : myMap){
        cout << "Key: " << pair.first << ", Value: ";
        if(pair.second == '\0')
            cout << "\\0 (null character)";
        else
            cout << pair.second;
        cout << endl;
    }

    return 0;
}

/*
Better/Alternative Approaches (without code):

1. Use .at() for safer access:
   - Using myMap.at(key) throws an exception if the key does not exist, preventing accidental insertion of default values.
   - This is safer when you only want to read and not modify the map.

2. Use find() to check existence before access:
   - myMap.find(key) returns an iterator to the key if it exists, or myMap.end() if it doesn't.
   - This avoids inserting default values for missing keys.

3. Use unordered_map for faster average-case access:
   - If order of keys is not important, std::unordered_map provides O(1) average-case access and insertion.

4. Use emplace() or insert() for explicit insertion:
   - These methods avoid overwriting existing values and are more explicit than operator[].

5. For large data, consider custom hash or comparator functions for efficiency.

Dry Run:
-----------
Step 1: map<int, char> myMap; // myMap = {}
Step 2: myMap[0] = 'a';       // myMap = {0: 'a'}
Step 3: cout << myMap[0];     // Output: a
Step 4: cout << myMap[1];     // myMap[1] is accessed, key 1 is inserted with value '\0'
                              // Output: (empty line)
Step 5: cout << myMap.size(); // Output: 2
Step 6: Print all key-value pairs:
        Key: 0, Value: a
        Key: 1, Value: \0 (null character)
*/