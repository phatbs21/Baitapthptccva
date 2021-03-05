#include <iostream>

using namespace std;

template <class KIEU>
class DSLKDOI
{
	struct Node
	{
		KIEU data;
		Node *prev, *next;
	};
	Node *head, *tail;
	//ham tao nut moi
	Node * makeNode(KIEU d) {
		Node * p = new Node;
		p->data=d;
		p->next=NULL;
		p->prev=NULL;
		return p;
	}
public:
	DSLKDOI() {
		head=tail=NULL;
	}
	~DSLKDOI() {
		//Xoa danh sach de giai phong bo nho
		clearAll();
	}
	void printList() {
		Node * p;
		p = head;
		if (head==NULL)
		{
			cout<<"DS rong"<<endl;
			return;
		}
		while (p!=NULL) {
			cout<<p->data<<" ";
			p=p->next;
		}
	}
	void add2Head(KIEU d) {
		Node * p = makeNode(d);
		if (head==NULL) {
			head=tail=p;
		}
		else {
			p->next=head;
			head->prev=p;
			head=p;
		}
	}
	void add2Tail(KIEU d) {
		Node *p= makeNode(d);
		if (head==NULL)
		{
			head=tail=p;
		}
		else {
			tail->next=p;
			p->prev=tail;
			tail=p;
		}
	}
	void removeHead() {
		if (head==NULL) return;
		Node *p = head;
		head=head->next;
		if (head==NULL) {
			tail=NULL;
		}
		else {
			head->prev=NULL;
		}
		delete p;
	}
	void clearAll() {
		Node *p = head;
		while (p!=NULL)
		{
			head=head->next;
			delete p;
			p=head;
		}
		tail=NULL;
	}
	int getSize() {

	}

};

int main()
{
    DSLKDOI<int> ds;
    ds.add2Head(3);
    ds.add2Head(5);
    ds.add2Tail(4);
    ds.add2Head(8);
    ds.add2Tail(7);
    ds.removeHead();
    //ds.clearAll();
    ds.printList();
    return 0;
}
