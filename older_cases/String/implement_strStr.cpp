#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(haystack == NULL || needle == NULL) {
            return NULL;
        }
        if(haystack[0] == '\0' && needle[0] == '\0') {
            return haystack;
        }
        else if(haystack[0] == '\0' && needle[0] != '\0') {
            return NULL;
        }
        else if(haystack[0] != '\0' && needle[0] == '\0') {
            return haystack;
        }
        int i = 0;
        int j;
        int k;
        while(haystack[i] != '\0') {
            if(haystack[i] == needle[0]) {
                j = i;
                k = 0;
                while(haystack[j] == needle[k]) {
                    if(haystack[j + 1] == '\0' && needle[k + 1] != '\0') {
                        return NULL;
                    }
                    if(needle[k + 1] == '\0') {
                        return &(haystack[i]);
                    }
                    j++;
                    k++;
                }
            }
            i++;
        }
        return NULL;
    }
};

int main(int argc, char* argv[]) {
    char* s = "abcdefghijklmn";
    cout << s << endl;
    char* c = "ghil";
    Solution sol;
    char* ret = sol.strStr(s, c);
    if(ret != NULL) {
        cout << ret << endl;
    }
    else {
        cout << "ret is NULL!" << endl;
    }
    return 0;
}
