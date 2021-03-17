#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    int getCandy(vector<int> &ratings, int &candy_num, int min_index, int delta, int index_bound) {
        int next_candy = 0;
        int next_index = min_index + delta;
        while(next_index != index_bound) {
            next_candy++;
            next_index += delta;
            candy_num += next_candy;
        }
        return next_candy;
    }
    int candy(vector<int> &ratings) {
        int length = ratings.size();
        int candy_num;
        int all_candy = 0;
        int search_index = 0;
        int left_index;
        int right_index;
        int left_max_candy_num;
        int right_max_candy_num;
        int max_index;
        while(search_index < length) {
            left_index = search_index;                                 // Set the left bound of a peak
            while(search_index < length - 1 && ratings[search_index] < ratings[search_index + 1]) {
                search_index++;
            }
            max_index = search_index;                                  // get the index of peak
            while(search_index < length - 1 && ratings[search_index] > ratings[search_index + 1]) {
                search_index++;
            }
            right_index = search_index;                                // Set the right bound of a peak

            candy_num = 0;
            if(left_index > 0 && ratings[left_index - 1] < ratings[left_index]) {   // When (left_index - 1) get less candy
                left_max_candy_num = getCandy(ratings, candy_num, max_index, -1, left_index - 2);   // Get candies in left side of peak, and get max candy num of left side
                candy_num--;
            }
            else {                          // When there is no (left_index - 1) or if there be one, the rating of (left_index - 1) equals that of (left_index)
                left_max_candy_num = getCandy(ratings, candy_num, max_index, -1, left_index - 1);
            }
            right_max_candy_num = getCandy(ratings, candy_num, max_index, +1, right_index + 1);    // Get candies in right side of peak, and get max candy num of right side
            candy_num += left_max_candy_num > right_max_candy_num ? (left_max_candy_num + 1) : (right_max_candy_num + 1); // Get candy of peak rating
            all_candy += candy_num;           //Get candies of this peak
            search_index++;                   //Ready to search next peak
        }
        return all_candy;
    }
};

int main(int argc, char* argv[]) {
    vector<int> ratings;
    ratings.push_back(4);
    ratings.push_back(2);
    ratings.push_back(3);
    ratings.push_back(4);
    ratings.push_back(1);
    Solution s;
    copy(ratings.begin(), ratings.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "Result: " << s.candy(ratings) << endl;
    return 0;
}
