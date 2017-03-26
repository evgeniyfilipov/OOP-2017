#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class String
{
private:

    char* str;
    size_t size;

    void copy(const String&);
    void destroy();

public:
    String();
    String (char* str, size_t size);
    String (const String& other);
    String& operator = (const String&);
    ~String();

    // Getters
    char* getStr() const;
    size_t getSize() const;
    //

    // Setters
    void setStr(char* newStr);
    void setSize(size_t size);
    //

    const char* GetStr() const;

};

