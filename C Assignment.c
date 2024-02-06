/*main menu code*/

#include "main.h"

void mainmenu() {
    printf("\t\t\t\tWELCOME TO APU PROGRAMMING CAFE MANAGEMENT SYSTEM\n");
    printf("\n\nChoose User Type (1/2/3)\n\n1. ADMIN\n2. TUTOR\n3. STUDENT\n0. Terminate Program\n");

    int menuc1;
    printf("\n\nEnter Your Choice : ");
    scanf("%d", &menuc1);

    if (menuc1 == 1) {
        printf("\n\t\tYou've Chosen The Admin User Type\n");
        adminlogin();
    }
    else if (menuc1 == 2) {
        printf("\n\t\tYou've Chosen The Tutor User Type\n");
        tutorlogin();
    }
    else if (menuc1 == 3) {
        printf("\n\t\tYou've Chosen The Student User Type\n");
        studentlogin();
    }
    else if (menuc1 == 0) {
        printf("Program Terminated. Good Bye!\n");
    }
    else {
        printf("\n\t\tWrong Input\n");
        mainmenu();
    }
}

int main() {
    mainmenu();
    return 0;
}






/*Admin login code*/

void adminlogin() {
    printf("\n\n\t\tLOGIN TO USE ADMIN SYSTEMS\n");

    int adminpass;
    printf("\n\nPlease Enter The Admin System Password : ");
    scanf("%d", &adminpass);

    if (adminpass == 444602) {
        printf("\n\t\tLogin Successful\n");
        adminmenu();
    } else {
        printf("Wrong Password!\n");
        adminlogin();
    }
}

void adminmenu() {
    printf("\n\n\t\tWELCOME TO APU PROGRAMMING CAFE MANAGEMENT ADMIN SYSTEMS");
    printf("\n\n\t\tHere Are The Functionalities!");
    printf("\n\n1. Add Records of \n\n\t11. Tutor\n\t12. Student\n\t13. Programming Cafe Session\n\n2. Display All Records of\n\n\t21. Tutor\n\t22. Programming Cafe Session\n\t23. Registered Students"
           "\n\n3. Search Specific Records of\n\n\t31. Tutor by Tutor ID\n\t32. Programming Cafe Session by Session ID\n\t33. Student by Student ID"
           "\n\n4. Modify Record of\n\n\t41. Tutor\n\t42. Student\n\t43. Programming Cafe Session\n\n5. Enroll\n\n\t51. Student in a Session\n\n0. Exit");

    int adminc1;
    printf("\nEnter Your Choice: ");
    scanf("%d", &adminc1);

    switch (adminc1) {
        case 11:
            addtutor();
            break;
        case 12:
            addstudent();
            break;
        case 13:
            addprgcafses();
            break;
        case 21:
            distutor();
            break;
        case 22:
            disprgcafses();
            break;
        case 23:
            disregstud();
            break;
        case 31:
            distutorid();
            break;
        case 32:
            dissessionid();
            break;
        case 33:
            disstudid();
            break;
        case 41:
            modtutor();
            break;
        case 42:
            modstudent();
            break;
        case 43:
            modprgcafses();
            break;
        case 51:
            addstudses();
            break;
        case 0:
            mainmenu();
            break;
        default:
            printf("Invalid choice\n");
            adminmenu();
    }
}






//Tutor Addition Code (ADMIN 11)


void addtutor() {
    printf("\n\n\t\tTutor Records\n");

    FILE *tutorrec;
    tutorrec = fopen("Tutor Records.txt", "a");

    printf("\n\n\t\tEnter Tutor Details\n");
    char Tutorid[50], Pass[50], Name[50], DOB[50], Prgses[50], Prgsescode[50];

    printf("Tutor ID: ");
    scanf("%s",Tutorid);

    printf("Password: ");
    scanf("%s",Pass);

    printf("Name: ");
    scanf("%s",Name);

    printf("Date of Birth: ");
    scanf("%s",DOB);

    printf("Programming Session: ");
    scanf("%s",Prgses);

    printf("Programming Session Code: ");
    scanf("%s",Prgsescode);

    fprintf(tutorrec, "\n%s\t\t%s\t%s\t%s\t%s\t\t%s", Tutorid, Pass, Name, DOB, Prgses, Prgsescode);
    fclose(tutorrec);

    int X;
    printf("Do You Want To Continue? [0 / 1]: ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        addtutor();
    } else {
        printf("Wrong Input\n");
        mainmenu();
    }
}






