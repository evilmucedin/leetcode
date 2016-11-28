#include <cstdlib>

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findDuplicate(const vector<int>& nums) {
        /*
        static constexpr int K = 32;
        vector<size_t> indices(K);
        vector<int> numbers(K);

        for (size_t i = 0; i < K; ++i) {
            indices[i] = rand() % nums.size();
        }
        sort(indices.begin(), indices.end());
        auto toEnd = unique(indices.begin(), indices.end());
        size_t index = 0;
        for (auto it = indices.begin(); it != toEnd; ++it) {
            numbers[index++] = nums[*it];
        }
        sort(numbers.begin(), numbers.begin() + index);
        for (size_t i = 1; i < index; ++i) {
            if (numbers[i - 1] == numbers[i]) {
                return numbers[i];
            }
        }
        */

        for (size_t i = 0; i < 10; ++i) {
            int index1 = rand() % nums.size();
            int index2 = rand() % nums.size();
            if (index1 != index2 && nums[index1] == nums[index2]) {
                return nums[index1];
            }
        }

        int i = nums.size() - 1;
        int j = nums.size() - 1;
        do {
            i = nums[i] - 1;
            j = nums[nums[j] - 1] - 1;
        } while (nums[i] != nums[j]);

        if (i != j) {
            return nums[i];
        }

        int t = nums.back();
        for (int i = 0; (i < nums.size()) && (t != nums[t - 1]); ++i) {
            t = nums[t - 1];
        }
        int q = t;
        int l = 0;
        do {
            ++l;
            q = nums[q - 1];
        } while (q != t);
        int f0 = nums.back();
        int f1 = nums.back();
        for (int i = 0; i < l; ++i) {
            f1 = nums[f1 - 1];
        }
        while (f0 != f1) {
            f0 = nums[f0 - 1];
            f1 = nums[f1 - 1];
        }
        return f0;
    }
};

int main() {
    Solution s;
    cout << s.findDuplicate({2, 1, 1, 1, 4}) << endl;
    cout << s.findDuplicate({2, 1, 2}) << endl;
    cout << s.findDuplicate({2, 2, 2}) << endl;
    cout << s.findDuplicate({1, 2, 2}) << endl;
    cout << s.findDuplicate({1, 2, 4, 3, 4}) << endl;
    return 0;
}
