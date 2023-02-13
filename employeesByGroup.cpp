#include <iostream>
using namespace std;
#include <vector>
#include <map>

enum DEP
{
   Planning = 0,
   Research,
   Sales,
};

class Employee
{
public:
   Employee(string name, int salary)
   {
      this->m_Name = name;
      this->m_Salary = salary;
   }
   string m_Name;
   int m_Salary;
};

void createEmployee(vector<Employee> &v)
{
   srand((unsigned int)time(NULL));
   string nameSeed = "ABCDEFGHIJ";
   for (int i = 0; i < 10; i++)
   {
      string name = "Employee";
      name += nameSeed[i];
      int salary = rand() % 1001 + 2000;
      Employee emp(name, salary);
      v.push_back(emp);
   }
}

void setGroup(multimap<int, Employee> &m, vector<Employee> &v)
{
   srand((unsigned int)time(NULL));
   for (vector<Employee>::iterator it = v.begin(); it != v.end(); it++)
   {
      int depId = rand() % 3;
      m.insert(make_pair(depId, *it));
   }
}

void showEmpByGroup(multimap<int, Employee> &m)
{
   cout << "Planning Department: " << endl;
   int count = m.count(Planning);
   for (multimap<int, Employee>::iterator it = m.find(Planning); it != m.end() && count > 0; it++, count--)
   {
      cout << "Name: " << (*it).second.m_Name << "\tSalary: " << (*it).second.m_Salary << endl;
   }

   cout << "----------------------------" << endl;
   cout << "Research Department: " << endl;
   count = m.count(Research);
   for (multimap<int, Employee>::iterator it = m.find(Research); it != m.end() && count > 0; it++, count--)
   {
      cout << "Name: " << (*it).second.m_Name << "\tSalary: " << (*it).second.m_Salary << endl;
   }

   cout << "----------------------------" << endl;
   cout << "Sales Department: " << endl;
   count = m.count(Sales);
   for (multimap<int, Employee>::iterator it = m.find(Sales); it != m.end() && count > 0; it++, count--)
   {
      cout << "Name: " << (*it).second.m_Name << "\tSalary: " << (*it).second.m_Salary << endl;
   }
}

void printEmp(vector<Employee> &v)
{
   for (vector<Employee>::iterator it = v.begin(); it != v.end(); it++)
   {
      cout << "Name: " << (*it).m_Name << "\tsalary: " << (*it).m_Salary << endl;
   }
}

int main()
{
   vector<Employee> v;
   createEmployee(v);
   // printEmp(v);
   multimap<int, Employee> m;
   setGroup(m, v);
   showEmpByGroup(m);
   return 0;
}
