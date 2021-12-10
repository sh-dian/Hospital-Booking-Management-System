#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//1st Function: Get input from user
void getPatient(char typ_Patient[], char gender[], char name[], char icNum[], char phoneNum[], char work_History[], int *age, int *citizenship, int *registrationFee);

//2nd Function : Department
float getdepartments(char Department[4][15], char date[4][50], char hourClock[4][4], float time[50][50], int *numTreat);

//3rd Function : Calculate discount
void getCalc(int citizenship, char Citizenship[], int age, float totalTreatment, char work_History[],  int registrationFee, float *TotalTreat, float *totalBill);

//4th Function : Calculate treatment
float getcalcTotalTreat(float totalTreatment, float Discount1, float Discount2);

//5th Function : Calculate Bill
float getcalctotalBill(int registrationFee, float TotalTreat);

//6th Function : Display Output
void getprint(char typ_Patient[], int numTreat, char name[], int age, char gender[], char icNum[], char phoneNum[], int citizenship, char Citizenship[], char work_History[], int registrationFee, float totalTreatment, char Department[4][15], char date[4][50], float time[50][50], char hourClock[4][4], float totalTreat, float totalBill);

int main()
{
    //declaration for function 1
    char typ_Patient[10], gender[10], name[50], icNum[15], phoneNum[15], work_History[5];
    int age, citizenship, registrationFee, i, j, numTreat;
    char Citizenship[15], date[4][50], hourClock[4][4], Department[4][15];
    float totalTreatment, time[50][50], TotalTreat, totalBill;

    //1st Function
    getPatient(typ_Patient, gender, name, icNum, phoneNum, work_History, &age, &citizenship, &registrationFee);
    totalTreatment = getdepartments(Department, date, hourClock, time, &numTreat);
    getCalc(citizenship, Citizenship, age, totalTreatment, work_History, registrationFee, &TotalTreat, &totalBill);
    getprint(typ_Patient, numTreat, name, age, gender, icNum, phoneNum, citizenship, Citizenship, work_History, registrationFee, totalTreatment, Department, date, time, hourClock, TotalTreat, totalBill);

}

void getPatient(char typ_Patient[], char gender[], char name[], char icNum[], char phoneNum[], char work_History[], int *age, int *citizenship, int *registrationFee)
{

	system("COLOR 50");

    printf("\n\t\t\t\t\t\tHOSPITAL PANTAI MELAKA\n");
    printf("\t\t\t\t\t\tAPPOINTMENT BOOKING SYSTEM\n");
    printf("\t\t\t\t\t=========================================\n");

    printf("\n\tAre you New or Usual Patient? [New/Usual]    : ");
    scanf(" %s", typ_Patient);

      if((strcmp(typ_Patient, "New"))==0)
      {
          FILE *fpointer;
          fpointer = fopen("NewPatient.txt","w");

          printf("\n\tPlease enter your name                       : ");
          scanf(" %[^\n]", name);

          fprintf(fpointer,"PATIENT NAME\n");
          fprintf(fpointer,"\n%s", name);

          fclose(fpointer);
      }
      else
      {
          FILE *fpointer;
          fpointer = fopen("UsualPatient.txt","w");

          printf("\n\tPlease enter your name                       : ");
          scanf(" %[^\n]", name);

          fprintf(fpointer,"PATIENT NAME\n");
          fprintf(fpointer,"\n%s", name);

          fclose(fpointer);
      }

    printf("\n\tPlease enter your age                        : ");
    scanf("%d", age);

    printf("\n\tPlease enter your gender [Female/Male]       : ");
    scanf("%s", gender);

    printf("\n\tPlease enter your IC number                  : ");
    scanf("%s", icNum);

    printf("\n\tPlease enter your phone number               : ");
    scanf("%s", phoneNum);

    printf("\n\tPlease state your nationality [citizen(1)/foreigner(0)] : ");
    scanf("%d", citizenship);

    printf("\n\tDo you or any of your family members work for the government? [yes/no]: ");
    scanf("%s", work_History);

    //decision for type patient

    if(strcmp(typ_Patient, "new") == 0)
    {
    	*registrationFee = 5;
    }
    else if(strcmp(typ_Patient, "New") == 0)
    {
    	*registrationFee = 5;
    }
    else
    {
		  *registrationFee = 0;
    }

}

