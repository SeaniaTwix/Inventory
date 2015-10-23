#ifndef __MONEY_H__
#define __MONEY_H__

class Money {
public:
	void incMoney(int moneyValue);
	void decMoney(int moneyValue);
protected:
	int money;
private:
};
#endif