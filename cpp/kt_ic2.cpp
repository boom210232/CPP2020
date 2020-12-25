#include <iostream>


using namespace std;

typedef int ValueT;

struct ListNode {
  ValueT val;
  ValueT flavor;
  ListNode* next;

  ListNode(ValueT val, ValueT flavor,ListNode* next=0)
    : val(val), flavor(flavor), next(next) {}
};

ListNode* front;
ListNode* rear;

void init_queue()
{
  front = rear = 0;
}

void insert_queue(ValueT v, ValueT f)
{
  ListNode* new_node = new ListNode(v, f);

  if(rear != 0) {
    rear->next = new_node;
    rear = new_node;
  } else {
    front = rear = new_node;
  }
}

pair<ValueT, ValueT> extract_queue()
{
  if(front != 0) {
    pair<ValueT, ValueT> ice_cream;
    ice_cream.first = front->val;
    ice_cream.second = front->flavor;

    ListNode* new_front = front->next;
    delete front;
    front = new_front;

    if(front == 0) {
      rear = 0;
    }
    
    return ice_cream;
  } else {
    throw "Error extract from empty queue";
  }
}

bool is_queue_empty()
{
  return (front == 0);
}

int M, T, N;
int sold_flavor[20] = {0};

int main()
{
    cin >> M;

    int id, flavor;
    pair<ValueT, ValueT> ice_cream;
    int customer = 0;

    for (int i=0; i<M; i++) {
        cin >> T;
        if (T == 1)
        {
            // add customer to queue
            cin >> T;
            for (int i=0; i<T; i++) {
                cin >> id >> flavor;
                insert_queue(id, flavor);
                customer++;
            }
        } 
        else if ( T == 2)
        {
            // remove customer from queue
            ice_cream = extract_queue();
            cout << ice_cream.first << endl;
            sold_flavor[ice_cream.second-1]++;
            customer--;
        }
    }
    cout << customer << endl;

    for (int i=0; i<20; i++){
        cout << sold_flavor[i] << " ";
    }
}
