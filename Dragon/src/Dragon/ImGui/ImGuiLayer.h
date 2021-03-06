#pragma once

#include "Dragon/Core/Layer.h"

#include "Dragon/Events/ApplicationEvent.h"
#include "Dragon/Events/KeyEvents.h"
#include "Dragon/Events/MouseEvent.h"

namespace Dragon
{
	class DRAGON_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		//virtual void OnEvent(Event& e) override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}
