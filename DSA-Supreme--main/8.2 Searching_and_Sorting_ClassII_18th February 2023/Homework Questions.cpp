#include <iostream> // for input/output operations // needed for cout, endl
#include <cmath>    // for mathematical functions // not used directly here, but often for sqrt
#include <vector>   // for using vector container // used for dynamic arrays
using namespace std; // use standard namespace // avoids std:: prefix

// 1) Why is 11 digits of precision not acceptable in case of square root using binary search?
void explainPrecision() {
    cout << "Calculating square roots with binary search uses floating point types (float/double)." << endl; // explains float/double usage // context for precision
    cout << "Floating point types have limited precision (double: ~15-16 decimal digits)." << endl; // states double precision // highlights limitation
    cout << "Trying to guarantee 11 digits after the decimal point is unreliable due to rounding errors and how floats are stored." << endl; // mentions rounding errors // float storage issues
    cout << "For most real-world code, 6-7 digits of precision is considered safe for double." << endl; // practical advice // safe precision range
    cout << "More info: https://stackoverflow.com/questions/2096346/why-should-i-not-use-double-equals-comparison-in-java" << endl; // reference link // further reading
}

// 2) Dry Run: Pivot and Search in Rotated Sorted Array
int findPivot(const vector<int>& arr) { // finds pivot in rotated array // returns index of pivot
    int n = arr.size(); // get size of array // used for bounds
    int l = 0, r = n-1; // initialize left and right pointers // binary search setup
    while(l < r) { // loop until left meets right // binary search loop
        int mid = l + (r-l)/2; // calculate mid index // avoids overflow
        if(mid < n-1 && arr[mid] > arr[mid+1]) return mid; // check if mid is pivot // compare with next element
        if(arr[l] <= arr[mid]) l = mid+1; // left part sorted, move right // update left pointer
        else r = mid; // right part unsorted, move left // update right pointer
    }
    return l; // return pivot index // l will be at pivot
}

int searchInRotated(const vector<int>& arr, int target) { // search target in rotated array // returns index or -1
    int n = arr.size(); // get array size // used for bounds
    int pivot = findPivot(arr); // find pivot index // split array
    int l, r; // declare left and right pointers // for binary search
    if(target >= arr[0] && target <= arr[pivot]) { // check if target in left part // compare with bounds
        l = 0; r = pivot; // search in left part // set search range
    } else { // target in right part // else case
        l = pivot+1; r = n-1; // search in right part // set search range
    }
    while(l <= r) { // binary search loop // until pointers cross
        int mid = l + (r-l)/2; // calculate mid index // avoids overflow
        if(arr[mid] == target) return mid; // found target // return index
        else if(arr[mid] < target) l = mid+1; // move right if mid less // update left pointer
        else r = mid-1; // move left if mid greater // update right pointer
    }
    return -1; // target not found // return -1
}

// 3) Search in a nearly sorted array in O(log n)
int searchNearlySorted(int arr[], int n, int target) { // search in nearly sorted array // returns index or -1
    int l = 0, r = n-1; // initialize left and right pointers // binary search setup
    while(l <= r) { // loop until pointers cross // binary search loop
        int mid = l + (r-l)/2; // calculate mid index // avoids overflow
        if(arr[mid] == target) return mid; // check mid for target // return if found
        if(mid-1 >= l && arr[mid-1] == target) return mid-1; // check left neighbor // boundary check
        if(mid+1 <= r && arr[mid+1] == target) return mid+1; // check right neighbor // boundary check
        if(arr[mid] > target) r = mid-2; // move left, skip checked // update right pointer
        else l = mid+2; // move right, skip checked // update left pointer
    }
    return -1; // target not found // return -1
}

// 4) Division of two numbers using binary search
double divide(double a, double b, double precision = 1e-6) { // divide a by b using binary search // precision parameter
    double l = 0, r = a, ans = 0; // initialize left, right, answer // search range [0, a]
    while(r - l > precision) { // loop until desired precision // binary search loop
        double mid = l + (r-l)/2; // calculate mid value // avoids overflow
        if(mid * b < a) { // check if mid*b less than a // need larger mid
            ans = mid; // update answer // store current mid
            l = mid; // move left pointer // search higher
        } else { // mid*b >= a // need smaller mid
            r = mid; // move right pointer // search lower
        }
    }
    return ans; // return approximate result // division result
}

// 5) Find odd occurring element using binary search
int findOdd(int arr[], int n) { // find element occurring odd times // array of pairs except one
    int l = 0, r = n-1; // initialize left and right pointers // binary search setup
    while(l < r) { // loop until left meets right // binary search loop
        int mid = l + (r-l)/2; // calculate mid index // avoids overflow
        if(mid % 2 == 0) { // check if mid is even // for pair alignment
            if(arr[mid] == arr[mid+1]) l = mid+2; // pair found, move right // update left pointer
            else r = mid; // odd element on left // update right pointer
        } else { // mid is odd // check previous element
            if(arr[mid] == arr[mid-1]) l = mid+1; // pair found, move right // update left pointer
            else r = mid-1; // odd element on left // update right pointer
        }
    }
    return arr[l]; // return odd occurring element // l points to answer
}

// Example usage
int main() {
    // 1) Precision explanation
    explainPrecision(); // call function to explain precision // prints explanation

    // 2) Pivot and search in rotated sorted array
    vector<int> arr = {6,7,8,9,1,2,3,4,5}; // example rotated array // for pivot/search
    int pivot = findPivot(arr); // find pivot index // call function
    cout << "Pivot index: " << pivot << ", value: " << arr[pivot] << endl; // print pivot info // output result
    int idx = searchInRotated(arr, 2); // search for 2 in array // call function
    cout << "Index of 2: " << idx << endl; // print index of 2 // output result

    // 3) Search in nearly sorted array
    int arr2[] = {10, 3, 40, 20, 50, 80, 70}; // nearly sorted array // for search
    int n2 = sizeof(arr2)/sizeof(arr2[0]); // calculate size of arr2 // number of elements
    int target2 = 40; // target value to search // in arr2
    int idx2 = searchNearlySorted(arr2, n2, target2); // search for target2 // call function
    cout << "Index of " << target2 << " in nearly sorted array: " << idx2 << endl; // print result // output index

    // 4) Division using binary search
    double a = 10, b = 3; // values to divide // a divided by b
    cout << "10 / 3 (approx): " << divide(a, b) << endl; // print division result // call divide

    // 5) Find odd occurring element
    int arr3[] = {1,1,2,2,3,3,4,4,5}; // array with odd element // all others paired
    int n3 = sizeof(arr3)/sizeof(arr3[0]); // calculate size of arr3 // number of elements
    cout << "Odd occurring element: " << findOdd(arr3, n3) << endl; // print odd element // call function

    return 0; // indicate successful execution // end of main
}
