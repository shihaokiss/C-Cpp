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

//8.�ж�һ�������Ƿ�������������������ĳ����Լ���ڵ�
template<class T>
ListNode<T>* List<T>::IsRingList()
{
	if (_head == NULL)
		return false;
	Node* fast = _head,* slow = _head,* Input;
	while (fast && fast->_next)
	{
		if (fast == slow)     //������� ������ĳ��Ⱥ���ڵ�
		{
			int count = 1;
			do
			{
				slow = slow->_next;
				fast = fast->_next->_next;
				++count;
			} while (fast == slow);
			cout << "���Ľڵ�ĸ���Ϊ��" << count << endl;

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

//9.�ж����������Ƿ��ཻ������ཻ�������(������)
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

	Tmp1 = List1._head, Tmp2 = List2._head;   /*����ָ�������ͷ*/
	int n = abs(Length1 - Length2);
	if (Length1 > Length2)        /*�������һ ���� �����*/
	{
		while (n--)
		{
			Tmp1 = Tmp1->_next;
		}
	}
	else                          /*�������� ���� ����һ*/
	{
		while (n--)
		{
			Tmp2 = Tmp2->_next;
		}
	}

	while (Tmp1)
	{
		if (Tmp1 == Tmp2)
			return Tmp1;        /*�ҵ��˽��㣬����*/
		else
		{
			Tmp1 = Tmp1->_next;
			Tmp2 = Tmp2->_next;
		}
	}
	return NULL;                /*û�ҵ���NULL ����*/
}


//10.�ж����������Ƿ��ཻ������ཻ�������(��ȷ����������)
template<class T>
ListNode<T>* List<T>::IsCrossStrengthen(const List<T>& List1, const List<T>& List2)
{
	Node* Cross1 = List1.IsRingList(), *Cross2 = List2.IsRingList();
	if (Cross1 == NULL && Cross2 == NULL)   /*���������������*/
		return List1.IsCross(List1, List2);
	else if (Cross1 && Cross2)   /*����������*/
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
	return false;    /*һ�����������һ��������*/
}


//11.������������ͬ��Ԫ��
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