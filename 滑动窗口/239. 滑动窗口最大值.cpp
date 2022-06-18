#include <vector>
using namespace std;
class Solution {
   public:
    //滑动窗口吗,考虑一下如何按照自己的思想取复刻一个
    //好好思考一下指针的指向
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int s = nums.size();
        if (s == 0)
            return ans;    //返回一个空的vector
        int l = 0, r = 1;  //维护窗口的左右连边;
        int rear = 1;
        int front = 1;
        //第一步把第一个元素压进去
        queue[rear] = nums[0];
        ++rear;

        //知道第一个窗口位置
        while (r < k) {
            int elem = nums[r];
            pushElem(elem, rear, front);
            r++;
        }

        //每次都让r指向窗口的右边
        ans.push_back(queue[front]);
        //滑动窗口的过程
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
    //队列是先进先出
    //这个题是双端队列
    void pushElem(int num, int& rear, int& front) {
        //每次把元素加进去rear指向的是最后一个元素
        int now = rear - 1;
        while (queue[now] < num && now >= front) {
            now--;
        }

        // queue[now]>=num
        //如何把元素插入进去
        // now+1是插入的地方
        // rear则是now+1+1
        //此外我们需要好好设计
        //每次通过指针l和r来判定队首元素是否要出队即可
        queue[now + 1] = num;
        rear = now + 2;
    }
    //使用单调队列,其实是一个双端队列
    int queue[100000 + 10];

    //队列空的条件front==rear
};

//双端队列是这样的