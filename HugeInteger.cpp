#include <iostream>
#include <string>
using namespace std;

//the implementation of class HugeInteger 
class HugeInteger{
    string value;
    
    public:
    //the construtor
    HugeInteger(){
        value = "0";
    }
    
    HugeInteger(int n){
        value = to_string(n);
    }
    
    HugeInteger(string n){
        value = n;
    }
    
    void clearall(void){
        value.clear();
    }
    //the operator overloading
    friend ostream &operator<<(ostream &output, const HugeInteger &H )
    { 
        output << H.value;
        return output;            
    }
 
    friend istream &operator>>(istream  &input, HugeInteger &H )
    { 
         input >> H.value;
         return input;            
    }
    //the core part of operator overloading
    HugeInteger operator+(const HugeInteger& H){
        HugeInteger res;
        res.clearall();
        char temp;
        int carry=0;
        int i=this->value.length()-1;
        int j=H.value.length()-1;
        while(i>=0||j>=0){
            if(i<0)temp = H.value[j]+carry;
            else if(j<0)temp = this->value[i]+carry;
            else temp = this->value[i]+H.value[j]+carry-'0';
            carry=0;
            if(temp>'9'){
                temp-=10;
                carry=1;
            }
            res.value.insert(0,1,temp);
            if(i>=0)i--;
            if(j>=0)j--;
        }
        if(carry==1)res.value.insert(0,1,carry+'0');
        return res;
    }
    //the calling of existing definition (namely the overloading of plus sign)
    HugeInteger operator+(int a){
        HugeInteger res(a);
        res=*this + res;
        return res;
    }
    
    HugeInteger operator+(string a){
        HugeInteger res(a);
        res=*this + res;
        return res;
    }
};

int main()
{
   HugeInteger n1( 7654321 );
   HugeInteger n2( 7891234 );
   HugeInteger n3( "99999999999999999999999999999" );
   HugeInteger n4( "1" );
   HugeInteger n5;
   cout << "n1 is " << n1 << "\nn2 is " << n2
      << "\nn3 is " << n3 << "\nn4 is " << n4
      << "\nn5 is " << n5 << "\n\n";
   n5 = n1 + n2;
   cout << n1 << " + " << n2 << " = " << n5 << "\n\n";
   cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";
   n5 = n1 + 9;
   cout << n1 << " + " << 9 << " = " << n5 << "\n\n";
   n5 = n2 + "10000";
   cout << n2 << " + " << "10000" << " = " << n5 << endl;

    return 0;
}

