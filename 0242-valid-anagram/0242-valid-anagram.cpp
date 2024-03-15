#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#define all(v)      ((v).begin()), ((v).end())
#define rall(v)     ((v).rbegin()), ((v).rend())
#define fori(i,x,n) for(int i=x; i<n; i++)
#define forn(i,x,n) for(int i=x; i>n; i--)
#define gcd(a,b)    __gcd(a,b)//O(logN)//
#define lcm(a,b)    ((a/gcd(a,b))*b) //O(log(min(a,b)))//
#define unq(v)      sort(all(v));v.resize(distance(v.begin(),unique(v.begin(), v.end())));
//#define int         long long
#define MOD         1000000007
#define fast        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pii         pair<int,int>
#define vi          vector<int>
#define pr(v)       for(auto i:v) cout<<i<<" ";cout<<endl;
#define sc(v)       fori(i,0,v.size()) cin>>v[i];
#define yes         cout<<"YES"<<endl;
#define no          cout<<"NO"<<endl;
#define clr(v,x)    memset(v,x,sizeof v);
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};