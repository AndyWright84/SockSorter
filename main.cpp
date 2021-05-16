#include <iostream>
#include <vector>
#include <queue>
#include <sstream>


using namespace std;

void print(priority_queue<int> sockBox);
void sockPairing(int numSocks, string socks);
void unitTest();

int main()
{
    unitTest();
    
    
    return 0;
}

void print(priority_queue<int> sockBox)
{
    while(!sockBox.empty())
    {
        cout << sockBox.top() << " ";
        sockBox.pop();
    }
    cout << endl;
}

void unitTest()
{
    int elements = 13;
    string s1 {"4 5 2 3 5 1 8 6 3 3 3 2 1"}; //5 pairs
    sockPairing(elements, s1);
}

void sockPairing(int numSocks, string socks)
{
    //int numSocks = 0;
    priority_queue<int> sockBox;
    //cin >> numSocks;
    stringstream ss {socks};
    
    for(int i = 0;i < numSocks; i++)
    {
        int temp = 0;
        ss >> temp;
        sockBox.push(temp);
    }
    print(sockBox);
    
    int numPairs = 0;
    int lastNum = 0;
    int sockCount = 1;
    
    for(int i = 0; i < numSocks; i++)
    {
        cout << sockBox.top() << endl;
        
        if(sockBox.top() == lastNum)
        {
            
            sockCount++;
            sockBox.pop();
 //           cout << sockCount << endl;
        }
        else
        {
            
            lastNum = sockBox.top();
  //          cout << lastNum << endl;
            sockBox.pop();
            numPairs += (sockCount/2);
            sockCount = 1;
        }
    }
    cout << numPairs << endl;
}