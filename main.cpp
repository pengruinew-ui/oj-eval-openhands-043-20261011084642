#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

struct NODE
{
    int data;
    NODE* prev;
    NODE* next;
    
    NODE(int val) : data(val), prev(nullptr), next(nullptr) {}
};

NODE *head = nullptr, *tail = nullptr;
int len = 0;

void Pre()
{
    // Initialize the list - already done by global initialization
    head = nullptr;
    tail = nullptr;
    len = 0;
}

NODE* move(int i)
{
    // Move to the node at position i (0-based)
    if (i < 0 || i >= len || head == nullptr)
        return nullptr;
    
    NODE* current;
    
    // Optimize by starting from the closer end
    if (i < len / 2) {
        // Start from head
        current = head;
        for (int j = 0; j < i; j++) {
            current = current->next;
        }
    } else {
        // Start from tail
        current = tail;
        for (int j = len - 1; j > i; j--) {
            current = current->prev;
        }
    }
    
    return current;
}

void insert(int i, int x)
{
    // Create new node
    NODE* new_node = new NODE(x);
    
    // Case 1: Insert at beginning (i = 0)
    if (i == 0) {
        if (len == 0) {
            // Empty list
            head = new_node;
            tail = new_node;
        } else {
            // Insert at beginning
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    // Case 2: Insert at end (i = len)
    else if (i == len) {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    // Case 3: Insert in middle
    else {
        NODE* current = move(i);
        if (current != nullptr) {
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
        }
    }
    
    len++;
}

void remove(int i)
{
    if (i < 0 || i >= len || head == nullptr)
        return;
    
    NODE* to_remove;
    
    // Case 1: Remove first node
    if (i == 0) {
        to_remove = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            // List becomes empty
            tail = nullptr;
        }
    }
    // Case 2: Remove last node
    else if (i == len - 1) {
        to_remove = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            // List becomes empty
            head = nullptr;
        }
    }
    // Case 3: Remove middle node
    else {
        to_remove = move(i);
        if (to_remove != nullptr) {
            to_remove->prev->next = to_remove->next;
            to_remove->next->prev = to_remove->prev;
        }
    }
    
    // Delete the node
    delete to_remove;
    len--;
}

int Get_length()
{
    return len;
}

int Query(int i)
{
    if (i < 0 || i >= len) {
        return -1;
    }
    
    NODE* current = move(i);
    if (current != nullptr) {
        return current->data;
    }
    
    return -1;
}

void Print()
{
    if (head == nullptr) {
        cout << -1 << endl;
        return;
    }
    
    NODE* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}

void Clear()
{
    // Delete all nodes to prevent memory leak
    NODE* current = head;
    while (current != nullptr) {
        NODE* next = current->next;
        delete current;
        current = next;
    }
    
    // Reset pointers and length
    head = nullptr;
    tail = nullptr;
    len = 0;
}

}

int n;
int main()
{
    cin >> n;
    int op, x, p, ans;
    LIST::Pre();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op)
        {
            case 0:
                ans = LIST::Get_length();
                cout << ans << endl;
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p, x);
                break;
            case 2:
                cin >> p;
                ans = LIST::Query(p);
                cout << ans << endl;
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                LIST::Print();
                break;
        }
    }
    LIST::Clear();
    return 0;
}