//Add Student Code (ADMIN 12)


void addstudent() {
    printf("\n\n\t\tStudent Records\n");

    FILE *studentrec;
    studentrec = fopen("Student Records.txt", "a");

    if (studentrec == NULL) {
        printf("Failed to open Sport Records.txt\n");
        return;
    }

    printf("\n\n\t\tEnter Student Details\n");
    char Name[50];
    char DOB[50];
    char Tpnumber[50];
    char Pass[50];

    printf("Enter Student Name: ");
    scanf("%s", Name);

    printf("Enter Date of Birth: ");
    scanf("%s", DOB);

    printf("Enter TP Number: ");
    scanf("%s", Tpnumber);

    printf("Enter Password: ");
    scanf("%s",Pass);

    fprintf(studentrec, "\n%s\t\t%s\t%s\t%s", Name, DOB, Tpnumber, Pass);
    fclose(studentrec);

    int X;
    printf("Do You Want To Continue? [0 / 1]: ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        addstudent();
    } else {
        printf("Wrong Input\n");
        mainmenu();
    }
}






//Programming Session Addition Code (ADMIN 13)

void addprgcafses() {
    printf("\n\n\t\tProgramming Cafe Session Record\n");

    FILE *prgsesrec;
    prgsesrec = fopen("Programming Cafe Session.txt", "a");

    if (prgsesrec == NULL) {
        printf("Failed to open Sport Schedule.txt\n");
        return;
    }

    printf("\n\n\t\tEnter Programming Cafe Details\n");
    char prgsescode[50], Name[50], Wkday[50], Time[50], Location[50], Tutor_ID[50];

    printf("Enter Programming Session Code: ");
    scanf("%s", prgsescode);

    printf("Enter Programming Session Name: ");
    scanf("%s", Name);

    printf("Enter Day of The Week: ");
    scanf("%s", Wkday);

    printf("Enter Time of The Day [HH:MM AM/PM]: ");
    scanf("%s", Time);

    printf("Enter Session Location: ");
    scanf("%s", Location);

    printf("Enter Tutor ID for this Session: ");
    scanf("%s", Tutor_ID);

    fprintf(prgsesrec, "\n%s\t\t%s\t\t%s\t%s\t%s\t\t%s", prgsescode, Name, Wkday, Time, Location, Tutor_ID);
    fclose(prgsesrec);

    int X;
    printf("Do You Want To Continue? [0 / 1]: ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        addprgcafses();
    } else {
        printf("Wrong Input\n");
        mainmenu();
    }
}






//Display Tutor Records code (ADMIN 21)

