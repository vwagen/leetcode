#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
    Solution() {
        cout<<"Solution struct func."<<endl;
    }
    ~Solution() {
        cout<<"Solution struct destroy."<<endl;
    }
    void reverseWords(string &s) {
        const char* sample;
        int i;
        int j;
        int k;
        int w = 0;
        //int size = s.size();
        //string result;
        sample = s.c_str();
        char* result = new char[s.size() + 1];
        for(i = s.size() - 1, j = s.size(); i >= 0; i--) {
            if(s[i] == ' ') {
                if(i == j - 1) {
                    j = i;
                    continue;
                }
                //result += s.substr(i + 1, j - i - 1);
                //result += " ";
                for(k = i + 1; k < j; k++, w++) {
                    result[w] = sample[k];
                }
                result[w++] = ' ';
                j = i;
            }
        }
        if(i != j - 1) {
            for(k = i + 1; k < j; k++, w++) {
                result[w] = sample[k];
            }
            //result += s.substr(i + 1, j - i - 1);
        }
        result[w] = 0;
        string resultstring(result);
        if(resultstring[resultstring.size() - 1] == ' ') {
            resultstring.erase(resultstring.size() - 1, 1);
        }
        //cout << result <<endl;
        s = resultstring;
        free(result);
    }
};

int main(int argc, char** argv) {
    Solution test;
    string s = argv[1];
    //string s = "1 ";
    //string s = "ngtbikppgpheyuvlgzwndg..j ?tgg!,iyrgnc!t,gvornut,gkxicik,rixjh ";
    //string s = "asdfjlkwejlkfjalnvl;asjdfowopjvopa'g1sjdfkwo8";
    cout << s << endl;
    test.reverseWords(s);
    cout << s << endl;
    return 0;
}
