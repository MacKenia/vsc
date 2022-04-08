/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1, *t2 = l2;
        ListNode *r = nullptr, *t = nullptr;
        int T = t1->val + t2->val;
        t = r = new ListNode(one(T),nullptr);
        t = t->next;
        t1 = t1->next;
        t2 = t2->next;
        while (true)
        {
            t = new ListNode(ten(T), nullptr);
            T = t->val + t1->val + t2->val;
            t->val = one(T);
            if(!t1->next || !t2->next)
            {
                if (!t1->next)
                {
                    t->next = t2->next;
                }
                else
                {
                    t->next = t1->next;
                }
                
                while ()
                {
                    t->val = one(ten(T)+t->val);
                    T = ten(T) + t->next->val;
                    t = t->next;
                }
                break;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return r;
    }

    int one(int a)
    {
        return a%10;
    }

    int ten(int a)
    {
        return a/10;
    }
};
// @lc code=end

