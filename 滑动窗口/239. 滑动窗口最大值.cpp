#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int s = nums.size();
        if (s == 0)
            return ans;    //返回一个空的vector
        int l = 0, r = 1;  //维护窗口的左右连边;
        int rear = 1;
        int front = 1;
        queue[rear] = nums[0];
        ++rear;
        while (r < k) {
            int elem = nums[r];
            pushElem(elem, rear, front);
            r++;
        }
        ans.push_back(queue[front]);
        while (r < s) {
            if (queue[front] == nums[l])
                front++;
            pushElem(nums[r], rear, front);
            l++;
            r++;
            ans.push_back(queue[front]);
        }
        return ans;
    }

   private:
    void pushElem(int num, int& rear, int& front) {
        int now = rear - 1;
        while (queue[now] < num && now >= front) {
            now--;
        }

        queue[now + 1] = num;
        rear = now + 2;
    }
    int queue[100000 + 10];
};
