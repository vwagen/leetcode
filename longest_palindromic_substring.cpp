#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    typedef struct {
        int pos;
        int length;
    } index_pair;
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len < 3) {
            return s;
        }
        int head;
        int tail;
        int head_tmp;
        int tail_tmp;
        head = 0;
        vector<index_pair> rets;
        while(head < len - 1) {
            tail = head + 1;
            head_tmp = head;
            tail_tmp = tail;
            if(s[head] != s[tail] && s[head - 1] != s[tail]) {
                head = head_tmp + 1;
                continue;
            }
            if(s[head] == s[tail]) {
                while(s[head] == s[tail] && head >= 0 && tail < len) {
                    head--;
                    tail++;
                }
                index_pair ret_tmp = {head + 1, tail - head - 1};
                rets.push_back(ret_tmp);
            }
            head = head_tmp;
            tail = tail_tmp;
            if(s[head - 1] == s[tail]) {
                head--;
                while(s[head] == s[tail] && head >= 0 && tail < len) {
                    head--;
                    tail++;
                }
                index_pair ret_tmp = {head + 1, tail - head - 1};
                rets.push_back(ret_tmp);
            }
            head = head_tmp + 1;
        }
        vector<index_pair>::iterator it_max;
        vector<index_pair>::iterator it = rets.begin();
        int max_length = 0;
        while(it != rets.end()) {
            if(max_length < (*it).length) {
                max_length = (*it).length;
                it_max = it;
            }
            it++;
        }
        return s.substr((*it_max).pos, (*it_max).length);
    }
};

int main(int argc, char* argv[]) {
    string s;
    if(argc == 2) {
        string s_tmp(argv[1]);
        s = s_tmp;
    }
    else {
        string s_tmp("ccd");
        s = s_tmp;
    }
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}
