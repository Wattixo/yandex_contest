#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

struct logEntry {
    int time;
    int id;
    char status;
};

int toMinutes(int day, int hour, int minutes) {
    return (day - 1) * 1440 + hour * 60 + minutes;
}

int main() {
    vector<logEntry> logs;
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; ++i) {
        int day, hour, minutes, id;
        char status;
        cin >> day >> hour >> minutes >> id >> status;
        logs.push_back({ toMinutes(day, hour, minutes), id, status });
    }
    sort(logs.begin(), logs.end(), [](const logEntry& a, const logEntry& b) {return a.time < b.time; });
    map<int, int> startTime;
    map<int, int> totalTime;

    for (const auto& log : logs) {
        int id = log.id;
        char status = log.status;
        int time = log.time;

        if (status == 'A') {
            startTime[id] = time;
        }
        else if (status == 'C' || status == 'S') {
            if (startTime.count(id)) {
                totalTime[id] += time - startTime[id];
            }
        }
    }
    for (const auto& [id, time] : totalTime) {
        cout << time << " ";
    }
}