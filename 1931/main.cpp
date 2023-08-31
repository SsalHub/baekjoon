#include <stdio.h>

struct Graph {
    int x;
    int y;
    int length;
    struct Graph* next;
};

class SLL {
    public:
        void insert(Graph*);
        void clear();
        int getLength();
        void print();
    private:
        Graph* head;
        Graph* tail;
        int length;
};

void mergeSort(Graph*, Graph*, int, int, int);
void merge(Graph*, Graph*, int, int, int);
int getCount(Graph*, int, int);

int main() {
    const int DUMMY = -1;
    Graph *arr, *sub;
    int n, max;
    SLL* sll;

    scanf("%d", &n);
    arr = new Graph[n];
    sub = new Graph[n];


    for(int i=0; i<n; i++) {
        scanf("%d %d", &(arr[i].x), &(arr[i].y));
        arr[i].length = arr[i].y - arr[i].x;
    }

    mergeSort(arr, sub, 0, (n-1)/2, n-1);

    // printf("arr : [");
    // for(int i=0; i<n; i++) {
    //     printf("(%d %d %d), ", arr[i].x, arr[i].y, arr[i].length);
    // }

    sll = new SLL();
    max = 0;
    for(int i=0; i<n-max; i++) {
        for(int j=i; j<n; j++) {
            sll->insert(arr+j);
        }
        int len = sll->getLength();
        max = max < len ? len : max;

        sll->clear();
    }

    printf("%d\n", max);

    delete []arr;
    delete []sub;
    delete sll;

    return 0;
}

void mergeSort(Graph* arr, Graph* sub, int left, int mid, int right) {
    int length = (right - left) + 1;
    if(2 < length) {
        mergeSort(arr, sub, left, (left+mid)/2, mid);
        mergeSort(arr, sub, mid+1, ((mid+1)+right)/2, right);
    }

    merge(arr, sub, left, mid, right);
}

void merge(Graph* arr, Graph* sub, int left, int mid, int right) {
    int i, j, k;

    i = left;
    j = mid + 1;
    k = 0;

    while(i <= mid && j <= right) {
        if(arr[i].length < arr[j].length) {
            sub[k].x = arr[i].x;
            sub[k].y = arr[i].y;
            sub[k].length = arr[i].length;
            k++; i++; 
        }
        else if(arr[i].length > arr[j].length) {
            sub[k].x = arr[j].x;
            sub[k].y = arr[j].y;
            sub[k].length = arr[j].length;
            k++; j++;
        }
        else {
            if(arr[i].x < arr[j].x) {
                sub[k].x = arr[i].x;
                sub[k].y = arr[i].y;
                sub[k].length = arr[i].length;
                k++; i++; 
            }
            else {
                sub[k].x = arr[j].x;
                sub[k].y = arr[j].y;
                sub[k].length = arr[j].length;
                k++; j++;
            }
        }
    }

    while(i <= mid ^ j <= right) {
        if(i <= mid) {
            sub[k].x = arr[i].x;
            sub[k].y = arr[i].y;
            sub[k].length = arr[i].length;
            k++; i++;
        }
        else {
            sub[k].x = arr[j].x;
            sub[k].y = arr[j].y;
            sub[k].length = arr[j].length;
            k++; j++;
        }
    }

    k = 0;
    for(int i=left; i<=right; i++) {
        arr[i].x = sub[k].x;
        arr[i].y = sub[k].y;
        arr[i].length = sub[k].length;
        k++;
    }
}

int getCount(Graph* arr, int size, int idx) {
    int i = idx + 1;
    while(i < size && arr[idx].y > arr[i].x) {
        i++;
    }
    if(i >= size) return 1;
    return getCount(arr, size, i) + 1;
}

void SLL::insert(Graph* g) {
    g->next = NULL;

    if(head == NULL) {
        head = g;
        tail = g;
        length++;
        return;
    }

    Graph* prev = head;
    Graph* next = prev->next;
    if(g->y <= head->x) {
        g->next = head;
        head = g;
        length++;
        return;
    }
    while(next != NULL) {
        if(prev->y <= g->x && g->y <= next->x) {
            prev->next = g;
            g->next = next;
            length++;
            return;
        }
        prev = next;
        next = next->next;
    }
    if(tail->y <= g->x) {
        tail->next = g;
        tail = g;
        length++;
        return;
    }
}

void SLL::clear() {
    head = NULL;
    tail = NULL;
    length = 0;
}
        
int SLL::getLength() {
    return length;
}

void SLL::print() {
    Graph* search = head;
    int i = 0;
    while(search != NULL) {
        printf("[%d] SLL : (%d %d)\n", i++, search->x, search->y);
        search = search->next;
    }
}