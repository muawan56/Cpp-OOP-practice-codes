// Set Class

#include <iostream>
#include <set>

using namespace std;

class Set
{
private:
    set<int> elements;

public:
    Set();
    Set(const Set &other);
    Set &operator=(const Set &other);
    ~Set();

    friend

        ostream &
        operator<<(

            ostream &out, const Set &set);
    friend

        istream &
        operator>>(

            istream &in, Set &set);

    Set operator+(const Set &other) const;
    Set &operator+=(const Set &other);
    Set operator+(int value) const;
    Set &operator+=(int value);

    Set Union(const Set &other) const;
    Set Intersection(const Set &other) const;
    Set Difference(const Set &other) const;
    bool isSubsetOf(const Set &other) const;
};

Set::Set() {}

Set::Set(const Set &other) : elements(other.elements) {}

Set &Set::operator=(const Set &other)
{
    if (this != &other)
    {
        elements = other.elements;
    }
    return *this;
}

Set::~Set() {}

ostream &operator<<(

    ostream &out, const Set &set)
{
    out << "Size: " << set.elements.size() <<

        endl;
    for (const int &element : set.elements)
    {
        out << element << ' ';
    }
    return out;
}

istream &operator>>(

    istream &in, Set &set)
{
    int size;
    in >> size;
    set.elements.clear();
    for (int i = 0; i < size; i++)
    {
        int element;
        in >> element;
        set.elements.insert(element);
    }
    return in;
}

Set Set::operator+(const Set &other) const
{
    Set result = *this;
    result += other;
    return result;
}

Set &Set::operator+=(const Set &other)
{
    for (const int &element : other.elements)
    {
        elements.insert(element);
    }
    return *this;
}

Set Set::operator+(int value) const
{
    Set result = *this;
    result += value;
    return result;
}

Set &Set::operator+=(int value)
{
    elements.insert(value);
    return *this;
}

Set Set::Union(const Set &other) const
{
    Set result = *this;
    result += other;
    return result;
}

Set Set::Intersection(const Set &other) const
{
    Set result;
    for (const int &element : elements)
    {
        if (other.elements.find(element) != other.elements.end())
        {
            result += element;
        }
    }
    return result;
}

Set Set::Difference(const Set &other) const
{
    Set result = *this;
    for (const int &element : other.elements)
    {
        result.elements.erase(element);
    }
    return result;
}

bool Set::isSubsetOf(const Set &other) const
{
    for (const int &element : elements)
    {
        if (other.elements.find(element) == other.elements.end())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Set set1;
    set1 += 1;
    set1 += 2;
    set1 += 3;

    Set set2;
    set2 += 3;
    set2 += 4;
    set2 += 5;

    Set set3 = set1 + set2;

    cout << "Set 1: " << set1 <<

        endl;

    cout << "Set 2: " << set2 <<

        endl;

    cout << "Set 3 (Set 1 + Set 2): " << set3 <<

        endl;

    cout << "Union of Set 1 and Set 2: " << set1.Union(set2) <<

        endl;

    cout << "Intersection of Set 1 and Set 2: " << set1.Intersection(set2) <<

        endl;

    cout << "Difference of Set 1 and Set 2: " << set1.Difference(set2) <<

        endl;

    if (set1.isSubsetOf(set2))
    {

        cout << "Set 1 is a subset of Set 2." <<

            endl;
    }
    else
    {

        cout << "Set 1 is not a subset of Set 2." <<

            endl;
    }

    return 0;
}
