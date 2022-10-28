class Solution {
 public:
  string reformatDate(string date) {
    stringstream ss(date);
    string day;
    string mon;
    int year = 0;
    ss >> day;
    ss >> mon;
    ss >> year;
    
    //int day_size = day.size();
    day.erase(day.size() - 1);
    day.erase(day.size() - 1);
    if (day.size() == 1) day = "0" + day;
    //int day_int = stoi(day);
    
    if (mon == "Jan") mon = "01";
    else if (mon == "Feb") mon = "02";
    else if (mon == "Mar") mon = "03";
    else if (mon == "Apr") mon = "04";
    else if (mon == "May") mon = "05";
    else if (mon == "Jun") mon = "06";
    else if (mon == "Jul") mon = "07";
    else if (mon == "Aug") mon = "08";
    else if (mon == "Sep") mon = "09";
    else if (mon == "Oct") mon = "10";
    else if (mon == "Nov") mon = "11";
    else if (mon == "Dec") mon = "12";
    
    string output = to_string(year) + "-" + mon + "-" + day;
    return output;
  }
};

/* Runtime: 2 ms, faster than 42.63% of C++ online submissions for Reformat Date.
 * Memory Usage: 6 MB, less than 67.07% of C++ online submissions for Reformat Date.
 */

