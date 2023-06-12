#pragma once
#include <iostream>
#include <map>
#include <string>
#include "UI.h"
using namespace std;
#define SIZE 100

typedef struct {
	string foodname;
	int price;
	int count;
} Order;

class Hamberger {
private:
	int total, pay, change;
	map<string,unsigned int> food,side,drink;

public:
	Hamberger();
	void showmenu();

	void hambergur_order(Order*, string, int);
	void side_order(Order*, string, int);
	void drink_order(Order*, string, int);

	void sub_food(Order*);
	void select_showmenu(Order*, int);
	
	bool card_cash(Order*);

	void set_total(int);
	int get_total();
	void select(Order* );
	void set_change(int, int);
	int get_change();


};