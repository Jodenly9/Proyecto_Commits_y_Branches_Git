#include "User.h"
#include <iostream>
#include <string>

using UUser::User;
using std::string;

struct UUser::User{
    string nickName;
    string name;
    string lastName;
};
	// Postdondicion: Crea una instancia valida de un User el cual tiene como nick name @nickName y
	// un string vacio como nombre y como apellido
User* UUser::CreateUser(string nickName){
	User* user= new User;
    user->nickName= nickName;
    user->name= "";
    user->lastName= "";
	return user;
}
	// Postcondicion: Devuelve el nick name de @user
string UUser::GetNickName(const User* user){
	return user->nickName;
}
	// Postcondicion: Devuelve el apellido de @user
string UUser::GetLastName(const User* user){
	return user->lastName;
}
	// Postcondicion: Devuelve el nombre de @user
string UUser::GetName(const User* user){
	return user->name;
}
	// Postcondicion: Cambia el nombre de @user por @name
void UUser::SetName(User* user, string name){
	user->name= name;
}
	// Postcondicion: Cambia el pellido de @user por @apellido
void UUser::SetLastName(User* user, string lastName){
	user->lastName= lastName;
}
	// Postcondicion: Libera todos los recursos asociados a @user
void UUser::DestroyUser(User* user){
	delete user;
}
