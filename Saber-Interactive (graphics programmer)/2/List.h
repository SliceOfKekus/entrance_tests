#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::vector;
using std::map;
using std::string;
using std::move;

struct ListNode
{
  ListNode() 
  {}
  ListNode(ListNode* p, ListNode* n,
           ListNode* r, std::string s)
    : prev(p)
    , next(n)
    , rand(r)
    , data(s)
  {}
  ListNode* prev;
  ListNode* next;
  ListNode* rand; // ��������� �� ������������ ������� ������� ������ ���� NULL
  std::string data;
};

class List
{
public:
  List() 
  {}
  List(ListNode* h, ListNode* t, int count)
    : head(h), tail(t), count(count)
  {}

  void Serialize(FILE* file);  // ���������� � ���� (���� ������ � ������� fopen(path, "wb"))
  void Deserialize(FILE* file);  // �������� �� ����� (���� ������ � ������� fopen(path, "rb"))

private:
  ListNode* head;
  ListNode* tail;
  int       count;
};
