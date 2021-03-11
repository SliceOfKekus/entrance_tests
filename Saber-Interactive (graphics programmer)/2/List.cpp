#include "List.h"


//file struct: |nodes_count| -> |rand_index|data_size|data| ->
//-> |rand_index|data_size|data| -> -//-

void List::Serialize(FILE* file)
{
	size_t _size = 0;
	map<ListNode*, size_t> _list;

	for (auto _ptr = head; _ptr != nullptr; _ptr = _ptr->next, ++_size)
		_list.insert(std::make_pair(_ptr, _size));

	fwrite(&count, sizeof(int), 1, file);
	for (auto _ptr = head; _ptr != nullptr; _ptr = _ptr->next)
	{
		auto _rand = _list.find(_ptr->rand);
		int64_t _randIndex;
		size_t _dataSize = _ptr->data.size();

		if (_rand == _list.end())
			_randIndex = -1;
		else
			_randIndex = _rand->second;

		fwrite(&_randIndex, sizeof(int64_t), 1, file);
		fwrite(&_dataSize, sizeof(size_t), 1, file);
		fwrite(_ptr->data.c_str(), sizeof(char), _ptr->data.size(), file);
	}
}

void List::Deserialize(FILE* file)
{
	//is deleting previous nodes required?
	//if so, there's code
	//ListNode* _next;
	//
	//for (auto _ptr = head; _ptr != nullptr; _ptr = _next)
	//{
	//	_next = _ptr->next;
	//	delete _ptr;
	//}
	vector<ListNode*> list;
	vector<int64_t> indecies;
	
	fread(&count, sizeof(size_t), 1, file);
	list.assign(count, nullptr);
	indecies.assign(count, 0);

	size_t _dataSize;
	char* _data;
	ListNode* _prev = nullptr;

	for (int i = 0; i < count; ++i)
	{
		fread(&indecies[i], sizeof(int64_t), 1, file);
		fread(&_dataSize, sizeof(size_t), 1, file);
		//realloc()?
		_data = new char[_dataSize];
		fread(_data, sizeof(char), _dataSize, file);
		
		//change new ListNode(...) to _next->prev = ...
		auto _next = new ListNode(_prev, nullptr, nullptr, move(string(_data)));

		if (i != 0)
			list[i - 1]->next = _next;
		
		list[i] = _next;
		_prev = _next;
		delete[] _data;
	}

	for (int i = 0; i < count; ++i)
		if (indecies[i] != -1)
			list[i]->rand = list[indecies[i]];
		else
			list[i]->rand = nullptr;

	head = list[0];
	tail = list[list.size() - 1];
}

