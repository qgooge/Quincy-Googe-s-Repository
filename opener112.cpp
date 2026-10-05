#include <iostream>
using namespace std;

int main()
{
int softness;

cout << "Rate the softness of your bed from 1 (hardest) to 10 (softest): ";
cin >> softness;

if (softness <= 3)
{
cout << "That is too hard!" << endl;
}
else if (softness >= 8)
{
cout << "That is too soft!" << endl;
}
else
{
cout << "That is just right!" << endl;
}

cout << "Pleasant dreams!" << endl;

return 0;
}
