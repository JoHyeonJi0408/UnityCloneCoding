#include "jrdApplication.h"
#include "jrdInput.h"

namespace jrd
{
	Application::Application() 
		: mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0.0f)
	{

	}

	Application::~Application() 
	{
		
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0.0f, 0.0f);

		Input::Initialize();
	}

	void Application::Run() 
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() 
	{
		Input::Update();
		mPlayer.Update();
	}

	void Application::LateUpdate() 
	{
		// Late update logic here
	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
	}
} 