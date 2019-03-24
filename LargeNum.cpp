#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class LargeNum
{
    public:
        vector<int> a;
        ~LargeNum();
        friend bool operator<(const LargeNum &fir,const LargeNum &sec);
        friend bool operator>(const LargeNum &fir,const LargeNum &sec);
        friend istream& operator >>(istream &in,LargeNum &x);
        friend ostream& operator <<(ostream &in,LargeNum &x);
        friend LargeNum operator + (LargeNum fir,LargeNum sec);
        friend LargeNum operator - (LargeNum fir,LargeNum sec);
        friend LargeNum operator * (LargeNum fir,LargeNum sec);
};

LargeNum::~LargeNum()
{
}

bool operator<(const LargeNum &fir,const LargeNum &sec)
{
    int i;
    if(fir.a.size()!=sec.a.size())
        return fir.a.size()<sec.a.size();
    else
    {
        for(i=0;i<fir.a.size();i++)
        {
            if(fir.a[i]!=sec.a[i])
                return fir.a.size()<sec.a.size();
            else
                return false;
        }
    }
}

bool operator>(const LargeNum &fir,const LargeNum &sec)
{
    int i;
    if(fir.a.size()!=sec.a.size())
        return fir.a.size()>sec.a.size();
    else
    {
        for(i=0;i<fir.a.size();i++)
        {
            if(fir.a[i]!=sec.a[i])
                return fir.a.size()>sec.a.size();
            else
                return false;
        }
    }
}

istream& operator >>(istream &in,LargeNum &x)
{
    int i;
    string s;
    in>>s;
    for(i=0;i<s.length();i++)
    {
        x.a.push_back(s[i]-'0');
    }
    x.a.resize(s.length(),0);
    return in;
}

ostream& operator <<(ostream &in,LargeNum &x)
{
    int i;
    for(i=0;i<x.a.size();i++)
    {
        cout<<x.a[i];
    }
    cout<<endl;
    vector<int>().swap(x.a);
}

LargeNum operator + (LargeNum fir,LargeNum sec)
{
    LargeNum sum;
    sum.a.resize(fir.a.size(),0);
    int i,j,k=0;
    if(fir.a.size()<sec.a.size())
    {
        LargeNum temp=fir;
        fir=sec;
        sec=temp;
    }
    sum.a.assign(sum.a.size(),0);
    for(i=fir.a.size()-1,j=sec.a.size()-1;i>=0;i--)
    {
        if(j>=0)
        {
            sum.a[i]=fir.a[i]+sec.a[j];
            j--;
        }
        else
        {
            sum.a[i]=fir.a[i];
        }
    }
    for(k=sum.a.size()-1;k>=0;k--)
    {
        if(sum.a[k]>9)
        {
            sum.a[k]-=10;
            if(k!=0)
            {
                sum.a[k-1]++;
            }
            else
            {
                sum.a.insert(sum.a.begin(),1);
            }
        }
    }
    return sum;
}

LargeNum operator - (LargeNum fir,LargeNum sec)
{
    int i,j,k;
    LargeNum sum;
    sum.a.clear();
    sum.a.resize(fir.a.size(),0);
    cout<<"fir-sec=";
    if(fir.a.size()<sec.a.size())//被减数位数少于减数时
    {
        vector<int> temp=fir.a;
        fir.a=sec.a;
        sec.a=temp;
        cout<<"-";
    }
    else if(fir.a.size()==sec.a.size())
    {
        for(i=0;i<fir.a.size();i++)
        {
            if(fir.a[i]==sec.a[i])
                continue;
            else if(fir.a[i]<sec.a[i])
            {
                vector<int> temp=fir.a;
                fir.a=sec.a;
                sec.a=temp;
                break;
            }
            else
                break;
        }
    }
    sum.a.assign(fir.a.size(),0);
    for(i=fir.a.size()-1,j=sec.a.size()-1;i>=0;i--)
    {
        if(j>=0)
        {
            sum.a[i]=fir.a[i]-sec.a[j];
            j--;
        }
        else
            sum.a[i]=fir.a[i];
    }
    for(k=sum.a.size()-1;k>=0;k--)
    {
        if(sum.a[k]<0)
        {
            sum.a[k]+=10;
            sum.a[k-1]-=1;
        }
    }
        for(i=0;i<sum.a.size()-1;i++)
    {
        if(sum.a[i]!=0)
            break;
    }
    for(k=i;k<sum.a.size();k++)
    {
        cout<<sum.a[k];
    }
    cout<<endl;
    return sum;
}

LargeNum operator * (LargeNum fir,LargeNum sec)
{
    LargeNum sum;
    int i,j,k,t;
    if(sec.a.size()>fir.a.size())
    {
        vector<int> temp=fir.a;
        fir.a=sec.a;
        sec.a=temp;
        vector<int>().swap(temp);
    }
    sum.a.resize(fir.a.size()+sec.a.size()-1,0);
    for(i=0;i<fir.a.size();i++)
    {
        k=i;
        for(j=0;j<sec.a.size();j++)
        {
            sum.a[k++]+=fir.a[i]*sec.a[j];
        }
    }
    for(k=sum.a.size()-1;k>=0;k--)
    {
        if(sum.a[k]>9)
        {
            if(k!=0)//如果不是首位
            {
                sum.a[k-1]+=sum.a[k]/10;
                sum.a[k]%=10;
            }
            else
            {
                t=sum.a[k]/10;
                sum.a[k]%=10;
                sum.a.insert(sum.a.begin(),t);
            }
        }
    }
    return sum;
}

int main()
{
    LargeNum fir,sec,sum;
    cout<<"Please enter two numbers:"<<endl;
    cin>>fir;
    cin>>sec;
    sum=fir+sec;
    cout<<"fir+sec=";
    cout<<sum;
    sum=fir-sec;
    sum=fir*sec;
    cout<<"fir*sec=";
    cout<<sum;
    return 0;
}