class Solution {
   public:
    bool isAnagram(string s, string t) {
        std::map<std::string, int> myMap;
        for (char character : s) {
            std::string letter = std::to_string(character);
            if (myMap.find(letter) != myMap.end()) {
                myMap[letter] = myMap[letter] + 1;
            } else {
                myMap.insert({letter, 1});
            }
        }
        for (char character : t) {
            std::string letter = std::to_string(character);
            if (myMap.find(letter) == myMap.end()) {
                return false;
            } else if (myMap[letter] == 1) {
                myMap.erase(letter);
            } else {
                myMap[letter] = myMap[letter] - 1;
            }
        }
        return myMap.empty();
    }
};
