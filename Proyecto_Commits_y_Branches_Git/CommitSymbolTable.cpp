#include "CommitSymbolTable.h"

using UGit::Commit;
using UDiccionario::CommitSymbolTable;

struct Node {
	std::string hashCode;
	UGit::Commit* commit;
	Node* next;
};

struct CommitSymbolTable {
	Node* head;
};

UDiccionario::CommitSymbolTable* UDiccionario::CreateCommitSymbolTable() {
	CommitSymbolTable* table = new CommitSymbolTable;
	table->head = nullptr;
	return table;
}

UGit::Commit* UDiccionario::GetCommit(CommitSymbolTable* table, const std::string& hashCode) {
	Node* node = table->head;
	while (node != nullptr) {
		if (node->hashCode == hashCode) {
			return node->commit;
		}
		node = node->next;
	}
	return nullptr; 
}

void UDiccionario::AddCommit(CommitSymbolTable* table, Commit* commit) {
	Node* node = new Node;
	node->hashCode = GetHashCode(commit);
	node->commit = commit;
	node->next = table->head;
	table->head = node;
}

void UDiccionario::DestroyCommitSymbolTable(CommitSymbolTable* table) {
	Node* node = table->head;
	while (node != nullptr) {
		Node* next = node->next;
		DestroyCommit(node->commit);
		delete node;
		node = next;
	}
	delete table;
}