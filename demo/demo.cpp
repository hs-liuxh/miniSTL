
#include<iostream>
using std::cout;
using std::endl;

class A
{
public:
     A()
     {
          std::cout<<"call A constructor"<<std::endl;
     }

     // void func(){
     //      void* p = ::operator new(sizeof(A));
     //      ::new (p) A;
     // }
     
     void* operator new(size_t size){
          cout << "my operator new" << endl;
          return malloc(size);
     }

     ~A()
     {
          std::cout<<"call A destructor"<<std::endl;
     }
};

int main()
{
 
     // A* a = ::new A;
     // delete a;
 
     A* p = (A*) ::operator new(sizeof(A));  // 空间分配
     A* a = new(p) A();                      // 构造

     cout << p << " - " << a << endl;
 
     p->~A();                                // 析构
     ::operator delete(p);                   // 空间释放
 
     return 0;
}