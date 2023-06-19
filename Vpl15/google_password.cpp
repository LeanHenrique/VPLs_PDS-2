#include "google_password.h"
#include <iostream>
using namespace std;

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  if(validPassword(password)){
    if(passwords_.find(url)== passwords_.end()){                          
    Usuario u;
    u.login = login;
    u.password = password;
    passwords_[url]= u;
    }
  }
}

void GooglePassword::remove(const std::string& url) {
  for(auto it = passwords_.begin(); it != passwords_.end(); it++){
     if(it->first == url){
        passwords_.erase(it);
        break;
  }
 }
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo
  /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */
  if(validPassword(new_password)){
    for(auto it = passwords_.begin(); it != passwords_.end(); it++){
        if(it->first == url && it->second.password == old_password){
            it->second.login = login;
            it->second.password = new_password;
        }
  }
}
                            }

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * 3
   * aaa.site.com: login and password
   * www.site.com: login and password
   * zzz.site.com: login and password
   *
   */
  cout << passwords_.size() << endl;
  for(auto it = passwords_.begin(); it != passwords_.end(); it++){
    cout << it->first << ": " << it->second.login << " and " << it->second.password << endl;
  }

}

bool GooglePassword::validPassword(const std::string& password) const {
   string sequencia = "123456";
   string whiteCaracter = " ";
   if(password.find(sequencia) == std::string::npos){
     if(password.size() <= 50 && password.size() >= 6){
        if(password.find(whiteCaracter) == std::string::npos){
            return true;
        }
     }
   }
   return false;
}

