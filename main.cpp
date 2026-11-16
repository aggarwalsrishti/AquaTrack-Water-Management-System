#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Household
{
private:
    int id;
    string name;
    double waterUsed;

public:
    Household(int i, string n, double w)
    {
        id = i;
        name = n;
        waterUsed = w;
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    double getWaterUsed()
    {
        return waterUsed;
    }

    void updateUsage(double amount)
    {
        waterUsed = amount;
    }

    void display()
    {
        cout << "\nHousehold ID: " << id;
        cout << "\nName: " << name;
        cout << "\nWater Used: " << waterUsed << " litres\n";
    }
};

class LeakReport
{
private:
    int reportId;
    string location;
    string problem;
    string status;

public:
    LeakReport(int id, string loc, string prob)
    {
        reportId = id;
        location = loc;
        problem = prob;
        status = "Pending";
    }

    int getReportId()
    {
        return reportId;
    }

    void updateStatus(string newStatus)
    {
        status = newStatus;
    }

    void display()
    {
        cout << "\nReport ID: " << reportId;
        cout << "\nLocation: " << location;
        cout << "\nProblem: " << problem;
        cout << "\nStatus: " << status << "\n";
    }
};

class AquaTrack
{
private:
    vector<Household> households;
    vector<LeakReport> reports;
    int nextReportId;

public:
    AquaTrack()
    {
        nextReportId = 1;
    }

    void addHousehold()
    {
        int id;
        string name;
        double usage;

        cout << "Enter household ID: ";
        cin >> id;

        for (int i = 0; i < (int)households.size(); i++)
        {
            if (households[i].getId() == id)
            {
                cout << "This household ID already exists.\n";
                return;
            }
        }

        cout << "Enter household name: ";
        getline(cin >> ws, name);

        cout << "Enter water used today (litres): ";
        cin >> usage;

        if (usage < 0)
        {
            cout << "Water usage cannot be negative.\n";
            return;
        }

        households.push_back(Household(id, name, usage));
        cout << "Household added successfully.\n";
    }

    void displayHouseholds()
    {
        if (households.empty())
        {
            cout << "No household records available.\n";
            return;
        }

        for (int i = 0; i < (int)households.size(); i++)
        {
            households[i].display();
        }
    }

    void checkHighUsage()
    {
        const double LIMIT = 500;
        bool found = false;

        for (int i = 0; i < (int)households.size(); i++)
        {
            if (households[i].getWaterUsed() > LIMIT)
            {
                households[i].display();
                cout << "Alert: Usage is above 500 litres.\n";
                found = true;
            }
        }

        if (!found)
            cout << "No household is above the 500-litre limit.\n";
    }

    void reportLeak()
    {
        string location, problem;

        cout << "Enter leakage location: ";
        getline(cin >> ws, location);

        cout << "Describe the leakage: ";
        getline(cin, problem);

        reports.push_back(LeakReport(nextReportId, location, problem));
        cout << "Leak reported successfully. Report ID: " << nextReportId << "\n";
        nextReportId++;
    }

    void displayReports()
    {
        if (reports.empty())
        {
            cout << "No leakage reports available.\n";
            return;
        }

        for (int i = 0; i < (int)reports.size(); i++)
        {
            reports[i].display();
        }
    }

    void updateReportStatus()
    {
        int id;
        string status;
        bool found = false;

        cout << "Enter report ID: ";
        cin >> id;

        for (int i = 0; i < (int)reports.size(); i++)
        {
            if (reports[i].getReportId() == id)
            {
                cout << "Enter new status (Pending / In Progress / Resolved): ";
                getline(cin >> ws, status);
                reports[i].updateStatus(status);
                cout << "Report status updated.\n";
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Report ID not found.\n";
    }

    void saveReport()
    {
        ofstream file("aquatrack_summary.txt");

        if (!file)
        {
            cout << "Unable to create summary file.\n";
            return;
        }

        file << "AQUATRACK - HOUSEHOLD WATER USAGE\n";
        file << "--------------------------------\n";

        for (int i = 0; i < (int)households.size(); i++)
        {
            file << "ID: " << households[i].getId()
                 << ", Name: " << households[i].getName()
                 << ", Usage: " << households[i].getWaterUsed()
                 << " litres\n";
        }

        file << "\nLEAKAGE REPORTS\n";
        file << "---------------\n";

        for (int i = 0; i < (int)reports.size(); i++)
        {
            file << "Report " << reports[i].getReportId() << "\n";
            // Full report details are displayed in the application.
        }

        file.close();
        cout << "Summary saved in aquatrack_summary.txt\n";
    }
};

int main()
{
    AquaTrack system;
    int choice;

    do
    {
        cout << "\n========== AQUATRACK ==========\n";
        cout << "1. Add Household\n";
        cout << "2. Display Households\n";
        cout << "3. Check Excessive Water Usage\n";
        cout << "4. Report Water Leakage\n";
        cout << "5. Display Leakage Reports\n";
        cout << "6. Update Leakage Report Status\n";
        cout << "7. Save Summary to File\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addHousehold();
            break;
        case 2:
            system.displayHouseholds();
            break;
        case 3:
            system.checkHighUsage();
            break;
        case 4:
            system.reportLeak();
            break;
        case 5:
            system.displayReports();
            break;
        case 6:
            system.updateReportStatus();
            break;
        case 7:
            system.saveReport();
            break;
        case 0:
            cout << "Thank you for using AquaTrack.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
