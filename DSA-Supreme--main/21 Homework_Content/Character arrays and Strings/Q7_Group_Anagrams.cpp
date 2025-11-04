
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            // // // Approach 1: Hashmap and sorted string
            // // key = sorted string, value = list of anagram
            // unordered_map<string, vector<string>> mp;
            // vector<vector<string>> result;
            // for(string s : strs){
            //     string key = s;
            //     sort(key.begin(), key.end());
            //     mp[key].push_back(s);
            // }
            // // extract result
            // for(auto &it : mp){
            //     result.push_back(it.second);
            // }
    
            // return result;
    
            // // Approach 2: hashmap + frequency count
            // key = frequency sign, value = list of words
            unordered_map<string, vector<string>> mp; // map to group anagrams // key: freq signature, value: list of words
            for(string s: strs){ // iterate over each string in input // process every word
                vector<int> freq(26,0); // frequency array for a-z // initialized to 0

                // count each char
                for(char c: s){ // loop through each character in string // count occurrences
                    freq[c - 'a']++; // increment count for this character // update frequency array
                }

                // build sign from frequency count
                string key = ""; // will store unique signature for group // used as hashmap key
                for(int i=0; i<26; i++){ // check all possible characters // from 'a' to 'z'
                    if(freq[i]>0){ // if character exists in string // only include present chars
                        key += string(1, 'a'+i) + to_string(freq[i]); // append char and its count // build signature
                    }
                }

                // add word to its group
                mp[key].push_back(s); // group word by its signature // add to corresponding vector
            }

            // convert hashmap to result vector
            vector<vector<string>> result; // will store final grouped anagrams // output variable
            for(auto &it : mp){ // iterate over each group in map // extract all groups
                result.push_back(it.second); // add group to result // push vector of anagrams
            }

            return result; // return all grouped anagrams // final answer
        }
    };