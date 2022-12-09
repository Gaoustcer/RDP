// #include <fstream>
// #include <iostream>
// using namespace std;

class filestruct{
public:
    int size;
    int * filepointer;
    filestruct(int _size,int * _filepointer):size(_size),filepointer(_filepointer){}
    filestruct():size(0),filepointer(nullptr);
    filestruct * operator^(filestruct &rightop);
    ~filestruct(){
        if(size != 0){
            delete [] filepointer;
        }
    }
};

// filestruct * 
int * fileread(const char * filepath,int sizeoffilebyte = 1024 * 1024 * 104);
