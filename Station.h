/* 
 * File:   Station.h
 * Author: psycku
 *
 * Created on 14 de Janeiro de 2014, 14:27
 */

#ifndef STATION_H
#define	STATION_H

#include <time.h>
#include "General.h"

#define STA_SIZE 5
#define STA_INIT 0
#define STA_NUMB_MAX 999

typedef enum sensors {
    TEMPERATURE, PRECIPITATION, WINDSPEED, WINDDIRECTION, CLOUDINESS
} Sensors;

typedef struct station {
    unsigned short int number;
    General general;
    Sensors sensors;
    float coordinatesX;
    float coordinatesY;
} Station;

typedef struct sensCloudiness {
    char cloudtype;
    char coverage;

} SensCloudiness;

typedef struct metering {
    unsigned short int day;
    unsigned short int year;
    unsigned short int month;
    unsigned short int time;
    unsigned short int minutes;
    //  char funcionario;
    unsigned short int temperature;
    unsigned short int wind;
    unsigned short int direction;
    unsigned short int speed;
    SensCloudiness cloudiness;
} Metering;


unsigned short int verifyStaPosition(Station stations[]);
Station getNumberStation(Station station);
Station getSensors(Station station);
Station getCoordinates(Station station);
Station addStation(Station station);
//Station modifyStation(Station station[], unsigned short int staNumb);
Station modifyStation(Station station, int modOpt);
Station removeStation(Station stations[], unsigned short int number);
void listStations(Station station[]);
Station modiStation(Station station[], unsigned short int numbSta);
void createStationFile(Station stations[]);
Station iniStation(Station station[]);
Station readStationFile(Station stations[]);
void saveStationFile(Station stations[]);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* STATION_H */

