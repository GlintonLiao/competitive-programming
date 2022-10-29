/*
    Get Formatted date
*/
string date = "2022-10-17";
int year, day, month;
sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);


int d[100010];
// memset to -1
memset(d, 0xff, sizeof d);
// memset to 0x3f3f3f3f
memset(d, 0x3f, sizeof d);


/*
    Self defined sort methods
    1. override < inside struct
    2. write a cmp function
*/
// 1
struct Edges {
    int a, b, w;
    bool operator<(const Edges& e) const {
        return w < e.w;
    }
} edges[m];
sort(edges, edges + m);

// 2
struct Edges {
    int a, b, w;
} edges[m];

bool cmp(const Edges& e1, const Edges& e2) {
    return e1.w < e2.w;
}
sort(edges, edges + m, cmp);


/*
    Sum all values in string or vector or array
*/
int getSum(vector<int>& arr) {
    return reduce(arr.begin(), arr.end());
}
