//
// 1.ʵ�����¼�����ĳ�Ա����
// 2.ʵ��һ���麯���ĸ��Ǽ�����
// 3.�������μ̳����⡣
//

// ֲ��
class Botany
{
public:
	Botany(string & name)
		:_name(name)
	{
		++_sCount;
	}

	virtual void Display ();

protected:
	string _name;		//����
};

class Tree : public Botany
{
public:
	//...ʵ��Ĭ�ϵĳ�Ա����

protected:
	int _hight;		// �߶�
};

class Flower : public Botany
{
public:
	//...ʵ��Ĭ�ϵĳ�Ա����

protected:
	int _colour;	// ��ɫ
};

// ����������������ʱ����
class MicheliaAlba : public Flower, public Tree
{
protected:
	// ...
};
