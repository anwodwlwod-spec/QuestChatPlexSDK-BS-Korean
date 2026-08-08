#include "CP_SDK/UI/Views/SettingsRightView.hpp"
#include "CP_SDK/Unity/SpriteU.hpp"

using namespace CP_SDK::XUI;
using namespace UnityEngine;

namespace CP_SDK::UI::Views {

    CP_SDK_IL2CPP_INHERIT_INIT(SettingsRightView);

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Constructor
    CP_SDK_IL2CPP_DECLARE_CTOR_IMPL(SettingsRightView)
    {
        OnViewCreation = {this, &SettingsRightView::OnViewCreation_Impl};
    }
    /// @brief Destructor
    CP_SDK_IL2CPP_DECLARE_DTOR_MONOBEHAVIOUR_IMPL(SettingsRightView)
    {

    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief On view creation
    void SettingsRightView::OnViewCreation_Impl()
    {
        Templates::FullRectLayout({
            Templates::TitleBar(u"기타 설정"),

            XUIText::Make(u"현재 사용 가능한 기타 설정이 없습니다!")->AsShared()
        })
        ->SetBackground(true, std::nullopt, true)
        ->BuildUI(get_transform());
    }

}   ///< namespace CP_SDK::UI::Views