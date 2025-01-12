// #include <stdio.h>
// int main (){
//     int a[5],i,data;
//     for (i=0;i<5;i++){
//         scanf ("%d", &a[i]);
//     }
//     printf ("data =");
//     scanf ("%d", &data);
//     if (a[i]==data){
//         printf ("found at index %d",i);
//     }
//     printf ("not found");
// }

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[5], i, data;
    int found = 0; // Flag to indicate if data is found

    // Input five integers into the array
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    printf("data = ");
    scanf("%d", &data);

    // Check for the presence of data in the array
    for (i = 0; i < 5; i++) {
        if (a[i] == data) {
            printf("found at index %d\n", i);
            found = 1; // Set flag to indicate data was found
            break; // Exit loop if found
        }
    }

    // If data was not found, print not found message
    if (found==0) {
        printf("not found\n");
    }

    return 0;
}