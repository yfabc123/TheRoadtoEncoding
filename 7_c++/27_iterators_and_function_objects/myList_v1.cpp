/*
实现一个list
1.构造
2.pushfront
3.pushback
4.迭代器类 包括运算符重载 前置++ 后置++  指针操作->   * ==  !=
5.begin 返回迭代器 end 返回迭代器
 */
#include <iostream>
using namespace std;
// 假设左边是:front prev   右边end next
class Node
{
public:
    // 三种情况
    Node(string val, Node *head, Node *tail)
    {
        // 第一次
        if (!head && !tail)
        {
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
        // front插
        else if (head)
        {
            this->val = val;
            this->next = head;
            this->prev = NULL;
            head->prev = this;
        }
        // end插
        else if (tail)
        {
            this->val = val;
            this->prev = tail;
            this->next = NULL;
            tail->next = this;
        }
    }
    // private://设为私有太难受了 注释掉
    Node *next;
    Node *prev;
    string val;
};

class List
{
public:
    class iterator // 迭代器的本质就是经过封装的指向list每一个节点的指针
    {
    public:
        iterator operator++(int)
        {
            iterator temp;
            temp = *this;
            this->itr = this->itr->next;
            return temp;
        }
        iterator &operator++()
        {
            this->itr = this->itr->next;
            return *this;
        }
        string operator*()
        {
            return itr->val;
        }
        bool operator!=(const iterator &i)
        {
            if (this->itr != i.itr)
            {
                return 1;
            }
            return 0;
        }
        bool operator==(iterator &i)
        {
            if (this->itr == i.itr)
            {
                return 1;
            }
            return 0;
        }
        // private:
        Node *itr;
    };
    List()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    iterator list_begin()
    {
        iterator temp;
        temp.itr = this->head;
        return temp;
    }
    iterator list_end()
    {
        iterator temp;
        temp.itr = this->tail->next;
        return temp;
    }

    void push_front(string value)
    {
        if (!this->head)
        {
            Node *temp = new Node(value, NULL, NULL);
            this->head = temp;
            this->tail = temp;
        }
        else
        {
            Node *temp = new Node(value, head, NULL);
            head = temp;
        }
    }
    void push_back(string value)
    {
        if (!this->tail)
        {
            Node *temp = new Node(value, NULL, NULL);
            this->head = temp;
            this->tail = temp;
        }
        else
        {
            Node *temp = new Node(value, NULL, tail);
            tail = temp;
        }
    }

private:
    Node *head;
    Node *tail;
};
int main()
{
    List list;
    list.push_back("5");
    list.push_front("1");
    list.push_front("2");
    list.push_front("3");
    list.push_front("4");
    list.push_back("5");
    for (List::iterator it = list.list_begin(); it != list.list_end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
