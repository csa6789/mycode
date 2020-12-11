//dfs 排列，组合，子集

/* 子集 */

vector<vector<int>> subsets(vector<int>& nums)
{
    vecotr<int> track;
    vector<vector<int>> res;
    backtrackdfs(nums,0,track);
}

void backtrackdfs(vector<int>& nums, int start, vector<int> &track)
{
     res.push_back(track);

     for(int i = start; i < nums.size(); i++) {

         track.push_back(nums[i]);
         backtrackdfs(nums,i+1,track);
         track.pop_back();
     }
}
// 组合 类似子集

vector<vector<int>>res;

vector<vector<int>> combine(int n, int k) {
    if (k <= 0 || n <= 0) return res;
    vector<int> track;
    backtrack(n, k, 1, track);
    return res;
}

void backtrack(int n, int k, int start, vector<int>& track) {
    // 到达树的底部
    if (k == track.size()) {
        res.push_back(track);
        return;
    }
    // 注意 i 从 start 开始递增
    for (int i = start; i <= n; i++) {
        // 做选择
        track.push_back(i);
        backtrack(n, k, i + 1, track);
        // 撤销选择
        track.pop_back();
    }
}


//排列

vector<vector<int>>res;

vector<vector<int>> permute(vector<int>& nums) {
   
    vector<int> track;
    backtrack(nums, track);
    return res;
}

void backtrack(vector<int>& nums, vector<int>& track) {
    // 到达树的底部
    if (nums.size() == track.size()) {
        res.push_back(track);
        return;
    }
    vector<bool> visited(nums.size(),0);
        // 注意 i 从 start 开始递增
    for (int i = 0; i <= n; i++) {
        // 做选择
        if(visited[i]){
            continue;
        }
        visited[i]=1;
        track.push_back(i);
        backtrack(nums, track);
        // 撤销选择
        visited[i]=0;
        track.pop_back();
    }
}

