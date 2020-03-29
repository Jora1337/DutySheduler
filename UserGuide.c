#include "UserGuide.h"


void UserGuide(struct usrSettings_str *usrSet){


    char help[6] = ".help";
    char settings[10] = ".settings";
    char quit[10] = ".quit";
    char usrEnter[10];
    printf("GVC Sheduler v0.1 (Alpha)\n");
    printf("Enter .settings to set the parameters or .help for open man-page\n");


    printf("> ");
    while(strcmp(quit, usrEnter, sizeof(quit)) != 0){
        scanf("%s", &usrEnter);
        if(strcmp(quit, usrEnter, sizeof(help)) == 0){
            return 0;
        } else
            if(strcmp(help, usrEnter, sizeof(help)) == 0){
                helpAbout();
                printf("> ");
            }
        else
            if(strcmp(settings, usrEnter, sizeof(settings)) == 0){
                usrSettings(usrSet);
                printf("> ");
            }
        else
            {
                printf("Command %s not found. Use .help for see all commands.\n", usrEnter);
                printf("> ");
            }
    }
}

void helpAbout(){
    printf("The scheduler is designed to facilitate the preparation of a duty schedule for the commanders \n"
        "of structural divisions. The program can create schedules for one month based on the number of people.\n"
        "You can set the next parameters:\n\n"
        "(1) \"Only duty men: TRUE/FALSE\" (Default - TRUE) - Generates a schedule only for those on duty.\n"
        "(2) \"Only assistent men: TRUE/FALSE\" (Default - FALSE) - Generates a schedule only for those on assistent.\n"
        "(3) \"Charts of both types: TRUE/FALSE\" (Default - FALSE) - Generates schedules for both types of shifts.\n"
        "(4) \"Avoid matches: TRUE/FALSE\" (Default - FALSE) - Dutyman's and assistenss will not take over on the same day.\n"
        "\n\n"
        "ATTENTION!:Parameter 3 has more advantages over parameters 1 and 2. Be careful. (For example: If you specify parameter\n"
        "1 as true, 2 as false, and 3 as true, parameter 2 will be ignored. The same applies to rule 3 in relation to rule 1)\n");

}

void usrSettings(struct usrSettings_str *usrSet){
    char consent;
    char confirm;
    unsigned short int answer;

    printf("Before changing the settings, read the command manual .help\n");
    printf("Are you sure? (Y/y(fon 'Yes') or N/n(for 'No' - setting by default))");
    while (consent != 'Y' || consent != 'y' || consent != 'N' || consent != 'y')
    {
        scanf("%c", &consent);
        if(consent == 'Y' || consent == 'y'){
            while (confirm != 'Y' || confirm != 'y')
            {
                /*заполнение структуры настроек пользователя*/
                printf("Shedule only duty men: TRUE/FALSE\" (Default - TRUE)   1 - TRUE, 2 - FALSE");
                while(answer != 1 || answer != 0){
                    scanf("%hu", &answer);
                    if(answer == 1){
                        usrSet.onlyDuty = 1;
                    }
                    if(answer == 0){
                        usrSet.onlyDuty = 0;
                    }
                    printf("Please, set '1' - for TRUE or '0' - for FALSE\n");
                    printf("> ");
                }
                printf("Shedule only assistents: TRUE/FALSE\" (Default - FALSE)   1 - TRUE, 2 - FALSE");
                while(answer != 1 || answer != 0){
                    scanf("%hu", &answer);
                    if(answer == 1){
                        usrSet.onlyAssist = 1;
                    }
                    if(answer == 0){
                        usrSet.onlyAssist = 0;
                    }
                    printf("Please, set '1' - for TRUE or '0' - for FALSE\n");
                    printf("> ");
                }
                while(answer != 1 || answer != 0){
                    scanf("%hu", &answer);
                    if(answer == 1){
                        usrSet.both = 1;
                    }
                    if(answer == 0){
                        usrSet.both = 0;
                    }
                    printf("Please, set '1' - for TRUE or '0' - for FALSE\n");
                    printf("> ");
                }
                while(answer != 1 || answer != 0){
                    scanf("%hu", &answer);
                    if(answer == 1){
                        usrSet.coincidences = 1;
                    }
                    if(answer == 0){
                        usrSetcoincidences = 0;
                    }
                    printf("Please, set '1' - for TRUE or '0' - for FALSE\n");
                    printf("> ");
                }
            }
        if(consent == 'N' || consent == 'n'){

        }
        }
    printf("Please, enter Y/y or N/n\n")
    printf("> ");
    }
}