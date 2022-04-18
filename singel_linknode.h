#pragma once
#include <iostream>
#include <ctime>
typedef struct lnode{
	int data;
	struct lnode* next;
}lnode,*linklist;
bool Init_have_head_List(linklist &l) {
	l = new lnode;
	l->next = nullptr;
	return true;
}
bool listInsert(linklist &l, int i, int e) {
	if (i < 1)
		return false;
	lnode* p = l;
	int j = 0;
	while (p != nullptr && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == nullptr)
		return false;
	lnode* s = new lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool listDel(linklist&l, int i) {
	if (i < 1)
		return false;
	lnode* p = l;
	int j = 0;
	while (p != nullptr && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == nullptr)
		return false;
	lnode* s = p->next;
	p->next = s->next;
	delete s;
	return true;
}
int length(linklist l) {
	int len = 0;
	lnode* p = l;
	while (p->next != nullptr) {
		p = p->next;
		len++;
	}
	return len;
}
void show_list(linklist l) {
	lnode* p = l->next;
	while (p) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
void show_list_for_after_findunion(linklist l) {
	lnode* p = l;
	while (p) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
bool Del_List_x(linklist& l, int x) {
	lnode* p = l->next;
	lnode* r = l;
	lnode* q;
	while (p != nullptr) {
		if (p->data != x) {
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			q = p;
			p = p->next;
			delete q;
		}
	}
	r->next = nullptr;
	return true;
}
bool List_Reverse_show(linklist l) {
	if (l->next != nullptr)
		List_Reverse_show(l->next);
	if (l != nullptr) {
		if (l->data > 0)
			std::cout << l->data <<" ";
	}
	else
	{
		return false;
	}
	return true;
}
bool Del_List_min(linklist& l) {
	lnode* p = l->next; //p作为指向第一个元素的指针
	lnode* q = p;//q指针用来存放p指到的最小值元素
	lnode* s = l;//s作为p的前驱
	lnode* r = s;//r作为q的前驱
	while (p) {
		if (p->data < q->data) {
			q = p;
			r = s;
		}
		s = p;
		p = p->next;
	}
	r->next = q->next; 
	delete q;
	return true;
}
void Reverse_list_o1(linklist& l) {
	lnode* p = l->next;
	lnode* r = p->next;
	p->next = nullptr;
	lnode* f;
	p = r;
	while (p) {
		f = l;
		r = p->next;
		while (f->next != nullptr && p->data > f->next->data){
			f = f->next;
			if (f == nullptr)
				break;
		}

		p->next = f->next;
		f->next = p;
		p = r;
	}
}

void Del_between_x_and_y(linklist &l,int x,int y) {
	lnode* p = l->next;
	lnode* r = l;
	while (p) {
		if (p->data < y && p->data > x && p != nullptr)
		{
			r->next = p->next;
			delete p;
			p = r->next;
			/*r = p;
			p = p->next;*/
		}
		else 
		{
			r = p;
			p = p->next;
		}
	}
}
void creat_list(linklist& l, int a[], int n) {
	l = new lnode;
	lnode* s, * r = l;
	for (int i = 0; i < n; i++) {
		s = new lnode;
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = nullptr;
}
linklist List_unino_point(linklist l1,linklist l2) {
	lnode* p = l1->next;
	lnode* q = l2->next;
	int len1 = 0;
	int len2 = 0;
	while (p) {
		p = p->next;
		len1++;
	}
	while (q) {
		q = q->next;
		len2++;
	}
	linklist long_, short_;
	int dist = 0;
	if (len1 > len2) {
		long_ = l1->next;
		short_ = l2->next;
		dist = len1 - len2;
	}
	else {
		long_ = l2->next;
		short_ = l1->next;
		dist = len2 - len1;
	}
	while (dist--) {
		long_ = long_->next;
	}
	while (long_ != nullptr) {
		if (long_ == short_)
			return long_;
		else {
			long_ = long_->next;
			short_ = short_->next;
		}
	}
	return nullptr;


}
void Min_Del_show(linklist& l) {
	while (l->next) {
		lnode* r = l;
		lnode* p = r->next;
	while (p->next)
		{
		if (p->next->data < r->next->data)
			r = p;
		p = p->next;
		}
	std::cout << r->next->data << " ";
	lnode* q = r->next;
	r->next = q->next;
	delete q;
	}
	delete l;
}
linklist Device_list(linklist& a) {
	linklist b = new lnode;
	lnode* q = b;
	lnode* r = a;
	lnode* p = r->next;
	while (p) {
		if (p->data % 2 != 0) 
		{
			q->next = p;
			r->next = p->next;
			p = r->next;
			q = q->next;
			q->next = nullptr;
		}
		else
		{
			r = p;
			p = r->next;
		}
	}
	return b;
}
linklist Chai_list(linklist& a) {
	linklist b = new lnode;
	lnode* q = b;
	lnode* r = a;
	lnode* p = r->next; 
	int len = 0;
	while (p) {
		p = p->next;
		len++;
	}
	p = r->next;
	int i = 0;
	while (p) {
		if (i % 2 != 0)
		{
			q->next = p;
			r->next = p->next;
			p = r->next;
			q = q->next;
			q->next = nullptr;
			i++;
		}
		else
		{
			r = p;
			p = r->next;
			i++;
		}
		
	}
	return b;
}

void Del_override(linklist& l) {
	lnode* r = l;
	lnode* p = r->next;
	while (p->next) {
		if (p->next->data == r->next->data) {
			lnode* u = p;
			p = u->next;
			r->next = u->next;
			delete u;
		}
		else {
			r = p;
			p = p->next;
		}
	}

}
linklist& merge_list(linklist& a, linklist& b) {
	lnode* p_t = b->next;
	lnode* q_t = a;
	while (q_t->next) {
		q_t = q_t->next;
	}
	q_t->next = p_t;
	delete b;
	return a;
}
linklist& merge_list_decent_bate1(linklist& a, linklist& b) {
	clock_t startTime, endTime;
	startTime = clock(); //开始计时
	lnode* p = a->next;
	lnode* r = p->next;
	p->next = nullptr;
	lnode* start;
	p = r;
	while (p) {
		start = a;
		r = p->next;
		if (start->next != nullptr && p->data < start->next->data)
			start = start->next;
		p->next = start->next;
		start->next = p;
		p = r;
	}
	p = b->next;
	r = p->next;
	p->next = nullptr;
	p = r;
	while (p) {
		start = a;
		r = p->next;
		if (start->next != nullptr && p->data < start->next->data)
			start = start->next;
		p->next = start->next;
		start->next = p;
		p = r;
	}
	return a;
	endTime = clock();
	std::cout << "Run time is " << endTime - startTime << " s" << std::endl;
}

linklist& merge_list_decent_bate2(linklist& a, linklist& b) {
	lnode* pa = a->next, * pb = b->next, * r;
	a->next = nullptr;
	while (pa && pb) {
		if (pa->data < pb->data)
		{
			r = pa->next;
			pa->next = a->next;
			a->next = pa;
			pa = r;
		}
		else {
			r = pb->next;
			pb->next = a->next;
			a->next = pb;
			pb = r;
		}
	}
	if (pa) pb = pa;
	while (pb) {
		r = pb->next;
		pb->next = a->next;
		a->next = pb;
		pb = r;
	}
	return a;
}
linklist& union_elem(linklist& A, linklist& B) {
	lnode* pa = A->next;
	lnode* pb = B->next;
	linklist C = new lnode;
	lnode* pc, * r, * s;
	s = C;
	while (pb && pa) {
		if (pa->data > pb->data) pb = pb->next;
		else if (pa->data < pb->data) pa = pa->next;
		else {
			r = new lnode;
			r->data = pa->data;
			s->next = r;
			s = r;
			pb = pb->next;
			pa = pa->next;
		}
	}
	s->next = nullptr;
	return C;
}
linklist& union_elem_TO_A(linklist& A, linklist& B) {
	lnode* pa = A->next;
	lnode* pb = B->next;
	lnode* s, * r, * f;
	
	A->next = nullptr;
	f = A;
	while (pa && pb) {
		if (pa->data > pb->data) pb = pb->next; 
		else if (pa->data < pb->data) {
			s = pa; pa = pa->next;
		}
		else {
			r = pa;
			pa = r->next;
			r->next = nullptr;
			f->next = r;
			f = r;
			pb = pb->next;
		}
	}
	f->next = nullptr;
	return A;
}


void Create_have_no_head_List(linklist& l) {
	//头插法
	l = nullptr;
	lnode* s =new lnode;
	lnode* r = l;
	int a[5] = { 2,1,3,4,1 };
	int n = 5;
	s->data = a[0];
	s->next = l;
	l = s ;
	if (n == 1) {
		r->next = nullptr;
	}
	else {
		for (int i = 1; i < n; i++) {
			s = new lnode;
			s->data = a[i];
			s->next = l;
			l = s;
		}
	}
}
void Create_have_no_head_List_2(linklist& l) {
	//尾插法
	lnode* s;
	lnode* r = l = new lnode;
	int a[5] = { 2,1 };
	int n = 2;
	r->data = a[0];
	if (n == 1) {
		r->next = nullptr;
	}
	else {
		for (int i = 1; i < n; i++) {
			s = new lnode;
			s->data = a[i];
			r->next = s;
			r = r->next;
		}
		r->next = nullptr;
	}
}
void list_show(linklist l) {
	lnode* p = l;
	while (p) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

//判断无头结点的单链表是否为回文
bool isPalindrome(linklist head) {
	lnode* p = head;
	lnode* q = head;
	linklist t = nullptr;
	while (q) {
		lnode* s = new lnode;
		s->data = q->data;
		s->next = t;
		t = s;
		q = q->next;
	}
	
	lnode* r = t;
	while (p != r && r->next != p) {
		if (p->data == r->data) {
			r = r->next;
			p = p->next;
		}
		else {
			return false;
		}
	}
	return true;
}
