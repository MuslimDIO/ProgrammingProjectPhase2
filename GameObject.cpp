#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos , GameObject_Type a_type):_type(a_type)
{
	position = pos; // Sets Position
	
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject_Type GameObject ::getObjType () const
{
	return _type;
}
GameObject::~GameObject()
{
}