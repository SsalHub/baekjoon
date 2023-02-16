#include <stdio.h>

void mergeSort(int*, int*, int, int, int);
void merge(int*, int*, int, int, int);
bool findByBinaryTree(int*, int, int, int);

int main() {
    int n, m;
    int *arr, *sub;

    scanf("%d", &n);
    arr = new int[n];
    sub = new int[n];

    for(int i=0; i<n; i++) {
        scanf("%d", arr+i);
    }

    mergeSort(arr, sub, 0, (n-1)/2, n-1);

    scanf("%d", &m);

    for(int i=0; i<m; i++) {
        int input;
        scanf("%d", &input);
        if(findByBinaryTree(arr, 0, n-1, input)) printf("1\n");
        else printf("0\n");
    }

    delete []arr;
    delete []sub;

    return 0;
}

void mergeSort(int* arr, int* sub, int left, int mid, int right) {
    int length = (right - left) + 1;
    if(2 < length) {
        mergeSort(arr, sub, left, (left+mid)/2, mid);
        mergeSort(arr, sub, mid+1, ((mid+1)+right)/2, right);
    }

    merge(arr, sub, left, mid, right);
}

void merge(int* arr, int* sub, int left, int mid, int right) {
    int i, j, k;

    i = left;
    j = mid + 1;
    k = 0;

    while(i <= mid && j <= right) {
        if(arr[i] < arr[j]) {
            sub[k++] = arr[i++];
        }
        else {
            sub[k++] = arr[j++];
        }
    }

    while(i <= mid ^ j <= right) {
        if(i <= mid) {
            sub[k++] = arr[i++];
        }
        else {
            sub[k++] = arr[j++];
        }
    }

    k = 0;
    for(int i=left; i<=right; i++) {
        arr[i] = sub[k++];
    }
}

bool findByBinaryTree(int* sorted, int left, int right, int data) {
    int mid = (left + right) / 2;
    bool _left, _right;
    if(sorted[mid] == data) return true;

    if(data < sorted[mid]) {
        if(left <= mid-1 && findByBinaryTree(sorted, left, mid-1, data)) return true;
    }
    else {
        if(mid+1 <= right && findByBinaryTree(sorted, mid+1, right, data)) return true;
    }

    return false;
}

#if 0
#include <stdio.h>
#include <string>//

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class BinaryTree {
    public:
        BinaryTree(int*, int);
        ~BinaryTree();
        bool isExist(int);
        void print(Node*, std::string);
    private:
        Node* root;
        void initBinaryTree(int*, Node*, int, int);
        void deleteAll(Node*);
};

void mergeSort(int*, int*, int, int, int);
void merge(int*, int*, int, int, int);

int main() {
    int n, m;
    int *arr, *sub;
    BinaryTree* btree;

    scanf("%d", &n);
    arr = new int[n];
    sub = new int[n];

    for(int i=0; i<n; i++) {
        scanf("%d", arr+i);
    }

    mergeSort(arr, sub, 0, (n-1)/2, n-1);

    printf("arr : [");
    for(int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");

    btree = new BinaryTree(arr, n);

    scanf("%d", &m);

    for(int i=0; i<m; i++) {
        int input;
        scanf("%d", &input);
        if(btree->isExist(input)) printf("1\n");
        else printf("0\n");
    }

    delete []arr;
    delete []sub;
    delete btree;

    return 0;
}

BinaryTree::BinaryTree(int* sortedArray, int size) {
    root = NULL;
    initBinaryTree(sortedArray, root, 0, size-1);
    print(root, "root : ");
}

BinaryTree::~BinaryTree() {
    deleteAll(root);
}

bool BinaryTree::isExist(int data) {
    Node* search = root;
    while(search != NULL) {
        if(search->data == data) {
            return true;
        }
        else if(search->data < data) {
            search = search->right;
        }
        else {
            search = search->left;
        }
    }
    return false;
}

void BinaryTree::print(Node* node, std::string str) {
    printf("%s%d\n", str, node->data);
    if(node->left != NULL) print(node->left, "left : ");
    if(node->right != NULL) print(node->right, "right : ");
}
    
void BinaryTree::initBinaryTree(int* arr, Node* parent, int left, int right) {
    if(left > right) return;

    int mid = (left + right) / 2;
    Node* node = new Node();
    node->data = arr[mid];
    node->left = NULL;
    node->right = NULL;

    if(parent == NULL) {
        root = node;
        parent = root;
    }
    else if(parent->data < node->data) {
        parent->right = node;
        parent = parent->right;
    }
    else if(parent->data > node->data) {
        parent->left = node;
        parent = parent->left;
    } else {
        int size = right - left + 1;
        int* newArr = new int[size];
        int k = left;
        for(int i=0; i<size; i++) {
            if(k != mid) newArr[i] = arr[k++];
        }
        initBinaryTree(newArr, parent, 0, size-1);
        delete []newArr;
        return;

    }
    initBinaryTree(arr, parent, left, mid-1);
    initBinaryTree(arr, parent, mid+1, right);
}
        
void BinaryTree::deleteAll(Node* node) {
    if(node->left != NULL) deleteAll(node->left);
    if(node->right != NULL) deleteAll(node->right);
    delete node;
}

void mergeSort(int* arr, int* sub, int left, int mid, int right) {
    int length = (right - left) + 1;
    if(2 < length) {
        mergeSort(arr, sub, left, (left+mid)/2, mid);
        mergeSort(arr, sub, mid+1, ((mid+1)+right)/2, right);
    }

    merge(arr, sub, left, mid, right);
}

void merge(int* arr, int* sub, int left, int mid, int right) {
    int i, j, k;

    i = left;
    j = mid + 1;
    k = 0;

    while(i <= mid && j <= right) {
        if(arr[i] < arr[j]) {
            sub[k++] = arr[i++];
        }
        else {
            sub[k++] = arr[j++];
        }
    }

    while(i <= mid ^ j <= right) {
        if(i <= mid) {
            sub[k++] = arr[i++];
        }
        else {
            sub[k++] = arr[j++];
        }
    }

    k = 0;
    for(int i=left; i<=right; i++) {
        arr[i] = sub[k++];
    }
}
#endif