//Student_Information_Managment_System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define student struct
typedef struct student {
    char name[10]; // Student Name
    int no; // Student No
    int classno; // Student Class No
    int score; // General Score
    struct student *pno; // Student No Pointer
    struct student *pclass; // Class No Pointer
    struct student *pscore; // Score Pointer
} stu, *LinkList;


// Declare functional functions 
void Add(); 
void NoOut(); 
void Sort2(); 
void ClassNoOut(); 
void Sort3();
void ScoreOut(); 
void Sort3();
void DeleteBaseNo(); 
void ChangeScore(); 
void ChangeName(); 
void SearchBaseScore(); 
void SearchBaseClass(); 


LinkList SL;

// Main Function: Display the main menu and receive operation number
int main() {
    SL = (stu *)malloc(sizeof(stu));
    SL -> pno = NULL;
    SL -> pclass = NULL;
    SL -> pscore = NULL;
    

    int choice; // user's input

    while (1) {
        
        
        printf("********** Student Information Management System **********\n");
        printf("1. Add\n");
        printf("2. Output by Student No\n");
        printf("3. Output by Class No\n");
        printf("4. Output by Score\n");
        printf("5. Delete\n");
        printf("6. Change Score According to Student No\n");
        printf("7. Change Name According to Student No\n");
        printf("8. Search According to Score\n");
        printf("9. Search According to Class No\n");
        printf("10. Quir\n");
        printf("Your Operation：");
        


        scanf("%d", &choice); // Get user's input

        switch (choice) { // choose whcih operation to do
            case 1:
                Add();
                break;
            case 2:
                NoOut();
                break;
            case 3:
                ClassNoOut();
                break;
            case 4:
                ScoreOut();
                break;
            case 5:
                DeleteBaseNo();
                break;
            case 6:
                ChangeScore();
                break;
            case 7:
                ChangeName();
                break;
            case 8:
                SearchBaseScore();
                break;
            case 9:
                SearchBaseClass();
                break;
            case 10:
                exit(0); // quit
            default:
                printf("Wrong Input Number! Type Again!\n");
        }
    }

    return 0;
}


// 1. add a student information to linklist
void Add() {
    stu *st = (stu *)malloc(sizeof(stu));

    scanf("%05d %s %d %d", &(st -> no), st -> name, &(st -> classno), &(st -> score));
    
    st -> pno = SL -> pno;
    st -> pclass = SL -> pclass;
    st -> pscore = SL -> pscore;

    SL -> pno = st;
    SL -> pclass = st;
    SL -> pscore = st;
}

// 2. print student information in incremental order by Student No
void Sort2() {
    if((SL -> pno == NULL) || (SL -> pno -> pno == NULL)) {   
        return;
    }   
 
    stu *head, *p1, *prep1, *p2, *prep2, *temp;
    head = SL;
    prep1 = head -> pno;
    p1 = prep1 -> pno;
    
    int flag;
 
    while(p1 != NULL) {   
        flag = 1;
        temp = p1; 
        
        for(prep2 = head, p2 = prep2 -> pno; p2 != p1; prep2 = prep2 -> pno, p2 = p2 -> pno) {   
            
            if(p2 -> no > p1 -> no) {   
                p1 = p1 -> pno;
                prep1 -> pno = p1; 
                prep2 -> pno = temp;
                temp -> pno = p2; 
                flag = 0;
                break;
            }   
        }   
        
        if(flag) {   
            prep1 = prep1 -> pno;
            p1 = p1 -> pno;
        }   
    }   
}

void NoOut() {
    Sort2();

    stu *h = SL -> pno;
    while (h) {
        printf("%05d %s %d %d\n", h -> no, h -> name, h -> classno, h -> score);
        h = h -> pno;
    }
}

/* 
3. print student information in incremental order by Class No, 
if equal, output in incremental order by student number 
*/
void Sort3() {
    if((SL -> pclass == NULL) || (SL -> pclass -> pclass == NULL)) {   
        return;
    }   
 
    stu *head, *p1, *prep1, *p2, *prep2, *temp;
    head = SL;
    prep1 = head -> pclass;
    p1 = prep1 -> pclass;
    
    int flag;
 
    while(p1 != NULL) {   
        flag = 1;
        temp = p1; 
        
        for(prep2 = head, p2 = prep2 -> pclass; p2 != p1; prep2 = prep2 -> pclass, p2 = p2 -> pclass) {   
            
            if(p2 -> classno > p1 -> classno) {   
                p1 = p1 -> pclass;
                prep1 -> pclass = p1; 
                prep2 -> pclass = temp;
                temp -> pclass = p2; 
                flag = 0;
                break;
            }
            else if(p2 -> classno == p1 -> classno && p2 -> no > p1 -> no) {
                p1 = p1 -> pclass;
                prep1 -> pclass = p1; 
                prep2 -> pclass = temp;
                temp -> pclass = p2; 
                flag = 0;
                break;
            }   
        }   
        
        if(flag) {   
            prep1 = prep1 -> pclass;
            p1 = p1 -> pclass;
        }   
    }
}

