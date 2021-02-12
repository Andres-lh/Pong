#pragma once
#include "render.h"
#include "player.h"
#include "input.h"
#include "ball.h"

void simulateGame( RenderState& renderState, Input& input, float deltaTime);

void collision(Ball& ball, Player& player1, Player& player2);

void score(Ball& ball, Player& player1, Player& player2);