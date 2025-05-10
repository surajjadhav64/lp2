#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    float attendance;
    float punctuality;
    float taskCompletion;
    float teamwork;
    float initiative;
};

float calculateAverage(const Employee& emp) {
    return (emp.attendance + emp.punctuality + emp.taskCompletion + emp.teamwork + emp.initiative) / 5.0;
}

string evaluatePerformance(float avgScore) {
    if (avgScore >= 8.5) return "Excellent";
    else if (avgScore >= 7.0) return "Good";
    else if (avgScore >= 5.0) return "Average";
    else return "Needs Improvement";
}

void getInput(Employee &emp) {
    cout << "Enter employee name: ";
    getline(cin, emp.name);

    cout << "Enter score (0-10) for Attendance: ";
    cin >> emp.attendance;
    cout << "Enter score (0-10) for Punctuality: ";
    cin >> emp.punctuality;
    cout << "Enter score (0-10) for Task Completion: ";
    cin >> emp.taskCompletion;
    cout << "Enter score (0-10) for Teamwork: ";
    cin >> emp.teamwork;
    cout << "Enter score (0-10) for Initiative: ";
    cin >> emp.initiative;

    cin.ignore(); // flush input buffer
}

int main() {
    char cont;

    do {
        Employee emp;
        getInput(emp);

        float avg = calculateAverage(emp);
        string result = evaluatePerformance(avg);

        cout << "\n--- Performance Summary ---\n";
        cout << "Employee: " << emp.name << endl;
        cout << "Average Score: " << avg << "/10" << endl;
        cout << "Overall Evaluation: " << result << endl;
        cout << "---------------------------\n";

        cout << "\nEvaluate another employee? (y/n): ";
        cin >> cont;
        cin.ignore(); // flush newline for next loop
    } while (cont == 'y' || cont == 'Y');

    return 0;
}
