
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "General.h"

General getName(General general) {
    bool val = false;
    int i;
    
    /* Keeps asking for a name until that name is valid.
     */
    do{
        printf("Insert name: ");
        lerFrase(general.name, NAME_LENGTH);
        // for that goes through the entire array or until it reaches the end.
        for( i=0; i<NAME_LENGTH && general.name[i] != '\0'; i++){
            // Verifies if its either a letter or a space in each array's positions.
            if(isalpha(general.name[i]) || isspace(general.name[i])){
                val = true;
            } else {
                /* If it finds a position that doesn't contain either a letter 
                 * nor a space, breaks the for cycle.
                 */
                val = false;
                break;
            }// if ends.
        }// for ends.
    } while(val == false);
    return general;
}

Address getStreetName(Address address) {
    bool val = false;
    int i;
    
    /* Keeps asking for a street name until that name is valid.
     */
    do {
        printf("Insert street name: ");
        lerFrase(address.streetName, STREET_LENGTH);
        // for that goes through the entire array or until it reaches the end.
        for( i=0; i<STREET_LENGTH && address.streetName[i] != '\0'; i++){
            // Verifies if its either a letter or a space in each array's positions.
            if(isalpha(address.streetName[i]) || isspace(address.streetName[i])){
                val = true;
            } else {
                /* If it finds a position that doesn't contain either a letter 
                 * nor a space, breaks the for cycle.
                 */
                val = false;
                break;
            }// if ends.
        }// for ends.
    } while(val == false);
    return address;
}

Address getNumber(Address address) {
    bool val = false;
    
    do {
        printf("Insert number: ");
        scanf("%hu", &address.number);
        limparBufferEntradaDados();
        // if checks if the number is between the right values.
        if(address.number > NUMBER_MIN && address.number < NUMBER_MAX) {
            val = true;
        } else {
            /* if the number isn't between 0 and 1000 val = false, so it asks 
             * for the number again.
             */
            val = false;
        }// if ends.
    } while(val == false);
    return address;
}

Address getPostalCode(Address address) {
    bool val1 = false, val2 = false, val3 = false;
    int i, check = 0;
    
    do {
        if(check == 0) {
            printf("Insert Postal Code: ");
        } else {
            printf("Insert a valid Postal Code: ");
        }
        lerFrase(address.postalCode, POSTALCODE_LENGTH);
        if(address.postalCode[PC_DASH] == '-')
            val1 = true;
        for( i=0; i<PC_DASH; i++){
            if(isdigit(address.postalCode[i])){
                val2 = true;
            } else {
                val2 = false;
                break;
            }
        }
        for( i=PC_ADASH; i<POSTALCODE_LENGTH-1; i++){
            if(isdigit(address.postalCode[i])) {
                val3 = true;
            } else {
                val3 = false;
                break;
            }
        }
        check = 1;
    } while (val1 == false || val2 == false || val3 == false);
    limparBufferEntradaDados();
    return address;
}

Address getCity(Address address) {
    bool val = false;
    int i;
    
    do {
        printf("Insert City: ");
        lerFrase(address.city, CITY_LENGTH);
        // for that goes through the entire array or until it reaches the end.
        for( i=0; i<CITY_LENGTH && address.city[i] != '\0'; i++){
            // Verifies if its either a letter or a space in each array's positions.
            if(isalpha(address.city[i]) || isspace(address.city[i])){
                val = true;
            } else {
                /* If it finds a position that doesn't contain either a letter 
                 * nor a space, breaks the for cycle.
                 */
                val = false;
                break;
            }// if ends.
        }// for ends.
    } while(val == false);
    return address;
}

General getAddress(General general) {
    
    general.address = getStreetName(general.address);
    general.address = getNumber(general.address);
    general.address = getPostalCode(general.address);
    general.address = getCity(general.address);
    
    return general;
}

General getPhone(General general) {
    bool val = false;
    
    do {
        printf("Insert phone number: ");
        scanf("%lu", &general.phone);
        limparBufferEntradaDados();
        
        if(general.phone > 210000000 && general.phone < 299999999) {
            val = true;
        } else if(general.phone > 910000000 && general.phone < 919999999) {
            val = true;
        } else if(general.phone > 920000000 && general.phone < 929999999) {
            val = true;
        } else if(general.phone > 930000000 && general.phone < 939999999) {
            val = true;
        } else if(general.phone > 960000000 && general.phone < 969999999) {
            val = true;
        } else {
            val = false;
        }
    } while(val == false);
    return general;
}

General getLevel(General general) {
    bool val = false;
    char level;
    
    do {
        printf("Insert Level access: ");
        scanf("%c", &level);
        limparBufferEntradaDados();
        if (level == 'L' || level == 'l'){
            val = true;
            general.level = LOW;
        } else if (level == 'M' || level == 'm'){
            val = true;
            general.level = MEDIUM;
        } else if (level == 'H' || level == 'h'){
            val = true;
            general.level = HIGH;
        } else {
            val = false;
        }
    } while(val == false);
    return general;
}


