#include"List.h"
#include"Interview.h"

void Test()
{
	vector<int> Vector = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	List<int> list;
	list.Insert(Vector);
	list.Show();
	for (int i = 0; i < 20; ++i)
	{
		list.ReciprocalK(i) == NULL ? (cout << "����û�� " << i << " ���ڵ�" << endl) :
			(cout << "������ " << i << " ���ڵ�Ϊ�� " << list.ReciprocalK(i)->_value << endl);
	}

}

void main()
{
	Test();
}