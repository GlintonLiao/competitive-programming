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