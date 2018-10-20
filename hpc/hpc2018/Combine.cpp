﻿//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  Copyright (c) 2018 HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------
// メインとなる cpp に #pragma once を書くと
// コンパイラによっては警告が出るため、
// ここには #pragma once は書きません。

// 複数のcppファイルを1ファイルにまとめてコンパイルします。
// これにより、コンパイラの最適化が促進されます。(主に関数のインライン展開)

// この手法は、あるcppの記述が別のcppに影響を与えるケースがあることに注意してください。
// 例: #includeしたヘッダが他のcppでも使用できる
// 例: #defineで定数やマクロを定義すると、他のcppにも反映される
// 例: 無名名前空間で関数を定義すると、他のcppからも参照できる

// Answer.cpp以外のファイルをインクルードします。
// 順番は任意です。
#include "src/Action.cpp"
#include "src/CandidateLane.cpp"
#include "src/CandidateLaneRecipe.cpp"
#include "src/Game.cpp"
#include "src/Main.cpp"
#include "src/Math.cpp"
#include "src/Oven.cpp"
#include "src/OvenRecipe.cpp"
#include "src/Parameter.cpp"
#include "src/Piece.cpp"
#include "src/Random.cpp"
#include "src/RandomSeed.cpp"
#include "src/Recorder.cpp"
#include "src/Simulator.cpp"
#include "src/Stage.cpp"
#include "src/Timer.cpp"
#include "src/Util.cpp"
#include "src/Vector2i.cpp"

// Answer.cppは最後にインクルードします。
// (Answer.cpp内の定義が、意図せず他のファイルに影響を与えるのを防ぐため)
#include "src/Answer.cpp"
