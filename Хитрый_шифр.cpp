#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;

string shifr(string fiodmy) {
    string prev;
    for (char c : fiodmy) {
        if (c == ',') {
            continue;
        }
        else prev += c;
    } //cout << prev;

    int sum_digits = 0;
    int sum_letters;
    unordered_set <char> s;
    int num_first_letter = (prev[0] >= 'a') ? (prev[0] - 'a' + 1) : (prev[0] - 'A' + 1);

    for (int i = 0; i < prev.length() - 4; i++) {
        if (prev[i] >= '0' && prev[i] <= '9') {
            sum_digits += prev[i] - '0';
        }
        else {
            s.insert(prev[i]);
        }
    } //cout<<'\n'<<s.size()<<' '<<sum_letters<<' '<<num_first_letter;
    sum_letters = s.size();

    int res = num_first_letter * 256 + sum_digits * 64 + sum_letters;

    stringstream stream;
    stream << hex << res;
    string result(stream.str());
    if (result.length() > 3) result.erase(0, result.length() - 3);
    if (result.length() < 3) result.insert(0, 1, '0');
    for (char& c : result) {
        if (c >= 'a') c -= 32;
    } //cout<<result;
    return result;
}

int main() {
    vector < std::string > candidates;
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; ++i) {
        std::string candidateInfo;
        std::getline(std::cin, candidateInfo);
        candidates.push_back(candidateInfo);
    }
    for (string& res : candidates) {
        cout << shifr(res) << ' ';
    }

}