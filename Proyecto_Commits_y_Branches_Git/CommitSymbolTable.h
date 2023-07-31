#ifndef COMMIT_SYMBOL_TABLE_H_
#define COMMIT_SYMBOL_TABLE_H_

#include <string>
#include "Commit.h"
using UGit::Commit;

namespace UDiccionario {

	struct CommitSymbolTable;

	CommitSymbolTable* CreateCommitSymbolTable();
	UGit::Commit* GetCommit(CommitSymbolTable* table, const std::string& hashCode);
	void AddCommit(CommitSymbolTable* table, UGit::Commit* commit);
	void DestroyCommitSymbolTable(CommitSymbolTable* table);
}

#endif