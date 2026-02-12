#include "studentManager.h"
#include <iostream>
#include <algorithm> 
#include<format> 

int Student::nextId = 0;  

void studentManager::add(Student newStudent) {
    std::cout << "Adding a student record..." << std::endl;
    // Implementation for adding a student record
    students.push_back(newStudent);
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

std::vector<Student> studentManager::searchByName(std::string name){

    std::vector<Student> foundStudents;

    for(const Student& student : students){
        if(student.getName() == name){
            foundStudents.push_back(student);
        }
    }

    return foundStudents;
}

void studentManager::display(){

    std::cout << "Student Records:\n";

    std::cout << std::format("{:>10} | {:>3} | {:>20} | {:>30}\n",
                             "Name", "Age", "Major", "Email");

    std::cout << std::string(70, '-') << '\n';

    for(const Student& student : students){
        std::cout << std::format("{:>10} | {:>3} | {:>20} | {:>30}\n",
                                 student.getName(),
                                 student.getAge(),
                                 student.getMajor(),
                                 student.getEmail());
    }
}

