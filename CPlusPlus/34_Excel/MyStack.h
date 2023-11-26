#pragma once

#include "utils.h"

// Ό³Έν :
class MyStack
{
private:
	struct Node
	{
		friend MyStack;

	private:
		Node* PrevNode;
		char s;

	public:

		Node(Node* _Node, const char _s)
			: PrevNode(_Node), s(_s)
		{

		}
	};


public:
	// constrcuter destructer
	MyStack();
	~MyStack();

	// delete Function
	MyStack(const MyStack& _Other) = delete;
	MyStack(MyStack&& _Other) noexcept = delete;
	MyStack& operator=(const MyStack& _Other) = delete;
	MyStack& operator=(MyStack&& _Other) noexcept = delete;

protected:

private:
	Node StartNode;
	Node* CurNode;


};

