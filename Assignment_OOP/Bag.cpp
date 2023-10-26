// Bag

#include <iostream>
#include <vector>

using namespace std;

class Bag
{
private:
    vector<int> elements;

public:
    Bag();
    Bag(const Bag &other);
    Bag &operator=(const Bag &other);
    ~Bag();

    friend ostream &operator<<(ostream &out, const Bag &bag);
    friend istream &operator>>(istream &in, Bag &bag);

    Bag operator+(const Bag &other) const;
    Bag &operator+=(const Bag &other);
    Bag operator+(int value) const;
    Bag &operator+=(int value);
};

Bag::Bag() {}

Bag::Bag(const Bag &other) : elements(other.elements) {}

Bag &Bag::operator=(const Bag &other)
{
    if (this != &other)
    {
        elements = other.elements;
    }
    return *this;
}

Bag::~Bag() {}

ostream &operator<<(ostream &out, const Bag &bag)
{
    out << "Size: " << bag.elements.size() << endl;
    for (const int &element : bag.elements)
    {
        out << element << ' ';
    }
    return out;
}

istream &operator>>(istream &in, Bag &bag)
{
    int size;
    in >> size;
    bag.elements.clear();
    for (int i = 0; i < size; i++)
    {
        int element;
        in >> element;
        bag.elements.push_back(element);
    }
    return in;
}

Bag Bag::operator+(const Bag &other) const
{
    Bag result = *this;
    result += other;
    return result;
}

Bag &Bag::operator+=(const Bag &other)
{
    for (const int &element : other.elements)
    {
        elements.push_back(element);
    }
    return *this;
}

Bag Bag::operator+(int value) const
{
    Bag result = *this;
    result += value;
    return result;
}

Bag &Bag::operator+=(int value)
{
    elements.push_back(value);
    return *this;
}

int main()
{
    Bag bag1;
    bag1 += 1;
    bag1 += 2;
    bag1 += 2;
    bag1 += 3;

    Bag bag2;
    bag2 += 3;
    bag2 += 4;
    bag2 += 5;

    Bag bag3 = bag1 + bag2;

    cout << "Bag 1: " << bag1 << endl;
    cout << "Bag 2: " << bag2 << endl;
    cout << "Bag 3 (Bag 1 + Bag 2): " << bag3 << endl;

    return 0;
}
