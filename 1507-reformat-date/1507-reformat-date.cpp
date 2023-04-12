class Solution {
public:
    string reformatDate(string date) {
        istringstream ss(date);
        string day, mon, year, m;
        ss >> day >> mon >> year;
        string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        for (int i = 0; i < 12; ++i) {
            if (months[i] == mon) {
                m = to_string(i + 1);
                if (m.size() == 1) m = "0" + m;
                break;
            }
        }
        string d = to_string(stoi(day));
        return year + "-" + m + "-" + (d.size() == 1? "0" + d : d);
    }
};