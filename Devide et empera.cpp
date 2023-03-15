#include <iostream>
using namespace std;
int a[100],n,i;
void citire (){
    cout<<"n= ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }
}void afisare(){
    for (int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    // a suma cifrelor
}int devidesuma(int i ,int j){
    if(i==j) return a[i];
    else {
        int m,s1,s2;
        m=(i+j)/2;
        s1=devidesuma(i,m);
        s2=devidesuma(m+1,j);
        return s1+s2;
    }
}
// b produsul cifrelor
int devideprodus (int i,int j){
    if(i==j) return a[i];
    else {
        int  m,p1,p2;
        m=(i+j)/2;
        p1=devideprodus(i,m);
        p2=devideprodus(m+1,j);
        return p1*p2;
    }
}
//c suma nr pare
int devideimp(int i, int j){
    if(i==j){
        if(a[i]%2==1) return a[i];
        else return 0;
    } else{int m,s1,s2;
        
        m=(i+j)/2;
        s1=devideimp(i,m);
        s2=devideimp(m+1,j);
        return s1+s2;
    }
}
//d cmmdc
int cmmdc(int x,int y){
    while (x!=y)
        if(x>y) x=x-y;
        else y=y-x;
    return x;
    }
int devidecmmdc(int i, int j){
    if (i==j ) return a[i];
    else {int m,d1,d2;
        m=(i+j)/2;
        d1=devidecmmdc(i,m);
        d2=devidecmmdc(m+1,j);
        return cmmdc(d1,d2);
    }
}
//e minimul
int devidemin(int i,int j){
    if(i==j)return a[i];
    else {int m,min1,min2;
        m=(i+j)/2;
        min1=devidemin(i,m);
        min2=devidemin(m+1,j);
        if(min1<min2) return min1;
        else return min2;
    }
}//f suma cifrelor
int sumacif(int x){
    int s=0;
    while(x!=0){
        s=s+x%10;
        x=x/10;
    }
    return s;}
int devidesumacif(int i,int j ){
    if(i==j) return sumacif (a[i]);
    else{int m,s1,s2;
        m=(i+j)/2;
        s1=devidesumacif(i,m);
        s2=devidesumacif(m+1,j);
        return(s1+s2);
        
    }
}
//g nr valorilor palindron
int palindrom(int x){
    int y=x,
    inv =0;
    while (y!=0)
    {inv =inv*10+y%10;
        y=y/10;
    } if(inv==x) return 1;
    else return 0;
}
int devidepalindrom(int i,int j){
    if (i==j){
        if(palindrom(a[i]==1)) return 1;
        else return 0;
        
    }else {
        int m,p1,p2;
        m=(i+j)/2;
        p1=devidepalindrom(i,m);
        p2=devidepalindrom(m+1,j);
        return p1+p2;
    }
}
//h nr valorilor prime
int prim(int x)
{
    int d;
    if(x<2)return 0;
    for(d=2;d<=x/2;d++)
        if(x%d==0) return 0;
    return 1;
}
int devideprim(int i,int j)
{
    if (i==j){
        if(prim(a[i])) return 1;
        else return 0;
    }
    
    else{int m,p1,p2;
        m=(i+j)/2;
        p1=devideprim(i,m);
        p2=devideprim(m+1,j);
        return p1+p2;
    }
    
}

int main (){
    citire();
    afisare();
    cout<<"sumacifrelor = "<<devidesuma(1,n)<<endl;
    cout<<"produsul= "<<devideprodus (1,n)<<endl;
    cout<<"suma nr pare = "<<devidesumacif(1,n)<<endl;
    cout<<"cmmdc ="<<devidecmmdc(1,n)<<endl;
    cout<<"minim= "<<devidemin(1,n)<<endl;
    cout<<"sumacifrelor= "<<devidesumacif(1,n)<<endl;
    cout<<"nr valorilor palindrom= "<<devidepalindrom(1,n)<<endl;
    cout<<"nr de val prime ="<<devideprim(1,n)<<endl;
    return 0;
                                          
}

