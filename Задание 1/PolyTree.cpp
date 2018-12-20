#include "pch.h"
#include "PolyTree.h"


PolyTree::PolyTree()
{
	PolyTreeItem initItem;
	initItem.OriginIndex = -1;
	initItem.value = 2000000000;
	root = new PolyTreeCell(initItem);
}


PolyTree::~PolyTree()
{
	delete root;
}

void PolyTree::Add(PolyTreeItem newItem)
{
	root->Add(newItem);
}

PolyTreeItem PolyTree::ReturnAndRemoveMinimum()
{
	PolyTreeCell* parent;
	PolyTreeCell * current;

	parent = current = root;

	while (current->less)
	{
		parent = current;
		current = current->less;
	}

	PolyTreeItem result = current->item;

	if (current->more)
		parent->less = current->more;
	else
		parent->less = nullptr;

	delete current;

	return result;
}

PolyTreeCell::PolyTreeCell(PolyTreeItem newItem)
{
	less = nullptr;
	more = nullptr;
	item = newItem;
}

PolyTreeCell::~PolyTreeCell()
{
	if (less)
		delete less;
	if (more)
		delete more;
}

void PolyTreeCell::Add(PolyTreeItem newItem)
{
	//Если новый элемент меньше, то добавить его налево, если больше - направо
	if (newItem.value < item.value)
	{
		//Если элемента слева нет - создать его
		if (!less)
			less = new PolyTreeCell(newItem);
		//Иначе просим меньший элемент добавить айтем к себе
		else
			less->Add(newItem);
	}
	else
	{
		if (!more)
			more = new PolyTreeCell(newItem);
		else
			more->Add(newItem);
	}
}

bool PolyTree::IsEmpty()
{
	return root->less == nullptr;
}