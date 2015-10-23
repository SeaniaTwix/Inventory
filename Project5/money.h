#pragma once

class Money {
public:
	void incMoney(int moneyValue, int Who);
	void decMoney(int moneyValue, int Who);
protected:
	int money;
private:
};