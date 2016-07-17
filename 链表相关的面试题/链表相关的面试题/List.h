#pragma once
#include"Configer.h"

template<class T>
struct ListNode
{
	ListNode(T value) 
	:_value(value), _next(NULL)
	{}
	T _value;
	ListNode<T>* _next;
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List() :_head(NULL)
	{}
	List(T value) :_head(new Node(value))
	{}

	void Insert(vector<T>& Vector)
	{
		Node* tmp = new Node(Vector[0]);
		if (_head == NULL)
			_head = tmp;
		else
			_head->_next = tmp;
		for (int i = 1; i < Vector.size();++i)
		{
			tmp->_next = new Node(Vector[i]);
			tmp = tmp->_next;
		}		
	}
	Node* Find(T value)
	{
		Node* tmp = _head;
		while (tmp)
		{
			if (tmp->_value == value)
				return tmp;
			tmp = tmp->_next;
		}
		return NULL;
	}
	void Show()
	{
		Node* tmp = _head;
		while (tmp)
		{
			cout << tmp->_value << " -> ";
			tmp = tmp->_next;
		}
		cout << "NULL" << endl;
	}

	/*面试题*/
	//1.逆序打印单链表
	void PrintTailToHead(Node * pHead);

	//2.删除无头节点的单链表的非尾节点
	void DelNonTailNode(Node * pos);

	//3.在非头节点前添加一个节点
	void InsertFrontNode(Node* pos, T x);

	//4.逆序单链表
	void ReverseList();

	//5.单链表的冒泡排序
	void BubbleSortOfList();

	//6.查找单链表的中间节点
	Node* MiddleOfList();

	//7.倒数第k个节点 
	Node* ReciprocalK(int k);

	//8.判断一个链表是否带环，如果带环求出环的长度以及入口点
	Node* IsRingList();

	//9.判断两个链表是否相交，如果相交求出交点(不带环)
	Node* IsCross(const List<T>& List1, const List<T>& List2);

	//10.判断两个链表是否相交，如果相交求出交点(加强版)
	Node* IsCrossStrengthen(const List<T>& List1, const List<T>& List2);

	//11.排序链表中相同的元素
	void TheSameInTwoList(const List<T>& List1, const List<T>& List);
public:
	Node* _head;
};




