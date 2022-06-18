#include <iostream>
#include <vector>
using namespace std;
//先测试一下类

// class Animal
// {
// private:
//     string name;

// public:
//     Animal(string name)
//     {
//         this->name = name;
//     }
//     void Bark()
//     {
//         cout << "Animal Bark" << endl;
//     }
// };
// class Cat : public Animal
// {
// public:
//     Cat(string name) : Animal(name){}; //采用这种方法写构造函数
//     // void Bark()
//     // {
//     //     cout << "Cat Bark" << endl;
//     // }
//     void test()
//     {
//         this->Bark();
//         this->Animal::Bark();
//         //这也就是说在这个derived
//         class中,继承的函数名字仍然叫Animal::function()
//         //但是可以通过重写函数来来实现,有点类似于函数重载的样子
//         //故而要不留歧义的使用基类的方法,请加上Base_class::function()
//         }
// };
// int main()
// {
//     Cat mycat("tom");
//     mycat.test();
//     return 0;
// }
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */
class Iterator {
    struct Data;
    Data* data;

   public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    int next();
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
   public:
    //这个题的本意是对迭代器的进一步封装
    //学习一下迭代器的思想
    //然后了解一下类的继承机制
    int _next;
    bool _has_next;
    //学习一下这个构造函数的写法,继承构造函数
    //可以直接继承掉私有的变量
    //换言之struct Data, Data
    //*data还是再这个class里面,但是不能直接访问,所以直接采取基类的构造函数初始化
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        //注意写法,要调用基类的方法不是使用this指针
        _has_next = Iterator::hasNext();  //有一个疑问
        if (_has_next)
            _next = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() { return _next; }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ret = _next;
        _has_next = Iterator::hasNext();
        if (_has_next)
            _next = Iterator::next();
        return ret;
    }

    bool hasNext() const { return _has_next; }
};