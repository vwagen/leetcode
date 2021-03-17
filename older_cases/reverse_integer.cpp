#include <iostream>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            long long tmp = 0;
            long long x_tmp;  
            bool sign = false;
            if(x < 0) {   
                x_tmp = -x;  
                sign = true;  
            }  
            else { 
                x_tmp = x;      
            }   
            while((x_tmp / 10) != 0 || (x_tmp % 10) != 0) {    
                tmp *= 10;     
                tmp += x_tmp % 10;   
                x_tmp /= 10; 
            } 
            cout << "tmp: " << tmp << endl;
            if(sign) {    
                return -(int)tmp;  
            }   
            else {   
                return (int)tmp;   
            } 
        }
};

int main(int argc, char* argv[]) {
    Solution s;
    int i = 0;
    if(argc == 2) {
        i = atoi(argv[1]);
    }
    int ret = s.reverse(i);
    cout << "ret: " << ret << endl;
    typedef struct aaa {} bbb;
    cout << "sizeof(void)" << sizeof(bbb) << endl;
    return 0;
}
