#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int eliminate_dots_and_slashs(int slash_index, int slash_index_last, string &path, stack<int> &slash_stack) {
        string tmp = path.substr(slash_index_last + 1, slash_index - slash_index_last - 1);
        if(tmp == ".") {
            path.erase(slash_index_last + 1, slash_index - slash_index_last);
            return slash_index_last;
        }
        else if(tmp == "..") {
            if(slash_index_last != 0) {
                slash_stack.pop();
                slash_index_last = slash_stack.top();
            }
            path.erase(slash_index_last + 1, slash_index - slash_index_last);
            return slash_index_last;
        }
        else {
            return slash_index;
        }
    }
    string simplifyPath(string path) {
        int slash_index = 0;
        int slash_index_last = 0;
        stack<int> slash_stack;
        slash_stack.push(0);
        do {
            while(slash_index < path.size() - 1 && path[slash_index + 1] == '/') {
                path.erase(slash_index + 1, 1);
            }
            slash_index_last = slash_index;
            if(slash_stack.top() != slash_index) {
                slash_stack.push(slash_index);
            }
            slash_index = path.find('/', slash_index + 1);
            slash_index = eliminate_dots_and_slashs(slash_index, slash_index_last, path, slash_stack);
        }while(slash_index != string::npos);

        slash_index = path.size();
        eliminate_dots_and_slashs(slash_index, slash_index_last, path, slash_stack);
        if(path.size() != 1 && *(path.rbegin()) == '/') {
            path.erase(path.size() - 1, 1);
        }
        return path;
    }
};

int main(int argc, char* argv[]) {
    //string ss("/home/c/../../usr////a/./b/");
    string ss("//aaa////bbb/..");
    if(argc == 2) {
        ss = argv[1];
    }
    Solution s;
    cout << "Path \"" << ss << "\" " << "after simplification is:" << endl;
    cout << s.simplifyPath(ss) << endl;
    //bool ret = s.();
    //if(ret) {
    //    cout << "This is a palindrom!" << endl;
    //}
    //else {
    //    cout << "This is not a palindrom!" << endl;
    //}
    return 0;
}
