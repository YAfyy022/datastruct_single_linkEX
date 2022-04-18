#include "singel_linknode.h"
#include <iostream>
#include<windows.h>  

int main() {
	//double time = 0;
	//double counts = 0;
	//LARGE_INTEGER nFreq;
	//LARGE_INTEGER nBeginTime;
	//LARGE_INTEGER nEndTime;
	lnode* l = NULL;
	Init_have_head_List(l);
	listInsert(l, 1, 1);
	listInsert(l, 2, 1);
	listInsert(l, 3, 2);
	listInsert(l, 4, 3);
	listInsert(l, 5, 4);
	listInsert(l, 6, 24);
	listInsert(l, 7, 31);
	listInsert(l, 8, 43);
	//lnode* l2 = NULL;
	//l2 = Chai_list(l);
	show_list(l);
	//show_list(l2);
	//show_list(l);
	//std::cout << "-----------------" << std::endl;
	////Del_List_x(l,2);
	//std::cout << "-----------------" << std::endl;
	//Reverse_list_o1(l);
	//show_list(l);
	//Del_between_x_and_y(l, 8, 25);
	//show_list(l);
	lnode* l2 = nullptr;
	Init_have_head_List(l2);
	listInsert(l2, 1, 1);
	listInsert(l2, 2, 3);
	listInsert(l2, 3, 13);
	listInsert(l2, 4, 20);
	listInsert(l2, 5, 24);
	listInsert(l2, 6, 31);
	listInsert(l2, 7, 43);
	show_list(l2); 
	//QueryPerformanceFrequency(&nFreq);
	//QueryPerformanceCounter(&nBeginTime);//开始计时
	lnode* l3 = union_elem_TO_A(l,l2);
	//QueryPerformanceCounter(&nEndTime);//停止计时  
	show_list(l3);
	//time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	//std::cout << "运行时间：" << time * 1000 << "ms" << std::endl;

	/* 制造一个有公共结点的链表
	lnode* q = l2;
	lnode* r = nullptr;
	while (q) {
		r = q;
		q = q->next;
	}
	r->next = l->next;*/
	//show_list(l);
	//show_list(l2);
	//lnode* l3 = List_unino_point(l,l2);
	//show_list_for_after_findunion(l3);
	/*show_list(l);
	Min_Del_show(l);*/
	return 0;
}