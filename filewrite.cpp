#include <fstream>
#include <iostream>
#define N 1024 * 1024 * 1024

using namespace std;
int main(){
    ifstream file("test",ios::binary|ios::in);
    char * ptr = new char[N];
    file.read(ptr,sizeof(char) * N);
    ofstream outfile("out",ios::binary|ios::out);
    outfile.write(ptr,sizeof(char) * N);
}   