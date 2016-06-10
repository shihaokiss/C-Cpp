#pragma once
#include"List.h"

//1.�����ӡ������
template<class T>
void List<T>::PrintTailToHead(Node * pHead)
{
	if (pHead == NULL)
		return;
	PrintTailToHead(pHead->_next);
	cout << pHead->_value << " -> ";
}

//2.ɾ����ͷ�ڵ�ĵ�����ķ�β�ڵ�
template<class T>
void List<T>::DelNonTailNode(Node * pos)
{
	assert(pos && pos->_next);
	Node* tmp = pos->_next;
	pos->_value = tmp->_value;
	pos->_next = tmp->_next;
	delete tmp;
}

//3.��ͷ������ĳһ�ڵ�ǰ����һ���ڵ�
template<class T>
void List<T>::InsertFrontNode(Node* pos, T x)
{
	assert(pos);
	Node* tmp = new Node(x);
	tmp->_next = pos->_next;
	pos->_next = tmp;
	swap(pos->_value, tmp->_value);
}


//4.���õ�����
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

//5.�������ð������
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

//6.�м�ڵ�
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

//7.�������еĵ����� k ���ڵ�
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