float getdepartments(char Department[4][15], char date[4][50], char hourClock[4][4], float time[50][50],  int *numTreat)
{

	int i, proceed, j, fexit, treatmentFee, x;
	const char * listDepart[] = {"A","B","C","D"};
	char valid[15];
	char department[4][4];
	float totalTreatment;

	do
    {
    	proceed = 0;
    	totalTreatment = 0;
    	printf("\n\tHow many treatment do you want to book?    : ");
    	scanf("%d", numTreat);

        //looping for 1
    	for ( j=0; j < *numTreat; j++)
        {
            system("cls");
            FILE * fPointer;
            fPointer = fopen("ListDepartment.txt","r");
            char line[120];

            while(!feof(fPointer))
            {
                fgets(line,120,fPointer);
                printf(line);
            }
            fclose(fPointer);

            printf("\tPlease choose health department based on injury   : ");
            scanf(" %s", department[j]);

            printf("\n\tEnter date of Appointment [dd/mm/yy]              : ");
            scanf(" %s", date[j]);

            printf("\n\tEnter time of Appointment                         : ");
            scanf("%f", time[j]);

            printf("\n\tEnter hour Clock of Appointment [am/pm]           : ");
            scanf(" %s", hourClock[j]);


            //decision for department & validation
            if((strcmp(department[j], listDepart[0]))==0)
            {
            	char V1[15] = "APPROVED!";
                strcpy(valid, V1);
                char D1[15] = "Psychology";
                strcpy(Department[j], D1);

                treatmentFee = 100;
            }
            else if((strcmp(department[j], listDepart[1]))==0)
            {
                char V2[15] = "APPROVED!";
                strcpy(valid, V2);
                char D2[15] = "Dermatology";
                strcpy(Department[j], D2);

                treatmentFee = 120;
            }
            else if((strcmp(department[j], listDepart[2]))==0)
            {
                char V3[15] = "APPROVED!";
                strcpy(valid, V3);
                char D3[15] = "Cardiology";
                strcpy(Department[j], D3);

                treatmentFee = 130;
            }
            else if((strcmp(department[j], listDepart[3]))==0)
            {
                char V4[15] = "APPROVED!";
                strcpy(valid, V4);

                char D4[15] = "Neurology";
                strcpy(Department[j], D4);

                treatmentFee = 150;
            }
            else
            {
                char V5[15] = "CANCELLED!";
                strcpy(valid, V5);
                char D5[15] = "WRONG DEPART!";
                strcpy(Department[j], D5);

                treatmentFee = 0;
            }
              totalTreatment = totalTreatment + treatmentFee;
				 //calculate total treatment
        }

        //input for output
        printf("\n\tDo you want to submit(0) or not(1)    : ");
        scanf("%d", &fexit);

        //output 1 - if user not submit the appointment
        if(fexit == 1)
        {
            printf("\n\n\tYOUR APPOINTMENT IS BEEN CANCELLED BY YOU");

            //input for do-while looping
            printf("\n\n\tDo you want to make new appointment[1-yes/0-No]   : ");
            scanf("%d", &proceed);

            if(proceed == 0)
            {
            	exit(0);

            }
        }

    }while(proceed != 0);

		return totalTreatment;
}

