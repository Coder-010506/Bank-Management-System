
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
char name[60];
int dip_amt, acc_no, ac, count = 0;
int trans_amt;
int with_amt;
char dob[15];
int age;
char address[60];
char phone[15];
char acc_type[10];
float balance;
char decision;
int branch_no;
int count1;
int count2;
int loans_taken;

void create_account();
void deposit_money();
void withdraw_money();
void transfer_money();
void checkDetail();
void LastDetail();
void loan_service();
void transaction_details();
void menu();

void divider()
{
    for (int i = 0; i < 20; i++)
    {
        printf("*-*-");
    }
}
int main()
{
    char password[10], actual_password[] = "admin";
    int attempt = 0;

    while (attempt < 3)
    {
        printf("\nEnter Password to Login: ");
        scanf("%s", password);

        if (strcmp(password, actual_password) == 0)
        {
            printf("\nLogin Successful!\n");
            menu();
            break;
        }
        else
        {
            printf("Incorrect Password!\n");
            attempt++;
        }
    }

    if (attempt == 3)
    {
        printf("Too many failed attempts! Exiting program.\n");
    }
    return 0;
}

void menu()
{
    int choice;
    system("cls");
    printf("\n\n\t\t\tBKA BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t       WELCOME TO THE MENU");
    printf("\n");
    divider();
    printf("\n");
    printf("1.Create New Account\n");
    printf("2.Deposit Money\n");
    printf("3.Withdraw Money\n");
    printf("4.Transfer Money\n");
    printf("5.Account details\n");
    printf("6.Transaction details\n");
    printf("7.Loan Services\n");
    printf("8.Exit\n");
    printf("\t\tEnter your choice: ");
    scanf("%d", &choice);

    while (1)
    {

        switch (choice)
        {
        case 1:
            system("cls");
            create_account();
            break;

        case 2:
            system("cls");
            deposit_money();
            break;

        case 3:
            system("cls");
            withdraw_money();
            break;

        case 4:
            system("cls");
            transfer_money();
            break;

        case 5:
            system("cls");
            checkDetail();
            break;
        case 6:
            transaction_details();
            break;

        case 7:
            loan_service();
            break;

        case 8:
            system("cls");
            LastDetail();
            exit(0);

        default:
            printf("*****Invalid choice*****");
        }
    }
}
//!---------------------------------------------------------
void create_account()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a+");
    printf("Enter Account Number: ");
    scanf("%d", &acc_no);

    printf("Enter Name: ");
    scanf(" %[^\n]s", name);

    printf("Enter Date of Birth (DD/MM/YYYY): ");
    scanf("%s", dob);

    printf("Enter Age: ");
    scanf("%d", &age);

    printf("Enter Address: ");
    scanf(" %[^\n]s", address);

    printf("Enter Phone Number: ");
    scanf("%s", phone);

    printf("Enter Account Type (Savings/Current): ");
    scanf("%s", acc_type);

    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &balance);

    printf("Date/Time of creating account :  %s\n", ctime(&tm));

    fprintf(ptr, "Account Number: %d\nName: %s\nDOB: %s\nAge: %d\nAddress: %s\nPhone: %s\nAccount Type: %s\nBalance: %.2f\n\n", acc_no, name, dob, age, address, phone, acc_type, balance);
    fprintf(ptr, "Date/Time of creating account :  %s\n", ctime(&tm));
    fclose(ptr);

    printf("\nAccount successfully created!\n");
    printf("Press any key....\n");
    getch();
    menu();
}
//!---------------------------------------------------------
void deposit_money()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****DEPOSITING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the amount you want to deposit\n");
    scanf("%d", &dip_amt);

    balance += dip_amt;
    printf("****Money Deposited****\n");
    printf("Now balance: %.2f\n", balance);
    fprintf(ptr, "\nRs%d had been deposited to your account \n", dip_amt);
    fprintf(ptr, "Date/Time of transaction: %s\n", ctime(&tm));
    count++;

    fclose(ptr);
    printf("Press any key....\n");
    getch();
    menu();
}

//!---------------------------------------------------------

void withdraw_money()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****WITHDRAWING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the amount you want to withdraw\n");
    scanf("%d", &with_amt);

    if (balance < with_amt)
    {
        printf("****Insufficient balance****\n");
    }
    else
    {
        balance = balance - with_amt;
        printf("*****Money withdrawn*****\n");
        printf("Current balance : %f\n", balance);
        fprintf(ptr, "\nRs%d had been withdrawn from your account \n", with_amt);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Press any key....\n");

    getch();
    menu();
}

//!---------------------------------------------------------

void transfer_money()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    printf("*****TRANSFERRING MONEY*****\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nEnter the account no. in which you want to transfer the money : ");
    scanf("%d", &ac);
    printf("\nEnter the amount you want to transfer\n");
    scanf("%d", &trans_amt);

    if (balance < trans_amt)
    {
        printf("****You have not sufficient balance****\n");
    }
    else
    {
        balance = balance - trans_amt;
        printf("****Money Transferred****\n");
        printf("Current balance : %f\n", balance);
        fprintf(ptr, "\nRs%d had been transferred from your account to %d\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Press any key....\n");
    getch();
    menu();
}

