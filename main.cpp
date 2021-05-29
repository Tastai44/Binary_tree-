#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

// Use for cheak that there are not any same values.
bool cheak(vector<int> v, int num){
    for(int j=0; j<v.size(); j++){
            while(num==v[j]){
                return false;
            }
        }
        return true;
}

int main()
{
    srand(time(0));
    int x; //is value that was deleted
    int num_in; // number of interfaces.
    int num_delete; // number of delete elements.
    int search; // is number for finding.
    vector<int> v;
    Tree<int> mytree;
    for(int i=0; i<10000; i++){
        x = rand();
        if(!cheak(v,x)){
            x = rand();
        }
        mytree.insert(x);
        v.push_back(x);
    }
    
    cout << "The height of the binary tree: "<<mytree.height()<<endl;
    
    mytree.clear();
    mytree.balance(v, 0, v.size() - 1);
    
    cout << "The height of the binary tree after was balanced: "<<mytree.height()<<endl;
    
    //Add interfaces
    cout << "How many elements would you like to add? \n";
    cin >> num_in;
    cout << "The number that were added: ";
    for (int f=0; f<num_in; f++){
        x = rand();
        if(!cheak(v,x)){
            x = rand();
        }
        mytree.insert(x);
        v.push_back(x);
        cout << x << " ";
    }
    cout << endl;
    cout << "What number would you like to know? \n";
    cin >> search;
    if(mytree.Binary_Search_Tree(search)){
        cout << search << " is exited."<<endl;
    }else{
        cout << search << " isn't exited."<<endl;
    }
    
    cout << "How many elements would you like to delete? \n";
    cin >> num_delete;
    for (int d=0; d<num_delete; d++){
        x = rand();
        if(!cheak(v,x)){
            mytree.findAndDelete(x);
            cout << x << " ";
        }    
    }
    cout << endl;
    return 0;
}
