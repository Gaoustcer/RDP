// #include <fstream>
// #include <iostream>
// using namespace std;
#include <iostream>
class filestruct{
public:
    int size;
    char * filepointer;
    filestruct(int _size,char * _filepointer):size(_size),filepointer(_filepointer){}
    filestruct():size(0),filepointer(nullptr){};
    filestruct(int _size):size(_size),filepointer(nullptr){};
    // filestruct(filestruct & copyobj){
    //     size = copyobj.size;
    //     filepointer = copyobj.filepointer;
    // }
    filestruct & operator^(filestruct &);
    filestruct * operator^(filestruct *);
    ~filestruct(){
        if(size == 0){
            std::cout << "delete an non-element";
        }
        if(size != 0){
            delete [] filepointer;
        }
    }
    filestruct(filestruct & operation){
        size = operation.size;
        filepointer = operation.filepointer;
        operation.size = 0;
        operation.filepointer = nullptr;
    }
    void outputintofile(const char *);
    filestruct** filecut(int );
    filestruct & operator + (filestruct & );
    filestruct * operator + (filestruct * );
    // filestruct & operator = (filestruct & );
};

// filestruct * 
char * fileread(const char * filepath,int sizeoffilebyte = 1024 * 1024 * 1024);
// filestruct * operator+(filestruct * rightop,filestruct * leftop);
// bool filewrite(const char * filepath,char * filecontent,int sizeoffilebype = 1024 * 1024 * 1024);