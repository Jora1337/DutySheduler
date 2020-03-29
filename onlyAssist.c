#include <stdio.h>
#include <string.h>
#include "include/usrSettings_str.h"
#include "include/onlyDuty.h"
#include "include/onlyAssist.h"



void onlyAssist(struct Center_str *List_of_Duty,struct MenDates *Duty_date, struct MenDates *Duty_date_assist, int tmp_cntr, int tmp_assist_date, struct usrSettings_str usrSet){
//-----Initial weights 1 \ n are initialized, where n is the number of attendants-----------------
    if (usrSet.debug_info == 1)
    {
         for(int i = 0; i < tmp_cntr; i++){
             if (List_of_Duty[i].actual_duty_assist == 0)
             {
                List_of_Duty[i].actual_duty_assist = 1; 
             }
        List_of_Duty[i].last_delta_assist = List_of_Duty[i].actual_duty_assist / (float)List_of_Duty[i].number_of_assist;
        printf("Fist %hu center delta value = %.4f and factic (for assist ): %hu\n", i+1, List_of_Duty[i].last_delta_assist, (List_of_Duty[i].actual_duty_assist - 1));
    }
    }else
    {
        for(int i = 0; i < tmp_cntr; i++){
            if (List_of_Duty[i].actual_duty_assist == 0)
             {
                List_of_Duty[i].actual_duty_assist = 1; 
             }
            List_of_Duty[i].last_delta_assist = List_of_Duty[i].actual_duty_assist / (float)List_of_Duty[i].number_of_assist;
        }

    }
    
    
    if (usrSet.coincidences == 0)
    {
    float tmp_delta = List_of_Duty[0].last_delta_assist;
    int nowID;
    for(int i = 0; i < tmp_assist_date; i++){
            tmp_delta = List_of_Duty[0].last_delta_assist;
        for(int j = 0; j < tmp_cntr; j++){
            if((List_of_Duty[j].busy_assist == 1) || (strcmp(List_of_Duty[j].center_name, Duty_date[i].center_name) == 0) || (strcmp(List_of_Duty[j].center_name, Duty_date_assist[i-1].center_name) == 0)){
                continue;
            }
           // if(strcmp(List_of_Duty[i].center_name, Duty_date[j].center_name) == 0){
           //     continue;
           // } 
            else
            if(List_of_Duty[j].last_delta_assist <= tmp_delta){
                nowID = j;
                tmp_delta = List_of_Duty[j].last_delta_assist;
            }

        }
            memcpy(Duty_date_assist[i].center_name, List_of_Duty[nowID].center_name, sizeof(Duty_date_assist[i].center_name));
            List_of_Duty[nowID].actual_duty_assist++;
            List_of_Duty[nowID].last_delta_assist = (float)List_of_Duty[nowID].actual_duty_assist / (float)List_of_Duty[nowID].number_of_assist;
            List_of_Duty[nowID].busy_assist = 1;

            for(int k = 0; k < tmp_cntr; k++){
                if(k == nowID){
                    continue;
                } else {
                List_of_Duty[k].busy_assist = 0;}
            }
//            for(int s = 0; s < tmp_cntr; s++){
//        printf("%d center have delta = %f\n", s+1, List_of_Duty[s].last_delta_mens);
//            }
//            printf("\n");
    }
    }
    else
    {
        float tmp_delta = List_of_Duty[0].last_delta_assist;
    int nowID;
    for(int i = 0; i < tmp_assist_date; i++){
            tmp_delta = List_of_Duty[0].last_delta_assist;
        for(int j = 0; j < tmp_cntr; j++){
            if(List_of_Duty[j].busy_assist == 1){
                continue;
            }else
            if(List_of_Duty[j].last_delta_assist <= tmp_delta){
                nowID = j;
                tmp_delta = List_of_Duty[j].last_delta_assist;
            }

        }
        memcpy(Duty_date_assist[i].center_name, List_of_Duty[nowID].center_name, sizeof(Duty_date_assist[i].center_name));
            List_of_Duty[nowID].actual_duty_assist++;
            List_of_Duty[nowID].last_delta_assist = (float)List_of_Duty[nowID].actual_duty_assist / (float)List_of_Duty[nowID].number_of_assist;
            List_of_Duty[nowID].busy_assist = 1;

            for(int k = 0; k < tmp_cntr; k++){
                if(k == nowID){
                    continue;
                } else {
                List_of_Duty[k].busy_assist = 0;}
            }
//            for(int s = 0; s < tmp_cntr; s++){
//        printf("%d center have delta = %f\n", s+1, List_of_Duty[s].last_delta_mens);
//            }
//            printf("\n");
    }
    }





    if (usrSet.debug_info == 1)
    {
        for(int i = 0; i < tmp_cntr; i++){
            printf("Second %hu center delta value = %.4f and factic (for assist): %hu\n", i+1, List_of_Duty[i].last_delta_assist, (List_of_Duty[i].actual_duty_assist - 1));
        }
    }
    else
    {

    }
    

    printf("Assist men:\n");
    for(int i =  0; i < tmp_cntr; i++){
        printf("%-7s", List_of_Duty[i].center_name);
        for(int j = 0; j < tmp_assist_date; j++){
            if((strcmp(List_of_Duty[i].center_name, Duty_date_assist[j].center_name)) == 0){
                printf("%hu ", Duty_date_assist[j].date);
            }
        }
        printf("\n");
    }
    printf("\n");


        for(int i = 0; i < tmp_assist_date; i++){
        if(i == 0){
            printf("      ");
        }
        printf("|-%d-", i+1);
    }
    printf("\n");

    for(int i = 0; i < tmp_cntr; i++){
        printf("%-6s", List_of_Duty[i].center_name);
        for(int j = 0; j < tmp_assist_date; j++){
            if(j >= 9){
                if((strcmp(List_of_Duty[i].center_name, Duty_date_assist[j].center_name)) == 0){
                    printf("| *  ");
                }
                else{
                    printf("|    ");
                }
            }
            else{
                if((strcmp(List_of_Duty[i].center_name, Duty_date_assist[j].center_name)) == 0){
                    printf("| * ");
                }
                else{
                    printf("|   ");
                }
            }
        }
        printf("\n");
        printf("    ");
        for(int s = 0; s < tmp_assist_date; s++){
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