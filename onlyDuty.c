#include <stdio.h>
#include <string.h>
#include "include/usrSettings_str.h"
#include "include/onlyDuty.h"
#include "include/UserGuide.h"

//#include "include/onlyAssist.h"


void onlyDuty(struct Center_str *List_of_Duty, struct MenDates *Duty_date, int tmp_cntr, int tmp_date, struct usrSettings_str usrSet){

//---------CALENDAR GRID DISTRIBUTION----(FOR "MAX DAYS" LEIGHT)----------------------------------
//-----Initial weights 1 \ n are initialized, where n is the number of attendants-----------------
    if (usrSet.debug_info == 1)
    {
        for(int i = 0; i < tmp_cntr; i++){
            if (List_of_Duty[i].actual_duty_mens == 0)
            {
              List_of_Duty[i].actual_duty_mens = 1;  
            }
            
            List_of_Duty[i].last_delta_mens = List_of_Duty[i].actual_duty_mens / (float)List_of_Duty[i].number_of_duties;
            printf("Fist %hu center delta value = %.4f and factic: %hu\n", i+1, List_of_Duty[i].last_delta_mens, (List_of_Duty[i].actual_duty_mens - 1));
        }
    }else
    {
       for(int i = 0; i < tmp_cntr; i++){
            if (List_of_Duty[i].actual_duty_mens == 0)
            {
              List_of_Duty[i].actual_duty_mens = 1;  
            }
            
            List_of_Duty[i].last_delta_mens = List_of_Duty[i].actual_duty_mens / (float)List_of_Duty[i].number_of_duties;
       }
    }
    

    float tmp_delta = List_of_Duty[0].last_delta_mens;
    int nowID;
    for(int i = 0; i < tmp_date; i++){
            tmp_delta = List_of_Duty[0].last_delta_mens;
        for(int j = 0; j < tmp_cntr; j++){
            if(List_of_Duty[j].busy_man != 0){
                continue;
            } else
            if(List_of_Duty[j].last_delta_mens <= tmp_delta){
                nowID = j;
                tmp_delta = List_of_Duty[j].last_delta_mens;
            }

        }
        memcpy(Duty_date[i].center_name, List_of_Duty[nowID].center_name, sizeof(Duty_date[i].center_name));
            List_of_Duty[nowID].actual_duty_mens++;
            List_of_Duty[nowID].last_delta_mens = (float)List_of_Duty[nowID].actual_duty_mens / (float)List_of_Duty[nowID].number_of_duties;
            List_of_Duty[nowID].busy_man = 1;

            for(int k = 0; k < tmp_cntr; k++){
                if(k == nowID){
                    continue;
                } else {
                List_of_Duty[k].busy_man = 0;}
            }
//            for(int s = 0; s < tmp_cntr; s++){
//        printf("%d center have delta = %f\n", s+1, List_of_Duty[s].last_delta_mens);
//            }
//            printf("\n");
    }





    if (usrSet.debug_info == 1)
    {
        for(int i = 0; i < tmp_cntr; i++){
            printf("Second %hu center delta value = %.4f and factic: %hu\n", i+1, List_of_Duty[i].last_delta_mens, (List_of_Duty[i].actual_duty_mens - 1));
        }
    }

    printf("Duty men:\n");
    for(int i =  0; i < tmp_cntr; i++){
        printf("%-7s", List_of_Duty[i].center_name);
        for(int j = 0; j < tmp_date; j++){
            if((strcmp(List_of_Duty[i].center_name, Duty_date[j].center_name)) == 0){
                printf("%hu ", Duty_date[j].date);
            }
        }
        printf("\n");
    }
    printf("\n");


        for(int i = 0; i < tmp_date; i++){
        if(i == 0){
            printf("      ");
        }
        printf("|-%d-", i+1);
    }
    printf("\n");

    for(int i = 0; i < tmp_cntr; i++){
        printf("%-6s", List_of_Duty[i].center_name);
        for(int j = 0; j < tmp_date; j++){
            if(j >= 9){
                if((strcmp(List_of_Duty[i].center_name, Duty_date[j].center_name)) == 0){
                    printf("| *  ");
                }
                else{
                    printf("|    ");
                }
            }
            else{
                if((strcmp(List_of_Duty[i].center_name, Duty_date[j].center_name)) == 0){
                    printf("| * ");
                }
                else{
                    printf("|   ");
                }
            }
        }
        printf("\n");
        printf("    ");
        for(int s = 0; s < tmp_date; s++){
            if(s <= 9){
                printf("---");
            }
            else{
                printf("------");
            }
        }
        printf("\n");
    }

}
