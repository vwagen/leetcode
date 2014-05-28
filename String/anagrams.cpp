#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        multimap<string, string> alphabets;
        for(int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            alphabets.insert(pair<string, string>(tmp, strs[i]));
        }
        vector<string> ret;
        multimap<string, string>::iterator it = alphabets.begin();
        multimap<string, string>::iterator it_next;
        while(it != alphabets.end()) {
            it_next = it;
            it_next++;
            bool flag = false;
            while(it_next != alphabets.end() && (*it).first == (*it_next).first) {
                flag = true;
                ret.push_back((*it_next).second);
                it_next++;
            }
            if(flag) {
                ret.push_back((*it).second);
            }
            it = it_next;
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    vector<string> ss;
    ss.push_back(string("dog"));
    ss.push_back(string("god"));
    ss.push_back(string("pot"));
    Solution s;
    vector<string> ret = s.anagrams(ss);
    for(int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
    //cout << s.anagrams(ss) << endl;
    //bool ret = s.();
    //if(ret) {
    //    cout << "This is a palindrom!" << endl;
    //}
    //else {
    //    cout << "This is not a palindrom!" << endl;
    //}
    return 0;
}
