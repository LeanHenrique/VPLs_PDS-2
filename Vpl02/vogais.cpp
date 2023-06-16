#include <iostream>
#include <string>

using namespace std;

void vogals(string text){
  int l = text.length();
  int a = 0;int e = 0;int i = 0;int o = 0;int u = 0;

  for(int j = 0;j < l; j++){
    if(text[j] == 'a') a++;
    if(text[j] == 'e') e++;
    if(text[j] == 'i') i++;
    if(text[j] == 'o') o++;
    if(text[j] == 'u') u++;
  }
  if(a >= 1) cout <<"a " << a << endl;
  if(e >= 1) cout <<"e " << e << endl;
  if(i >= 1) cout <<"i " << i << endl;
  if(o >= 1) cout <<"o " << o << endl;
  if(u >= 1) cout <<"u " << u << endl;
  
  
}

int main(){
  string text;
  cin >> text;

 vogals(text);

}