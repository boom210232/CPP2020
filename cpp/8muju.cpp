#include <iostream>
#include <string>

using namespace std;

struct node{
    char character;
    node* next;
    
    node()
        : next(NULL)
    {}
    
    void remove()
    {
        if (next != NULL)
        {
            next->remove();
            delete next;
        }
    }
}
