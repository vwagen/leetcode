#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
    int atoi(const char *str) {  
        string s(str);
        int len = s.length(); 
        //cout << "len: " << s.length() << endl;
        if(len == 0) {   
            return 0;   
        }       
        long long ret = 0;    
        int i;  
        long long sign_flag = 1;  
        for(i = 0; i < len; i++) {   
            if(str[i] == ' ' || str[i] == '0') {
                continue;
            }
            if(str[i] >= '1' && str[i] <= '9' || str[i] == '-' || str[i] == '+') { 
                if(str[i] == '-') { 
                    sign_flag = -1;    
                    i++;  
                } else if(str[i] == '+') {
                    sign_flag = 1;    
                    i++;  
                }
                while(str[i] >= '0' && str[i] <= '9' && i < len) { 
                    //cout << "get: " << str[i] << endl;
                    if(ret < 2147483649) {
                        ret *= 10;
                        ret += (long long)(str[i] - '0');
                    }
                    i++;
                }
                break;
            } else {
                break;
            }
        }
        int real_ret;
        ret *= sign_flag;
        real_ret = (int)ret;
        if(ret > 2147483647) {
            real_ret = 2147483647;
        } else if(ret < -2147483648) {
            real_ret = -2147483648;
        }
        return real_ret;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    int ret = s.atoi((const char*)argv[1]);
    cout << "ret:" << ret << endl;
    char* c = " sb2148";
    cout << "atoi:" << atoi(c) << endl;
    return 0;
}
