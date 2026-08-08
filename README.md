# QuestChatPlexSDK-BS Korean

**Unofficial Korean patch for HardCPP's QuestChatPlexSDK-BS.**

Original project: https://github.com/hardcpp/QuestChatPlexSDK-BS

Korean patch/modifications by anwodwlwod-spec.

This repository retains the original MIT License and copyright notices. See `LICENSE` for details.

## 다운로드 / Download

한글 패치가 적용된 최신 `.qmod` 파일은 이 저장소의 **Releases**에서 받을 수 있습니다.

`.qmod` 파일을 설치하면 한글 패치가 적용됩니다.

---

Quest version of ChatPlex SDK for BeatSaber

This SDK was created to simplify and streamline mods creation for multiple games. It mostly provides generic components and utilities for Unity modding and also specific components and utilities for BeatSaber

Each mods using ChatPlexSDK-BS can declare a module (optional, described below), this module is like an interface for the SDK to manage your mod, show settings UI and a enable/disable toggle if the module `Type` is defined as `Integrated`

Components (Full list in documentation):
- **CP_SDK** *ChatPlex SDK game agnostic namepace*
  * **Animation** *Animated image loading and processing*
  * **Chat** *Chat service for connecting to various live streaming platforms chat*
  * **Config** *Json configuration utilities*
  * **Logging** *Logging utilities*
  * **Network** *Network and HTTP utilities*
  * **Pool** *Memory management & pools utilities*
  * **UI** *User interface components, views, flow coordinator, builders and factories*
  * **Unity** *Tools and extensions to interact with Unity on different layer & threads, load fonts/sprites/textures*
  * **Utils** *Various platform utils like Delegate/Action/Function/Event system*
  * **XUI** *Tree like syntax CP_SDK::UI builder*
- **CP_SDK_BS** *ChatPlex SDK BeatSaber specific*
  * **Game** *Game specific helper and utilities*
  * **UI** *BeatSaber specific UI compoenents and utilities*

# Documentation
[Doxygen Documentation](https://documentation.chatplex.org/QuestChatPlexSDK-BS/namespaces.html)

# Getting the SDK
To get the library, simply head over to the [releases](https://github.com/hardcpp/QuestChatPlexSDK-BS/releases) section, or build it yourself.
If you want to develop with the SDK simply follow the instructions below in `# How to use (As a dependency)`

# Building the library
To build the library, make sure you have QPM, CMake, Ninja installed
```sh
git clone https://github.com/hardcpp/QuestChatPlexSDK-BS.git --recursive
cd QuestChatPlexSDK-BS
qpm restore
qpm qmod build
cmake -G "Ninja" -DCMAKE_BUILD_TYPE="RelWithDebInfo" -B build
cmake --build ./build
```

# How to use (As a dependency)
Add this project as a dependence with QPM
```
qpm dependency add chatplex-sdk-bs
qpm restore
qpm qmod build
```

Add include path in `CMakeLists.txt` after `# codegen includes`
```cmake
# chatplex-sdk-bs includes
target_include_directories(${COMPILE_ID} PRIVATE ${EXTERN_DIR}/includes/chatplex-sdk-bs/shared)
```

Add defines in `CMakeLists.txt` after `include(qpm_defines.cmake)`
```cmake
add_definitions(-DCP_SDK_BMBF)
```

# Credits / Thanks
- Fern
- Pink
- RedBrumbler
- Sc2ad
