#include <iostream>
#include <string>
using namespace std;

class CopyTest {
    private:
        int a;
        int b;
    public:
        CopyTest() {
            cout << "CopyTest()" << endl;
        }
        CopyTest(int c, int d) {
            cout << "CopyTest(int c, int d)" << endl;
            a = c;
            b = d;
        }
        CopyTest(const CopyTest &T) {
            cout << "CopyTest(const CopyTest &T)" << endl;
            a = T.a;
            b = T.b;
        }
        void show() {
            cout << "show(): a is " << a << endl;
            cout << "show(): b is " << b << endl;
        }
        ~CopyTest() {
            cout << "~CopyTest()" << endl;
        }
};


int main(int argc, void* argv[]) {
    CopyTest a;
    CopyTest b(10, 11);
    CopyTest c(b);
    string aa;
    char* cc = "Test";
    aa.clear();
    aa = cc;
    cout << aa.length() << endl;
    cout << aa << endl;
    
    a.show();
    b.show();
    c.show();
    return 0;
}