//!---------------------------------------------------------

void checkDetail()
{
    printf("ACCOUNT DETAILS\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }

    printf("\nAccount Number: %d\n", acc_no);
    printf("Name: %s\n", name);
    printf("Date of Birth: %s\n", dob);
    printf("Age: %d\n", age);
    printf("Address: %s\n", address);
    printf("Phone: %s\n", phone);
    printf("Account Type: %s\n", acc_type);
    printf("Balance: %.2f\n", balance);
    printf("\n%d transactions have been made from your account \n", count);
    printf("Press any key.....");
    getch();
    menu();
}

//!---------------------------------------------------------

void transaction_details()
{

    system("cls");

    FILE *ptr;
    ptr = fopen("Account.txt", "r");
    char c = fgetc(ptr);
    if (c == EOF)
    {
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("\n*******NO RECENT TRANSACTION*******\n");
    }
    else
    {
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("\n%d transactions have been made from your account \n", count);
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(ptr);
        }
    }
    printf("\nPress any key to return to the menu...\n");
    getch();
    menu();
}

//!---------------------------------------------------------
void loan_service()
{
    int choice;
    printf("\t\t\tWELCOME TO THE SERVICE OF ONLINE LOAN\n");
    printf("1.Open new loan account\n");
    printf("2.Close loan account\n");
    printf("3.Loan Renewal or Extension\n");
    printf("4.Exit Loan service\n");
    printf("\t\tEnter your choice: ");
    scanf("%d", &choice);
    while (1)
    {

        switch (choice)
        {
        case 1:
            system("cls");
            printf("\n********** IMPORTANT INSTRUCTIONS **********\n");
            printf("1. Aadhaar and PAN card verification is mandatory at the nearest bank.\n");
            printf("2. Fake documents or malpractice will result in 5 years of imprisonment and a Rs.10,000 fine.\n");
            printf("3. Failure to verify your documents within the given time will lead to loan cancellation.\n");
            printf("4. Loan money will be credited only after successful document verification.\n");
            printf("5. A valid bank statement is crucial for loan approval.\n");
            printf("6. The loan amount approved by the manager will be credited to your account.\n");

            char agreement;
            printf("\nDo you agree with the Terms & Conditions? (Y/N): ");
            scanf(" %c", &agreement);

            if (agreement == 'Y' || agreement == 'y')
            {

                FILE *file = fopen("LoanApplications.txt", "a");
                if (file == NULL)
                {
                    printf("Error opening file!\n");
                    return;
                }

                long long acc_no, loan_no;
                int loan_type, branch_no;
                int day, month, year, hour, minute;
                float loan_amt, interest_rate;

                system("cls");
                printf("\n********** APPLY FOR A NEW LOAN **********\n");

                printf("Enter your Account Number: ");
                scanf("%lld", &acc_no);
                printf("Enter the Loan acc Number:");
                scanf("%d", &loan_no);

                printf("\nChoose your Loan Scheme:\n");
                printf("1. Basic Scheme  (Rs.5,00,000 at 0.5%% interest)\n");
                printf("2. Intermediate Scheme (Rs.10,00,000 at 1%% interest)\n");
                printf("3. Advanced Scheme (Rs.15,00,000 at 1.75%% interest)\n");
                printf("Enter your choice (1/2/3): ");
                scanf("%d", &loan_type);

                switch (loan_type)
                {
                case 1:
                    loan_amt = 500000;
                    interest_rate = 0.5;
                    break;
                case 2:
                    loan_amt = 1000000;
                    interest_rate = 1.0;
                    break;
                case 3:
                    loan_amt = 1500000;
                    interest_rate = 1.75;
                    break;
                default:
                    printf("Invalid loan type selected. Please restart the process.\n");
                    fclose(file);
                    return;
                }

                printf("\nYou have chosen a loan of Rs.%.2f with %.2f%% interest.\n", loan_amt, interest_rate);

                printf("Enter your Bank Branch Number: ");
                scanf("%d", &branch_no);

                printf("\n********** SLOT BOOKING FOR DOCUMENT VERIFICATION **********\n");
                printf("Bank is open from 10 AM to 5 PM.\n");

                printf("Enter Slot Date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);

                printf("Enter Slot Time (HH MM) in 24-hour format: ");
                scanf("%d %d", &hour, &minute);

                if (hour < 10 || hour > 17 || (hour == 17 && minute > 0))
                {
                    printf("Invalid time! Please choose a time between 10 AM to 5 PM.\n");
                    fclose(file);
                    return;
                }

                printf("\nSlot Confirmed for Document Verification on %02d/%02d/%04d at %02d:%02d.\n", day, month, year, hour, minute);
                printf("Ensure you verify your documents on time to avoid loan cancellation.\n");

                fprintf(file, "Account Number: %lld\n", acc_no);
                fprintf(file, "Loan Type: %s\n", (loan_type == 1) ? "Basic (Rs.5L, 0.5%)" : (loan_type == 2) ? "Intermediate (Rs.10L, 1%)"
                                                                                                             : "Advanced (Rs.15L, 1.75%)");
                fprintf(file, "Loan Amount: ₹%.2f\n", loan_amt);
                fprintf(file, "Interest Rate: %.2f%%\n", interest_rate);
                fprintf(file, "Bank Branch Number: %d\n", branch_no);
                fprintf(file, "Slot Date: %02d/%02d/%04d\n", day, month, year);
                fprintf(file, "Slot Time: %02d:%02d\n", hour, minute);
                fprintf(file, "----------------------------------------------\n");

                fclose(file);

                printf("\nLoan Application Process Completed! Visit your bank for verification.\n");
                count1++;
            }
            else
            {
                printf("\nLoan application canceled. You must agree to the terms to proceed.\n");
            }
            printf("\nPress any key to return to the menu...\n");
            getch();
            loan_service();
            break;

        case 2:
            system("cls");
            int loan_acc_no, branch_no;
            char confirm, slot_date[15];
            char hour[2], minute[2];

            printf("Enter Loan Account Number: ");
            scanf("%d", &loan_acc_no);

            printf("\nLoan Details...\n");
            printf("Name: %s\n", name);
            printf("Loan Account Number: %d\n", loan_acc_no);
            printf("Type of Loan: %s\n", acc_type);

            printf("\nConfirm Loan Closure? (Y/N): ");
            scanf(" %c", &confirm);

            if (confirm == 'Y' || confirm == 'y')
            {
                printf("\nEnter Bank Branch Number: ");
                scanf("%d", &branch_no);
                printf("Enter Slot Date (DD/MM/YYYY): ");
                scanf("%s", slot_date);
                printf("Enter Slot Time (HH MM) in 24-hour format: ");
                scanf("%s %s", hour, minute);

                printf("\nYour loan closure slot is booked for %s at %s:%s in branch %d.\n", slot_date, hour, minute, branch_no);
                printf("Please ensure all documents are verified before the closure date.\n");
            }
            else
            {
                printf("\nVisit the bank to resolve any issues.\n");
            }

            FILE *file = fopen("ClosedLoans.txt", "a");
            if (file == NULL)
            {
                printf("Error opening file!\n");
                return;
            }
            fprintf(file, "Name: %s\n", name);
            fprintf(file, "Loan Account Number: %d\n", loan_acc_no);
            fprintf(file, "Type of Loan: %s\n", acc_type);
            fprintf(file, "Branch Number: %d\n", branch_no);
            fprintf(file, "Slot Date: %s\n", slot_date);
            fprintf(file, "Slot Time: %s:%s\n", hour,minute);
            fprintf(file, "----------------------------------------------\n");
            fclose(file);
            printf("\nPress any key to return to the menu...\n");
            getch();
            loan_service();
            count2++;

            break;

        case 3:
            system("cls");
            long long search_acc_no, loan_no;
            int extension_period;
            float new_interest_rate;

            printf("\nEnter Account Number for Loan Renewal/Extension: ");
            scanf("%lld", &search_acc_no);
            printf("Enter Loan Account Number: ");
            scanf("%lld", &loan_no);

            printf("\nChoose Extension Period:\n");
            printf("1. 6 months (Additional 0.5%% interest)\n");
            printf("2. 1 year (Additional 1%% interest)\n");
            printf("Enter your choice: ");
            scanf("%d", &extension_period);

            if (extension_period == 1)
                new_interest_rate = 0.5;
            else if (extension_period == 2)
                new_interest_rate = 1.0;
            else
            {
                printf("Invalid Extension Period.\n");
                break;
            }
            printf("\nLoan Renewal Successful for Account %lld, Loan %lld.\n", search_acc_no, loan_no);
            printf("New Additional Interest Rate: %.2f%%\n", new_interest_rate);
            FILE *file = fopen("RenewalLoans.txt", "a");
            if (file == NULL)
            {
                printf("Error opening file!\n");
                return;
            }
            fprintf(file, "Name: %s\n", name);
            fprintf(file, "Loan Account Number: %d\n", loan_acc_no);
            fprintf(file, "Type of Loan: %s\n", acc_type);
            fprintf(file, "Branch Number: %d\n", branch_no);
            fprintf(file, "Slot Date: %s\n", slot_date);
            fprintf(file, "Slot Time: %s:%s\n", hour,minute);
            fprintf(file, "Renewal Details:%f\n",new_interest_rate);
            fprintf(file, "----------------------------------------------\n");
            fclose(file);
            printf("\n\nPress any key to exit.....");
            getch();
            loan_service();
            break;

        case 4:
            system("cls");
            menu();
            break;

        default:
            printf("*****Invalid choice*****");
        }
    }
}

//!---------------------------------------------------------
void LastDetail()
{
    printf("ACCOUNT DETAILS\n");
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %f\n ", balance);

    printf("\n\nPress any key to exit.....");
    getch();
}