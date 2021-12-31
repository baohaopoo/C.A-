#pragma once
#include "Define.h"
#include "Enum.h"
#include "Functional.h"

class MainGame
{
public:
	MainGame();
	~MainGame();


public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render();
	void Release();

private:
	HDC m_DC;


};

