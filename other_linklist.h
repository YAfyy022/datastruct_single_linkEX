#pragma once
//循环双链表是否对称
#include <iostream>

//循环双链表
typedef struct lnode {
	int val;
	struct lnode* next, * prior;
}lnode,*linklist;
int a[6] = { 1,2,3,2,1,2};

void Create_cir_Dulinklist(linklist& l) {
	l = new lnode;
	lnode* s, * r = l;
	l->prior = l;
	l->next = l;
	for (int i = 0; i < 6; i++) {
		s = new lnode;
		s->val = a[i];
		s->next = r->next;
		r->next->prior = s;
		s->prior = r;
		r->next = s;
		r = s;
		l->prior = s;
	}
}
void show_CDL(linklist& l) {
	lnode* s = l->next;
	while (s != l) {
		std::cout << s->val << " ";
		s = s->next;
	}
	std::cout << std::endl;
}
bool isok(linklist& l) {
	lnode* p = l->next, * q = l->prior;
	while (p != q && p->next != p) {
		if (p->val == q->val) {
			q = q->prior;
			p = p->next;
		}
		else return false;
	}
	return true;
}
