#ifndef STRBLOB_H
#define STRBLOB_H

#include <iostream>
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <initializer_list>
#include <memory>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
        friend class StrBlobPtr;
        friend class ConstStrBlobPtr;
public:
        using size_type = vector<string>::size_type;
        
	StrBlob();
        StrBlob(std::initializer_list<string> il);
	StrBlob(const StrBlob &sb);

	StrBlob &operator=(const StrBlob&);

        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }

        void push_back(const string &t) 
	{
		std::cout << "void push_back(const string &t)" << std::endl;
		data->push_back(t); 
	}
        void push_back(string &&t) 
	{
		std::cout << "void push_back(string &&t)" << std::endl;
		data->push_back(std::move(t)); 
	}
        void pop_back();

        string& front();
        const string& front() const;
        string& back();
        const string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();

        ConstStrBlobPtr begin() const;
        ConstStrBlobPtr end() const;

private:
        std::shared_ptr<vector<string>> data;
        void check(size_type i, const std::string &msg) const;
};

#endif
