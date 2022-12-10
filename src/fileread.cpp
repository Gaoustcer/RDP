#include "fileread.h"
#include <fstream>
#include <assert.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
char * fileread(const char * filename,int sizeoffilebyte){
    ifstream file(filename,ios::binary|ios::in);
    char * filecontent = new char[sizeoffilebyte];
    file.read((char *)filecontent,sizeof(char) * sizeoffilebyte);
    file.close();
    return filecontent;
}
// bool filewrite(const char * filepath,char *)
void filestruct::outputintofile(const char* filename){
    ofstream file(filename,ios::binary|ios::out);
    file.write(filepointer,size * sizeof(char));
    file.close();
    return ;
}
filestruct& filestruct::operator^(filestruct &rightop){
    assert(size == rightop.size);
    char * file = new char[size];
    for(int i = 0;i < size;i++){
        file[i] = rightop.filepointer[i] ^ filepointer[i];
    }
    filestruct f(size,file);
    // return std::move(f);
    return f;
}
filestruct* filestruct::filecut(int cutnum){
    assert (size % cutnum == 0);
    int eachfilesize = size/cutnum;
    // string basicfilename("Codingorigingfile");
    filestruct * files = new filestruct[cutnum];
    for(int i = 0;i < cutnum;i++){
        char * ptr = new char[eachfilesize];
        memcpy(ptr,filepointer + i * eachfilesize,eachfilesize);
        files[i] = filestruct(eachfilesize,ptr);
        // memcpy(ptr,)
        // string filename = basicfilename + to_string(i);
        cout << "cut the file" << endl;    
    }
    return files;
}

filestruct & filestruct::operator+(filestruct & rightop){
    int newsize = size + rightop.size;
    char * ptr = new char[newsize];
    memcpy(ptr,filepointer,size);
    cout << "the first file concat\n";
    memcpy(ptr + size,rightop.filepointer,rightop.size);
    cout << "the second file concar\n";
    filestruct f(newsize,ptr);
    cout << "return the instance\n";
    return f;
}