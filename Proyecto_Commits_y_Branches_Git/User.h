#ifndef USER_H_
#define USER_H_

#include <string>
using std::string;

namespace UUser{
	struct User;

	// Precondicion: Ninguna
	// Postdondicion: Crea una instancia valida de un User el cual tiene como nick name @nickName y
	// un string vacio como nombre y como apellido
	User* CreateUser(string nickName);

	// Precondicion: @user es una instancia valida
	// Postcondicion: Devuelve el nick name de @user
	string GetNickName(const User* user);

	// Precondicion: @user es una instancia valida
	// Postcondicion: Devuelve el apellido de @user
	string GetLastName(const User* user);


	// Precondicion: @user es una instancia valida
	// Postcondicion: Devuelve el nombre de @user
	string GetName(const User* user);


	// Precondicion: @user es una instancia valida
	// Postcondicion: Cambia el nombre de @user por @name
	void SetName(User* user, string name);


	// Precondicion: @user es una instancia valida
	// Postcondicion: Cambia el pellido de @user por @apellido
	void SetLastName(User* user, string lastName);

	// Precondicion: @user es una instancia valida
	// Postcondicion: Libera todos los recursos asociados a @user
	void DestroyUser(User* user);
}

#endif