void getCalc(int citizenship, char Citizenship[], int age, float totalTreatment, char work_History[], int registrationFee, float *TotalTreat, float *totalBill)
{

	float Discount1, Discount2;


	if(citizenship == 1)
    {
        char c1[15] ="Citizen";
        strcpy(Citizenship, c1);

        //decision Discount1
        if(age >= 50)
        {
        	Discount1 = totalTreatment * 0.15;

            //decision Discount2
            if(strcmp("Yes", work_History) == 0)
            {
             	Discount2 = totalTreatment * 0.25;
            }
            else if(strcmp("yes", work_History) == 0)
            {
                Discount2 = totalTreatment * 0.25;
            }
            else
            {
                Discount2 = totalTreatment * 0;
            }
        }
        else if(age <= 12)
        {
            Discount1 = totalTreatment * 0.05;

            if(strcmp("Yes", work_History) == 0)
            {
                Discount2 = totalTreatment * 0.15;
            }
            else if(strcmp("yes", work_History) == 0)
            {
            	Discount2 = totalTreatment * 0.15;
            }
            else
            {
                Discount2 = totalTreatment * 0;
            }
        }
        else
        {
            Discount1 = totalTreatment * 0;

            if(strcmp("Yes", work_History) == 0)
            {
                Discount2 = totalTreatment * 0.25;
            }
            else if(strcmp("yes", work_History) == 0)
            {
            	Discount2 = totalTreatment * 0.25;
            }
            else
            {
            	Discount2 = totalTreatment * 0;
            }
        }
    }
    else //Discount1
    {
        char c2[15] = "Foreigner";
        strcpy(Citizenship, c2);

            //Discount2
        if(age >= 60)
        {
              Discount1 = totalTreatment * 0.10;
        }
        else if(age <= 12)
        {
              Discount1 = totalTreatment * 0.05;
        }
        else
        {
              Discount1 = totalTreatment * 0;
        }
    }

          //calculation
     *TotalTreat = getcalcTotalTreat(totalTreatment, Discount1, Discount2);
	 *totalBill = getcalctotalBill(registrationFee, *TotalTreat);

}

float getcalcTotalTreat(float totalTreatment, float Discount1, float Discount2)
{
	float totalTreat;
	totalTreat = totalTreatment - Discount1 - Discount2;

	return totalTreat;
}

float getcalctotalBill(int registrationFee, float TotalTreat)
{
	float totalbill;
	totalbill = registrationFee + TotalTreat;
	return totalbill;
}

