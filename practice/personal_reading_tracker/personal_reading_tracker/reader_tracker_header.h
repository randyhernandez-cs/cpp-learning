#pragma once

struct Book 
{
	std::string title{};
	int currentPage{};
	int totalPage{};
};

void bookSelection(const std::vector<Book>& collection,const size_t choice);


