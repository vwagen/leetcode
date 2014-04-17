#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
class Solution {
    public:    
        vector<int> twoSum(vector<int> &numbers, int target) {        
            int size = numbers.size();        
            int i;        
            int j;
            int flag = 1;
            int max = 0;
            for(i = 0; i < size; i++) {
                max = max >= numbers[i] ? max : numbers[i];
            }
            for(i = 0, j = 1; (i < size - 1) && flag ; i++, j = i+1) {            
                if((target - numbers[i]) > max) {
                    continue;
                }
                for(; j < size; j++) {        
                    if((numbers[i] + numbers[j]) == target) {       
                        flag = 0;      
                        break;     
                    }    
                }
            }   
            vector<int> ret;   
            ret.push_back(i+1);
            ret.push_back(j+1);
            return ret;
        }
};
*/


class Solution {
    public:    
        vector<int> twoSum(vector<int> &numbers, int target) {        
            int size = numbers.size();        
            int i;        
            multimap<int, int> sortnumbers;
            for(i = 0; i < size; i++) {
                sortnumbers.insert(pair<int, int>(numbers[i], i));
            }
            int target_tmp;
            multimap<int, int>::iterator head = sortnumbers.begin();
            multimap<int, int>::iterator tail = sortnumbers.end();
            tail--;
            while(1) {
                target_tmp = (*head).first + (*tail).first;
                if(target_tmp > target) {
                    tail--;
                }
                else if(target_tmp < target) {
                    head++;
                }
                else {
                    break;
                }
            }
            //multimap<int, int>::iterator it_tmp = tail;
            //while(it_tmp != head) {
            //    it_tmp = tail;
            //    it_tmp--;
            //    if((*it_tmp).first != (*tail).first) {
            //        break;
            //    }
            //    tail--;
            //}
            vector<int> ret;   
            int first_index = (*head).second + 1;
            int second_index = (*tail).second + 1;
            int tmp_index;
            if(first_index > second_index) {
                tmp_index = first_index;
                first_index = second_index;
                second_index = tmp_index;
            }
            ret.push_back(first_index);
            ret.push_back(second_index);
            return ret;
        }
};


int main(int argc, char* argv[]) {
    vector<int> v;
    v.push_back(0);
    v.push_back(4);
    v.push_back(3);
    v.push_back(0);
    Solution s;
    vector<int> ret = s.twoSum(v, 0);
    cout << "ret.size(): " << ret.size() << endl;
    cout << "ret[0]: " << ret[0] << " ret[1]: " << ret[1] << endl;
    return 0;
}
