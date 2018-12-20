#pragma once

//������� �������� ���������� ������� �� ������
struct PolyTreeItem
{
	int value;
	int OriginIndex;
};

//������ ������ ������� ������ ���������� 
struct PolyTreeCell
{
	PolyTreeCell * less;
	PolyTreeCell * more;
	PolyTreeItem item;

	PolyTreeCell(PolyTreeItem newItem);
	~PolyTreeCell();

	void Add(PolyTreeItem newItem);
};

class PolyTree
{
public:
	PolyTree();
	~PolyTree();

	PolyTreeCell *root;

	void Add(PolyTreeItem newItem);
	PolyTreeItem ReturnAndRemoveMinimum();

	bool IsEmpty();
};

