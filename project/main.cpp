

#include <iostream>
#include<vector>
#include<fstream>

using namespace std;
class Person
{
public:

    Person()
    {

    }

    string name;
    int age;
    int id;
    Person(string name, int age, int id)
    {
        name = this->name;
        age = this->age;
        id = this->id;

    }
    // override function
    string virtual role() = 0;
};

class Manger : public Person
{
private:
    int salary;
    static  Manger* manger;
    Manger() : Person()
    {

    }
public:
    // Singlton function
    static Manger* GetInstance()
    {
        cout<<"Manger added"<<"\n";
        if (manger == NULL)
        {
            manger = new Manger();
        }
        return manger;
    }
    void Set_Salary(int s)
    {
        salary = s;
    }
    int Get_salary()
    {
        return salary;
    }
    string role()
    {
        return"The primary role of the manager is to co-ordinate the work of all the employees in the organization and to bring about the best results that"
              "ensures the growth of the organization. There are various roles and responsibilities that"
              "managers hold in order to bring about the best outcomes from the employees";
    }
};
Manger* Manger::manger = NULL;
class Student : public Person
{

public:
    Student() : Person()
    {

    }
    float GPA;
    Student(string name, int age, int id, float __GPA) :Person(name, age, id)
    {
        GPA = __GPA;
    }

    void getData()
    {
        cout << "\nEnter Student Name : ";
        cin >> name;
        cout << "\nEnter Age  : ";
        cin >> age;
        cout << "\nEnter ID : ";
        cin >> id;
        cout << "\n Enter GPA : ";
        cin >> GPA;

    }

    void displayData()
    {
        cout << "\nName of Student :  " << name << endl;
        cout << "\n Age of Student " << age << endl;
        cout << "\nID of Student" << id << endl;
        cout << "\nGPA of Student" << GPA << endl;
    }
    string role()
    {
        return"Asking and answering questions"

              "Completing in - class assignments"

              "Consistently aligning behavior to classroom norms"

              "Students should always acknowledge that they are a part of a learning community.Each person is responsible for taking ownership of their actions in a way that values building safeand positive classrooms.";
    }
};
class Instructor : public Person
{
public:
    int Salary;
    int Hours;
    Instructor()
    {

    }
    Instructor(string name, int age, int id, int __Salary, int __Hours) : Person(name, age, id)
    {
        Salary = __Salary;
        Hours = __Hours;
    }
    void getData()
    {
        cout << "\nEnter Instructor Name : ";
        cin >> name;
        cout << "\nEnter Age  : ";
        cin >> age;
        cout << "\nEnter ID : ";
        cin >> id;
        cout << "\n Enter salary : ";
        cin >> Salary;
        cout << "\n Enter hours : ";
        cin >> Hours;

    }

    void displayData()
    {
        cout << "\nName of Instrctor :  " << name << endl;
        cout << "\n Age of Instrctor " << age << endl;
        cout << "\nID of Instrctor" << id << endl;
        cout << "\nSalary of Instrctor" << Salary << endl;
        cout << "\nHours of Instrctor" << Hours << endl;

    }
    string role()
    {
        return
            "Instructors provide teaching or training in a classroom setting or via a remote platform."
            "They create and follow lesson plans, choose any necessary curriculum or resource materials."
            "explain conceptsand theories, and review assignmentsand examinations.They may also demonstrate techniquesand assist with experiments, research, or hands - on projects."
            "They frequently serve as mentors or advisors, offering insight on how the course or program may align with the student’s professional or educational goals.";
    }

};
class Employee : public Person
{

public:
    int salary;
    int Hours;
    Employee() : Person()
    {

    }
    Employee(string name, int age, int id, int __Salary, int __Hours) : Person(name, age, id)
    {
        salary = __Salary;
        Hours = __Hours;
    }
    void getData()
    {
        cout << "\nEnter Employee Name : ";
        cin >> name;
        cout << "\nEnter Age  : ";
        cin >> age;
        cout << "\nEnter ID : ";
        cin >> id;
        cout << "\n Enter salary : ";
        cin >> salary;
        cout << "\n Enter hours : ";
        cin >> Hours;

    }

    void displayData()
    {
        cout << "\nName of Employee :  " << name << endl;
        cout << "\n Age of Employee " << age << endl;
        cout << "\nID of Employee" << id << endl;
        cout << "\nSalary of Employee" << salary << endl;
        cout << "\nHours of Employee" << Hours << endl;

    }
    string role()
    {
        return
            "These are the main responsibilities of employees :"
            "to personally do the work they were hired to do"
            "to do their work carefullyand seriously(In some cases, they could be fired or disciplined if they’re often late for work, or if they’re absent too often or for no good reason.)"
            "to avoid putting themselves or others in danger"
            "to follow their employer’s instructions(There are some exceptions.For example, if an employer asks an employee to do something dangerous or illegal, the employee doesn’t have to follow these instructions."
            "to be loyaland honest";
    }

};
class Course
{

public:
    string title;
    int icourse_id;
    Course()
    {

    }
    Course(string t, int id)
    {
        title = t;
        icourse_id = id;
    }


