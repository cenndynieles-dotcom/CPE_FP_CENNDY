
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Employee infomation structure
struct Employee {
	int id;
	string First_Name;
	string Last_Name;
	float basicSalary;
	int OverTime;
	int Absent;
	int minutesLate;
	int holidaysWorked;
	string isLegit13th;
	float deductions;
	float thirteenthMonthpay;
	float netSalary;
	float holidayPay;
	float monthsWorked;
};

//Variables

Employee employees[500];
int employeeCount;


//Taxes and Deduction
const float OVERTIME_RATE = 100.0;
const float ABSENCE_DEDUCTION = 500.0;
const float LATE_DEDUCTION = 2.0;
const float SSS_RATE = 0.045;
const float PHILHEALTH_RATE = 0.035;
const float PAGIBIG_CONTRIBUTION = 100.0;

//FUNCTION PROTOTYPES

float computeNetSalary(Employee &emp);
void addEmployee();
void viewEmployees();
void updateEmployee();
void deleteEmployee();

// MAIN MENU/FUNCTIONS

int main(){
	int choice;
	
	
	do{
		cout << "\n========== PAYROLL MANAGEMENT SYSTEM ===========\n";
		cout << "1. Add Employee\n";
		cout << "2. View Employees\n";
		cout << "3. Update Employee\n";
		cout << "4. Delete Employee\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice){
		case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";	
		}
	} while (choice != 5);
	
	return 0;
}

// SALARY COMPUTATION

float computeNetSalary(Employee &emp){
	float overtimePay = emp.OverTime * OVERTIME_RATE;
    float sss = emp.basicSalary * SSS_RATE;
    float philhealth = emp.basicSalary * PHILHEALTH_RATE;
    float pagibig = PAGIBIG_CONTRIBUTION;
    float lateDeduction = emp.minutesLate * LATE_DEDUCTION;
    float absenceDeduction = emp.Absent * ABSENCE_DEDUCTION;

    float dailyRate = emp.basicSalary / 22;
    emp.holidayPay = emp.holidaysWorked * dailyRate * 2;

    if (emp.monthsWorked >= 1) {
        emp.thirteenthMonthpay = emp.basicSalary / 12;
    } else {
        emp.thirteenthMonthpay = 0;
    }

    emp.deductions = sss + philhealth + pagibig + lateDeduction + absenceDeduction;
    emp.netSalary = emp.basicSalary + overtimePay + emp.holidayPay + emp.thirteenthMonthpay - emp.deductions;

    return emp.netSalary; 
}



// ADD EMPLOYEEE FUNCTION

void addEmployee(){
	if (employeeCount >= 500){
		cout << "Employee list if currently full\n";
		return;
	}
	
	Employee emp;
	cout << "\n--- Add Employee ---\n";
	cout << "Enter ID: ";
	cin >> emp.id;
	cin.ignore();
	
	cout << "Enter First Name: ";
	getline(cin, emp.First_Name);
	
	cout << "Enter Last Name: ";
	getline(cin, emp.Last_Name);
	
	
	cout << "Enter Basic Salary: ";
    cin >> emp.basicSalary;
    cout << "Enter Overtime Hours: ";
    cin >> emp.OverTime;
    cout << "Enter Days Absent: ";
    cin >> emp.Absent;
    cout << "Enter Minutes Late: ";
    cin >> emp.minutesLate;
    cout << "Enter Paid Holidays: ";
    cin >> emp.holidaysWorked;
    cout << "Enter Months Worked: ";
    cin >> emp.monthsWorked;

    computeNetSalary(emp);
    employees[employeeCount] = emp;
    employeeCount++;
	
	cout << "Employee Successfully Added";                                                                                                                                                                                
}


//View Employee List

void viewEmployees() {
	if (employeeCount == 0){
		cout << "\nNO Employee(s) Found please add employee(s)\n";
		return;
	}
	
	cout << "\n===========================================================================================================\n";
	cout << left
	     << setw(6)  << "ID"
         << setw(20) << "First Name"
         << setw(20) << "Last Name"
         << setw(12) << "Basic"
         << setw(12) << "Overtime"
         << setw(10) << "Abesent"
         << setw(10) << "Late"
         << setw(14) << "Holiday Pay"
         << setw(16) << "13thMonth"
         << setw(14) << "Deductions"
         << setw(12) << "Net Salary" << endl;
         
	cout << "\n===========================================================================================================\n";
	
	cout << fixed << setprecision(3);
	for (int i = 0; i < employeeCount; i++) {
		cout << left
	     << setw(6)  << employees[i].id << " | "
         << setw(20) << employees[i].First_Name << " | "
         << setw(20) << employees[i].Last_Name << " | "
         << setw(12) << employees[i].basicSalary << " | "
         << setw(12) << employees[i].OverTime << " | "
         << setw(10) << employees[i].Absent << " | "
         << setw(10) << employees[i].minutesLate << " | "
         << setw(14) << employees[i].holidayPay << " | "
         << setw(16) << employees[i].thirteenthMonthpay << " | "
         << setw(14) << employees[i].deductions
         << setw(12) << employees[i].netSalary << endl << " | ";
		     
	}
	
	cout << "\n===========================================================================================================\n";
	
}


//Update Employee(s)
void updateEmployee(){
	int id;
	cout <<" Enter Employee ID to Update Information: ";
	cin >> id;
	
	bool found = false;
	for (int i = 0; i < employeeCount; i++){
		if(employees[i].id == id){
		found = true;
		cout << "Updating " << employees[i].First_Name << " " << employees[i].Last_Name << endl;
			cout << "Enter Basic Salary: ";
			cin >> employees[i].basicSalary;
			cout << "Enter Overtime Hours: ";
			cin >> employees[i].OverTime;
			cout << "Enter Days Absent: ";
			cin >> employees[i].Absent;
			cout << "Enter Minutes Late: ";
			cin >> employees[i].minutesLate;
			cout << "Enter Paid Holidays: ";
			cin >> employees[i].holidaysWorked;
			cout << "Enter Months Worked: ";
		    cin >> employees[i].monthsWorked;
		    
		    
		    computeNetSalary(employees[i]);
		    cout << "Employee Updated Sucessfully";
		    break;
	}

  }
  
  if (!found){
  	cout << "EMPLOYEE CANNOT BE FOUND"<< endl; 
  }
	
}

//DELETE EMPLOYEE ACCOUNT
 
 void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to Delete: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            found = true;
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            cout << "Employee Deleted Successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Employee Not Found!\n";
    }
}




