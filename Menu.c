
#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"

void Menu(Employee employees[]) {
    int menuOpt;
    
    printf("Options: %c", NEWLINE);
    printf("1. Employee. %c", NEWLINE);
    printf("2. Station %c", NEWLINE);
    printf("3. Measurement %c", NEWLINE);
    printf("4. Exit %c", NEWLINE);
    
    do {
        printf("Option: ");
        scanf("%d", &menuOpt);
        limparBufferEntradaDados();
    } while(menuOpt < 1 && menuOpt > 3);
    
    if(menuOpt == 1) {
        empMenu(employees);
    } else if(menuOpt == 2) {
        // TODO: staMenu();
    } else if(menuOpt == 3) {
        // TODO: measMenu();
    } else {
        saveEmployeeFile(employees);
        // TODO: CLOSE PROGRAM
    }
}

void empMenu(Employee employees[]) {
    int empOpt, empNr, modOpt;
    unsigned long int removeId;
    
    printf("Options: %c", NEWLINE);
    printf("1. Add Employee. %c", NEWLINE);
    printf("2. Modify Employee. %c", NEWLINE);
    printf("3. Remove Employee %c", NEWLINE);
    printf("4. List Employee %c", NEWLINE);
    printf("5. Back %c", NEWLINE);
    
    do {
        printf("Option: ");
        scanf("%d", &empOpt);
        limparBufferEntradaDados();
    } while(empOpt < 1 && empOpt > 5);
    
    if(empOpt == 1) {
        printf("Which position to add? "); // for testing
        scanf("%d", &empNr);
        addEmployee(employees, empNr);
        saveEmployeeFile(employees);
        Menu(employees);
    } else if(empOpt == 2) {
        listEmployees(employees);
        printf("Insert which Employee to modify: "); // TODO: CHANGE THIS TO MODIFY WITH ID
        scanf("%d", &empNr);
        limparBufferEntradaDados();
        modOpt = empModifyMenu();
        employees[empNr] = modifyEmployee(employees[empNr], modOpt);
        saveEmployeeFile(employees);
        empMenu(employees);
    } else if(empOpt == 3) {
        listEmployees(employees);
        printf("Insert ID of Employee to remove: ");
        scanf("%lu", &removeId);
        employees[EMP_SIZE] = removeEmployee(employees, removeId);
        saveEmployeeFile(employees);
        empMenu(employees);
    } else if(empOpt == 4) {
        listEmployees(employees);
        empMenu(employees);
    } else {
        Menu(employees);
    }
}

int empModifyMenu() {
    int modOpt;
    
    printf("What to modify? %c", NEWLINE);
    printf("1. Name. %c", NEWLINE);
    printf("2. Street Name. %c", NEWLINE);
    printf("3. Number. %c", NEWLINE);
    printf("4. PostalCode. %c", NEWLINE);
    printf("5. City. %c", NEWLINE);
    printf("6. Phone number. %c", NEWLINE);
    printf("7. Level access. %c", NEWLINE);
    printf("8. Back %c", NEWLINE);
    
    do {
        printf("Option: ");
        scanf("%d", &modOpt);
        limparBufferEntradaDados();
    } while(modOpt < 1 && modOpt > 7);
    return modOpt;
}
