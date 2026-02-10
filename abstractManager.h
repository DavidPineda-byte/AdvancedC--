#include "student.h"
#include <vector>

class abstractManager{
    public: 
        virtual void add(Student student)=0;
        virtual void display()=0;
        virtual Student search(int id)=0; 
        virtual vector<Student> searchByName(string name)=0;
        virtual ~abstractManager() = default;

};