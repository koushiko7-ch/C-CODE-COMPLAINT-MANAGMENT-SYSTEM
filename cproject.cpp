#include <iostream>
#include <string>
using namespace std;

class Complaint
{
private:
    int id;
    string name;
    string phone;
    string problem;
    string status;

public:

    // Default Constructor
    Complaint()
    {  
        id = 0;
        status = "Pending";
    }

    // Register Complaint
    void registerComplaint(int newId)
    {
        id = newId;

        cout << "\nComplaint ID : " << id;

        cout << "\nEnter Name : ";
        cin >> name;

        cout << "Enter Phone : ";
        cin >> phone;

        cout << "Enter Complaint : ";
        cin >> problem;

        status = "Pending";

        cout << "\n================================";
        cout << "\n Complaint Registered Successfully!";
        cout << "\n Complaint ID : " << id;
        cout << "\n Status       : " << status;
        cout << "\n================================\n";
    }

    // Display Complaint
    void display()
    {
        cout << "\n-----------------------------";
        cout << "\nComplaint ID : " << id;
        cout << "\nName         : " << name;
        cout << "\nPhone        : " << phone;
        cout << "\nComplaint    : " << problem;
        cout << "\nStatus       : " << status;
        cout << "\n-----------------------------";
    }

    // Search Complaint
    bool search(int searchId)
    {
        return id == searchId;
    }

    // Update Status - Principal only
    void updateStatus()
    {
        int choice;

        cout << "\nCurrent Status : " << status;

        cout << "\n\n1. Pending";
        cout << "\n2. Resolved";

        cout << "\nEnter New Status : ";
        cin >> choice;

        if(choice == 1)
        {
            status = "Pending";
        }
        else if(choice == 2)
        {
            status = "Resolved";
        }
        else
        {
            cout << "\nInvalid Choice!";
            return;
        }

        cout << "\n================================";
        cout << "\n       STATUS UPDATED";
        cout << "\n================================";
        cout << "\nComplaint ID : " << id;
        cout << "\nName         : " << name;
        cout << "\nStatus       : " << status;1
        cout << "\n================================\n";
    }

    // User checks status
    void checkStatus()
    {
        cout << "\n================================";
        cout << "\n       COMPLAINT STATUS";
        cout << "\n================================";
        cout << "\nComplaint ID : " << id;
        cout << "\nName         : " << name;
        cout << "\nStatus       : " << status;
        cout << "\n================================\n";
    }

    // Get Status
    string getStatus()
    {
        return status;
    }
};


// PRINCIPAL DASHBOARD
void principalDashboard(Complaint c[], int count)
{
    int choice;
    int id;

    do
    {
        cout << "\n\n================================";
        cout << "\n      PRINCIPAL DASHBOARD";
        cout << "\n================================";

        cout << "\n1. View All Complaints";
        cout << "\n2. Search Complaint";
        cout << "\n3. Update Complaint Status";
        cout << "\n4. Analyse Complaints";
        cout << "\n5. Logout";

        cout << "\n\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {

        // PRINCIPAL VIEW
        case 1:
        {
            if(count == 0)
            {
                cout << "\nNo Complaints Available!";
            }
            else
            {
                cout << "\n===== ALL COMPLAINTS =====";

                for(int i = 0; i < count; i++)
                {
                    c[i].display();
                }
            }

            break;
        }


        // PRINCIPAL SEARCH
        case 2:
        {
            bool found = false;

            cout << "\nEnter Complaint ID : ";
            cin >> id;

            for(int i = 0; i < count; i++)
            {
                if(c[i].search(id))
                {
                    cout << "\nComplaint Found!";
                    c[i].display();

                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "\nComplaint Not Found!";
            }

            break;
        }


        // UPDATE STATUS
        case 3:
        {
            bool found = false;

            cout << "\nEnter Complaint ID : ";
            cin >> id;

            for(int i = 0; i < count; i++)
            {
                if(c[i].search(id))
                {
                    c[i].updateStatus();

                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "\nComplaint Not Found!";
            }

            break;
        }


        // ANALYSE
        case 4:
        {
            int pending = 0;
            int resolved = 0;

            for(int i = 0; i < count; i++)
            {
                if(c[i].getStatus() == "Pending")
                {
                    pending++;
                }
                else if(c[i].getStatus() == "Resolved")
                {
                    resolved++;
                }
            }

            cout << "\n================================";
            cout << "\n      COMPLAINT ANALYSIS";
            cout << "\n================================";
            cout << "\nTotal Complaints    : " << count;
            cout << "\nPending Complaints  : " << pending;
            cout << "\nResolved Complaints : " << resolved;
            cout << "\n================================";

            break;
        }


        // LOGOUT
        case 5:
            cout << "\nPrincipal Logged Out!";
            break;


        default:
            cout << "\nInvalid Choice!";
        }

    } while(choice != 5);
}


// MAIN FUNCTION
int main()
{
    Complaint c[50];

    int choice;
    int count = 0;
    int nextId = 101;

    do
    {
        cout << "\n\n================================";
        cout << "\n   COMPLAINT MANAGEMENT SYSTEM";
        cout << "\n================================";

        cout << "\n1. Register Complaint";
        cout << "\n2. View Complaints";
        cout << "\n3. Search Complaint";
        cout << "\n4. Check Complaint Status";
        cout << "\n5. Principal Login";
        cout << "\n6. Exit";

        cout << "\n\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {

        // USER REGISTER
        case 1:
        {
            if(count < 50)
            {
                c[count].registerComplaint(nextId);

                nextId++;
                count++;
            }
            else
            {
                cout << "\nComplaint Limit Reached!";
            }

            break;
        }


        // USER VIEW ALL COMPLAINTS
        case 2:
        {
            if(count == 0)
            {
                cout << "\nNo Complaints Available!";
            }
            else
            {
                cout << "\n\n===== ALL COMPLAINTS =====";

                for(int i = 0; i < count; i++)
                {
                    c[i].display();
                }
            }

            break;
        }


        // USER SEARCH COMPLAINT
        case 3:
        {
            int id;
            bool found = false;

            cout << "\nEnter Complaint ID to Search : ";
            cin >> id;

            for(int i = 0; i < count; i++)
            {
                if(c[i].search(id))
                {
                    cout << "\n===== COMPLAINT FOUND =====";
                    c[i].display();

                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "\nComplaint Not Found!";
            }

            break;
        }


        // USER CHECK STATUS
        case 4:
        {
            int id;
            bool found = false;

            cout << "\nEnter Your Complaint ID : ";
            cin >> id;

            for(int i = 0; i < count; i++)
            {
                if(c[i].search(id))
                {
                    c[i].checkStatus();

                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "\nComplaint Not Found!";
            }

            break;
        }


        // PRINCIPAL LOGIN
        case 5:
        {
            string username;
            string password;

            cout << "\n================================";
            cout << "\n       PRINCIPAL LOGIN";
            cout << "\n================================";

            cout << "\nEnter Username : ";
            cin >> username;

            cout << "Enter Password : ";
            cin >> password;

            if(username == "principal" && password == "1234")
            {
                cout << "\nLogin Successful!";

                principalDashboard(c, count);
            }
            else
            {
                cout << "\nInvalid Username or Password!";
            }

            break;
        }

        // EXIT
        case 6:
            cout << "\nThank You!";
            break;


        default:
            cout << "\nInvalid Choice!";
        }
    } while(choice != 6);

    return 0;
}
