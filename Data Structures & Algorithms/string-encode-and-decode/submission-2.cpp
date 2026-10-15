class Solution {
   public:
    // for string delimiter
    std::vector<std::string> split(std::string s, std::string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }
    string stringToHex(string str) {
        std::stringstream ss;
        for (int i = 0; i < str.size(); ++i) {
            ss << std::hex << (int)str[i];
        }
        return ss.str();
    }
    string hexToString(string hex) {
        string result;
        for (size_t i = 0; i + 1 < hex.size(); i += 2) {
            int value;
            std::stringstream ss;
            ss << std::hex << hex.substr(i, 2);
            ss >> value;
            result += static_cast<char>(value);
        }
        return result;
    }
    string encode(vector<string>& strs) {
        std::stringstream ss;
        for (string str : strs) {
            ss << std::hex << "01";
            ss << stringToHex(str);
        }
        return ss.str();
    }

    vector<string> decode(string s) {
        vector<string> output;
        auto vec = split(s, "01");
        for (std::size_t i = 1; i < vec.size(); i++) {
            output.push_back(hexToString(vec.at(i)));
        }
        return output;
    }
};
