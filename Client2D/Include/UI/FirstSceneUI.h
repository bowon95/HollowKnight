#pragma once

#include "UI\UIWindow.h"

class CFirstSceneUI	:
	public CUIWindow
{
	friend class CSceneViewport;
	friend class CScene;

protected:
	CFirstSceneUI();
	CFirstSceneUI(const CFirstSceneUI& Window);
	virtual ~CFirstSceneUI();

protected:
	CSharedPtr<class CUIButton>	m_Button;
	CSharedPtr<class CUIText>	m_Title;
	CSharedPtr<class CUIProgressBar>	m_ProgressBar;
	CSharedPtr<class CUINumber>	m_Number;

private:
	CSharedPtr<class CUIImage>	m_Back;
	CSharedPtr<class CBackObj>	m_BackObj;
	CSharedPtr<class CUIImage>	m_HP;
	CSharedPtr<class CPlayer2D>	m_Player;
	CSharedPtr<class CColliderBox2D> m_GroundCollider;

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Render();
	virtual CFirstSceneUI* Clone();
	virtual void Save(FILE* File);
	virtual void Load(FILE* File);
};

