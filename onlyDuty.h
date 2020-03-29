#ifndef ONLYDUTY_H_INCLUDED
#define ONLYDUTY_H_INCLUDED

    struct Center_str {
        char center_name[10];
        unsigned short int number_of_duties;
        unsigned short int number_of_assist;
        float last_delta_mens;
        float last_delta_assist;
        unsigned short int actual_duty_mens;
        unsigned short int actual_duty_assist;
        unsigned short int busy_man;
        unsigned short int busy_assist;
    };

struct MenDates {
        unsigned short int date;
        char center_name[10];
        unsigned short int weekend;
    };

struct Center_str List_of_Duty;
struct MenDates Duty_date, Duty_date_assist;

void onlyDuty(struct Center_str *List_of_Duty, struct MenDates *Duty_date, int tmp_cntr, int tmp_date, struct usrSettings_str usrSet);

#endif