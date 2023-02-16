#include <stdio.h>
#include <string.h>

struct User {
    int age;
    char name[101];
};

void mergeSort(User* user, User* sub, int left, int mid, int right);
void merge(User* user, User* sub, int left, int mid, int right);

int main() {
    int n;
    User *user, *sub;

    scanf("%d", &n);

    user = new User[n];
    sub = new User[n];

    for(int i=0; i<n; i++) {
        scanf("%d %s", &(user[i].age), user[i].name);
    }

    mergeSort(user, sub, 0, (n-1)/2, n-1);

    for(int i=0; i<n; i++) {
        printf("%d %s\n", user[i].age, user[i].name);
    }

    delete []user;

    return 0;
}

void mergeSort(User* user, User* sub, int left, int mid, int right) {
    int length = (right - left) + 1;
    if(2 < length) {
        mergeSort(user, sub, left, (left+mid)/2, mid);
        mergeSort(user, sub, mid+1, ((mid+1)+right)/2, right);
    }

    merge(user, sub, left, mid, right);
}

void merge(User* user, User* sub, int left, int mid, int right) {
    int i, j, k;

    i = left;
    j = mid + 1;
    k = 0;

    while(i <= mid && j <= right) {
        if(user[i].age < user[j].age) {
            sub[k].age = user[i].age;
            strcpy(sub[k].name, user[i].name);
            k++; i++;
        } 
        else if(user[i].age > user[j].age) {
            sub[k].age = user[j].age;
            strcpy(sub[k].name, user[j].name);
            k++; j++;
        }
        else {
            sub[k].age = user[i].age;
            strcpy(sub[k].name, user[i].name);
            k++; i++;
        }
    }

    while(i <= mid ^ j <= right) {
        if(i <= mid) {
            sub[k].age = user[i].age;
            strcpy(sub[k].name, user[i].name);
            k++; i++;
        } 
        else {
            sub[k].age = user[j].age;
            strcpy(sub[k].name, user[j].name);
            k++; j++;
        }
    }

    k = 0;
    for(int i=left; i <= right; i++) {
        user[i].age = sub[k].age;
        strcpy(user[i].name, sub[k].name);
        k++;
    }
}