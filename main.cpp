#include "fileread.h"

int main(){
    char * filecontent;
    filecontent = fileread("./test");
    filestruct file(1024 * 1024 * 1024,filecontent);
    file.outputintofile("./reconstruct");
    // filestruct
}