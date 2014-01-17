/* 
 * File:   Menu.h
 * Author: Psycku
 *
 * Created on 16 de Janeiro de 2014, 13:21
 */

#ifndef MENU_H
#define	MENU_H

#include "Utils.h"
#include "Employee.h"
#include "Station.h"

void Menu(Employee employees[], Station stations[]);

void empMenu(Employee employees[], Station stations[]);

void staMenu(Employee employees[], Station stations[]);

int empModifyMenu();

int staModifyMenu();


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MENU_H */

