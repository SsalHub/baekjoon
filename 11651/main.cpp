#include <stdio.h>

struct Point {
    int x;
    int y;
};

void mergeSort(Point* point, Point* sub, int left, int mid, int right);
void merge(Point* point, Point* sub, int left, int mid, int right);

int main() {
    Point *point, *sub;
    int n;

    scanf("%d", &n);
    point = new Point[n];
    sub = new Point[n];

    for(int i=0; i<n; i++) {
        scanf("%d %d", &(point[i].x), &(point[i].y));
    }

    mergeSort(point, sub, 0, (n-1)/2, n-1);

    for(int i=0; i<n; i++) {
        printf("%d %d\n", point[i].x, point[i].y);
    }

    delete []point;
    delete []sub;

    return 0;
}

void mergeSort(Point* point, Point* sub, int left, int mid, int right) {
    int length = (right - left) + 1;
    if(2 < length) {
        mergeSort(point, sub, left, (left+mid)/2, mid);
        mergeSort(point, sub, mid+1, ((mid+1)+right)/2, right);
    }

    merge(point, sub, left, mid, right);
}

void merge(Point* point, Point* sub, int left, int mid, int right) {
    int i=left, j=mid+1, k=0;

    while(i<=mid && j<=right) {
        if(point[i].y < point[j].y) {
            sub[k].x = point[i].x;
            sub[k].y = point[i].y;
            k++; i++;
        }
        else if(point[i].y > point[j].y) {
            sub[k].x = point[j].x;
            sub[k].y = point[j].y;
            k++; j++;
        }
        else {
            if(point[i].x < point[j].x) {
                sub[k].x = point[i].x;
                sub[k].y = point[i].y;
                k++; i++;
            }
            else {
                sub[k].x = point[j].x;
                sub[k].y = point[j].y;
                k++; j++;
            }
        }
    }

    while(i<=mid ^ j<=right) {
        if(i <= mid) {
            sub[k].x = point[i].x;
            sub[k].y = point[i].y;
            k++; i++;
        }
        else {
            sub[k].x = point[j].x;
            sub[k].y = point[j].y;
            k++; j++;
        }
    }

    k = 0;
    for(int i=left; i<=right; i++) {
        point[i].x = sub[k].x;
        point[i].y = sub[k].y;
        k++;
    }
}