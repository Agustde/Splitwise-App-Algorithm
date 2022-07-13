#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<set>
#include<map>
using namespace std;
class person_compare
{
    public:
    bool operator()(pair<string,int> p1,pair<string,int>p2)
    {
        return p1.second<p2.second;
    }
};

int main()
{
    int nooftransaction;
    int totalnofriends;
    cin>>nooftransaction>>totalnofriends;
    map<string,int> net;
    string name1,name2;
    int amount;
    while(nooftransaction)
    {
        cin>>name1>>name2;
        cin>>amount;
        if(net.count(name1)==0)
        {
            net[name1]=0;
        }
        if(net.count(name2)==0)
        {
            net[name2]=0;
        }
        net[name1]-=amount;
        net[name2]+=amount;
    }

    multiset<pair< string,int>,person_compare>mp;
    for(auto pr:net)
    {
        string person=pr.first;
        int amo=pr.second;

        if(net[person]!=0)
        {
            mp.insert(make_pair(person,amo));
        }
    }

    int count=0;
    while(!mp.empty())
    {
        auto start=mp.begin();
        auto end= prev(mp.end());

        int debit=start->second;
        string debit_person=start->first;

        int credit=end->second;
        string credit_person=end->first;

         mp.erase(start);
         mp.erase(end);
        int settleamount=min(-debit,credit);

        debit+=settleamount;
        credit-=settleamount;

        cout<<debit_person<<"will pay"<<settleamount<<"to"<<credit_person<<endl;

        if(debit!=0)
        {
            mp.insert(make_pair(debit_person,debit));

        }
         if(credit!=0)
        {
            mp.insert(make_pair(credit_person,credit));
            
        }
        count++;
     }
     cout<<"No. of transaction :"<<count;
     return 0;


}