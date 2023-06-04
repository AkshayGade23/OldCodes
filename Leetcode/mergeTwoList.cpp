#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergingList(ListNode *list1, ListNode *list2)
{
    ListNode *head1 = list1;
    ListNode *head2 = list2;
    while (head1 != nullptr || head2->next != nullptr)
    {
        if (head2->val <= head1->val && head2->next->val > head1->val)
        {
            ListNode *addingNode = head1;
            head1 = head1->next;
            addingNode->next = head2->next;
            head2->next = addingNode;
            head2 = addingNode;
        }
        else
            head2 = head2->next;
    }
    if (head1->next != nullptr && head2->next == nullptr)
        head2->next = head1;

    return list2;
}
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 != nullptr)
    {
        if (list2 != nullptr)
        {
            if (list1->val > list2->val)
                return mergingList(list1, list2);
            else
                return mergingList(list2, list1);
        }
        return list1;
    }
    return list2;
}
int main()
{

    return 0;
}