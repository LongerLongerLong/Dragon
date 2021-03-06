#pragma once

#include "Core.h"

#include "Window.h"
#include "Dragon/Core/LayerStack.h"
#include "Dragon/Events/Event.h"
#include "Dragon/Events/ApplicationEvent.h"
#include "Dragon/Events/KeyEvents.h"

#include "Dragon/ImGui/ImGuiLayer.h"

#include "Dragon/Core/Timestep.h"


namespace Dragon
{
	class  Application
	{
	public :
		Application();

		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnKeyBoard(KeyPressedEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Cursor = true;
		LayerStack m_LayerStack;
		Timestep timestep;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	// to be defined in the client
	Application* CreateApplication();
}

