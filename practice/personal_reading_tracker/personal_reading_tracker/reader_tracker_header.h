#pragma once

struct Book 
{
	std::string title{};
	int currentPage{};
	int totalPage{};
};

bool decision(char& retry);
void bookSelection(const std::vector<Book>& collection,const size_t choice);
void progressUpdate(std::vector<Book>& collection, const size_t choice);


