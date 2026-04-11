#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    //creation
    unordered_map<string,int>m;
    //insertion
    //1
    pair<string,int>p=make_pair("krishna",3);
    m.insert(p);

    //2
    pair<string,int>pair2("Bala",2);

    //3
    m["ballu"]=1;
    //whats gonna happen
    m["ballu"]=2;
    //here key value gets updated to 2 frm 1

    //search
    cout<<m["ballu"]<< endl;//here entry is done lets suppose if u have printed unknown key by this then unknown value will be stored to 0 and then if u wsnt to print by m.at method then 0 will be shown otherwise by m.at method abort error will be thrown
    cout<<m.at("krishna")<<endl;
    //size
    cout<<m.size()<<endl;
    //to check presence of certain key
    cout<<m.count("lala")<<endl;//here output will be 0 means false
    //erase
    m.erase("lala");
    cout<<m.size();
    
    //iterator
    unordered_map<string,int>:: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}
//when using ordered map tc while searchng by value will be o(n) 
//but when using map then tc will be o(log(n))
//also in unodered map order of printimg amd storing will ne be same as u have written like map 
//tc of hashmap while insertion deletion and search bu key is O(1)
//hashmap implementio using ll will O(n)
//hashmap implemention using bst will be O(logn)
//and using hashfunction it will beo(1)