#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ret("1");
        while(n > 1) {
            string tmp = ret;
            ret.clear();
            tmp += '*';
            int len = tmp.size();
            int i = 0;
            while(tmp[i] != '*') {
                int count = 1;
                while((tmp[i] ^ tmp[i + 1]) == 0) {
                    count++;
                    i++;
                }
                char str[10];
                sprintf(str, "%d", count);
                ret += str;
                ret += tmp[i];
                i++;
            }
            n--;
        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
    int ss = 12;
    if(argc == 2) {
        ss = atoi(argv[1]);
    }
    cout << ss << endl;
    Solution s;
    cout << ss << "th sequence is:" << endl;
    cout << s.countAndSay(ss) << endl;
    //bool ret = s.();
    //if(ret) {
    //    cout << "This is a palindrom!" << endl;
    //}
    //else {
    //    cout << "This is not a palindrom!" << endl;
    //}
    return 0;
}
