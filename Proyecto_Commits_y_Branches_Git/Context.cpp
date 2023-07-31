#include <iostream>
#include "context.h"
#include "User.h"
#include "DateTime.h"

using UUser::User;
using UDateTime::DateTime;

static User* currentUser = NULL;

// Correcto
User* UContext::GetCurrentUser(){
	if (currentUser== NULL){
	    currentUser = UUser::CreateUser("Default User");
	}
	return currentUser;
}

DateTime* UContext::GetNow(){
	return UDateTime::Now();    
}

void UContext::DestroyContext(){
    UUser::DestroyUser(currentUser);
}
