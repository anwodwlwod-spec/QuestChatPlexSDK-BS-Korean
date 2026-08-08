#include "CP_SDK/UI/Modals/Message.hpp"
#include "CP_SDK/XUI/Templates.hpp"

using namespace CP_SDK::XUI;
using namespace UnityEngine;
using namespace UnityEngine::UI;

namespace CP_SDK::UI::Modals {
    CP_SDK_IL2CPP_INHERIT_INIT(Message);
    CP_SDK_IL2CPP_DECLARE_CTOR_IMPL(Message) { OnShow = {this, &Message::Impl_OnShow}; OnClose = {this, &Message::Impl_OnClose}; }
    CP_SDK_IL2CPP_DECLARE_DTOR_MONOBEHAVIOUR_IMPL(Message) {}
    void Message::Impl_OnShow()
    {
        if (m_Message) return;
        Templates::ModalRectLayout({
            XUIHLayout::Make({ XUIText::Make(u"메시지...")->SetAlign(TMPro::TextAlignmentOptions::Top)->SetColor(Color::get_yellow())->Bind(&m_Message)->AsShared() })
                ->OnReady([](Components::CHLayout* x) -> void { x->HOrVLayoutGroup()->set_childForceExpandWidth(true); x->CSizeFitter()->set_horizontalFit(ContentSizeFitter::FitMode::Unconstrained); })->AsShared(),
            XUIHLayout::Make({ XUIPrimaryButton::Make(u"확인", {this, &Message::OnOKButton})->SetWidth(20.0f)->AsShared() })->SetPadding(0)->AsShared()
        })->BuildUI(get_transform());
    }
    void Message::Impl_OnClose() {}
    void Message::Init(std::u16string_view p_Message, _v::CActionRef<> p_Callback) { m_Message->Element()->SetText(p_Message); m_Callback = p_Callback; }
    void Message::OnOKButton() { VController->CloseModal(this); try { m_Callback(); } catch (const std::exception& l_Exception) { ChatPlexSDK::Logger()->Error(u"[CP_SDK.UI.Modals][Message.OnOKButton] Error:"); ChatPlexSDK::Logger()->Error(l_Exception); } }
}