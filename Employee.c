
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Employee.h"

Employee getEmployeeId(Employee employee) {
    bool val = false;
    int check = 0;
    
    do {
        if(check == 0) {
            printf("Insert Id: ");
        } else {
            printf("Insert a valid Id: ");
        }
        scanf("%lu", &employee.employeeId);
        limparBufferEntradaDados();

        if(employee.employeeId > 0 && employee.employeeId < 99999999) {
            val = true;
        } else {
            val = false;
        }
        check = 1;
    } while (val == false);
    return employee;
}

Employee addEmployee(Employee employees[], unsigned short int empNr) {
    
    employees[empNr] = getEmployeeId(employees[empNr]);
    employees[empNr].general = getName(employees[empNr].general);
    employees[empNr].general = getAddress(employees[empNr].general);
    employees[empNr].general = getPhone(employees[empNr].general);
    employees[empNr].general = getLevel(employees[empNr].general);
    printf("Client added successfully. %c", NEWLINE);
    
    return employees[empNr];
}

Employee modifyEmployee(Employee employee, int modOpt) {
    
    if(modOpt == 1) {
        employee.general = getName(employee.general);
    } else if(modOpt == 2) {
        employee.general.address = getStreetName(employee.general.address);
    } else if(modOpt == 3) {
        employee.general.address = getNumber(employee.general.address);
    } else if(modOpt == 4) {
        employee.general.address = getPostalCode(employee.general.address);
    } else if(modOpt == 5) {
        employee.general.address = getCity(employee.general.address);
    } else if(modOpt == 6) {
        employee.general = getPhone(employee.general);
    } else if(modOpt == 7) {
        employee.general = getLevel(employee.general);
    }
    
    return employee;
}

Employee removeEmployee(Employee employees[], unsigned long int id) {
    int i;
    
    for(i=0; i<EMP_SIZE; i++){
        if(employees[i].employeeId == id) {
            employees[i].employeeId = 0;
        }
    }
    return employees[EMP_SIZE];
}

void listEmployees(Employee employees[]) {
    int i;
    
    for(i=0; i<EMP_SIZE && employees[i].employeeId != 0; i++){
        printf("%d - %lu - %s %c", i, employees[i].employeeId, employees[i].general.name, NEWLINE);
    }
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
    int i;
    
    for(i=0; i<EMP_SIZE; i++){
        employees[i].employeeId = 0;
    }
    return employees[EMP_SIZE];
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

void saveEmployeeFile(Employee employees[]) {
    
    FILE *pEmployee = fopen("Employees","w");
    if(pEmployee == (FILE *) NULL) {
        puts("File doesn't exist.");
        puts("Couldn't save.");
    } else {
        fwrite(employees, sizeof(Employee), EMP_SIZE, pEmployee);
        puts("File saved.");
        fclose(pEmployee);
    }
}
