#pragma once
#include <iostream>

struct Node
{
	std::string key;

	std::string data;
	std::string hash;

	Node* parent;
};