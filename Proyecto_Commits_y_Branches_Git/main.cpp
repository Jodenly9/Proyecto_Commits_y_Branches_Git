#include <iostream>
#include <string>
#include "Commit.h"
#include "User.h"
#include "DateTime.h"

using namespace std;
using namespace UGit;
using UDateTime::DateTime;
using UDateTime::ToFormat;
using UUser::User;

struct Branch{
	UGit::Commit* lastCommit;
};

void AddCommits(Branch* branch);
void Commit(Branch* branch, string message);
void Log(const DateTime* dateTime);
void Log(const User* user);
void Log(const Branch* branch);
void Log(const UGit::Commit* commit);
void DestroyAllCommits(Branch* branch);

int main() {
	Branch head;
	head.lastCommit = NULL;
	AddCommits(&head);
	Log(&head);
	DestroyAllCommits(&head);
	
	return 0;
}

void Commit(Branch* branch, string message){
	branch->lastCommit = CreateCommit(branch->lastCommit, message);
}

void AddCommits(Branch* branch){
	string ordinals[]={"First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh"};
	for(int i=0; i<7;++i){
		::Commit(branch, ordinals[i] + " commit.");
	}
}

void Log(const UGit::Commit* commit){
	cout<<"commit "<<UGit::GetHashCode(commit)<<endl;
	cout<<"Author: ";
	Log(UGit::GetAuthor(commit));
	cout<<endl;
	cout<<"Date: ";
	Log(UGit::GetDate(commit));
	cout<<"\n\t"<<UGit::GetMessage(commit);
	cout<<endl;
}

void Log(const Branch* branch){
	UGit::Commit * commit = branch->lastCommit;
	while(commit!=NULL){
		Log(commit);
		cout<<endl;
		commit = UGit::GetParent(commit);
	}
}

void Log(const DateTime* dateTime){
	cout<<ToFormat(dateTime, UDateTime::DateTimeFormat::DDMMYYYY_HHmmss);
}

void DestroyAllCommits(Branch* branch){
	UGit::Commit * iterator = branch->lastCommit;
	while(iterator!=NULL){
		UGit::Commit* commit = iterator;
		iterator = UGit::GetParent(commit);
		UGit::DestroyCommit(commit);
	}
}

void Log(const User* user){
	cout<<UUser::GetName(user)<<" "<<UUser::GetLastName(user)<<" "<<"<"<<UUser::GetNickName(user)<<">";
}