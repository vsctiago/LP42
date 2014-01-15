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
#define EMP_MAX 20

typedef struct employee {
    unsigned long int employeeId;
    General general;
    //tm birthDay;
} Employee;

Employee getEmployeeId(Employee employee);

Employee addEmployee(Employee employees[], unsigned short int empNr);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* EMPLOYEE_H */

