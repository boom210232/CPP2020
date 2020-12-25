#include <iostream>

using namespace std;

typedef int cardNum;

struct ListNode
{
    cardNum val;
    ListNode *next;

    ListNode(cardNum val, ListNode *next = nullptr)
        : val(val), next(next) {}
};

int main()
{
    int n, m;
    cin >> n >> m;

    auto *header = new ListNode(0);
}
