
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <numeric>
#define Length 15
using std::vector;

int candy(vector<int>& ratings) {
	int size = ratings.size();
	if(size < 2) {
		return size;
	}
	vector<int> num(size,1);

	for(int i = 1; i < size; ++i) {
		if(ratings[i] > ratings[i-1]) {
			num[i] = num[i-1] + 1;
		}
	}
	for(int i = size-1; i >0; --i) {
		if(ratings[i-1] > ratings[i]) {
			num[i-1] = max(num[i-1], num[i] + 1);
		}
	}
	return accumulate()

}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	if(intervals.empty()) {  //参数检查，异常条件，边界条件
		return 0;
	}
	int n = intervals.size();
	sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
		return a[1] < b[1];
	});
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int pos = m + n - 1;
	while(m>=0 && n>=0) {
		nums1[pos--] = nums1[m] > nums2[n]? nums1[m--]:nums2[n--];	
	}
	while(n>=0) {
		nums1[pos--]=nums2[n--];
	}
}
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(nullptr) {}
};

vector<int> subarrySumClosest(vector<int> &nums) {

	int n = nums.size();
	vector<pair<int,int>> s(n);
	vector<int> res(2);

	if(n=0|n=1) {
		res[0] = 0;
		res[1] = 1;
		return res;
	}

	int sum = 0;
	for(int i=0;i<n;i++) {
		sum+ = num[i];
		s[i].first = sum;
		s[i].second = i;
	}
	sort(s.begin(),s.end());
	int ans = 100000;
	for(int i=0;i<n-1;i++) {
		if(abs(s[i+1].first-s[i].first)<ans) {
			ans = abs(s[i+1].first-s[i].first);
			res[0]
			
		}

	}
}

//单调队列，前后插入删除，每个窗口前进的时候，要添加一个数同时减少一个数，所以想在 O(1)O(1) 的时间得出新的最值，就需要「单调队列」这种特殊的数据结构来辅助了。
class deque {
    // 在队头插入元素 n
    void push_front(int n);
    // 在队尾插入元素 n
    void push_back(int n);
    // 在队头删除元素
    void pop_front();
    // 在队尾删除元素
    void pop_back();
    // 返回队头元素
    int front();
    // 返回队尾元素
    int back();
};

class MonotonicQueue {
	private:
		deque<int> data;
	public:
		void push(int n)
		{
			while(!data.empty()&&data.back()<n)
				data.pop_back();
			data.push_back(n);
		}
		int max()
		{
			retun data.front();
		}
		void pop(int n){
			if(!data.empty()&&data.front()==n)
				data.pop_front;
		}
};

vectorr<int> maxSlidingWindow(vector<int> &nums, int k)
{
	MonotonicQueue window;
	vector<int> res;
	for(int i = 0; i < k-1; ++i) {
		window.push(nums[i]);
	}
	res.push_back(window.max());
	for(int i=k-1; i<nums.size(); ++i){
		window.push(nums[i]);
		res.push_back(window.max());
		window.pop(nums[i-k+1]);
	}
	return res;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	if (k==0) return {};

	vector<int> res;
	deque<int> window;

	for(int i = 0; i < k; i++) {
		
		while (!window.empty()&&nums[window.back()]<nums[i])
		{
			window.pop_back();
		}
		window.push_back(i);
		
	}
	res.push_back(nums[window.front()]);
	for(int i = k; i < nums.size(); i++) {
		while(!window.empty()&&i-k>=window.front())
			window.pop_front();
		while (!window.empty()&&nums[window.back()]<nums[i])
		{
			window.pop_back();
		}
		window.push_back(i);
		res.push_back(nums[window.front()]);

	}
	return res;
		
	
}


//排序
//001 快熟排序

void quick_sort(vector<int>& nums, int l, int r)
{
	//check
//	if (l>=r)

	int i = l, j = r, key=nums[l];//选第一个为基准
	while(i<j){
		while (i < j && nums[j]>=key)
		{
			/* code */
			j--;
		}
		nums[i]=nums[j];
		while (i < j && nums[j]<=key)
		{
			/* code */
			j--;
		}
		nums[j]=nums[i];
		
	}
	nums[i]==key;
	quick_sort(nums,l,i-1);
	quick_sort(nums,i+1,r);
}

//归并排序，递归，排序一半，利用附加空间  分而治之
void merge_co(vector<int>& nums, int l,int r, int mid, vector<int> &temp)
{
	int i =l, j = mid+1, t=0;
	while(i<=mid&&j<=r) {
		temp[t++]=nums[i]<nums[j]? nums[i++]:nums[j++];
	}
	while (i<=mid)
	{
		temp[t++]=nums[i++];
	}
	while (j<=r)
	{
		/* code */
		temp[t++]= nums[j++];
	}
	for() { //拷贝到原来数组

	}
	
	
}
void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp) {
	if(l+1>=r){}
	int m = l + (r-l)/2;
	merge_sort(nums,l,m,temp);
	merge_sort(nums, m, r, temp);
	int p = l, q =m, i =;
	merge_co(nums,l,r,m,temp);
}

//冒泡 标记
void bubble_sort(vector<int>& nums , int n)
{
	bool swapped;
	for(int i = 0; i < n; i++) {
		swapped = false;
		for(int j = 1; j < n-i+1; j++){
			if(nums[j]<nums[j-1]){
				swap(nums[j],nums[j-1]);
				swapped = true;
			}
		}
		if(!swapped){
			break;
		}
	}
}

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        int n = airplanes.size();
        vector<pair<int,int>> setAirplanes(2*n);
        
        for(int i = 0; i<n; i++) {
            setAirplanes[2*i].first = airplanes[i].start;
            setAirplanes[2*i].second = 1;
            setAirplanes[2*i+1].first = airplanes[i].end;
            setAirplanes[2*i+1].second = 0;
        }
        sort(setAirplanes.begin(), setAirplanes.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.first< b.first||(a.first==b.first&&a.second<b.second);
        });
        int count=0, ans=0;
        for(int i=0; i<2*n; i++) {
            if(setAirplanes[i].second) {
                count++;
            } else {
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};


//快速排序，选择

int Partition(int data[], int length, int start, int end)
{
	if(data == nullptr|| length <= 0|| start < 0 || end >= length)
		throw new std::exception("Invalid Parameters");

	int index = RandomInRange(start, end);

	Swap(&data[index], &data[end]);
	int small = start-1;
	for(int i = start; i < end; ++i) {
		if(data[i] < data[end]) {
			++small;
			if(small != i)
				Swap(&data[small], &data[i]);
		}
	}
	++small;
	Swap(&data[small],&data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if(start==end)
		return;
	int index = Partition(data,length,start,end);
	if(index > start)
		QuickSort(data, length, start, index-1);
	if(index < end)
		QuickSort(data, length, index+1, end);

}

int QuickSelect(int data[], int length, int start, int end, int k)
{
	if(start == end || k <1|| start+k-1>end)
		return error;
	int target = start + k -1 ;
	
	while(start < end) {

		int index = Partition(data, length, start, end);

		if(index == target) {
			return data[index];
		}

		if(index < target) {
			start = index+1;
		} else if(index >target) {
			end = index-1;
		}
		return data[start];

	}
}