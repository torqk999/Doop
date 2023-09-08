#pragma once

#define ALL_PROPERTY_KEYS \
TRANSFORM_KEYS \
NullProperty, \

static int KEY_LIST_TOTAL = 0;

#define ADD_KEYLIST( listName , listSize ) \
static std::string listName[listSize]; \
KEY_LIST_TOTAL++;

#define ADD_KEY( index, enumName ) \


#define ADD_KEY_ENUM( enumKey ) \
enumKey ,

#define TRANSFORM_KEYS \
Right_X, Right_Y, Right_Z, Right_S, \
Up_X, Up_Y, Up_Z, Up_S, \
Forward_X, Forward_Y, Forward_Z, Forward_S, \
Pos_X, Pos_Y, Pos_Z, Pos_S, \
TRANSFORM_KEYS_END = Pos_S, \

#define stringify( name ) #name

class KeyLists
{
public:

	KEY_LIST(TransformList, (int)TransformKey::TRANSFORM_KEYS_END)

	//static std::string TransformList[(int)TransformKey::TRANSFORM_KEYS_END];
	void ListInit()
	{
		for (int i = 0; i < (int)TransformKey::TRANSFORM_KEYS_END; i++)
			TransformList[i] = stringify();
	}
};

enum class PropertyKey
{
	ALL_PROPERTY_KEYS
};

enum class TransformKey
{
	TRANSFORM_KEYS
};

enum SystemKey
{
	Transform,
};