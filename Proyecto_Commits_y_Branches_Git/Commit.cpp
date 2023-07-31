#include <iostream>
#include <string>
#include "Commit.h"
#include "Context.h"
#include "User.h"
#include "DateTime.h"
#include <random>

using std::string;
using UUser::User;
using UDateTime::DateTime;

struct UGit::Commit{
    User* author;
    DateTime* dateTime;
    string message;
    Commit* parent;
    string hashCode;
};
string generateRandomHash(){
	string characters = "0123456789abcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    string random_string;
    for (size_t i = 0; i < 40; ++i) {
        random_string += characters[distribution(generator)];
    }
    return random_string;
}
	// Postdondicion: Crea una instancia valida de un Commit el cual debe tener
	// - Un commit predecesor (@parent) el cual puede ser NULL
	// - Un mensaje (@message) que describe los objetivos de los cambios que se hicieron en el commit
	// - Un HashCode que por ahora sera simplemente un codigo alfanumerico de 40 caracteres randoms,
	// los caracteres deben estar en minusculas
	// - Una fecha y hora actual del momento de creacion obtenida de Context.h
	// - El usuario que se encuentra en el contexto de la operacion obtenido de Context.h
UGit::Commit* UGit::CreateCommit(Commit* parent, string message){
    Commit* commit= new Commit;
    commit->parent= parent;
    commit->message= message;
    commit->hashCode= generateRandomHash();
    commit->dateTime= UContext::GetNow();
    commit->author= UContext::GetCurrentUser();
    return commit;
}
	// Postcondicion: Devuelve el usuario autor del @commit
User* UGit::GetAuthor(const Commit* commit){
    return commit->author;
}
	// Postcondicion: Devuelve la fecha y hora de creacion del @commit
DateTime* UGit::GetDate(const Commit* commit){
    return commit->dateTime;
}
	// Postcondicion: Devuelve el mensaje asociado al @commit
string UGit::GetMessage(const Commit* commit){
    return commit->message;
}
	// Postcondicion: Devuelve el commit predecesor de @commit
UGit::Commit* UGit::GetParent(const Commit* commit){
    return commit->parent;
}
	// Postcondicion: Devuelve el hash code de @commit
string UGit::GetHashCode(const Commit* commit){
    return commit->hashCode;
}
	// Postcondicion: Devuelve los primero ocho caracteres del hash code de @commit
string UGit::GetShortHashCode(const Commit* commit){
    return commit->hashCode.substr(0, 8);
}
	// Postcondicion: Libera todos los recursos asociados de @commit
void UGit::DestroyCommit(Commit* commit){
    delete commit;
}
