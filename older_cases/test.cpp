#include <iostream>
#include <string>
using namespace std;
int f(char* a) {
    a++;
    *a = 'a';
    return 0;
}

int main(int argc, char* argv[]) {
    /*
    string s = "abcde";
    int a[128] = {0};
    int i;
    int length = s.length();
    cout << "length: " << length << endl;
    for(i = 0; i < length; i++) {
        a[s[i]] = 1;
    }
    for(i = 0; i < 128; i++) {
        if(a[i] != 0) {
            cout << "a[" << i << "] = " << a[i] << endl;
        }
    }
    string sss;
    cin >> sss;
    int aaa[100];
    for(i = 0; i < 100; i++) {
        aaa[i] = i;
    }
    cout << "aaa[sss[3]]: " << aaa[sss[3]] << endl;
    char* cc = new char [4];
    cc[0] = '1';
    cc[1] = '2';
    cc[2] = '3';
    cc[3] = '4';
    string ssss(cc);
    cout << "ssss: " << ssss << endl;
    */
    char str[sizeof("hello")];
    strcpy(str, "hello");
    f(str);
    string s("sdfasdfsdf/sdfweidif/fdf");
    cout << str << s <<endl;
    return 0;
}
