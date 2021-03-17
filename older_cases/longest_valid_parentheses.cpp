#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <map>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Solution {
    public:  
        int longestValidParentheses(string s) {    
            long long len = s.length();
            if(len < 2) {
                return 0;
            }
            stack<long long> open_parentheses;
            map<long long, long long> map_parentheses;
            long long i;
            for(i = 0; i < len; i++) {
                if(s[i] != '(') {
                    break;
                }
            }
            if(i == len) {
                return 0;
            }
            for(i = 0; i < len; i++) {
                if(s[i] == '(') {
                    open_parentheses.push(i);
                }
                else if(s[i] == ')') {
                    if(open_parentheses.empty()) {
                        continue;
                    }
                    else {
                        //cout << open_parentheses.top() << ":" << i << endl;     // Never use any print out function in leetcode problem solution!
                        map_parentheses[open_parentheses.top()] = i;
                        open_parentheses.pop();
                    }
                }
            }
            //cout << "open_parentheses.size(): " << open_parentheses.size() << endl;
            if(map_parentheses.empty()) {
                return 0;
            }
            else if(map_parentheses.size() == 1) {
                map<long long, long long>::iterator it = map_parentheses.begin();
                return (int)((*it).second - (*it).first) + 1;
            }
            else {
                map<long long, long long>::iterator it1 = map_parentheses.begin();
                map<long long, long long>::iterator it_tmp = it1;
                map<long long, long long>::iterator it2 = ++it1;
                it1 = it_tmp;
                while(it2 != map_parentheses.end()) {
                    if((*it2).first < (*it1).second) {
                        map_parentheses.erase(it2);
                        it_tmp = it1;
                        it2 = ++it1;
                        it1 = it_tmp;
                    }
                    else if((*it2).first == (*it1).second + 1) {
                        long long open_p = (*it1).first;
                        long long close_p = (*it2).second;
                        map_parentheses.erase(it1);
                        map_parentheses.erase(it2);
                        map_parentheses[open_p] = close_p;
                        it1 = map_parentheses.find(open_p);
                        it_tmp = it1;
                        it2 = ++it1;
                        it1 = it_tmp;
                    }
                    else {
                        it1 = it2;
                        it_tmp = it1;
                        it2 = ++it1;
                        it1 = it_tmp;
                    }
                }
                long long max = 0;
                long long tmp = 0;
                it1 = map_parentheses.begin();
                while(it1 != map_parentheses.end()) {
                    tmp = (*it1).second - (*it1).first + 1;
                    max = max < tmp ? tmp : max;
                    it1++;
                }
                return (int)max;
            }
        }
};

int main(int argc, char* argv[]) {
    Solution s;
    if(argc == 1) {
        char* c = "((()))(()))((()";
        //memset(c, '(', 17172);
        //c[17171] = ')';
        //cout << c << endl;
        string p(c);
        double start = (double)clock();
        cout << "ret: " << s.longestValidParentheses(p) << endl;
        double end = (double)clock();
        cout << "time: " << end - start << endl;
    }
    else {
        string p("argv[1]");
        cout << "ret: " << s.longestValidParentheses(p) << endl;
    }
    return 0;
}
