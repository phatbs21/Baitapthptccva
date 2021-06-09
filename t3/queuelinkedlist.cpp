#include <iostream>
using namespace std;
template <class KIEU>
class DSLKDOI
{
private:
    struct Node
    {
        KIEU data;
        Node *prev, *next;
    };
    Node *head, *tail;
    Node *makeNode(KIEU value)
    {
        Node *p = new Node;
        p->data = value;
        p->prev = NULL;
        p->next = NULL;
        return p;
    }

public:
    DSLKDOI()
    {
        head = tail = NULL;
    }
    ~DSLKDOI()
    {
        clearAll();
    }
    void addTail(KIEU value)
    {
        Node *p = makeNode(value);
        if (head == NULL)
            head = tail = p;
        else
        {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }
    void deleteHead()
    {
        if (head == NULL)
            return;
        Node *p = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
            delete p;
        }
        else
        {
            head->prev = NULL;
            delete p;
        }
    }
    void deleteTail()
    {
        if (tail == NULL)
            return;
        Node *p = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
            delete p;
        }
        else
        {
            tail->next = NULL;
            delete p;
        }
    }
    int getAtTail()
    {
        if (tail != NULL)
            return tail->data;
    }
    int getSize()
    {
        Node *p = head;
        int dem = 0;
        while (p != NULL)
        {
            dem++;
            p = p->next;
        }
        return dem;
    }
    void clearAll()
    {
        Node *p = head;
        while (p != NULL)
        {
            head = head->next;
            delete p;
            p = head;
        }
        tail = NULL;
    }
};
template <class KIEU>
class Stack : public DSLKDOI<KIEU>
{
public:
    void push(KIEU value)
    {
        DSLKDOI<int>::addTail(value);
    }
    void pop()
    {
        DSLKDOI<KIEU>::deleteTail();
    }
    KIEU top()
    {
        return DSLKDOI<KIEU>::getAtTail();
    }
    int size()
    {
        return DSLKDOI<KIEU>::getSize();
    }
    bool isEmpty()
    {
        return size() == 0;
    }
};
template <class KIEU>
class Queue : public DSLKDOI<KIEU>
{
public:
    void push(KIEU value)
    {
        DSLKDOI<int>::addTail(value);
    }
    void pop()
    {
        DSLKDOI<KIEU>::deleteHead();
    }
    KIEU top()
    {
        return DSLKDOI<KIEU>::getAtTail();
    }
    int size()
    {
        return DSLKDOI<KIEU>::getSize();
    }
    bool isEmpty()
    {
        return size() == 0;
    }
};

int main()
{
    Queue<int> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        s.push(val);
        cout << s.top() << " ";
    }
    cout << "\n"
         << s.size() << " " << s.isEmpty()<<" ";
    for (int i = 1; i <= n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n"
         << s.size() << " " << s.isEmpty();
    return 0;
}
