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