/* 
 * File:   Employee.h
 * Author: Psycku
 *
 * Created on 3 de Janeiro de 2014, 23:30
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <time.h>
#include "General.h"
#define EMP_SIZE 20

typedef struct employee {
    unsigned long int employeeId;
    General general;
    //tm birthDay;
} Employee;

unsigned short int verifyEmpPosition(Employee employees[]);

Employee getEmployeeId(Employee employee);

Employee addEmployee(Employee employee);

Employee modifyEmployee(Employee employee, int modOpt);

Employee removeEmployee(Employee employees[], unsigned long int id);

void listEmployees(Employee employees[]);

void createEmployeeFile(Employee employees[]);

Employee initEmployeeFile(Employee employees[]);

Employee readEmployeeFile(Employee employees[]);

void saveEmployeeFile(Employee employees[]);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* EMPLOYEE_H */

