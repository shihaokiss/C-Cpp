#include"List.h"
#include"Interview.h"

void Test()
{
	vector<int> Vector = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	List<int> list;
	list.Insert(Vector);
	list.Show();
	list.PrintTailToHead(list._head);
	cout <<"NULL"<< endl;
	ListNode<int>* Node = list.Find(0);
	list.DelNonTailNode(Node);
	list.Show();
}

void main()
{
	Test();
}