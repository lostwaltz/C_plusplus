#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(void)
{
    vector<string> participant = { "Leo", "Viter", "Sam", "Sara"};
    vector<string> completion = { "Leo", "Sam", "Sara"};

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    vector<string>::iterator iter_part;
    vector<string>::iterator iter_comp = completion.begin();
    for (iter_part = participant.begin(); iter_part != participant.end() - 1; iter_part++)
    {
        if (*iter_part != *iter_comp)
        {
            cout << *iter_part << endl;

            return 0;
        }
        iter_comp++;
    }
    iter_part = participant.end() - 1;
    cout << *iter_part << endl;
    

    return 0;
}