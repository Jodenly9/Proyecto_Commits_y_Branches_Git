#include <chrono>
#include <iostream>
#include <string>
#include <ctime>
#include "DateTime.h"

using std::to_string;
using std::string;
using UDateTime::DateTime;

struct UDateTime::DateTime{
	unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    int minutes;
    int seconds;
};
// Postcondicion: Devuelve una instancia v�lida de DateTime que representa la fecha y hora actual del sistema operativo.
UDateTime::DateTime* UDateTime::Now(){
    time_t now = time(0);
    tm* ltm = localtime(&now);

    DateTime* dateTime = new DateTime;

    dateTime->year = 1900 + ltm->tm_year;
    dateTime->month = 1 + ltm->tm_mon;
    dateTime->day = ltm->tm_mday;
    dateTime->hour = ltm->tm_hour;
    dateTime->minutes = ltm->tm_min;
    dateTime->seconds = ltm->tm_sec;

    return dateTime;
}
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool IsValidDateHour(int day, int month, int year, int hours, int minutes, int seconds) {

    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    bool isLeap = isLeapYear(year);
    int monthDays[] = {31, 28 + isLeap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDays = monthDays[month - 1];

    if(day > maxDays){
        return false;
    }
    if (hours > 23 || minutes > 59 || seconds > 59 || minutes < 0 || seconds < 0||hours < 0) {
        return false;
    }
    return true;
}

// Postcondicion: Devuelve una instancia valida de DateTime para la fecha y hora especificada. Si @month, @day, @hour, @minute y @seconds, no se corresponden a una fecha y hora posible devuleve NULL
UDateTime::DateTime* CreateDateTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, int minutes, int seconds){
    if (!IsValidDateHour(day, month, year, hour, minutes, seconds)) {
        return NULL;
    }
	DateTime* dateTime = new DateTime;
        
    dateTime->year = year;
    dateTime->month = month;
    dateTime->day = day;
    dateTime->hour = hour;
    dateTime->minutes = minutes;
    dateTime->seconds = seconds;

    return dateTime;
}
	// Postcondicion: Devuelve el a�o de @dateTime.
unsigned int UDateTime::GetYear(const DateTime* dateTime){
	return dateTime->year;
}
// Postcondicion: Devuelve el mes de @dateTime, siendo un valor de 1 - 12 donde 1 es Enero y 12 es Diciembre
unsigned int UDateTime::GetMonth(const DateTime* dateTime){
	return dateTime->month;
}
	// Postcondicion: Devuelve el dia de @dateTime.
unsigned int UDateTime::GetDay(const DateTime* dateTime){
	return dateTime->day;
}
	// Postcondicion: Devuelve la hora de @dateTime, siendo un valor entre 0 - 23
unsigned int UDateTime::GetHour(const DateTime* dateTime){
	return dateTime->hour;
}
	// Postcondicion: Devuelve los minutos de @dateTime, siendo un valor de 0 - 59
unsigned int UDateTime::GetMinutes(const DateTime* dateTime){
	return dateTime->minutes;
}
	// Postcondicion: Devuelve los segundos de @dateTime.
unsigned int UDateTime::GetSeconds(const DateTime* dateTime){
	return dateTime->seconds;
}
// Postcondicion: Devuelve @dateTime en el formato especificado por @format.
	// Valores esperados por cada formato.
	// Para la fecha y hora 27/4/2019 19:01:10
	// - YYYYMMDD_HHmmss: 2019-04-27 19:01:10
	// - YYYYMMDD_hhmmss: 2019-04-27 07:01:10 p.m.
	// - DDMMYYYY_hhmmss: 27-04-2019 07:01:10 p.m.
	// - DDMMYYYY_HHmmss: 27-04-2019 19:01:10
	// - YYYYMMDDHHmmss: 20190427191410
	// - YYMD_Hms: 19-4-27 19:1:10
	// - YYMD_hms: 19-4-27 7:1:10 p.m.
	// - DMYY_hms: 27-4-19 7:1:10 p.m.
	// - DMYY_Hms: 27-4-19 19:1:10
