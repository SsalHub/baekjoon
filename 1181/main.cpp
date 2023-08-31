#include <stdio.h>
#include <string.h>

void mergeSort(char** list, char** sorted, int left, int mid, int right);
void merge(char** list, char** sorted, int left, int mid, int right);

const char DUMMY = '\0';

int main() {
    char** list;
    char** sorted;
    int n, left, mid, right;

    scanf("%d", &n);
    list = new char*[n];
    sorted = new char*[n];

    for(int i=0; i<n; i++) {
        list[i] = new char[50];
        sorted[i] = new char[50];
        scanf("%s", list[i]);
    }

    left = 0;
    right = n - 1;
    mid = (left + right) / 2;

    mergeSort(list, sorted, left, mid, right);

    for(int i=0; list[i] && i<n; i++) {
        if(list[i][0] == DUMMY) continue;
        printf("%s\n", list[i]);
    }

    for(int i=0; i<n; i++) {
        delete []list[i];
        delete []sorted[i];
    }
    delete []list;
    delete []sorted;

    return 0;
}

void mergeSort(char** list, char** sorted, int left, int mid, int right) {
    int length = right - left + 1;
    if(2 < length) {
        mergeSort(list, sorted, left, (left+mid)/2, mid);
        mergeSort(list, sorted, mid+1, ((mid+1)+right)/2, right);
    }
    
    merge(list, sorted, left, mid, right);
}

void merge(char** list, char** sorted, int left, int mid, int right) {
    int i, j, k, dummy;

    i = left;
    j = mid + 1;
    k = dummy = 0;
    while(i<=mid && j<=right) {
        if(list[i][0] == DUMMY) {
            dummy++; i++;
            continue;
        }
        if(list[j][0] == DUMMY) {
            dummy++; j++;
            continue;
        }

        int iLen = strlen(list[i]), jLen = strlen(list[j]);
        if(iLen < jLen) {
            strcpy(sorted[k++], list[i++]);
            continue;
        }
        else if(jLen < iLen) {
            strcpy(sorted[k++], list[j++]);
            continue;
        }

        int flag = strcmp(list[i], list[j]);
        if(flag == 0) {
            dummy++; j++;
        }
        else if(flag < 0) {
            strcpy(sorted[k++], list[i++]);
        }
        else {
            strcpy(sorted[k++], list[j++]);
        }
    }

    while(i<=mid ^ j<=right) {
        if(i <= mid) {
            strcpy(sorted[k++], list[i++]);
        }
        else {
            strcpy(sorted[k++], list[j++]);
        }
    }

    for(int i=0; i<dummy; i++) {
        sorted[k++][0] = DUMMY;
    }

    k = 0;
    for(int i=left; i<=right; i++) {
        strcpy(list[i], sorted[k++]);
    }
}