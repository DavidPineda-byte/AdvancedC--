#include "studentManager.h"
#include "student.h"
#include <iostream>
#include <algorithm> 

int Student::nextId = 0;  

void studentManager::add(Student newStudent) {
    std::cout << "Adding a student record..." << std::endl;
    // Implementation for adding a student record
    students.push_back(newStudent);
}

void studentManager::display(){


}

Student studentManager::search(int id) {

    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& student) {
            return student.getId() == id;
        });

    if (it != students.end()) {
        return *it;
    }

    throw std::runtime_error("Student not found");
}

vector<Student> studentManager::searchByName(string name){

vector<Student> foundStudents;

for(Student student: students){
    if(student.getName() == name){
        foundStudents.push_back(student);
    }
}
return foundStudents; 
}
