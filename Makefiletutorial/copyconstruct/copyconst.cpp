#include <iostream>
using namespace std;
int id = 0;
class object{
public:
    int * ptr;
    int size;
    int myid;
    object(int _size){
        cout << "create the object " << "for id " << id << endl;
        size = _size;
        ptr = new int[_size];
        myid = id;
        id++;
    }
    ~object(){
        if(ptr == nullptr){
            cout << "remove the null object\n";
            return ;
        }
        cout << "rm the object for id " << myid << endl;
        delete [] ptr;
    }
    object(int _size,int* _ptr):size(_size),ptr(_ptr){}
    object(object && temp_object){
        cout << "call move copy function\n";
        ptr = temp_object.ptr;
        size = temp_object.size;
        temp_object.ptr = nullptr;
    }
    object & operator+(object &rightop){
        int _size = rightop.size;
        int * pointer = new int[_size];
        for(int i = 0;i < _size;i++){
            pointer[i] = this->ptr[i] + rightop.ptr[i];
        }
        // auto r = object(_size,pointer);
        // return std::move(r);
        const object & obj = object(_size,pointer);
        return (object &)obj;
    }
};

// object & operator+(object &leftop,object &rightop){
//     int _size = leftop.size;
//     int * pointer = new int[_size];
//     for(int i = 0;i < _size;i++){
//         pointer[i] = leftop.ptr[i] + rightop.ptr[i];
//     }
    
//     const object & obj = object(_size,pointer);
//     return (object &)obj;
// }
int main(){
    // object obj = object(10);
    object rightop(10);
    object leftop(10);
    for(int i = 0;i < 10;i++){
        rightop.ptr[i] = i;
        leftop.ptr[i] = i;
    }
    // object target(leftop + rightop);
    object &target = (leftop + rightop);
    cout << target.ptr[7] << endl;

    // return std::move(obj);
    // object obj = object(10);
    // cout << "after create the object\n";
    // return std::move(obj);
    // return obj;
    // return object(10);
}

// int main(){
//     object obj(generateobj());
//     cout << obj.ptr[2] << endl;
// }