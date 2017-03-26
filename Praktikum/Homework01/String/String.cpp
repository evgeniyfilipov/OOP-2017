#include "String.h"

void String::copy(const String& other)
{
    this -> size = other.size;
    this -> str = new char [strlen(other.str) + 1];
    strcpy (this -> str, other.str);
}

void String::destroy()
{
    delete [] this -> str;
    this -> size = 0;
}

String::String()
{
    this -> size = 0;
    this -> str = '\0';
}

String::String(const String& other)
{
    copy(other);
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
}

String::String(char* str, size_t size)
{
    this -> str = new char [strlen(str) + 1];
    strcpy (this -> str, str);
    this -> size = size;
}

String::~String()
{
    destroy();
}

char* String::getStr() const
{
    return str;
}

size_t String::getSize() const
{
    return size;
}

void String::setSize(size_t size)
{
    this -> size = size;
}

void String::setStr(char* newStr)
{
    delete[] str;

    if(str)
    {
        if(size != 0)
        {
            str = new char [strlen(str) + 1];
            strcpy(str, newStr);
        }
        else
        {
            str = new char [1];
            str = '\0';
        }
    }

}

const char* String::GetStr() const
{
    return str;
}
