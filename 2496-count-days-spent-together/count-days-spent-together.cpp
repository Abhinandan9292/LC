class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int a1 = stoi(arriveAlice.substr(0, 2));
        int a2 = stoi(arriveAlice.substr(3, 2));
        int a3 = stoi(leaveAlice.substr(0, 2));
        int a4 = stoi(leaveAlice.substr(3, 2));

        int b1 = stoi(arriveBob.substr(0, 2));
        int b2 = stoi(arriveBob.substr(3, 2));
        int b3 = stoi(leaveBob.substr(0, 2));
        int b4 = stoi(leaveBob.substr(3, 2));

        int startMonth = max(a1, b1);
        int endMonth = min(a3, b3);

        if (startMonth > endMonth) return 0;

        int startDay, endDay;

        if (a1 > b1) startDay = a2;
        else if (b1 > a1) startDay = b2;
        else startDay = max(a2, b2);

        if (a3 < b3) endDay = a4;
        else if (b3 < a3) endDay = b4;
        else endDay = min(a4, b4);

        if (startMonth == endMonth) {
            if (startDay > endDay) return 0;
            return endDay - startDay + 1;
        }

        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int ans = days[startMonth] - startDay + 1;

        for (int i = startMonth + 1; i < endMonth; i++) {
            ans += days[i];
        }

        ans += endDay;

        return ans;
    }
};