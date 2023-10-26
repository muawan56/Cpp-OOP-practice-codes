// MyString

#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
private:
    char *str;
    int size;

public:
    MyString(const char *string = "");
    MyString(const MyString &other);
    MyString &operator=(const MyString &other);
    ~MyString();

    friend ostream &operator<<(ostream &out, const MyString &myString);
    friend istream &operator>>(istream &in, MyString &myString);

    int FindSubstring(const char *substring) const;
    bool CompareWithCase(const MyString &other) const;
    bool CompareWithoutCase(const MyString &other) const;
    char **SplitIntoWords() const;
    operator int() const;
    operator float() const;
    void ReplaceSubstring(const char *oldSubstr, const char *newSubstr);

private:
    void InitializeFromString(const char *string);
};

MyString::MyString(const char *string)
{
    InitializeFromString(string);
}

MyString::MyString(const MyString &other)
{
    InitializeFromString(other.str);
}

MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        delete[] str;
        InitializeFromString(other.str);
    }
    return *this;
}

MyString::~MyString()
{
    delete[] str;
}

ostream &operator<<(ostream &out, const MyString &myString)
{
    out << myString.str;
    return out;
}

istream &operator>>(istream &in, MyString &myString)
{
    char buffer[1024];
    in.getline(buffer, sizeof(buffer));
    myString = buffer;
    return in;
}

int MyString::FindSubstring(const char *substring) const
{
    // implementation for finding a substring
}

bool MyString::CompareWithCase(const MyString &other) const
{
    // implementation for case-sensitive comparison
}

bool MyString::CompareWithoutCase(const MyString &other) const
{
    // implementation for case-insensitive
}

char **MyString::SplitIntoWords() const
{
    // implementation for splitting into words
}

MyString::operator int() const
{
    // implementation for type casting to integer
}

MyString::operator float() const
{
    // implementation for type casting to float
}

void MyString::ReplaceSubstring(const char *oldSubstr, const char *newSubstr)
{
    // implementation for replacing a substring
}

void MyString::InitializeFromString(const char *string)
{
    size = strlen(string);
    str = new char[size + 1];
    strcpy(str, string);
}

int main()
{
    MyString str1("Hello, world!");
    MyString str2 = str1;

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;

    int intVal = int(str1);
    float floatVal = float(str1);

    cout << "str1 as int: " << intVal << endl;
    cout << "str1 as float: " << floatVal << endl;

    str1.ReplaceSubstring("world", "C++");
    cout << "Modified str1: " << str1 << endl;

    return 0;
}
