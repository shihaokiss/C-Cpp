#pragma once
#include"List.h"

//1.逆序打印单链表
template<class T>
void List<T>::PrintTailToHead(Node * pHead)
{
	if (pHead == NULL)
		return;
	PrintTailToHead(pHead->_next);
	cout << pHead->_value << " -> ";
}

//2.删除无头节点的单链表的非尾节点
template<class T>
void List<T>::DelNonTailNode(Node * pos)
{
	assert(pos && pos->_next);
	Node* tmp = pos->_next;
	pos->_value = tmp->_value;
	pos->_next = tmp->_next;
	delete tmp;
}

//3.无头单链表某一节点前插入一个节点
template<class T>
void List<T>::InsertFrontNode(Node* pos, T x)
{
	assert(pos);
	Node* tmp = new Node(x);
	tmp->_next = pos->_next;
	pos->_next = tmp;
	swap(pos->_value, tmp->_value);
}


//4.逆置单链表
template<class T>
void List<T>::ReverseList()
{
	Node* cur = _head, *new_head = NULL, *tmp;
	while (cur)
	{
		tmp = cur;
		cur = cur->_next;
		tmp->_next = new_head;
		new_head = tmp;
	}
	_head = new_head;
}

//5.单链表的冒泡排序
template<class T>
void List<T>::BubbleSortOfList()
{
	if (_head == NULL || _head->_next == NULL)
		return;
	Node* tail = NULL,*cur;
	bool sign = true;
	while (tail != _head && sign)
	{
		Node* tmp = NULL;
		cur = _head;
		while (cur->_next != tail)
		{
			if (cur->_value > cur->_next->_value)
			{
				swap(cur->_value, cur->_next->_value);
				tmp = cur;
			}
			cur = cur->_next;
		}
		tmp == NULL ? sign = false : tail = cur;;
	}
}

//6.中间节点
template<class T>
ListNode<T>* List<T>::MiddleOfList()
{
	if (_head == NULL || _head->_next == NULL)
		return NULL;
	Node* fast = _head, *slow = _head;
	while (fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
	}
	return slow;
}

//7.单链表中的倒数第 k 个节点
template<class T>
ListNode<T>* List<T>::ReciprocalK(int k)
{
	if (_head == NULL)
		return NULL;
	Node* tmp = _head, *result = _head;
	while (k--)
	{
		tmp = tmp->_next;
		if (tmp == NULL)
			return (k == 0 ? _head : NULL);
	}
	while (tmp)
	{
		result = result->_next;
		tmp = tmp->_next;
	}
	return result;
}

//8.判断一个链表是否带环，如果带环求出环的长度以及入口点
template<class T>
ListNode<T>* List<T>::IsRingList()
{
	if (_head == NULL)
		return false;
	Node* fast = _head,* slow = _head,* Input;
	while (fast && fast->_next)
	{
		if (fast == slow)     //链表带环 输出环的长度和入口点
		{
			int count = 1;
			do
			{
				slow = slow->_next;
				fast = fast->_next->_next;
				++count;
			} while (fast == slow);
			cout << "环的节点的个数为：" << count << endl;

			while (Input == slow)
			{
				Input = Input->_next;
				slow = slow->_next;
			}
			return Input;
		}
	}
	return NULL;
}

//9.判断两个链表是否相交，如果相交求出交点(不带环)
template<class T>
ListNode<T>* List<T>::IsCross(const List<T>& List1, const List<T>& List2)
{
	Node* Tmp1 = List1._head, Tmp2 = List2._head;
	int Length1 = 0, Length2 = 0;
	while (Tmp1)
	{
		Length1++;
		Tmp1 = Tmp1->_next;
	}
	while (Tmp2)
	{
		Length2++;
		Tmp2 = Tmp2->_next;
	}

	Tmp1 = List1._head, Tmp2 = List2._head;   /*重新指向链表的头*/
	int n = abs(Length1 - Length2);
	if (Length1 > Length2)        /*如果链表一 长于 链表二*/
	{
		while (n--)
		{
			Tmp1 = Tmp1->_next;
		}
	}
	else                          /*如果链表二 长于 链表一*/
	{
		while (n--)
		{
			Tmp2 = Tmp2->_next;
		}
	}

	while (Tmp1)
	{
		if (Tmp1 == Tmp2)
			return Tmp1;        /*找到了交点，返回*/
		else
		{
			Tmp1 = Tmp1->_next;
			Tmp2 = Tmp2->_next;
		}
	}
	return NULL;                /*没找到，NULL 返回*/
}


//10.判断两个链表是否相交，如果相交求出交点(不确定带不带环)
template<class T>
ListNode<T>* List<T>::IsCrossStrengthen(const List<T>& List1, const List<T>& List2)
{
	Node* Cross1 = List1.IsRingList(), *Cross2 = List2.IsRingList();
	if (Cross1 == NULL && Cross2 == NULL)   /*两个链表均不带环*/
		return List1.IsCross(List1, List2);
	else if (Cross1 && Cross2)   /*两个均代环*/
	{
		if (Cross1 == Cross2)
			return Cross1;
		Node* tmp = Cross1->_next;
		while (tmp != Cross1)
		{
			if (Cross1 == Cross2)
				return Cross1;
			tmp = tmp->_next;
		}
	}
	return false;    /*一个链表带环，一个不带环*/
}


//11.排序链表中相同的元素
template<class T>
void List<T>::TheSameInTwoList(const List<T>& List1, const List<T>& List2)
{
	Node* Tmp1 = List1._head,* Tmp2 = List2._head;
	while (Tmp1 != NULL && Tmp2 != NULL)
	{
		if (Tmp1->_value == Tmp2->_value)
		{
			cout << Tmp1->_value << endl;
			Tmp1 = Tmp1->_next;
			Tmp2 = Tmp2->_next;
		}
		else if (Tmp1->_value > Tmp2->_value)
			Tmp2 = Tmp2->_next;
		else
			Tmp1 = Tmp1->_next;
	}
}