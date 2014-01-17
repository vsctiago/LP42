/* 
 * File:   main.c
 * Author: psycku
 *
 * Created on 14 de Janeiro de 2014, 14:24
 */

#include <stdio.h>
#include <stdlib.h>

#include "Employee.h"
#include "Station.h"
#include "Menu.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Employee employees[EMP_SIZE];
    Station stations[STA_SIZE];
    
    employees[EMP_SIZE] = readEmployeeFile(employees);
    stations[STA_SIZE] = readStationFile(stations);
    
    Menu(employees, stations);
    
/*
    printf("%lu %c", employees[empNr].employeeId, NEWLINE);
    printf("%s %c", employees[empNr].general.name, NEWLINE);
    printf("%s %c", employees[empNr].general.address.streetName, NEWLINE);
    printf("%hu %c", employees[empNr].general.address.number, NEWLINE);
    printf("%s %c", employees[empNr].general.address.postalCode, NEWLINE);
    printf("%s %c", employees[empNr].general.address.city, NEWLINE);
    printf("%lu %c", employees[empNr].general.phone, NEWLINE);
    switch(employees[empNr].general.level){
        case LOW: puts("LOW");
        break;
        case MEDIUM: puts("MEDIUM");
        break;
        case HIGH: puts("HIGH");
        break;
    }
*/
    
    
    
    return (EXIT_SUCCESS);
}

