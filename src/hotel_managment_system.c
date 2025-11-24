#include <stdio.h>
#include <string.h>

struct Customer {
    char room[10];
    char name[30];
    char phone[20];
    char nationality[20];
};

int main() {
    struct Customer c[100];
    int count = 0;
    int choice;
    char searchRoom[10];

    
    FILE *fp = fopen("hotel.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%s %s %s %s",
                      c[count].room, c[count].name,
                      c[count].phone, c[count].nationality) == 4) {
            count++;
        }
        fclose(fp);
    }

    while (1) {
        printf("\n===== HOTEL MANAGEMENT SYSTEM =====\n");
        printf("1. Book a Room\n");
        printf("2. View All Customers\n");
        printf("3. Search Customer by Room\n");
        printf("4. Delete Customer\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // BOOK A ROOM
        if (choice == 1) {
            printf("\nEnter Room Number: ");
            scanf("%s", c[count].room);

            printf("Enter Name: ");
            scanf("%s", c[count].name);

            printf("Enter Phone Number: ");
            scanf("%s", c[count].phone);

            printf("Enter Nationality: ");
            scanf("%s", c[count].nationality);

            count++;
            printf("\nRoom successfully booked!\n");
        else if (choice == 2) {
            if (count == 0) {
                printf("\nNo customer records yet.\n");
            } else {
                printf("\n===== CUSTOMER LIST =====\n");
                for (int i = 0; i < count; i++) {
                    printf("\nRoom: %s", c[i].room);
                    printf("\nName: %s", c[i].name);
                    printf("\nPhone: %s", c[i].phone);
                    printf("\nNationality: %s\n", c[i].nationality);
                }
            }
        }

        else if (choice == 3) {
            printf("\nEnter Room Number to Search: ");
            scanf("%s", searchRoom);

            int found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(c[i].room, searchRoom) == 0) {
                    printf("\nRecord Found!");
                    printf("\nRoom: %s", c[i].room);
                    printf("\nName: %s", c[i].name);
                    printf("\nPhone: %s", c[i].phone);
                    printf("\nNationality: %s\n", c[i].nationality);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nRecord not found.\n");
            }
        }


        else if (choice == 4) {
            printf("\nEnter Room Number to Delete: ");
            scanf("%s", searchRoom);

            int found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(c[i].room, searchRoom) == 0) {
    
                    for (int j = i; j < count - 1; j++) {
                        c[j] = c[j + 1];
                    }
                    count--;
                    found = 1;
                    printf("\nRecord deleted successfully!\n");
                    break;
                }
            }

            if (!found) {
                printf("\nRecord not found.\n");
            }
        }
        else if (choice == 5) {
            fp = fopen("hotel.txt", "w");
            for (int i = 0; i < count; i++) {
                fprintf(fp, "%s %s %s %s\n",
                    c[i].room, c[i].name, c[i].phone, c[i].nationality);
            }
            fclose(fp);

            printf("\nData saved. Exiting...\n");
            break;
        }

        else {
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
