#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "include/usrSettings_str.h"
#include "include/UserGuide.h"
#include "include/onlyDuty.h"
#include "include/onlyAssist.h"
#include "include/defaultSettings.h"


#define MAX_DUTY_CENTERS 12
#define MAX_MOUNTH 31

int main()
{
    struct Center_str List_of_Duty[MAX_DUTY_CENTERS];
    struct MenDates Duty_date[MAX_MOUNTH], Duty_date_assist[MAX_MOUNTH];
    
    defaultSettings(&usrSet);

    UserGuide(&usrSet);

    

    
    if (usrSet.debug_info == 1)
    {   printf("Settings:\n\n");
        printf("onlyDuty = %hu\n", usrSet.onlyDuty);
        printf("onlyAssist = %hu\n", usrSet.onlyAssist);
        printf("Concsidience = %hu\n", usrSet.coincidences);
        printf("Debug_info = %hu\n", usrSet.debug_info);
        printf("\n\n");
    }
    
  

    //usrSettingsOut(&usrSet);

    FILE* Centers = fopen("Center_list.txt", "r");
    FILE* Calendar = fopen("Calendar.txt", "r");
    FILE* Duty_list = fopen("Duty_list.txt", "w");

    int tmp_cntr = 0;
    int tmp_date = 0;
    int tmp_assist_date = 0;


    while(!feof(Centers)){
        fscanf(Centers, "%s%hu%hu%f%f%hu%hu%hu%hu",
            List_of_Duty[tmp_cntr].center_name,
            &(List_of_Duty[tmp_cntr].number_of_duties),
            &(List_of_Duty[tmp_cntr].number_of_assist),
            &(List_of_Duty[tmp_cntr].last_delta_mens),
            &(List_of_Duty[tmp_cntr].last_delta_assist),
            &(List_of_Duty[tmp_cntr].actual_duty_mens),
            &(List_of_Duty[tmp_cntr].actual_duty_assist),
            &(List_of_Duty[tmp_cntr].busy_man),
            &(List_of_Duty[tmp_cntr].busy_assist));
            tmp_cntr++;
    }

    while(!feof(Calendar)){
        fscanf(Calendar, "%hu%hu",
            &(Duty_date[tmp_date].date),
            &(Duty_date[tmp_date].weekend));
            tmp_date++;

    }
    fseek(Calendar, SEEK_SET, 0);
    while(!feof(Calendar)){
        fscanf(Calendar, "%hu%hu",
            &(Duty_date_assist[tmp_assist_date].date),
            &(Duty_date_assist[tmp_assist_date].weekend));
            tmp_assist_date++;
    }
    
////-----------------------CHECK CENTER READ-------------------------
//----------------------------CHECK DATE READ------------------------
    if (usrSet.debug_info == 1){
        printf("tmp_center = %d\n", tmp_cntr);
        printf("tmp_men_date = %d\n", tmp_date);
        printf("tmp_assist_date = %d\n", tmp_assist_date);
    }



    if ((usrSet.onlyDuty == 1) && (usrSet.onlyAssist == 1)){
        onlyDuty(List_of_Duty, Duty_date, tmp_cntr, tmp_date, usrSet);
        onlyAssist(List_of_Duty, Duty_date, Duty_date_assist, tmp_cntr, tmp_assist_date, usrSet);
    }else

        if ((usrSet.onlyDuty == 1) && (usrSet.onlyAssist == 0)){
            onlyDuty(List_of_Duty, Duty_date, tmp_cntr, tmp_date, usrSet);

        }else

            if ((usrSet.onlyDuty == 0) && (usrSet.onlyAssist == 1))
            {
                onlyAssist(List_of_Duty, Duty_date, Duty_date_assist, tmp_cntr, tmp_assist_date, usrSet);
            }
            
        else
        {
            printf("Nobody item set\n");
        }
        
        
        
    

}