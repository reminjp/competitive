//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  Copyright (c) 2019 HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
namespace hpc {

/// カメの行動。
enum Action
{
    /// その場で待機する。
    Action_Wait,
    /// 上に移動する。
    Action_MoveUp,
    /// 下に移動する。
    Action_MoveDown,
    /// 左に移動する。
    Action_MoveLeft,
    /// 右に移動する。
    Action_MoveRight,

    Action_TERM,
};

} // namespace
// EOF