    void getData()
    {
        cout << "\n Enter course title : ";
        getline(cin,title);
        cout << "\nEnter course Id : ";
        cin >> icourse_id;
    }
    void displayData()
    {
        cout << "\nTitle of Course : " << title << " id of Course : " << icourse_id<<"\n";

    }
};
class Department
{
public:
    string title;
    vector<Course>courses;
    Department()
    {

    }
    Department (string t)
    {
        title=t;
    }
    Department(string t, vector<Course>c)
    {
        title = t;
        courses = c;
    }
    void getData()
    {
        cout << "\nEnter Department Name : ";
        getline(cin,title);
        cout << "\n ";
    }
    void dispaly_Course()
    {
        for (int i = 0; i < courses.size(); i++)
        {
            courses[i].displayData();
        }
    }

    void Details()
    {
        cout<<"Department information "<<"\n"<<"\n";

        cout<<"Title of Department : "<<title<<"\n";
        string myText;
        ifstream File("addcourse.txt");
        while (getline (File, myText))
        {
            cout << myText<<"\n";
        }

        File.close();

    }

    void AddCourse()
    {
        int number;
        cout << "Enter Number of Course You Want to Add ";
        cin >> number;
        fstream file;
        file.open("addcourse.txt",std::ios_base::app);
        cout << "\nWriting Course information to the file :- " << endl;
        cout << "\nEnter course Details to the File :- " << endl;

        for (int i = 0; i < number; i++)
        {
            Course c;
            cout<<"Enter Course Title : ";
            string t;
            cin>>t;
            c.title=t;
            cout<<"\n Enter course id ";
            int id;
            cin>>id;
            c.icourse_id=id;
            file<<" course title is "<<c.title<<" id = "<<c.icourse_id<<" \n";

        }
        file.close();
    }
    void AddCourse( Course c)
    {
        fstream File;
        File.open("addcourse.txt", std::ios_base::app);
        courses.push_back(c);
        File<<" course title is "<<c.title<<" id = "<<c.icourse_id<<" \n";
        File.close();
    }

};


class Faculty
{

public:
    string title;
    vector<Student> students;
    vector<Instructor> instructors;
    vector<Employee>Employees;
    vector<Department>Departments;
    Faculty()
    {

    }
    Faculty(string t)
    {
        title=t;
    }
    Faculty(string t, vector<Student> s, vector<Instructor> i,vector<Employee>E,  vector<Department>D )
    {
        title=t;
        students=s;
        Employees=E;
        Departments=D;
    }
    void Details()
    {
        cout<<"Faculty  Information : "<<"\n"<<"\n";
        cout<<"Title of Department : "<<title<<"\n";

        string myText;
        ifstream File("addstudent.txt");
        while (getline (File, myText))
        {
            cout << myText<<"\n";
        }

        File.close();

        string myTextt;
        ifstream Filee("addinstructor.txt");
        while (getline (Filee, myTextt))
        {
            cout << myTextt<<"\n";
        }

        Filee.close();

        string myTexttt;
        ifstream Fileee("addemployee.txt");
        while (getline (Fileee, myTexttt))
        {
            cout << myTexttt<<"\n";
        }

        Fileee.close();

        string myTex;
        ifstream Fil("adddepartment.txt");
        while (getline (Fil, myTex))
        {
            cout << myTex<<"\n";
        }

        Fil.close();


    }
    void addStudent()
    {
        int number;
        cout << "Enter Number of Student You Want to Add ";
        cin >> number;
        fstream file;
        file.open("addstudent.txt",std::ios_base::app); // open file for writing
        cout << "\nWriting Student information to the file :- " << endl;
        cout << "\nEnter students Details to the File :- " << endl;

        for (int i = 0; i < number; i++)
        {
            Student s;
            string n;
            int a,idd;
            float g;
            cout << "\nEnter Student Name : ";
            cin >> n;
            cout << "\nEnter Age  : ";
            cin >> a;
            cout << "\nEnter ID : ";
            cin >> idd;
            cout << "\n Enter GPA : ";
            cin >> g;
            s.name=n;
            s.age=a;
            s.id=idd;
            s.GPA=g;
            file<<"Name is "<<s.name<< " - " <<" Age = "<<s.age<<" - "<< "ID = "<<s.id <<" - "<<"GPA = "<<s.GPA<<"\n";
        }

        file.close();


    }

    void addStudent( Student s)
    {
        fstream File;
        File.open("addstudent.txt", std::ios_base::app);
        students.push_back(s);
        File<<"Name is "<<s.name<< " - " <<" Age = "<<s.age<<" - "<< "ID = "<<s.id <<" - "<<"GPA = "<<s.GPA<<"\n";

        File.close();
    }


