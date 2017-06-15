// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

template<typename T>
class TSingleton
{
public:
	/// brief 获取单例指针
	static T& Instance()
	{
		static T Instance;
		return Instance;
	}

protected:
	TSingleton(void) {}
	~TSingleton(void) {}
};