#pragma once

class TournamentNode
{
	int value;
	int level;
	TournamentNode* firstChild;
	TournamentNode* secondChild;
public:
	TournamentNode(int _value, int _level, TournamentNode* _firstChild, TournamentNode* _secondChild);
	int getValue() { return value; };
	int getLevel() { return level; };
	bool isTerminationLeaf() { return (firstChild == NULL && secondChild == NULL) ? true : false; }
	bool operator==(TournamentNode& node);
};

TournamentNode::TournamentNode(int _value, int _level, TournamentNode* _firstChild, TournamentNode* _secondChild)
{
	value = _value;
	level = _level;
	firstChild = _firstChild;
	secondChild = _secondChild;
}

inline bool TournamentNode::operator==(TournamentNode& node)
{
	if (node.getValue() == getValue() && level == 0)
		return true;
	return false;
}