void distutor() {
    printf("\n\nHere is the Tutor Records\n\n");
    printf("\n\nTutor_ID\tPassword\tName\tDate_of_Birth\tProgramming_Session\tSession_Code\n\n");

    FILE *tutorrec;
    tutorrec = fopen("Tutor Records.txt", "rt");

    if (tutorrec == NULL) {
        printf("Failed to open Tutor Records.txt\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), tutorrec) != NULL) {
        printf("%s", line);
    }

    fclose(tutorrec);

    int X;
    printf("\n\nGo Back To Admin? [0 / 1]: ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        printf("Good Bye!\n");
    } else {
        printf("Wrong Input\n");
        mainmenu();
    }
}






//display Programming Cafe Session Record Code (ADMIN 22)

void disprgcafses() {
    printf("\n\nHere is the Programming Cafe Session Records\n\n");
    printf("\n\nSession_code\tSession_name\t\t\tWKday\t\tTime\t\tLocation\tTutor_ID\n\n");

    FILE *prgsesrec;
    prgsesrec = fopen("Programming Cafe Session.txt", "rt");

    if (prgsesrec == NULL){
        printf("Failed to open Programming Cafe Session.txt\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line),prgsesrec) != NULL){
        printf("%s", line);
    }

    fclose(prgsesrec);

    int X;
    printf("\nGo Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        printf("Good Bye!\n");
    }
}






//Display Student Record Code (ADMIN 23)

void disregstud() {
    FILE *studentrec = fopen("Student Records.txt", "rt");
    if (studentrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char c;
    printf("\n\nHere is the Student Records\n\n");
    printf("\n\nName\t\t\tDate_of_Birth\tTP_Number\tPass\n\n");
    while ((c = fgetc(studentrec)) != EOF) {
        printf("%c", c);
    }

    fclose(studentrec);

    int X;
    printf("\n\nGo Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        printf("Good Bye!\n");
    }
}






//Search Specific Record code
//Tutor by Tutor ID (ADMIN 31)

void distutorid() {
    FILE *tutorrec = fopen("Tutor Records.txt", "rt");
    if (tutorrec == NULL) {
        printf("Error opening file.\n");
        return;
    }


    char sid[5];
    char str[120];
    int flag = 0;
    char pos;
    printf("\nEnter Tutor ID To Search : ");
    scanf("%s",sid);

    while ((fgets(str, 120, tutorrec)) != NULL){
        pos = strstr(str, sid);                                   /// Finding The First Occurance Of Given Code

        if (pos != NULL){
            printf("\n\nTutor_ID\tPassword\tName\tDate_of_Birth\tProgramming_Session\tSession_code\n\n");
            printf("%s", str);
            flag = flag + 1 ;
            break;
        }
    }

    if (flag == 0)
    {
        printf("\nNo Entry Found For Tutor ID : '%s' !!!", sid);
    }

    fclose(tutorrec);

    int X;
    printf("\n\nGo Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        printf("Good Bye!\n");
    }
}






//Session by Session Code (ADMIN 32)

void dissessionid() {
    FILE *prgsesrec = fopen("Programming Cafe Session.txt", "rt");
    if (prgsesrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char spid[50];
    char str[120];
    int flag = 0;
    char pos;
    printf("\nEnter Session Code to Search: ");
    scanf("%s",spid);

    while ((fgets(str, 120, prgsesrec)) !=NULL){
        pos = strstr(str, spid);

        if (pos != NULL){
            printf("\n\nSession_code\tSession_name\t\t\tWKday\t\tTime\t\tLocation\tTutor_ID\n\n");
            printf("%s", str);
            flag = flag + 1;
            break;
        }
    }

    if (flag == 0){
        printf("\nNo Entry Found For Session Code : '%s' !!!", spid);
    }

    int X;
    printf("\nGo Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        printf("Good Bye!\n");
    }
}






//Student by Student ID (ADMIN 33)

void disstudid() {
    FILE *studentrec = fopen("Student Records.txt", "rt");
    if (studentrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char stid[50];
    char str[120];
    int flag = 0;
    char pos;
    printf("\nEnter TP Number to Search : ");
    scanf("%s", stid);

    while ((fgets(str, 120, studentrec)) !=NULL){
        pos = strstr(str, stid);

        if (pos != NULL){
            printf("\n\nName\t\t\tDate_of_Birth\tTP_Number\tPass\n\n");
            printf("%s",str);
            flag = flag + 1;
            break;
        }
    }

    if (flag == 0){
        printf("\nNo Entry Found For TP Number : '%s' !!!", stid);
    }

    int X;
    printf("\nGo Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        printf("Good Bye!\n");
    }
}






//Modify Tutor Record Code (ADMIN 41)

void modtutor() {
    printf("\nTutor_ID\tPassword\tName\tDate_of_Birth\tProgramming_Session\tSession_code\n");

    FILE *tutorrec = fopen("Tutor Records.txt", "rt");
    if (tutorrec == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("\n");
    char line[100];
    while (fgets(line, sizeof(line), tutorrec) != NULL) {
        printf("%s", line);
    }
    fclose(tutorrec);

    char O[50];
    char Y[50];

    printf("\n\n\tEnter The Word : ");
    scanf("%s",O);
    O[strcspn(O, "\n")] = '\0';

    printf("\tReplacement : ");
    scanf("%s",Y);
    Y[strcspn(Y, "\n")] = '\0';

    FILE *temp = fopen("out.txt", "wt");
    tutorrec = fopen("Tutor Records.txt", "rt");
    if (temp == NULL || tutorrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, sizeof(line), tutorrec) != NULL) {
        fprintf(temp, "%s", line);
    }
    fclose(tutorrec);
    fclose(temp);

    temp = fopen("out.txt", "rt");
    tutorrec = fopen("Tutor Records.txt", "wt");
    if (temp == NULL || tutorrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, sizeof(line), temp) != NULL) {
        char *pos;
        while ((pos = strstr(line, O)) != NULL) {
            int index = pos - line;
            strncpy(pos, Y, strlen(Y));
            strncpy(pos + strlen(Y), line + index + strlen(O), strlen(line) - index - strlen(O));
            line[strlen(line) - strlen(O) + strlen(Y)] = '\0';
        }
        fprintf(tutorrec, "%s", line);
    }

    fclose(temp);
    fclose(tutorrec);

    int X;
    printf("Go Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        printf("Good Bye!\n");
    }
}






//Modify Student Record Code (ADMIN 42)

void modstudent() {
    printf("\nName\t\t\tDate_of_Birth\tTP_Number\tPass\n");

    FILE *studentrec = fopen("Student Records.txt", "rt");
    if (studentrec == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("\n");
    char line[100];
    while (fgets(line, sizeof(line), studentrec) != NULL) {
        printf("%s", line);
    }
    fclose(studentrec);

    char O[50];
    char Y[50];

    printf("\n\n\tChoose The Entry : ");
    scanf("%s", O);
    O[strcspn(O, "\n")] = '\0';

    printf("\tReplacement : ");
    scanf("%s", Y);
    Y[strcspn(Y, "\n")] = '\0';

    FILE *temp = fopen("out.txt", "wt");
    studentrec = fopen("Student Records.txt", "rt");
    if (temp == NULL || studentrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, sizeof(line), studentrec) != NULL) {
        fprintf(temp, "%s", line);
    }
    fclose(studentrec);
    fclose(temp);

    temp = fopen("out.txt", "rt");
    studentrec = fopen("Student Records.txt", "wt");
    if (temp == NULL || studentrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, sizeof(line), temp) != NULL) {
        char *pos;
        while ((pos = strstr(line, O)) != NULL) {
            int index = pos - line;
            strncpy(pos, Y, strlen(Y));
            strncpy(pos + strlen(Y), line + index + strlen(O), strlen(line) - index - strlen(O));
            line[strlen(line) - strlen(O) + strlen(Y)] = '\0';
        }
        fprintf(studentrec, "%s", line);
    }

    fclose(temp);
    fclose(studentrec);

    int X;
    printf("Go Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        printf("Good Bye!\n");
    }
}






//Modify Programming Cafe Session Record Code (ADMIN 43)

void modprgcafses() {
    printf("\n\nSession_code\tSession_name\t\t\tWKday\t\tTime\t\tLocation\tTutor_ID\n\n");
    FILE *prgsesrec = fopen("Programming Cafe Session.txt", "rt");
    if (prgsesrec == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("\n");
    char line[100];
    while (fgets(line, sizeof(line), prgsesrec) != NULL) {
        printf("%s", line);
    }
    fclose(prgsesrec);

    char O[50];
    char Y[50];

    printf("\n\n\tChoose The Entry : ");
    scanf("%s", O);
    O[strcspn(O, "\n")] = '\0';

    printf("\tReplacement : ");
    scanf("%s", Y);
    Y[strcspn(Y, "\n")] = '\0';

    FILE *temp = fopen("out.txt", "wt");
    prgsesrec = fopen("Programming Cafe Session.txt", "rt");
    if (temp == NULL || prgsesrec== NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, sizeof(line), prgsesrec) != NULL) {
        fprintf(temp, "%s", line);
    }
    fclose(prgsesrec);
    fclose(temp);

    temp = fopen("out.txt", "rt");
    prgsesrec = fopen("Programming Cafe Session.txt", "wt");
    if (temp == NULL || prgsesrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, sizeof(line), temp) != NULL) {
        char *pos;
        while ((pos = strstr(line, O)) != NULL) {
            int index = pos - line;
            strncpy(pos, Y, strlen(Y));
            strncpy(pos + strlen(Y), line + index + strlen(O), strlen(line) - index - strlen(O));
            line[strlen(line) - strlen(O) + strlen(Y)] = '\0';
        }
        fprintf(prgsesrec, "%s", line);
    }

    fclose(temp);
    fclose(prgsesrec);

    int X;
    printf("Go Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        printf("Good Bye!\n");
    }
}






//Enroll Student in a Session (Admin 51)


void addstudses() {
    printf("\n\n\t\tParticipating Student in a Session Records\n");

    FILE *studsesrec;
    studsesrec = fopen("Enroll Student Session Records.txt", "a");

    if (studsesrec == NULL) {
        printf("Failed to open Sport Records.txt\n");
        return;
    }

    printf("\n\n\t\tEnter Student & Session Details\n");
    char Name[50];
    char TP_Number[50];
    char Prgsescode[50];
    char Tutor_ID[50];
    char Location[50];

    printf("Enter Student Name: ");
    scanf("%s", Name);

    printf("Enter TP Number: ");
    scanf("%s", TP_Number);

    printf("Enter Programming Session Code: ");
    scanf("%s", Prgsescode);

    printf("Enter Tutor ID for this Session: ");
    scanf("%s", Tutor_ID);

    printf("Enter Location: ");
    scanf("%s",Location);

    fprintf(studsesrec, "\n%s\t\t%s\t%s\t\t%s\t\t%s", Name, TP_Number, Prgsescode, Tutor_ID, Location);
    fclose(studsesrec);

    int X;
    printf("Do You Want To Continue? [0 / 1]: ");
    scanf("%d", &X);

    if (X == 0) {
        adminmenu();
    } else if (X == 1) {
        addstudent();
    } else {
        printf("Wrong Input\n");
        mainmenu();
    }
}







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Tutor Menu login Code

void tutorlogin() {
    FILE* tutorrec;
    char pass[50];
    char Tutorid[50];
    char str[50];
    char* pos;
    char* pos1;
    int count = 0;
    int count1 = 0;
    int flag = 0;
    int flag1 = 0;

    printf("Tutor Login Section");

    tutorrec = fopen("Tutor Records.txt", "r");

    if (tutorrec == NULL)
    {
        printf("\n\n\t\t\t\t\t\t\t\tCannot Open File!!!\n");
    }

    else{
        printf("\n\nTutor ID : ");
        scanf("%s",Tutorid);
        printf("\n\nPassword : ");
        scanf("%s",pass);

        while (fgets(str, 120, tutorrec) != NULL){
            pos = strstr(str, Tutorid);

            if (pos != NULL){

                if (count == 0)
                {
                    while (fgets(str, 120, tutorrec) != NULL){
                        pos1 = strstr(str, pass);
                    }

                    if (count1 == 0){
                        printf("\n\nLogin Successful!!");
                        fclose(tutorrec);
                        tutormenu();
                    }

                    flag1 = 1;
                    count1++;
                }

                flag = 1;
                count++;
            }
        }
    }
}

void tutormenu(){

    int tutoroption;

    printf("Welcome to Tutor Menu!");

    printf("\nChoose an option! \n\n1. Search & Display \n\n\t11. Sessions Timing by Tutor ID\n\t12. Participating Student Details by Tutor ID\n0. Exit");

    int tutorc1;
    printf("\nEnter Your Choice: ");
    scanf("%d", &tutorc1);

    switch (tutorc1){
        case 11:
            distutorses();
            break;
        case 12:
            disstudlist();
            break;
        case 0:
            mainmenu();
            break;
        default:
            printf("Invalid Choice\n");
            studentmenu();
    }

}


//Search & Display Session Timing By Tutor ID (TUTOR 11)

void distutorses() {
    FILE *prgsesrec = fopen("Programming Cafe Session.txt", "rt");
    if (prgsesrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char sid[50];
    char str[120];
    int flag = 0;
    char pos;
    printf("\nEnter Tutor ID to Search : ");
    scanf("%s", sid);

    while ((fgets(str, 120, prgsesrec)) !=NULL){
        pos = strstr(str, sid);

        if (pos != NULL){
            printf("\n\nSession_code\tSession_name\t\t\tWKday\t\tTime\t\tLocation\tTutor_ID\n\n");
            printf("%s",str);
            flag = flag + 1;
            break;
        }
    }

    if (flag == 0){
        printf("\nNo Entry Found For Tutor_ID : '%s' !!!", sid);
    }

    int X;
    printf("\n\nGo Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        tutormenu();
    } else if (X == 0) {
        printf("Good Bye!\n");
    }
}





//Search & Display Participating Student List by Tutor ID (TUTOR 12)

void disstudlist() {
    FILE *studsesrec = fopen("Enroll Student Session Records.txt", "rt");
    if (studsesrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char sid[50];
    char str[120];
    int flag = 0;
    char pos;
    printf("\nEnter Tutor ID to Search : ");
    scanf("%s", sid);
    printf("\n\nStudent_Name\t\tTP_Number\tSession_Code\tTutor_ID\tLocation\n\n");

    while ((fgets(str, 120, studsesrec)) !=NULL){
        pos = strstr(str, sid);

        if (pos != NULL){
            printf("%s",str);
            flag = flag + 1;
        }
    }

    if (flag == 0){
        printf("\nNo Entry Found For Tutor_ID : '%s' !!!", sid);
    }

    int X;
    printf("\nGo Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        tutormenu();
    } else if (X == 0) {
        printf("Good Bye!\n");
    }
}









/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Student Menu login code

void studentlogin(){
    FILE* studentrec;
    char pass[50];
    char Tpnumber[10];
    char str[50];
    char* pos;
    char* pos1;
    int count = 0;
    int count1 = 0;
    int flag = 0;
    int flag1 = 0;

    printf("Student Login Section");

    studentrec = fopen("Student Records.txt", "r");

    if (studentrec == NULL)
    {
        printf("\n\n\t\t\t\t\t\t\t\tCannot Open File!!!\n");
    }

    else{
        printf("\n\nTP Number : ");
        scanf("%s",Tpnumber);
        printf("\n\nPassword : ");
        scanf("%s",pass);

        while (fgets(str, 120, studentrec) != NULL){
            pos = strstr(str, Tpnumber);

            if (pos != NULL){

                if (count == 0)
                {
                    while (fgets(str, 120, studentrec) != NULL){
                        pos1 = strstr(str, pass);
                    }

                    if (count1 == 0){
                        int match = strcmp(str, str);

                        if (match == 0){
                            printf("\n\nLogin Successful!!");
                            fclose(studentrec);
                            studentmenu();
                        }
                    }

                    flag1 = 1;
                    count1++;
                }

                flag = 1;
                count++;
            }
        }
    }
}

void studentmenu(){

    int studentoption;

    printf("Welcome to Student Menu!");

    printf("\nChoose an option! \n\n1. Search & Display \n\n\t11. Session Timing by TP Number\n0. Exit");

    int studentc1;
    printf("\nEnter Your Choice: ");
    scanf("%d", &studentc1);

    switch (studentc1){
        case 11:
            disstudses();
            break;
        case 0:
            mainmenu();
            break;
        default:
            printf("Invalid Choice\n");
            studentmenu();
    }
}

//Display Student Session code (STUDENT 11)

void disstudses() {
    FILE *studsesrec = fopen("Enroll Student Session Records.txt", "rt");
    if (studsesrec == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char stid[50];
    char str[120];
    int flag = 0;
    char pos;
    printf("\nEnter TP Number to Search : ");
    scanf("%s", stid);

    while ((fgets(str, 120, studsesrec)) !=NULL){
        pos = strstr(str, stid);

        if (pos != NULL){
            printf("\n\nStudent_Name\t\tTP_Number\tSession_Code\tTutor_ID\tLocation\n\n");
            printf("%s",str);
            flag = flag + 1;
            break;
        }
    }

    if (flag == 0){
        printf("\nNo Entry Found For TP Number : '%s' !!!", stid);
    }

    int X;
    printf("\nGo Back To Admin? [0 / 1] : ");
    scanf("%d", &X);

    if (X == 0) {
        studentmenu();
    } else if (X == 0) {
        printf("Good Bye!\n");
    }
}
