#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    string CNP;
    cout << "Introduceti CNP-ul (13 cifre): ";
    cin >> CNP;

    
    string sex;
    if (CNP[0] == '2' || CNP[0] == '4' || CNP[0] == '6') {
        sex = "Feminin";
    }
    else {
        sex = "Masculin";
    }

    
    int an, luna, zi;
    if (CNP[0] == '1' || CNP[0] == '2') {
        an = 1900 + stoi(CNP.substr(1, 2));
    }
    else {
        an = 2000 + stoi(CNP.substr(1, 2));
    }
    luna = stoi(CNP.substr(3, 2));
    zi = stoi(CNP.substr(5, 2));

    
    time_t now = time(0);
    tm* today = localtime(&now);
    int varsta = today->tm_year + 1900 - an;
    if (today->tm_mon < luna || (today->tm_mon == luna && today->tm_mday < zi)) {
        varsta--;
    }

    
    cout << "Sex: " << sex << endl;
    cout << "Data nasterii: " << zi << "." << luna << "." << an << endl;
    cout << "Varsta: " << varsta << " ani" << endl;

    return 0;
}

