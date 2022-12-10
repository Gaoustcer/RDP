#include "fileread.h"
#include <fstream>
#include <iostream>

using namespace std;
char * fileread(const char * filename,int sizeoffilebyte = 1024 * 1024 * 1024){
    ifstream file(filename,ios::binary|ios::in);
    char * filecontent = new char[sizeoffilebyte];
    file.read((char *)filecontent,sizeof(char) * sizeoffilebyte);
    file.close();
    return filecontent;
}