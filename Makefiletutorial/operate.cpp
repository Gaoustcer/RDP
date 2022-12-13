#include <bitset>
#include <iostream>
using namespace std;
int main(){
    char c = 69;
    char b = 73;
    bitset<8> c_bit(c);
    bitset<8> b_bit(b);
    cout << c_bit << endl;
    cout << b_bit << endl;
    char a = c ^ b;
    bitset<8> a_bit(a);
    cout << a_bit << endl;
}