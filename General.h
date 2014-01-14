/* 
 * File:   General.h
 * Author: Psycku
 *
 * Created on 3 de Janeiro de 2014, 23:48
 */

#ifndef GENERAL_H
#define	GENERAL_H

#include "Utils.h"
#define NAME_LENGTH 100+1
#define STREET_LENGTH 50+1
#define NUMBER_LENGTH 3
#define POSTALCODE_LENGTH 8+1
#define CITY_LENGTH 30+1
#define NUMBER_MIN 0
#define NUMBER_MAX 999
#define PC_DASH 4
#define PC_ADASH 5


typedef enum level {
    LOW = 'L', MEDIUM = 'M', HIGH = 'H'
} Level;

typedef struct address {
    char streetName[STREET_LENGTH];
    unsigned short int number;
    char postalCode[POSTALCODE_LENGTH];
    char city[CITY_LENGTH];
} Address;

typedef struct general {
    char name[NAME_LENGTH];
    Address address;
    unsigned long int phone;
    Level level;
} General;

General getName(General general);

Address getStreetName(Address address);

Address getNumber(Address address);

Address getPostalCode(Address address);

Address getCity(Address address);

General getAddress(General general);

General getPhone(General general);

General getLevel(General general);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* GENERAL_H */

