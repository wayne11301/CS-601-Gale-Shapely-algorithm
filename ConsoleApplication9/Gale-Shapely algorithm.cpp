
#include <iostream>
#include<string>

using namespace std;

int preference[10][5] = { { 6,5,8,9,7 }, { 8,6,5,7,9 },{6,9,7,8,5},{5,8,7,6,9},{6,8,5,9,7}, {4,0,1,3,2},{2,1,3,0,4}, {1,2,3,4,0}, {0, 4,3,2,1}, {3,1,4,2,0} };
string namelist[10] = { "Victor", "Wyatt","Xavier","Yancey","Zeus","Amy","Bertha","Clare", "Diane"," Erika" };

bool switch_partner(int preference[10][5], int woman, int man, int to_compare) {
    for (int i = 0; i < 5; i++) {
        if (preference[woman][i] == to_compare) return true;
        if (preference[woman][i] == man) return false;
    }
}

void matching(int preference[10][5]) {
    int partner[5];
    bool engaged_women[5];
    int free = 5;

    //initilize
    for (int i = 0; i < 5; i++) {
        partner[i] = -1;
        engaged_women[i] = false;
    }

    while (free > 0) {
        int woman;
        for (woman = 5; woman < 10; woman++) {
            if (engaged_women[woman-5] == false) break;
        }

        for (int i = 0; i < 5 ; i++) {
            if (engaged_women[woman-5] != false) continue;
            int man = preference[woman][i];
            if (partner[man ] == -1) {
                partner[man ] = woman;
                engaged_women[woman-5] = true;
                free--;
            }
            else {
                int to_compare = partner[man];
                if (switch_partner(preference, woman , man, to_compare) == true) {
                    partner[man] = woman;
                    engaged_women[woman- 5] = true;
                    engaged_women[to_compare] = false;
                }
            }
        }
    }
    cout << "The final matching using GS algorithm is:" << endl;
    cout << "   Man    Woman" << endl;
    for (int i = 0; i < 5; i++)
        cout << "  "<<namelist[i] << "   " << namelist[partner[i]] << endl;
}
int main()
{
    matching(preference);
}


