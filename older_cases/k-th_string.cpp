//source here
#include <iostream>
using namespace std;
int f(int begin, int move, int end, char* rt);
int flag;
int k;

int main() {
    int t;
    cin >> t;
    int loop;
    char* rt;
    int k_tmp;
    int zs = 0;
    int ws = 0;
    int i = 0;
    int j = 0;
    int hw;
    for(loop = 0; loop < t; loop++) {
        cin >> zs >> ws >> k;
        rt = new char [zs + ws + 1];
        rt[zs + ws] = 0;
        for(i = 0; i < zs; i++) {
            rt[i] = '0';
        }
        hw = i;
        for(; i < zs + ws; i++) {
            rt[i] = '1';
        }
        flag = 1;
        f(0, hw, zs + ws - 1, rt);
        if(k != 0) {
            cout << "k is: " << k << endl;
            cout << "Impossible" << endl;
        }
        delete(rt);
    }
    return 0;
}

int f(int begin, int move, int end, char* rt) {
    int check1;
    int check2;
    int move_tmp;
    //cout << endl << "in f: begin is:::::::::::::::::::::::::::::::::::::::::" << begin << " move:" << move << "    " << rt << endl << endl;
    while(begin != move && flag) {
        //cout << endl <<"begin while: " << rt << "    k is: " << k << endl;
        cout << rt << endl;
        k--;
        if(k == 0) {
            cout << "in k == 0: " << rt << endl;
            flag = 0;
            return 0;
        }
        rt[move] = '0';
        rt[--move] = '1';
        check1 = move + 1;
        check2 = end;
        move_tmp = check1;
        //cout << check1 << "  1  " << check2 << "         " << rt << endl;
        while(rt[check1] == '0' && check1 <= end) {
            check1++;
        }
        //cout << check1 << "  2  " << check2 <<  "         " << rt << endl;
        while(rt[check1] != rt[check2] && check1 < check2 && check1 <= end) {
            //cout << check1 << "  3  " << check2 <<  "         " << rt << endl;
            rt[check1++] = '0';
            rt[check2--] = '1';
        }
        check1 = move + 1;
        //cout << check1 << "  4  " << check2 <<  "         " << rt << endl;
        while(rt[check1] == '0' && check1 <= end) {
            check1++;
        }
        //cout << check1 << "  5  " << check2 <<  "         " << rt << endl;
        if(flag && rt[end] == '1') {
            //cout << "before next f: " << rt << endl;
            f(move_tmp, check1, end, rt);
        }
        //cout << "end while: " << rt << "    k is: " << k << endl;
    }
    //cout << "now return: " << rt << endl;
    return 0;
}