string UDateTime::ToFormat(const DateTime* dateTime, DateTimeFormat format){
	string formatted_time;
        switch (format) {
            case YYYYMMDD_HHmmss:
                formatted_time = to_string(dateTime->year) + "-" +
                                string(dateTime->month < 10 ? "0" : "") + to_string(dateTime->month) + "-" +
                                string(dateTime->day < 10 ? "0" : "") + to_string(dateTime->day) + " " +
                                string(dateTime->hour < 10 ? "0" : "") + to_string(dateTime->hour) + ":" +
                                string(dateTime->minutes < 10 ? "0" : "") + to_string(dateTime->minutes) + ":" +
                                string(dateTime->seconds < 10 ? "0" : "") + to_string(dateTime->seconds);
                break;
            case YYYYMMDD_hhmmss:
                formatted_time = to_string(dateTime->year) + "-" +
                                string(dateTime->month < 10 ? "0" : "") + to_string(dateTime->month) + "-" +
                                string(dateTime->day < 10 ? "0" : "") + to_string(dateTime->day) + " " +
                                string((dateTime->hour % 12) < 10 ? "0" : "") + to_string(dateTime->hour % 12) + ":" +
                                string(dateTime->minutes < 10 ? "0" : "") + to_string(dateTime->minutes) + ":" +
                                string(dateTime->seconds < 10 ? "0" : "") + to_string(dateTime->seconds) + 
                                (dateTime->hour < 12 ? " a.m." : " p.m.");
                break;
            case DDMMYYYY_hhmmss:
                formatted_time = string(dateTime->day < 10 ? "0" : "") + to_string(dateTime->day) + " " +
                                string(dateTime->month < 10 ? "0" : "") + to_string(dateTime->month) + "-" +
								to_string(dateTime->year) + "-" +
                                string((dateTime->hour % 12) < 10 ? "0" : "") + to_string(dateTime->hour % 12) + ":" +
                                string(dateTime->minutes < 10 ? "0" : "") + to_string(dateTime->minutes) + ":" +
                                string(dateTime->seconds < 10 ? "0" : "") + to_string(dateTime->seconds) + 
                                (dateTime->hour < 12 ? " a.m." : " p.m.");
                break;
            case DDMMYYYY_HHmmss:
                formatted_time = string(dateTime->day < 10 ? "0" : "") + to_string(dateTime->day) + " " +
                                string(dateTime->month < 10 ? "0" : "") + to_string(dateTime->month) + "-" +
								to_string(dateTime->year) + "-" +
                                string(dateTime->hour < 10 ? "0" : "") + to_string(dateTime->hour) + ":" +
                                string(dateTime->minutes < 10 ? "0" : "") + to_string(dateTime->minutes) + ":" +
                                string(dateTime->seconds < 10 ? "0" : "") + to_string(dateTime->seconds);
			case YYYYMMDDHHmmss:
                formatted_time = to_string(dateTime->year) +
                                string(dateTime->month < 10 ? "0" : "") + to_string(dateTime->month)+
                                string(dateTime->day < 10 ? "0" : "") + to_string(dateTime->day)+
                                string(dateTime->hour < 10 ? "0" : "") + to_string(dateTime->hour)+
                                string(dateTime->minutes < 10 ? "0" : "") + to_string(dateTime->minutes)+
                                std::string(dateTime->seconds < 10 ? "0" : "") + to_string(dateTime->seconds);
                break;
            case YYMD_Hms:
                formatted_time = to_string(dateTime->year % 100) + "-" +
                                to_string(dateTime->month) + "-" +
                                to_string(dateTime->day) + " " +
                                to_string(dateTime->hour) + ":" +
                                to_string(dateTime->minutes) + ":" +
                                to_string(dateTime->seconds);
                break;
            case YYMD_hms:
                formatted_time = to_string(dateTime->year % 100) + "-" +
                                to_string(dateTime->month) + "-" +
                                to_string(dateTime->day) + " " +
                                to_string(dateTime->hour % 12) + ":" +
                                to_string(dateTime->minutes) + ":" +
                                to_string(dateTime->seconds) +
                                (dateTime->hour < 12 ? " a.m." : " p.m.");
                break;
            case DMYY_hms:
                formatted_time = to_string(dateTime->day) + " " +
                                to_string(dateTime->month) + "-" +
                                to_string(dateTime->year % 100) + "-" +
                                to_string(dateTime->hour % 12) + ":" +
                                to_string(dateTime->minutes) + ":" +
                                to_string(dateTime->seconds) +
                                (dateTime->hour < 12 ? " a.m." : " p.m.");
                break;
            case DMYY_Hms:
                formatted_time = to_string(dateTime->day) + " " +
                                to_string(dateTime->month) + "-" +
                                to_string(dateTime->year % 100) + "-" +
                                to_string(dateTime->hour) + ":" +
                                to_string(dateTime->minutes) + ":" +
                                to_string(dateTime->seconds);
                break;
            default:
                return "";
        }
    return formatted_time;
}
    // Postcondicion: Devuelve el a�o de @dateTime.
void UDateTime::DestroyDateTime(DateTime* dateTime){
	delete dateTime;
}
