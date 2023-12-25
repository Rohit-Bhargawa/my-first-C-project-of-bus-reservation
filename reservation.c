#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>

struct profilo
{
    char name[20];
    int age;
    char contact[10];
};

struct booking_detail
{
    char location[28];
    char destini[28];
    char journey_day [10];
    char doj[10];
    int n_seat;
    int seat_cancel;
    int UPI;
    char reason[28];
};

/**********************************************PAYMENTS******************************************************************/

void payment()
{
    struct booking_detail B1;
    printf("\n=================================\n");
    printf("\nPAYMENTS\n");
    printf("\n=================================\n");
    printf("\nPlease enter UPI number: ");
    scanf("%d",&B1.UPI);
    printf("\nTicket Booked :)\n");
    printf("\nPress ENTER to Confirm.\n");
    getch();
}

/**********************************************BOOKINGS******************************************************************/

void booking()
{
    int amount;
    struct booking_detail B1;

    FILE *fp1;

    fp1=fopen("C:\\Users\\rohit\\OneDrive\\Desktop\\bookings.txt","w");
    printf("\n=================================\n");
    printf("\nBOOKINGS\n");
    printf("\n=================================\n");
    printf("Enter Location: ");           //from stop.
    scanf("%s",B1.location);
    printf("Enter Destination: ");        //to stop.
    scanf("%s",B1.destini);

    printf("\nAvail Srevices:(for whole week) \n\t1. Mahadev travels at 2:30 P.M \n \t2. Volvo srvice at 7:00 A.M\n\n");

    printf("Press the Option Number of Bus Service You want to Book.\n");
    getch();
    system("cls");

    printf("Enter Day of Journey: ");            //in days of week.
    scanf("%s",B1.journey_day);
    printf("Enter Date of Journey: ");           //in numeric.
    scanf("%s",B1.doj);

    printf("\nSeats Avail= 11 out of 28\n");

    printf("\nEnter Seats to be Booked: ");
    scanf("%d",&B1.n_seat);

    if(B1.n_seat<=11)
    {
        amount=(B1.n_seat)*550;
        printf("\nTotal Amount= %d\n",amount);
        payment();
    }
    else { printf("error"); }

    fprintf(fp1,"%s\n%s\n%s\n%s\n%d\n%d",B1.location,B1.destini,B1.journey_day,B1.doj,B1.n_seat,amount);
    fclose(fp1);

    system("cls");
}

/**********************************************CANCELLATION******************************************************************/

void cancellation()
{
    struct booking_detail B2;
    int n,ref_amount;

    printf("\n=================================\n");
    printf("\nCANCELLATIONS\n");
    printf("\n=================================\n");

    printf("Enter The Login Number: ");           //last 4 digits of your contact number.
    scanf("%d",&n);
    if(n>=4)
    {
    printf("\nEnter Location: ");
    scanf("%s",B2.location);
    printf("\nEnter Destination: ");
    scanf("%s",B2.destini);
    printf("\nEnter Day of Journey: ");
    scanf("%s",B2.journey_day);
    printf("\nEnter Date of Journey: ");
    scanf("%s",B2.doj);
    printf("\nEnter the Reason to Cancel Booking: ");
    scanf("%s",B2.reason);
    printf("\nEnter Seats Booked: ");
    scanf("%d",&B2.n_seat);
    printf("\nenter  Seats to be Canceled: ");
    scanf("%d",&B2.seat_cancel);
    if(B2.seat_cancel<B2.n_seat)           //as total booking amount is not refundable.
    {
        printf("\nTicket Cancelled.");
        ref_amount=(B2.n_seat*550)-(B2.seat_cancel*550);
        printf("\nAmount Refounded: %d",ref_amount);           //returned to users UPI
    }
    else { printf("error"); }
    printf("\nPress ENTER to Confirm.\n");
    getch();
    system("cls");
    }
    else { printf("error:404 page not found"); }
}

/**********************************************CURRENT STATUS******************************************************************/

void current_status()
{
    struct booking_detail B3;

    printf("\n=================================\n");
    printf("\nCURRENT STATUS\n");
    printf("\n=================================\n");

    printf("\nEnter Location: ");
    scanf("%s",B3.location);
    printf("\nEnter Destination: ");
    scanf("%s",B3.destini);
    printf("\nEnter Day of Journey: ");
    scanf("%s",B3.journey_day);
    printf("\nEnter Date of journey: ");
    scanf("%s",B3.doj);
    printf("\nThe Bus is on the way to Your Location and it will reach within 10 Minutes.\n");
    printf("\nPress ENTER to Confirm.\n");
    getch();
    system("cls");
}

/**********************************************MAIN MENU******************************************************************/

int main()
{
    printf("\n\n==================================================\n");
    printf("\n\t WELCOME TO RESERVATIOIN CORNER");
    printf("\n\n==================================================\n");

    struct profilo P1;
    FILE *fp;

    fp=fopen("C:\\Users\\rohit\\OneDrive\\Desktop\\profilo info.txt","w");

    printf("Enter Name: ");           //with dot not with space.
    scanf("%s",P1.name);
    printf("Enter Age: ");            //in years.
    scanf("%d",&P1.age);
    printf("Enter Contact: ");        //mobile number.
    scanf("%s",P1.contact);

    fprintf(fp,"%s\n%d\n%s",P1.name,P1.age,P1.contact);
    fclose(fp);

    system("cls");

    int ch;
    printf("\n======================================\n");
    printf("1. BOOKING.\n");
    printf("\n======================================\n");
    printf("2. CANCELLATION.\n");
    printf("\n======================================\n");
    printf("3. CHECK THE CURRENT STATUS OF THE BUS.\n");
    printf("\n======================================\n");
    printf("\nEnter Your Choice from Above Given and press ENTER to Continue: ");
    scanf("%d",&ch);

    system("cls");

    switch(ch)
    {
        case 1: booking();
        break;
        case 2: cancellation();
        break;
        case 3: current_status();
        break;
        default: printf("error");
    }
    printf("\n\n==================================================\n");
    printf("\n\t THANK YOU VISIT AGAIN>>");
    printf("\n\n==================================================\n");

    printf("\nby:-Rohit.Kumar.Bhargawa\nComputer Engineering\n");

    return 0;
}
