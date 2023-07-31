#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <iostream>
#include "User.h"
#include "DateTime.h"
using UUser::User;
using UDateTime::DateTime;

namespace UContext{
	// Precondicion: Ninguna
	// Postcondicion: Obtiene el usuario actual.
	// Para la entrega actual debe crear un unico usuario
	// y siempre debe devolver esa misma instancia de usuario
	User* GetCurrentUser();

	// Precondicion: Ninguna
	// Postcondicion: Libera todos los recursos asociados al contexto 
	DateTime* GetNow();

	// Precondicion: Ninguna
	// Postcondicion: Libera todos los recursos asociados al contexto
	void DestroyContext();
}

#endif
