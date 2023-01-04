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

/*
    HashMap setting empty value
*/
void work(int item) {
    unordered_map<int, int> mp;
    mp[item]; // no need to set it to 0
}

/*
    Deconstructing array or pair
*/
pair<int, int> cur = {1, 2};
auto [x, y] = cur;
// x is now 1, y is now 2
// no need of cur.first and cur.second

array<int, 3> arr = {1, 0, -1};
auto [a, b, c] = arr;
// a is now 1, b is now 0, c is now -1


/*
    Debug
*/
#define deb(x) cout << #x << " " << x 
int ten = 10;
deb(ten); // prints "ten = 10"


/*
    Even powerful debug marco
*/
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values << endl, delim = ", "));
}

int xx = 3, yy = 10, xxyy = 103;
deb(xx); // prints "xx = 3"
deb(xx, yy, xxyy); // prints "xx, yy, xxyy = 3, 10, 103"


/*
    More Powerful Debug Macro with input and output
*/
template<typename F>
auto debug_func(const F& func) {
    return [func](auto &&...args) { // forward reference
        cout << "input = ";
        printer(args...);
        auto res = func(forward<decltype(args)>(args)...);
        cout << "res = " << res << endl;
        return res;
    };
}

debug_func(pow)(2, 3);
// ^ this automatically prints
// input = 2 3 res = 8