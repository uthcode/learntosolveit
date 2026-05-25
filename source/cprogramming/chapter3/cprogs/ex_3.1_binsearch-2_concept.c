/* Concept: binary search — compute mid first, then loop */
#include <stdio.h>
int binsearch(int x, int v[], int n) {
    int low = 0, high = n - 1, mid;
    mid = (low + high) / 2;
    while (low < high && x != v[mid]) {
        if (x > v[mid]) low = mid + 1;
        else high = mid - 1;
        mid = (low + high) / 2;
    }
    return (x == v[mid]) ? mid : -1;
}
int main(void) {
    int arr[] = {2, 4, 6, 9, 15};
    printf("%d\n", binsearch(9, arr, 5));   /* found at index 3 */
    printf("%d\n", binsearch(5, arr, 5));   /* not found: -1 */
    return 0;
}