void ClassNoOut() {
    Sort3();

    stu *h1 = SL -> pclass;
    while (h1) {
        printf("%05d %s %d %d\n", h1 -> no, h1-> name, h1 -> classno, h1 -> score);
        h1 = h1 -> pclass;
    }
} 

/* 
4. print student information in incremental order by Student Score, 
if equal, output in incremental order by student number
*/
void Sort4() {
    if((SL -> pscore == NULL) || (SL -> pscore -> pscore == NULL)) {   
        return;
    }   
 
    stu *head, *p1, *prep1, *p2, *prep2, *temp;
    head = SL;
    prep1 = head -> pscore;
    p1 = prep1 -> pscore;
    
    int flag;
 
    while(p1 != NULL) {   
        flag = 1;
        temp = p1; 
        
        for(prep2 = head, p2 = prep2 -> pscore; p2 != p1; prep2 = prep2 -> pscore, p2 = p2 -> pscore) {   
            
            if(p2 -> score > p1 -> score) {   
                p1 = p1 -> pscore;
                prep1 -> pscore = p1; 
                prep2 -> pscore = temp;
                temp -> pscore = p2; 
                flag = 0;
                break;
            }
            else if(p2 -> score == p1 -> score && p2 -> no > p1 -> no) {
                p1 = p1 -> pscore;
                prep1 -> pscore = p1; 
                prep2 -> pscore = temp;
                temp -> pscore = p2; 
                flag = 0;
                break;
            }   
        }   
        
        if(flag) {   
            prep1 = prep1 -> pscore;
            p1 = p1 -> pscore;
        }   
    }
}

void ScoreOut() {
    Sort4();

    stu *h = SL -> pscore;
    while (h) {
        printf("%05d %s %d %d\n", h -> no, h -> name, h -> classno, h -> score);
        h = h -> pscore;
    }
} 


// 5. Delete the recording of inputed student no
void DeleteBaseNo() {
    int A_no;
    scanf("%05d", &A_no);

    stu *node = SL -> pno;
    stu *pre = SL;
    while(node) {
        if(node -> no == A_no) {
            pre -> pno = node -> pno;
            pre -> pclass = node -> pclass;
            pre -> pscore = node -> pscore;
            free(node);
            break;
        }
        else {
            pre = pre -> pno;
            node = node -> pno;
        }
    }
}

/* 
6. enter a student no and total grade points, 
find the student with that number and change the total grade points 
*/
void ChangeScore() {
    int A_N, A_s;
    scanf("%05d %d", &A_N, &A_s);

    stu *node = SL -> pno;
    while(node) {
        if(node -> no == A_N) {
            node -> score = A_s;
            break;
        }
        node = node -> pno;
    }
} 


/* 
7. enter a student no and name, 
find the student with that number and change the name
*/
void ChangeName() {
    int N;
    char A_name[10];
    scanf("%d %s", &N, A_name);

    stu *node = SL -> pno;
    int flag = 1;
    while(flag) {
        if(node -> no == N) {
            strcpy(node -> name, A_name);
            flag = 0;
        }
        else node = node -> pno;
    }
} 

/* 
8. enter a student score,  
output all students'information with this score by 3. rule
*/
void SearchBaseScore() {
    Sort3();

    int s;
    scanf("%05d", &s);

    stu *node = SL -> pclass;
    while(node) {
        if(node -> score == s) {
            printf("%05d %s %d %d\n", node -> no, node -> name, node -> classno, node -> score);
        }
        node = node -> pclass;
    }
} 

/* 
8. enter a class no,  
output all students'information in this class by 4. rule
*/
void SearchBaseClass() {
    Sort4();

    int A_cn;
    scanf("%d", &A_cn);
    
    stu *node = SL -> pscore;
    while(node) {
        if(node -> classno == A_cn) {
            printf("%05d %s %d %d\n", node -> no, node -> name, node -> classno, node -> score);
        }
        node = node -> pscore;
    }
}


