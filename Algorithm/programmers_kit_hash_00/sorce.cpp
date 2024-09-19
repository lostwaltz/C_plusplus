#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(void)
{
    vector<int> nums = {3, 1, 2, 3, 6, 6};

    int answer = 0;
    int nums_half_size = nums.size() / 2;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    answer = nums_half_size > nums.size() ? nums.size() : nums_half_size;

    cout << answer << " ";


    return 0;
}