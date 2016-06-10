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
public:
	Node* _head;
};




