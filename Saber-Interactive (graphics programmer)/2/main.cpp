#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

#include "List.h"


const char* path = "C:\\Users\\SliceOfKekus\\Desktop\\test.txt";
std::string temp = "la";

int main()
{
	//FILE* read = fopen(path, "rb");
	//
	//std::vector<ListNode*> nodes;
	//ListNode* tmp = new ListNode(nullptr, nullptr, nullptr, temp);
	//
	//nodes.assign(5, nullptr);
	//nodes[0] = tmp;
	//for (int count = 1; count < 5; ++count)
	//{
	//	nodes[count] = new ListNode(nodes[count - 1], nullptr, nullptr, temp += " la");
	//	nodes[count - 1]->next = nodes[count];
	//	nodes[count]->rand = nodes[(count * count + count) % nodes.size()];
	//}
	//
	//FILE* wFile = fopen(path, "wb");	
	//List _list(nodes[0], nodes[4], nodes.size());
	//
	//_list.Serialize(wFile);
	List _list;
	
	FILE* rFile = fopen(path, "rb");
	
	_list.Deserialize(rFile);

	return 0;
}