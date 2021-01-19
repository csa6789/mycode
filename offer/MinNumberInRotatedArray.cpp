#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

int MinInOrder(int* numbers, int index1, int index2);

int Min(int* numbers, int length)
{
    if(numbers == nullptr || length <0)
        throw new exception("queue is empty");

    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;

    while (numbers[index1] >= numbers[index2]) {
        if(index2 - index1 == 1) {
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2) / 2;

        if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
            return MinInOrder(numbers, index1, index2);
        if(numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if(numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
    }

    return numbers[indexMid];
    
}

int MinInOrder(int* numbers, int index1, int index2)
{
    int result = numbers[index1];
    for(int i = index1 + 1; i <= index2; ++i) {
        if(result > numbers[i])
            result = numbers[i];
    }

    return result;
}


bool search(vector<int>& nums, int target)
{
    int start = 0, end = nums.size() -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if(nums[mid] == target)
            return true;
        if(nums[start] == nums[mid]) {
            ++start;
        } else if (nums[mid] <= nums[end]) {
            if(target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;              
            }
            
        } else {
             if(target < nums[mid] && target >= nums[start]) {
                end = mid - 1;
            } else {
                start = mid + 1;              
            }           
        }
    }
    return false;
    
}