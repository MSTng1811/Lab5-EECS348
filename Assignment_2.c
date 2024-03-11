#include<stdio.h>
void main() {
    int score, td, fg, safety, td2, tdFg, rem;
    while(1) {
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    printf("Possible combinations of scoring plays:\n");
    if(score<=1)
        break;
    else {
        for(td=0; td<=score/6; td++) {
            for(fg=0; fg<= score/3; fg++) {
                for(safety=0; safety<=score/2; safety++) {
                    for(td2=0; td2<=(score-(td*6 + fg*3 + safety*2))/8; td2++) {
                        for(tdFg=0; tdFg<=(score-(td*6 + fg*3 + safety*2 + td2*8))/7; tdFg++) {
                            rem = score-(td*6 + fg*3 + safety*2 + td2*8 + tdFg*7);
                            if(rem==0) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, tdFg, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }
}}
    