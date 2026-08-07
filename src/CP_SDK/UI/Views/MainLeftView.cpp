#include "CP_SDK/UI/Views/MainLeftView.hpp"
#include "CP_SDK/UI/FlowCoordinators/MainFlowCoordinator.hpp"
#include "CP_SDK/Unity/SpriteU.hpp"

using namespace CP_SDK::XUI;
using namespace UnityEngine;

namespace CP_SDK::UI::Views {

    CP_SDK_IL2CPP_INHERIT_INIT(MainLeftView);

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Constructor
    CP_SDK_IL2CPP_DECLARE_CTOR_IMPL(MainLeftView)
    {
        OnViewCreation = {this, &MainLeftView::OnViewCreation_Impl};
    }
    /// @brief Destructor
    CP_SDK_IL2CPP_DECLARE_DTOR_MONOBEHAVIOUR_IMPL(MainLeftView)
    {

    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief On view creation
    void MainLeftView::OnViewCreation_Impl()
    {
        Templates::FullRectLayout({
            Templates::TitleBar(u"정보"),

            Templates::ScrollableInfos(50, {
                XUIText::Make(u"<b>" + FlowCoordinators::MainFlowCoordinator::Instance()->Title() + u"에 오신 것을 환영합니다!</b>\nHardCPP 제작")
                    ->SetAlign(TMPro::TextAlignmentOptions::CaplineLeft)
                    ->AsShared()
            }),

            Templates::ExpandedButtonsLine({
                XUIPrimaryButton::Make(u"문서", {this, &MainLeftView::OnDocumentationButton})->AsShared(),
                XUIPrimaryButton::Make(u"디스코드", {this, &MainLeftView::OnDiscordButton})->AsShared()
            }),
            Templates::ExpandedButtonsLine({
                XUISecondaryButton::Make(u"후원 - Patreon", {this, &MainLeftView::OnDonateButton})->AsShared()
            })
        })
        ->SetBackground(true, std::nullopt, true)
        ->BuildUI(get_transform());
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Documentation button
    void MainLeftView::OnDocumentationButton()
    {
        ShowMessageModal(u"웹 브라우저에서 URL을 열었습니다.");
        ChatPlexSDK::OpenURL(u"https://github.com/hardcpp/BeatSaberPlus/wiki");
    }
    /// @brief Go to discord
    void MainLeftView::OnDiscordButton()
    {
        ShowMessageModal(u"웹 브라우저에서 URL을 열었습니다.");
        ChatPlexSDK::OpenURL(u"https://discord.chatplex.org");
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    /// @brief Go to donate
    void MainLeftView::OnDonateButton()
    {
        ShowMessageModal(u"웹 브라우저에서 URL을 열었습니다.");
        ChatPlexSDK::OpenURL(u"https://donate.chatplex.org");
    }

}   ///< namespace CP_SDK::UI::Views