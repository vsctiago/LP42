
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Employee.h"

Employee getEmployeeId(Employee employee) {
    bool val = false;
    
    printf("Insert ID: ");
    scanf("%lu", &employee.employeeId);
    limparBufferEntradaDados();
    while(val == false){
        if(employee.employeeId > 0 && employee.employeeId < 99999999) {
            val = true;
        } else {
            val = false;

            printf("Insert a valid ID: ");
            scanf("%lu", &employee.employeeId);
            limparBufferEntradaDados();
        }
    }
    return employee;
}

Employee addEmployee(Employee employees[], unsigned short int empNr) {
    
    employees[empNr] = getEmployeeId(employees[empNr]);
    employees[empNr].general = getName(employees[empNr].general);
    employees[empNr].general = getAddress(employees[empNr].general);
    employees[empNr].general = getPhone(employees[empNr].general);
    employees[empNr].general = getLevel(employees[empNr].general);
    
    return employees[empNr];
}



void createEmployeeFile(Employee employees[]) {
    
    FILE *pEmployee = fopen("Employees", "w");
    if(pEmployee == (FILE *) NULL) {
        puts("Couldn't create file.");
    } else {
        fwrite(employees, sizeof(Employee), EMP_SIZE, pEmployee);
        fclose(pEmployee);
    }
}

Employee initEmployeeFile(Employee employees[]) {
    
}

Employee readEmployeeFile(Employee employees[]) {
    
    FILE *pEmployee = fopen("Employees", "r");
    if (pEmployee == (FILE *) NULL) {
        puts("File doesn't exist");
        puts("Creating file now...");
        createEmployeeFile(employees);
        employees[EMP_SIZE] = initEmployeeFile(employees);
        puts("File created.");
        readEmployeeFile(employees);
    } else {
        fread(employees, sizeof(Employee), EMP_SIZE, pEmployee);
        fclose(pEmployee);
    }
}