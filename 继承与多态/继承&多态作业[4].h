//
// 1.实现以下几个类的成员函数
// 2.实现一个虚函数的覆盖及调用
// 3.处理菱形继承问题。
//

// 植物
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
	string _name;		//名字
};

class Tree : public Botany
{
public:
	//...实现默认的成员函数

protected:
	int _hight;		// 高度
};

class Flower : public Botany
{
public:
	//...实现默认的成员函数

protected:
	int _colour;	// 颜色
};

// 白兰花，即是树有时花。
class MicheliaAlba : public Flower, public Tree
{
protected:
	// ...
};