    void addInstructor()
    {
        int number;
        cout << "Enter Number of Instructor You Want to Add ";
        cin >> number;
        fstream file;
        file.open("addinstructor.txt",std::ios_base::app);
        cout << "\nWriting Instructor information to the file :- " << endl;
        cout << "\nEnter Insructor Details to the File :- " << endl;

        for (int i = 0; i < number; i++)
        {
            Instructor ins;
            string n;
            int a,idd,s,h;
            cout << "\nEnter Instructor Name : ";
            cin >> n;
            cout << "\nEnter Age  : ";
            cin >> a;
            cout << "\nEnter ID : ";
            cin >> idd;
            cout << "\n Enter salary : ";
            cin >> s;
            cout << "\n Enter hours : ";
            cin >> h;
            ins.name=n;
            ins.age=a;
            ins.id=idd;
            ins.Salary=s;
            ins.Hours=h;
            file<< "Instructor Name is "<<ins.name <<" - "<< "Age : "<<ins.age<<" - ID : "<<ins.id<<" - Salary : "<<ins.Salary<<" - Hours : "<<ins.Hours<<"\n";

        }

        file.close();
    }
    void addInstructor( Instructor ins)
    {
        fstream file;
        file.open("addinstructor.txt", std::ios_base::app);
        instructors.push_back(ins);
        file<< "Instructor Name is "<<ins.name <<" - "<< "Age : "<<ins.age<<" - ID : "<<ins.id<<" - Salary : "<<ins.Salary<<" - Hours : "<<ins.Hours<<"\n";
        file.close();
    }

    void addEmployee()
    {
        int number;
        cout << "Enter Number of Employee You Want to Add ";
        cin >> number;
        fstream file;
        file.open("addemployee.txt",std::ios_base::app);
        cout << "\nWriting Employee information to the file :- " << endl;
        cout << "\nEnter Employee Details to the File :- " << endl;

        for (int i = 0; i < number; i++)
        {
            Employee ee;
            string n;
            int a,idd,s,h;
            cout << "\nEnter Employee Name : ";
            cin >> n;
            cout << "\nEnter Age  : ";
            cin >> a;
            cout << "\nEnter ID : ";
            cin >> idd;
            cout << "\n Enter salary : ";
            cin >> s;
            cout << "\n Enter hours : ";
            cin >> h;
            ee.name=n;
            ee.age=a;
            ee.id=idd;
            ee.salary=s;
            ee.Hours=h;

            file<< "Employee Name is "<<ee.name <<" - "<< "Age : "<<ee.age<<" - ID : "<<ee.id<<" - Salary : "<<ee.salary<<" - Hours : "<<ee.Hours<<"\n";

        }

        file.close();
    }
    void addEmployee( Employee ee)
    {
        fstream file;
        file.open("addemployee.txt", std::ios_base::app);
        Employees.push_back(ee);
        file<< "Employee Name is "<<ee.name <<" - "<< "Age : "<<ee.age<<" - ID : "<<ee.id<<" - Salary : "<<ee.salary<<" - Hours : "<<ee.Hours<<"\n";
        file.close();
    }

    void addDepartments(Department D)
    {
        fstream File;
        File.open("adddepartment.txt", std::ios_base::app);
        Departments.push_back(D);
        File<<" Department title is "<<D.title<<" \n";
        File.close();
    }



};

class University
{

public:
    string title;
    Manger* manger;
    vector<Faculty>Faculties;

    University()
    {
        cout<<"University added"<<"\n";

    }
    University(string t)
    {
        title=t;
        cout<<"University added"<<"\n";
    }
  University(string t, Manger * m)
    {
        title = t;
        manger =m;
    cout<<"University added"<<"\n";

    }
    University(string t, Manger * m, vector<Faculty>F)
    {
        title = t;
        manger = m;
        Faculties = F;
    cout<<"University added"<<"\n";

    }

    void Details()
    {
        cout<<"University Information "<<"\n"<<"\n";
        cout<<"University Title : "<<title<<"\n";
        cout<<"Manger : "<<manger->name<<"\n";


    }

    void addFaculty(Faculty f)
    {
        fstream file;
        file.open("addfaculty.txt", std::ios_base::app);
        Faculties.push_back(f);
        file<< "Faculty title is "<<f.title<<"\n";
        file.close();

    }

};
int main()
{
    // university

    Manger* m1 = Manger::GetInstance();
    m1->name="mohamed samir";
    m1->age=35;
    m1->id=1;
    m1->Set_Salary(30000);
    University u("SVU" , m1);
    u.Details();
    Faculty f1("Computer And Information");
    u.addFaculty(f1);  // add faculty


    //add course
// adding course by asking the user
    Department d("Department 1");
    Course c1;
    c1.getData();
    d.AddCourse(c1);
    // adding course by constructor
    Course c2("database",3);
    d.AddCourse(c2);
    d.AddCourse();
     d.Details();


    //faculty
    Faculty f;
    Department d2("IT");
    f.addStudent();
    f.addEmployee();
    f.addInstructor();
    f.addDepartments(d2);
    f.Details();





}


