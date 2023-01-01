#include <iostream>
using namespace std;

struct EMPLOYEE
{
    //EMPLOYEE();
    ~EMPLOYEE(){};
    void deleteData();
    string Fname;
    string Lname;
    string id_no;
    float salary;
};
/*
EMPLOYEE::EMPLOYEE()
{
    float salary = 0;
}
*/
void EMPLOYEE::deleteData()
{
    Fname = "";
    Lname = "";
    id_no = "";
    salary = 0;
}
