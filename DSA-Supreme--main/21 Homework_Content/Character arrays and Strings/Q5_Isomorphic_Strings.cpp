// https://leetcode.com/problems/isomorphic-strings/description/

/*
Approach:
---------
We check if two strings s and t are isomorphic by ensuring a one-to-one mapping between characters of s and t. 
We use two hash maps:
- ST: maps each character in s to a character in t.
- TS: maps each character in t to a character in s.

For each character pair (s[i], t[i]):
- If s[i] is already mapped, it must map to t[i]. If not, return false.
- If t[i] is already mapped, it must map to s[i]. If not, return false.
- Otherwise, create the mapping in both directions.

If all checks pass, the strings are isomorphic.

*/

class Solution { // class for solution // main logic container
public: // public access // allows function to be called
    bool isIsomorphic(string s, string t) { // function to check isomorphism // takes two strings
        if(s.size() != t.size()) return false; // check length mismatch // not isomorphic if sizes differ
        unordered_map<char, char> ST; // map from s to t // stores mapping s->t
        unordered_map<char, char> TS; // map from t to s // stores mapping t->s
        for(int i=0; i<s.size(); i++){ // iterate over string // process each character
            char c1 = s[i]; // get char from s // current char in s
            char c2 = t[i]; // get char from t // current char in t

            if(ST.count(c1)){ // if c1 already mapped // check s->t mapping exists
                if(ST[c1] != c2) return false; // mapping mismatch // not isomorphic
            } else { // c1 not mapped yet // need to check t->s
                if(TS.count(c2)){ // if c2 already mapped // check t->s mapping exists
                    if(TS[c2] != c1) return false; // mapping mismatch // not isomorphic
                }
                ST[c1] = c2; // create s->t mapping // store mapping
                TS[c2] = c1; // create t->s mapping // store reverse mapping
            }
        }
        return true; // all checks passed // strings are isomorphic
    }
};

/*
Dry Run Example:
----------------
s = "egg", t = "add"

i=0: s[0]='e', t[0]='a'
- No mapping exists, create: 'e'->'a', 'a'->'e'

i=1: s[1]='g', t[1]='d'
- No mapping exists, create: 'g'->'d', 'd'->'g'

i=2: s[2]='g', t[2]='d'
- Mapping exists: 'g'->'d', 'd'->'g' (matches)

=> Return true

s = "foo", t = "bar"

i=0: s[0]='f', t[0]='b'
- No mapping exists, create: 'f'->'b', 'b'->'f'

i=1: s[1]='o', t[1]='a'
- No mapping exists, create: 'o'->'a', 'a'->'o'

i=2: s[2]='o', t[2]='r'
- Mapping exists: 'o'->'a', but t[2]='r' != 'a', so return false

*/