void getprint(char typ_Patient[], int numTreat, char name[], int age, char gender[], char icNum[], char phoneNum[], int citizenship, char Citizenship[], char work_History[], int registrationFee, float totalTreatment, char Department[4][15], char date[4][50], float time[50][50], char hourClock[4][4], float TotalTreat, float totalBill)
{
	int j, i;

	system("cls");
    printf("\n\t\t\t\t\t\tAPPOINTMENT BOOKING RECEIPT\n========================================================================================================================\n");

    printf("\n\t\t\t\t\t\tPatient Detail\n\t\t\t\t\t-------------------------------------\n");
    //printf("\nType of patient           : %s" ,typ_Patient);
    printf("\n\t\t\t\t\tName                      : %s", name);
    printf("\n\t\t\t\t\tAge                       : %d", age);
    printf("\n\t\t\t\t\tGender                    : %s", gender);
    printf("\n\t\t\t\t\tIC number                 : %s", icNum);
    printf("\n\t\t\t\t\tPhone number              : %s", phoneNum);

        //condition for output citizenship
        if(citizenship == 1)
        {
            char c1[15] ="Citizen";
            strcpy(Citizenship, c1);
        }
        else
        {
            char c2[15] = "Foreigner";
            strcpy(Citizenship, c2);
        }

    printf("\n\t\t\t\t\tCitizenship               : %s", Citizenship);

        //condition for output work history
        if(strcmp("Yes", work_History) == 0)
        {
            printf("\n\t\t\t\t\tGovernment worker         : Yes");
        }
        else if(strcmp("yes", work_History) == 0)
        {
            printf("\n\t\t\t\t\tGovernment worker         : Yes");
        }
        else
        {
            printf("\n\t\t\t\t\tGovernment worker         : No");
        }

    printf("\n\n\t\t\t\t\t\tAppointment Detail\n\t\t\t\t\t-------------------------------------\n");

        for(j=0; j< numTreat; j++)
        {

            printf("\n\t\t\t\t\tDepartment                : %s", Department[j]);
            printf("\n\t\t\t\t\tDate of appointment       : %s", date[j]);
            for(i=0; i< 1; i++)
                {
                    printf("\n\t\t\t\t\tTime of appointment       : %.2f %s", time[j][i], hourClock[j]);
                }
        }

        printf("\n\t\t\t\t\tRegistration fee          : RM %d", registrationFee);
        printf("\n\t\t\t\t\tTreatment Fee             : RM %.2f", totalTreatment);

        printf("\n\n\t\t\t\t\t\tPayment Detail\n\t\t\t\t\t-------------------------------------\n");
    printf("\n\n\t\t\t\t\tTotal treat             : RM %.2f", TotalTreat);
    printf("\n\t\t\t\t\tTotal bill              : RM %.2f\n", totalBill);

        FILE *fpointer;
        fpointer = fopen("AppointmentReceipt.txt","w");

            fprintf(fpointer,"\n\t\t\t\t\t\tAPPOINTMENT BOOKING RECEIPT\n\t\t\t\t\t========================================================================================================================\n");


            fprintf(fpointer,"\n\t\t\t\t\t\tPatient Detail\n\t\t\t\t\t-------------------------------------\n");
            //printf("\nType of patient           : %s" ,typ_Patient);
            fprintf(fpointer,"\n\t\t\t\t\tName                      : %s", name);
            fprintf(fpointer,"\n\t\t\t\t\tAge                       : %d", age);
            fprintf(fpointer,"\n\t\t\t\t\tGender                    : %s", gender);
            fprintf(fpointer,"\n\t\t\t\t\tIC number                 : %s", icNum);
            fprintf(fpointer,"\n\t\t\t\t\tPhone number              : %s", phoneNum);

            //condition for output citizenship
            if(citizenship == 1)
            {
                char c1[15] ="Citizen";
                strcpy(Citizenship, c1);
            }
            else
            {
                char c2[15] = "Foreigner";
                strcpy(Citizenship, c2);
            }

        fprintf(fpointer,"\n\t\t\t\t\tCitizenship               : %s", Citizenship);

            //condition for output work history
            if(strcmp("Yes", work_History) == 0)
            {
                fprintf(fpointer,"\n\t\t\t\t\tGovernment worker         : Yes");
            }
            else if(strcmp("yes", work_History) == 0)
            {
                fprintf(fpointer,"\n\t\t\t\t\tGovernment worker         : Yes");
            }
            else
            {
                fprintf(fpointer,"\n\t\t\t\t\tGovernment worker         : No");
            }

            fprintf(fpointer,"\n\n\t\t\t\t\t\tAppointment Detail\n\t\t\t\t\t-------------------------------------\n");

            for(j=0; j< numTreat; j++)
            {

                fprintf(fpointer,"\n\t\t\t\t\tDepartment                : %s", Department[j]);
                fprintf(fpointer,"\n\t\t\t\t\tDate of appointment       : %s", date[j]);
                for(i=0; i< 1; i++)
                    {
                        fprintf(fpointer,"\n\t\t\t\t\tTime of appointment       : %.2f %s", time[j][i], hourClock[j]);
                    }
            }

            fprintf(fpointer,"\n\t\t\t\t\tRegistration fee          : RM %d", registrationFee);
            fprintf(fpointer,"\n\t\t\t\t\tTreatment Fee             : RM %.2f", totalTreatment);

        fprintf(fpointer,"\n\n\t\t\t\t\t\tPayment Detail\n\t\t\t\t\t-------------------------------------\n");
        fprintf(fpointer,"\n\n\t\t\t\t\tTotal treat             : RM %.2f", TotalTreat);
        fprintf(fpointer,"\n\t\t\t\t\tTotal bill              : RM %.2f\n", totalBill);
}
