#include "IDSL_EMP.hpp"

const int maxEmployees = 3;
void createEmployee(EMPLOYEE&,int);
short printMenu();
bool searchEmployee(EMPLOYEE&,string,int);
short searchEmployee(EMPLOYEE&,string,int,char&);
void deleteEmployee(EMPLOYEE&);
bool PrintALL(EMPLOYEE&,int);
short Menu();
char YES = 'Y', NO = 'N';
const bool Null = false;
enum Choice{create = 1, display, deleteemp, endp};

int main()
{
    EMPLOYEE IDSL[maxEmployees];
    short choice;
    int emp_no = 0;

    int nChoice = true;

    while(nChoice)
    {
        choice = Menu();
        switch (choice)
        {
            case create:
                {
                    if (emp_no == maxEmployees)
                        cout << "\nMax number of employees reached!" << endl << endl;
                    while (emp_no < maxEmployees)
                        {
                            createEmployee(IDSL[emp_no],emp_no);
                            emp_no++;

                            if (emp_no == maxEmployees)
                            {
                                cout << "Max number of employees reached!" << endl << endl;
                                break;
                            }
                            else
                            {
                                char cChoice;
                                cout << "\nCreate another employee? (Y/N)...";
                                cin >> cChoice;
                                cout << endl;

                                if (cChoice == YES)
                                    continue;
                                else
                                {
                                    if (cChoice == NO)
                                        break;
                                    else
                                        {
                                            cout << "Bad input!!" << endl;
                                            break;
                                        }
                                }
                            }
                        }
                        continue;
                }
            case display:
                {
                    int i = 0;
                    short pchoice = printMenu();
                    if (pchoice == 1)
                    {
                        string ID;
                        cout << "Provide ID: ";
                        cin >> ID;

                        short DBbal = 0, balHold = 0;

                        for (; i < maxEmployees; i++)
                        {
                            balHold = searchEmployee(IDSL[i],ID,i);
                            DBbal += balHold;
                        }
                        if (DBbal == 0)
                            cout << "\t\t\t\tSearch Completed!" << endl << endl << "\t\t\t\t No Match Found!" << endl;
                    }
                    if (pchoice == 2)
                    {
                        short DBbal = 0, balHold = 0;
                        cout << "\t\t\t\t====All Employees====" << endl;
                        for (int i = 0; i < maxEmployees; i++)
                        {
                            balHold = PrintALL(IDSL[i],i);
                            DBbal += balHold;
                        }
                        if (DBbal == Null)
                            cout << "\t\t\t\tNo Employee Data Found!" << endl;
                    }
                    break;
                }
            case deleteemp:
                {
                    string ID;
                    char delChoice;
                    cout << "\nProvide ID: ";
                    cin >> ID;

                    short DBbal = 0, balHold = 0;
                    for (int i = 0; i < maxEmployees; i++)
                    {
                        balHold = searchEmployee(IDSL[i],ID,i,delChoice);
                        DBbal += balHold;
                    }
                    if (DBbal == Null)
                        cout << "\t\t\t\t No Match Found!" << endl;
                    else
                    {
                        if (delChoice == YES)
                            deleteEmployee(IDSL[(balHold--)]);        // position of employee in array is stored in balHold
                    }
                    continue;
                }
            case endp:
                nChoice = false;
                break;
            default:
                cout << "Bad input!!";
                continue;
        }
    }
    cout << "\nClosing program...\n";
    return 0;
}

short Menu()
{
    short choice;
    cout << "\n+++IDSL EMPLOYEE DBMS+++" << endl;
    cout << "(1) Create a profile" << endl;
    cout << "(2) Display employees" << endl;
    cout << "(3) Delete employees" << endl;
    cout << "(4) Close" << endl;
    cout << "...";
    cin >> choice;
    return choice;
}

void createEmployee(EMPLOYEE &myEmployee,int i)
{
    string fname, lname, id_no;
    float salary;

    cout << "\nEmployee " << i << " profile:" << endl << endl;

    cout << "First Name: ";
    cin >> fname;
    cout << "Last Name: ";
    cin >> lname;
    cout << "ID No.: ";
    cin >> id_no;
    cout << "Salary: ";
    cin >> salary;
    cout << endl;

    myEmployee.Fname = fname;
    myEmployee.Lname = lname;
    myEmployee.id_no = id_no;
    myEmployee.salary = salary;
    cout << myEmployee.Fname << " " << myEmployee.Lname << "'s profile has been created." << endl << endl;
}

short printMenu()
{
    short pChoice;
    cout << "\n+++EMPLOYEE LIST+++" << endl;
    cout << "(1) Search employee" << endl;
    cout << "(2) Print all" << endl << "...";
    cin >> pChoice;
    cout << endl;
    return pChoice;
}

bool searchEmployee(EMPLOYEE &myEmployee, string ID, int i)
{
    if (myEmployee.id_no == ID)
    {
        cout << "\nSearch completed!\n\n"
            <<"\t\t\t\t>>>MATCH FOUND<<<"
             << "\n\t\t\t\t Employee " << i << endl;
        cout << "\t\t\t\t Name: " << myEmployee.Fname << " " << myEmployee.Lname << endl;
        cout << "\t\t\t\t ID: " << myEmployee.id_no << endl;
        cout << "\t\t\t\t Salary: " << myEmployee.salary << endl << endl;
        return true;
    }
    else
        return false;
}

bool PrintALL(EMPLOYEE& myEmployee, int i)
{
    if (myEmployee.id_no == "")
        return false;
    else
    {
        cout << "\n\t\t\t\t Employee " << i << endl;
        cout << "\t\t\t\t Name: " << myEmployee.Fname << " " << myEmployee.Lname << endl;
        cout << "\t\t\t\t ID: " << myEmployee.id_no << endl;
        cout << "\t\t\t\t Salary: " << myEmployee.salary << endl;
        return true;
    }
}

short searchEmployee(EMPLOYEE& myEmployee,string ID,int i,char& delChoice)
{
    if (myEmployee.id_no == ID)
    {
        char choice;
        cout << "Are you sure you want to delete " << myEmployee.Fname << " " << myEmployee.Lname
            << " (ID " << myEmployee.id_no << ") from the database?" << endl << "(Y/N): ";
        cin >> choice;
        if (choice == YES || NO)
            delChoice = choice;
        else
        {
            cout << "Bad input!" << endl;
        }
        return ++i;             // will return 1 for employee 0, and 2 for employee 1
    }
    else
    {
        return 0;
    }
}

void deleteEmployee(EMPLOYEE& myEmployee)
{
    string name = myEmployee.Fname + " " + myEmployee.Lname;
    myEmployee.deleteData();
    cout << "Profile deleted!" << endl << endl;
}
