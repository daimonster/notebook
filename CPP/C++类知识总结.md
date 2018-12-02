## 父类指针调用子类方法
想要父类指针调用子类的方法,一般只能调用加上virtual的方法

这里用C++primer的类进行举例
```
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>
// 抽象类
class AcctABC
{
private:
	std::string fullName;
	long acctNum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const std::string & FullName() const {return fullName;}
	long AcctNum() const {return acctNum;}
	Formatting SetFormat() const;
	void Restore(Formatting & f) const;
public:
	AcctABC(const std::string & s = "Nullbody",long an = -1,double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) = 0;//纯虚函数
	double Balance() const {return balance;};
	virtual void ViewAcct() const = 0;
	virtual ~AcctABC() {};
};

// 子类Brass
class Brass : public AcctABC
{
public:
	Brass(const std::string & s = "Nullbody",long an = -1,double bal = 0.0) : AcctABC(s,an,bal){};
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() {};
};


// 子类BrassPlus
class BrassPlus : public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string & s = "Nullbody",long an = -1,double bal = 0.0,double ml = 500,double r =0.10);
	BrassPlus(const Brass & ba,double ml = 500,double r = 0.1);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) {maxLoan = m;};
	void ResetRate(double r){rate = r;};
	void ResetOwes() {owesBank = 0;};
};
#endif
```
创建子类
```
// 可以
AcctABC * plient = new Brass(temp,tempnum,tempbal);(这或者BrassPlus)
```

注意点:
+ 由于C++没有垃圾回收机制,所以在new了一个指针的同时,必须要delete,要么,就要用unique_ptr等智能指针
+ 基类必须要有虚析构函数,这样方便子类和基类释放内存
+ 如果你在virtual函数后面加上了"=0",表明这是纯虚函数,这只要是有子类集成这个基类,就必须要重写这个函数,作用相当于java中的interface
+ 如果使用了类的多态性,访问父类的private变量是不能直接访问的,你必须要通过public函数来访问父类的private变量
+ 在头文件里面定义了内联函数的,在cpp文件里面就不能定义,如果这个函数是virtual的,可以在子类中重载.
+ 当你定义了父类指针的时候,你是不可以子类非virtual函数的
