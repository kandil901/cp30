#include <iostream>
#include <vector>
using namespace std;


class Employee {
protected:
    string name;
public:
    Employee(const string& empName) : name(empName) {}
    
    
    virtual double calculateSalary() const = 0; 
    
   
    virtual ~Employee() {}
    
    
    virtual void displayInfo() const {
        cout << "Employee: " << name << endl;
    }
};


class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
public:
    FullTimeEmployee(const string& empName, double salary)
        : Employee(empName), monthlySalary(salary) {}


    double calculateSalary() const override {
        return monthlySalary;
    }

   
    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Full-time employee, Monthly Salary: $" << monthlySalary << endl;
    }
};


class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    PartTimeEmployee(const string& empName, double rate, int hours)
        : Employee(empName), hourlyRate(rate), hoursWorked(hours) {}

  
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

   
    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Part-time employee, Hourly Rate: $" << hourlyRate 
             << ", Hours Worked: " << hoursWorked << endl;
    }
};

int main() {

    Employee* fullTime = new FullTimeEmployee("MAX", 4000);
    Employee* partTime = new PartTimeEmployee("Jane ", 20, 80);
    
    
    vector<Employee*> employees;
    employees.push_back(fullTime);
    employees.push_back(partTime);
    

    for (const auto& employee : employees) {
        employee->displayInfo();
        cout << "Salary: $" << employee->calculateSalary() << endl;
        cout << "----" << endl;
    }


    for (auto& employee : employees) {
        delete employee;
    }

    return 0;
}
