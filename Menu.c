
#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"

void Menu(Employee employees[], Station stations[]) {
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
        empMenu(employees, stations);
    } else if(menuOpt == 2) {
        staMenu(employees, stations);
    } else if(menuOpt == 3) {
        // TODO: measMenu();
    } else {
        saveStationFile(stations);
        saveEmployeeFile(employees);
        
    }
}

/*
void empMenu(Employee employees[], Station stations[]) {
    int empOpt, empNr, modOpt;
    unsigned long int removeId, verified;
    
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
        verified = verifyEmpPosition(employees);
        if(verifyEmpPosition(employees) == EOF) {
            printf("Employees full.");
            printf("Must remove one Employee first.");
        } else {
            employees[verified] = addEmployee(employees[verified]);
            saveEmployeeFile(employees);
        }
        Menu(employees, stations);
    } else if(empOpt == 2) {
        listEmployees(employees);
        printf("Insert which Employee to modify: "); // TODO: CHANGE THIS TO MODIFY WITH ID
        scanf("%d", &empNr);
        limparBufferEntradaDados();
        modOpt = empModifyMenu();
        employees[empNr] = modifyEmployee(employees[empNr], modOpt);
        saveEmployeeFile(employees);
        empMenu(employees, stations);
    } else if(empOpt == 3) {
        listEmployees(employees);
        printf("Insert ID of Employee to remove: ");
        scanf("%lu", &removeId);
        employees[EMP_SIZE] = removeEmployee(employees, removeId);
        saveEmployeeFile(employees);
        empMenu(employees, stations);
    } else if(empOpt == 4) {
        listEmployees(employees);
        empMenu(employees, stations);
    } else {
        Menu(employees, stations);
    }
}
*/

void empMenu(Employee employees[], Station stations[]) {
    // verificar se devolve elementos!!!!!   
    int opt, empNr, modOpt;
    unsigned short int verified, removeNr;

    do {

        printf("Options: %c", NEWLINE);
        printf("1. Add Employee. %c", NEWLINE);
        printf("2. Modify Employee. %c", NEWLINE);
        printf("3. Remove Employee. %c", NEWLINE);
        printf("4. List Employee. %c", NEWLINE);
        printf("5. Back %c", NEWLINE);

        printf("Option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                verified = verifyEmpPosition(employees);
                if(verifyEmpPosition(employees) == EOF) {
                    printf("Employees full.");
                    printf("Must remove one Employee first.");
                } else {
                    employees[verified] = addEmployee(employees[verified]);
                    saveEmployeeFile(employees);
                }
                Menu(employees, stations);
                break;
            case 2:
                listEmployees(employees);
                printf("Insert which Employee to modify: "); // TODO: CHANGE THIS TO MODIFY WITH ID
                scanf("%d", &empNr);
                limparBufferEntradaDados();
                modOpt = empModifyMenu();
                employees[empNr] = modifyEmployee(employees[empNr], modOpt);
                saveEmployeeFile(employees);
                empMenu(employees, stations);
                break;
            case 3:
                listEmployees(employees);
                printf("Insert ID of Employee to remove: ");
                scanf("%hu", &removeNr);
                employees[EMP_SIZE] = removeEmployee(employees, removeNr);
                saveEmployeeFile(employees);
                empMenu(employees, stations);
                break;
            case 4:
                listEmployees(employees);
                empMenu(employees, stations);
                break;
            case 5:
                Menu(employees, stations);
                break;
        }
    } while (opt < 1 && opt > 5);
}

void staMenu(Employee employees[], Station stations[]) {
    // verificar se devolve elementos!!!!!   
    int opt, numbSta, staNr, modOpt;
    unsigned short int verified, removeNr;

    do {

        printf("Options: %c", NEWLINE);
        printf("1. Add Station. %c", NEWLINE);
        printf("2. Modify Station. %c", NEWLINE);
        printf("3. Remove Station %c", NEWLINE);
        printf("4. List Station %c", NEWLINE);
        printf("5. Back %c", NEWLINE);

        printf("Option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                verified = verifyStaPosition(stations);
                if(verifyStaPosition(stations) == EOF) {
                    printf("Stations full.");
                    printf("Must remove one Station first.");
                } else {
                    stations[verified] = addStation(stations[verified]);
                    saveStationFile(stations);
                }
                Menu(employees, stations);
                break;
            case 2:
                listStations(stations);
                printf("Insert which Station to modify: "); // TODO: CHANGE THIS TO MODIFY WITH ID
                scanf("%d", &staNr);
                limparBufferEntradaDados();
                modOpt = staModifyMenu();
                stations[staNr] = modifyStation(stations[staNr], modOpt);
                saveStationFile(stations);
                staMenu(employees, stations);
                break;
            case 3:
                listStations(stations);
                printf("Insert ID of Station to remove: ");
                scanf("%hu", &removeNr);
                stations[STA_SIZE] = removeStation(stations, removeNr);
                saveStationFile(stations);
                staMenu(employees, stations);
                break;
            case 4:
                listStations(stations);
                staMenu(employees, stations);
                break;
            case 5:
                Menu(employees, stations);
                break;
        }
    } while (opt < 1 && opt > 5);
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

int staModifyMenu() {
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

