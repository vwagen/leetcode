#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0) {
            return "";
        }
        else if(strs.size() == 1) {
            return strs[0];
        }
        int len = 0;
        int len_min = strs[0].size();
        for(int i = 0; i < strs.size(); i++) {
            len_min = len_min <= strs[i].size() ? len_min : strs[i].size();
        }
        for(int j = 0; j < len_min; j++) {
            int i = 0;
            while(i < strs.size() - 1) {
                if((strs[i][j] ^ strs[i + 1][j]) != 0) {
                    break;
                }
                i++;
            }
            if(i == strs.size() - 1) {
                len++;
            }
            else {
                break;
            }
        }
        return strs[0].substr(0, len);
    }
};

int main(int argc, char* argv[]) {
    vector<string> strs;
    //strs.push_back(string("abcdefghijk"));
    //strs.push_back(string("abcdbf"));
    //strs.push_back(string("abcdee"));
    //strs.push_back(string("abcdcf"));
    //strs.push_back(string("abcdmf"));
    for(int i = 0; i < strs.size(); i++) {
        cout << strs[i] << endl;
    }
    cout << "The longest common prefix of strings above is:" << endl;
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
